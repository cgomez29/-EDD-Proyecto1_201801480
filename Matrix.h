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
	void add(Objeto* obj, string x, string y);
	string name;
public:
	Matrix();
	~Matrix();
	void add(Objeto* obj);
	void graficar();
	void setName(string name);
	string getName();
};

#endif //MATRIX_H