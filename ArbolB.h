#ifndef ARBOLB_H
#define ARBOLB_H

#include "NodoB.h"
#include <iostream>
#include "Objeto.h"
#include "Point.h"
#include "SimpleList.h"
#include <ostream>
#include <sstream>
#include <fstream>

using namespace std;

class ArbolB
{
private:
	NodoB* raiz;
	NodoB* insert(NodoB* raiz, Objeto objeto);
	NodoB* delete_nodo(NodoB* raiz, Objeto objeto);
	Objeto findNodo(NodoB* raiz);
	void Delete(NodoB* raiz);
	void graficar(stringstream* cadena, NodoB* padre, NodoB* actual, bool left);
	NodoB* getRaiz();
public:
	ArbolB();
	~ArbolB();
	void insert(int id, string name, string letter, string color, SimpleList<Point>* list);
	void delete_nodo(Objeto objeto);
	void Delete();
	void graficar();
};
#endif // ARBOLB_H