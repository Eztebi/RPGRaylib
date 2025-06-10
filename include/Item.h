#pragma once
#include <string>

class Inventory;

class Item
{
public:
	std::string name;
	int id;
	Item(std::string name, int id) : 
		name(name), id(id) {}
	
	//setter de inventario
	void SetInventory(Inventory* _inventory)
	{
		inventory = _inventory;
	}
	void Consume();

private: 
	Inventory* inventory;

};

