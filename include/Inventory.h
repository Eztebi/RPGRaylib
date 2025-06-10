#pragma once
#include "LinkedList.h"
#include "Item.h"
#include "raylib.h"
class Inventory :
	public LinkedList<Item>
{

public:
	Vector2 position;
	Vector2 size;
	std::string message;

	//constructor
	Inventory() : LinkedList<Item>() {}
	//agregar item al inventario
	void AddItem(Item* _item);

	void NextItem();
	void PreviusItem();
	void debugPrintContents();
	void ShowItem(float posX, float posY, float width, float height);
	LLNode<Item>* currentItem;

};

