#include "EnemyCharacter.h"
#include <raymath.h>

void EnemyCharacter::Update(Vector2 playerPosition)
{
    Vector2 direction = Vector2Subtract(playerPosition, position);
    float distance = Vector2Length(direction);

    if (distance > 1.0f) {
        direction = Vector2Normalize(direction);
        position = Vector2Add(position, Vector2Scale(direction, speed * GetFrameTime()));
    }
}
void EnemyCharacter::Update()
{
}
void EnemyCharacter::FollowPlayer(Vector2 playerPos)
{
    Vector2 direction = Vector2Subtract(playerPos, position);
    float distance = Vector2Length(direction);

    if (distance > 1.0f) {
        direction = Vector2Normalize(direction);
        position = Vector2Add(position, Vector2Scale(direction, speed * GetFrameTime()));
    }
}
void EnemyCharacter::Start()
{
    texture = LoadTexture("CrabEnemy.png");
    inventory = new Inventory();
}


void EnemyCharacter::Draw() {
	DrawTexture(texture, position.x, position.y, WHITE);
	DrawText(name.c_str(), position.x, position.y - 40, 10, WHITE);
}
