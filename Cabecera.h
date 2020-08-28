#ifndef CABECERA_H
#define CABECERA_H

#include "Nodo.h"
#include <iostream>
using namespace std;

class Cabecera:public Nodo
{
private:
	string nombre;
	/*string x;
	string y;*/
public:
	Cabecera(string nombre);
	void setNombre(string nombre);
	string getNombre();
	/*void setX(string x);
	string getX();
	void setY(string y);
	string getY();*/
};

#endif //CABECERA_H