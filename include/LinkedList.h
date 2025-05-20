#pragma once
#include <iostream>
#include "LLNode.h"

template <class T>
class LinkedList
{

protected:
	LLNode<T> *head;


public:
	//lista vacia
	LinkedList() :head(nullptr){}
	LinkedList(LLNode<T> *_hd) : head(_hd) {};

	//imprimir el contenido 
	//void PrintElements();

	//agrega elemento al final de la lista ligada
	LLNode<T>* AddNode(T* _data)
	{
		
			if (head == nullptr)
			{
				head = new LLNode<T>(_data);
				return head;
			}

			LLNode<T>* iter = head;
			while (iter->next != nullptr)
				iter = iter->next;

			LLNode<T>* newNode = new LLNode<T>(_data);
			iter->next = newNode;
			newNode->previus = iter;

			return newNode;
		
	}

	//remover el ultimo nodo
	void RemoveLastNode()
	{
		if (head == nullptr)
			return;
		//si solo hay un nodo
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			return;
		}
		//iterar hasta el penultimo
		LLNode<T>* iter = head;
		while (iter->next->next != nullptr)
			iter = iter->next;
		delete iter->next;
		iter->next = nullptr;
	}


};

