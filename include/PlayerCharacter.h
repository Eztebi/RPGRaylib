#pragma once
#include "Inventory.h"
#include "GameObject.h"
class PlayerCharacter :public GameObject
{

public:
	float speed = 10.f;

	float scrollBorder = 100;
	Vector2 camaraOffset = { 0,0 };
	Inventory* inventory;
	PlayerCharacter(char* _name,bool isEnabled,Vector2 position) : GameObject(_name, isEnabled,position){}

	void Start() override;
	void Draw() override;
	void Update() override;
};

