#include "PlayerCharacter.h"
#include <raymath.h>

void PlayerCharacter::Start()
{
    position = { 100,100 };
	texture = LoadTexture("wabbit_alpha.png");
	inventory = new Inventory();
}

void PlayerCharacter::Draw() {
	DrawTexture(texture, position.x, position.y, WHITE);
	DrawText("Player", position.x, position.y-40, 10, WHITE);
}

void PlayerCharacter::Update()
{
    float speed = 200.0f;
    Vector2 vel = { 0 };

    if (IsKeyDown(KEY_W)) vel.y -= 1;
    if (IsKeyDown(KEY_S)) vel.y += 1;
    if (IsKeyDown(KEY_A)) vel.x -= 1;
    if (IsKeyDown(KEY_D)) vel.x += 1;

    if (Vector2Length(vel) > 0.0f)
        vel = Vector2Normalize(vel);

    position.x += vel.x * speed * GetFrameTime();
    position.y += vel.y * speed * GetFrameTime();

}
