#pragma once

template <class T>
class LLNode
{
public:
	//ref al siguiente nodo de la lista
	LLNode<T> *next;
	LLNode<T> *previus;
	//dato contenido
	T* data;

	//dos constructores 
	//recordar el polymorfismo de OOP
	LLNode(T* _data) : data(_data), next(nullptr), previus(nullptr) {}
	LLNode(T* d, LLNode<T>* nxt,LLNode <T>* prev) : data(d), next(nxt), previus(prev) {}
};

