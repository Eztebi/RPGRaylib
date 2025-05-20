#pragma once
//aqui nada de raylib porque explota
#include <iostream>

typedef struct HINSTANCE__* HINSTANCE;
//Envoltura para usar las funciones de la dll de pruebas y evitar colisiones de nombres
class Funny
{
	typedef int(*SumarPtr)(int, int);
	typedef long(*FactorialPtr)(int);
public:
	Funny();
	~Funny();
	SumarPtr Sumar = sumaStub;
	FactorialPtr Factorial = factorialStub;

private:
	HINSTANCE hDLL;
	//void* hDLL;
	

	static int sumaStub(int a, int b) { return -1; };
	static long factorialStub(int n) { return -1; };

};

