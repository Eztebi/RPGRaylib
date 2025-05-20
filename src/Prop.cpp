#include "Prop.h"

void Prop::Start()
{
	texture = LoadTexture("wabbit_alpha.png");
}

void Prop::Draw()
{
	DrawTexture(texture, position.x, position.y, WHITE);
}

void Prop::Update()
{
}
