#ifndef MATRIX_H
#define MATRIX_H

#include "Nodo.h"
#include "Cabecera.h"
#include "Objeto.h"
#include <ostream>
#include <sstream>
#include <fstream>

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
	void add(Objeto* obj, string x, string y);
	void graficar();
};

#endif //MATRIX_H