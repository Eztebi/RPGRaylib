#include "Prop.h"

void Prop::Start()
{
	texture = LoadTexture("CakeProp.png");
}

void Prop::Draw()
{
	DrawTexture(texture, position.x, position.y, WHITE);
	DrawText(name.c_str(), position.x, position.y - 40, 10, WHITE);
}

void Prop::Update()
{
}
