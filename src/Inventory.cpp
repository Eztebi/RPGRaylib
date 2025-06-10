#include "Inventory.h"

void Inventory::AddItem(Item* _item)
{
	currentItem = AddNode(_item);
	_item->SetInventory(this);
}

void Inventory::NextItem()
{
	if (currentItem == nullptr)
	{
		currentItem = head;
		return;
	}
	//todavia hay items en la lista
	if (currentItem->next != nullptr)
	{
		currentItem = currentItem->next;
	}
	else //ya llegamos a la cola, regresamos al head
	{
		currentItem = head;
	}
}
void Inventory::PreviusItem()
{
	if (currentItem == nullptr)
	{
		currentItem = head;
		return;
	}

	if (currentItem->previus != nullptr)
	{
		currentItem = currentItem->previus;
	}
	else
	{
		
		LLNode<Item>* iter = head;
		while (iter->next != nullptr)
			iter = iter->next;

		currentItem = iter;
	}
}

void Inventory::debugPrintContents()
{
	//iterar en la lista
	LLNode<Item>* iter = head;
	std::cout << "Items en inventario:" << std::endl;
	while (iter != nullptr)
	{
		std::cout << "\t" << iter->data->name << std::endl;

		iter = iter->next;
	}
}

void Inventory::ShowItem(float posX, float posY, float width, float height)
{
	DrawRectangle(posX, posY, width , height, BEIGE);
	DrawRectangleLines(posX, posY, width, height, RED);
	DrawText(currentItem->data->name.c_str(), posX + 10, posY + 10, 20, DARKGRAY);
}



