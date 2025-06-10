#pragma once
#include "GameObject.h"
class Prop : public GameObject
{
public:
	Prop(char* _name,bool isEnabled, Vector2 position) : GameObject(_name,isEnabled,position) {}
	void Start() override;
	void Draw() override;
	void Update()override;
};

