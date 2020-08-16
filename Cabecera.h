#pragma once
#include "Nodo.h"
#include <iostream>
using namespace std;

class Cabecera:public Nodo
{
private:
	string nombre;
public:
	Cabecera(string nombre);
	void setNombre(string nombre);
	string getNombre();
};

