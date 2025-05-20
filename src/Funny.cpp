#include "Funny.h"

#include "Windows.h"



Funny::Funny()
{
	hDLL = LoadLibrary(L"ExemploDLL.dll");
	if (hDLL != NULL)
	{
		Sumar = (SumarPtr)GetProcAddress(hDLL, "Sumar");
		if (!Sumar)
		{
			//Sumar = &Funny::sumaStub;
		}
		Factorial = (FactorialPtr)GetProcAddress(hDLL, "Factorial");
		if (!Factorial)
		{
			//Factorial = &Funny::factorialStub;
		}
	}
	else
	{
		//Sumar = &Funny::sumaStub;
		//Factorial = &Funny::factorialStub;
		std::cout << "Error al cargar la dll" << std::endl;
	}
}

Funny::~Funny()
{
	FreeLibrary(hDLL);
}

