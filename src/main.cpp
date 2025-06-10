
#include "raylib.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include "resource_dir.h"	// utility header for SearchAndSetResourceDir
#include "PlayerCharacter.h"
#include "PanelMensaje.h"
#include "EnemyCharacter.h"
#include "Prop.h"
#include <raymath.h>
#include <queue>
#include "Heap.h"

extern "C" {
#include "md5.h"

}
typedef std::vector<std::vector<int>> Map2D;

void LoadMap(Map2D& _map, size_t _x, size_t _y,char* fileName) //Variable referencia con & y con loadmap podemos modificar el mapa
{
    std::ifstream filemap(fileName);
    if (filemap.is_open()) {
        char c;
        _map.resize(_y, std::vector<int>(_x, 0)); // Redimensionar el mapa
        for (size_t j = 0; j < _y; j++) {
            for (size_t i = 0; i < _x; i++) {
                filemap.get(c);
                if (filemap.eof()) {
                    std::cout << "Final inesperado del archivo de mapa" << std::endl;
                    return;
                }
                _map[j][i] = c - '0';
            }
            filemap.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    else {
        std::cout << "No se pudo abrir el archivo de mapa" << std::endl;
    }
}

Music LoadBGM() 
{
	const char* default = "TECNO1.XM";
	std::fstream configfile("config.ini");
	if (configfile.is_open()) 
	{
		std::string linea;
		char buffer[64];
		while (std::getline(configfile, linea)) 
		{
			std::cout << "Linea leida: " << linea << std::endl;
			char* llave = strtok((char*)linea.c_str(), "="); //con el token =
			if (strcmp("music", llave) == 0)
			{
				char* valor = strtok(NULL, "=");
				std::cout << "Se encontró la llave music" << std::endl;
			}
		}
	}
	else 
	{
		std::cout << "No se pudo abrir el archivo config.ini, usando BGM default" << std::endl;
		return LoadMusicStream("TECNO1.XM");
	}
}

int main ()
{
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

    int tileSize = 30;
    int maxTilesH = 25;
    int maxTilesV = 20;

    InitWindow(maxTilesH * tileSize, maxTilesV * tileSize, "Tiles");

    Rectangle button1 = { 100, 200, 200, 50 };
    Rectangle button2 = { 100, 300, 200, 50 };
    Rectangle button3 = { 100, 400, 200, 50 };

    bool menuVisible = true;

    Map2D mapa(maxTilesV, std::vector<int>(maxTilesH, 0));

    SearchAndSetResourceDir("resources");
    LoadMap(mapa, maxTilesH, maxTilesV, "map1.txt");

    Texture wabbit = LoadTexture("wabbit_alpha.png");
    Texture tiles[4] = {
        LoadTexture("tierra.png"),
        LoadTexture("roca.png"),
        LoadTexture("agua.png"),
        LoadTexture("pasto.png")
    };

    InitAudioDevice();
    Music bgm = LoadMusicStream("TECNO1.XM");
  
    char buffer[64];
    //Inventory
    Inventory* inventario = new Inventory();
    inventario->AddItem(new Item("Espada", 1));
    inventario->AddItem(new Item("Pocion", 2));
    inventario->AddItem(new Item("Mondongo", 3));
    inventario->debugPrintContents();

    //Gameobjects
    PlayerCharacter* player = new PlayerCharacter("Player1",true,{500,100});
    player->Start();
    player->inventory = inventario;
    player->printUID();
    EnemyCharacter* enemy1 = new EnemyCharacter("Enemy1",player->position,true,{100,300});
    enemy1->Start();
    enemy1->inventory = inventario;
    enemy1->printUID();
    EnemyCharacter* enemy2 = new EnemyCharacter("Enemy2", player->position, true,{200,500});
    enemy2->Start();
    enemy2->inventory = inventario;
    enemy2->printUID();
    EnemyCharacter* enemy3 = new EnemyCharacter("Enemy3", player->position, true, { 600,600 });
    enemy3->Start();
    enemy3->inventory = inventario;
    enemy3->printUID();
    EnemyCharacter* enemy4 = new EnemyCharacter("Enemy4", player->position, true, { 0,600 });
    enemy4->Start();
    enemy4->inventory = inventario;
    enemy4->printUID();
    Prop* prop = new Prop("Pastel", true, { 100,400 });
    prop->Start();

    //Gameobject list
    std::vector<GameObject*> gameObjects;
    gameObjects.push_back(enemy1);
    gameObjects.push_back(enemy2);
    gameObjects.push_back(enemy3);
    gameObjects.push_back(enemy4);
    gameObjects.push_back(player);
    gameObjects.push_back(prop);

    std::vector<EnemyCharacter*> enemies;
    enemies.push_back(enemy1);
    enemies.push_back(enemy2);
    enemies.push_back(enemy3);
    enemies.push_back(enemy4);
    PanelMensaje* panel = new PanelMensaje(GetScreenWidth() - 210, 200, 50, 2);
    panel->Show("thief");
    panel->Show("gossip");
    panel->Show("fisher");
    panel->Show("hoarder");
    PanelMensaje* enemyAttack = new PanelMensaje(GetScreenWidth() - 550, 300, 50, 1);

    //Enemy Heap fo Attacks
    Heap enemyHeap;
    EnemyCharacter* lastClosestEnemy = nullptr;
    float lastClosestDistance = std::numeric_limits<float>::max();
    //prueba de calculo de hash usando md5 usando la biblioteca de zunawe
    uint8_t result[16];
    char* mensaje = "hola mundo";

    md5String(mensaje, result);
    //imprimir el hash en hexadecimal
    for (int i = 0; i < 16;i++) {
        printf("%02X", result[i]);
        //printf
    }
    while (!WindowShouldClose()) {
        UpdateMusicStream(bgm);
        Vector2 mousePoint = GetMousePosition();
       
        if (menuVisible && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            if (CheckCollisionPointRec(mousePoint, button1)) {
                LoadMap(mapa, maxTilesH, maxTilesV, "map.txt");
                PlayMusicStream(bgm);
                menuVisible = false;
            }
            if (CheckCollisionPointRec(mousePoint, button2)) {
                LoadMap(mapa, maxTilesH, maxTilesV, "map1.txt");
                PlayMusicStream(bgm);
                menuVisible = false;
            }
            if (CheckCollisionPointRec(mousePoint, button3)) {
                LoadMap(mapa, maxTilesH, maxTilesV, "map2.txt");
                PlayMusicStream(bgm);
                menuVisible = false;
            }
            
        }
        else if (menuVisible == false) {
            player->Update();

            panel->Update();
            enemyAttack->Update();

            if (IsKeyPressed(KEY_LEFT)) {
                inventario->PreviusItem();
            }
            else if (IsKeyPressed(KEY_RIGHT)) {
                inventario->NextItem();
            }

            for (EnemyCharacter* enemy : enemies) {
                enemy->Update(player->position);

                float dist = Vector2Distance(player->position, enemy->position);

                if (dist < 40.f) {
                    enemyHeap.insert({ enemy, dist });
                }
            }

            if (!enemyHeap.is_empty()) {
                EnemyDistance closest = enemyHeap.peek();
                EnemyCharacter* closestEnemy = closest.enemy;
                float closestDist = closest.distance;

                if (closestEnemy != lastClosestEnemy || closestDist < lastClosestDistance) {
                    enemyAttack->Show(closestEnemy->GetName() + " te esta atacando!");

                    lastClosestEnemy = closestEnemy;
                    lastClosestDistance = closestDist;
                }
            }
            else {
                // Opcionalmente puedes ocultar el mensaje si no hay enemigos cerca
                // panelMensaje->Hide();

                //lastClosestEnemy = nullptr;
                //lastClosestDistance = std::numeric_limits<float>::max();
            }
        }
        BeginDrawing();
        ClearBackground(BLACK);

        for (int i = 0; i < maxTilesV; i++) {
            for (int j = 0; j < maxTilesH; j++) {
                DrawTexture(tiles[mapa[i][j]], j * tileSize, i * tileSize, WHITE);
            }
        }

        DrawText("TILES", 20, 20, 20, YELLOW);
        DrawText(buffer, 20, 40, 20, YELLOW);

        //Dibujar objetos
        for (GameObject* object: gameObjects)
        {
            if (object->isEnabled == true) {
                object->Draw();
                object->DrawUID();
            }
            
        }
        if (menuVisible) {
            DrawRectangleRec(button1, LIGHTGRAY);
            DrawRectangleRec(button2, LIGHTGRAY);
            DrawRectangleRec(button3, LIGHTGRAY);
            DrawText("Mapa 1", 130, 215, 20, BLACK);
            DrawText("Mapa 2", 130, 315, 20, BLACK);
            DrawText("Mapa 3", 130, 415, 20, BLACK);
        }


        panel->Draw();
        enemyAttack->Draw();
        
        inventario->ShowItem(0, 0, 150, 30);

        EndDrawing();
    }

    UnloadTexture(wabbit);
    CloseWindow();
    return 0;
}

