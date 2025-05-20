#pragma once
#include "GameObject.h"
class Prop : public GameObject
{
public:
	Vector2 position;
	Prop(char* _name,Vector2 pos,bool isEnabled) : GameObject(_name,isEnabled),position(pos) {}
	void Start() override;
	void Draw() override;
	void Update()override;
};

