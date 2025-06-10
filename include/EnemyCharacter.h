#pragma once
#include "Inventory.h"
#include "GameObject.h"
class EnemyCharacter:public GameObject
{
public:
	float speed = 40.f;
	Vector2 target;
	float scrollBorder = 100;
	Vector2 camaraOffset = { 0,0 };
	Inventory* inventory;
	EnemyCharacter(char* _name, Vector2 _target,bool isEnabled,Vector2 _position) : GameObject(_name, isEnabled,_position), target(_target) {}
	void Start() override;
	void Draw() override;
	void Update(Vector2 playerPosition);
	void Update()override;
	void FollowPlayer(Vector2 playerPos);
};

