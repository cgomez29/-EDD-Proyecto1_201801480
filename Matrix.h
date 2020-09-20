#ifndef MATRIX_H
#define MATRIX_H

#include "Nodo.h"
#include "Cabecera.h"
#include "Objeto.h"
#include "Point.h"
#include <ostream>
#include <sstream>
#include <fstream>

using namespace std;

class Matrix
{
private:
	string name;
	int id;
	SimpleListP* listTemp = new SimpleListP();
	Cabecera* horizontal;
	Cabecera* vertical;
	Cabecera* crearHorizontal(string x);
	Cabecera* crearVertical(string y);
	Cabecera* getHorizontal(string x);
	Cabecera* getVertical(string y);
	Nodo* getUltimoV(Cabecera* cabecera, string y);
	Nodo* getUltimoH(Cabecera* cabecera, string x);
	void add(Objeto* obj, string x, string y);
	void setPointEmpty();
	bool existePosicion(string x, string y);
	int coutEspacio;

public:
	Matrix();
	~Matrix();
	void add(int id, string nombre, string letter, string color, string x, string y);
	void graficar();
	void setName(string name);
	string getName();
	void setId(int id);
	int getId();
	void setCoutEspacio(int id);
	int getCoutEspacio();
};

#endif //MATRIX_H