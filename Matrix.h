#pragma once
#include "Cabecera.h"
#include "Objeto.h"

using namespace std;

class Matrix
{
private:
	Cabecera* horizontal;
	Cabecera* vertical;
	Cabecera* crearHorizontal(string x);
	Cabecera* crearVertical(string y);
	Cabecera* getHorizontal(string x);
	Cabecera* getVertical(string y);
	Nodo* getUltimoV(Cabecera* cabecera, string y);
	Nodo* getUltimoH(Cabecera* cabecera, string x);
public:
	Matrix();
	~Matrix();
	void add(Objeto* obj);
	void graficar();
};

