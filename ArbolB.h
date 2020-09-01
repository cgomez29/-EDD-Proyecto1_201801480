#ifndef ARBOLB_H
#define ARBOLB_H

#include "NodoB.h"
#include <iostream>
#include "Objeto.h"


using namespace std;

class ArbolB
{
private:
	NodoB* raiz;
	NodoB* insert(NodoB* raiz, Objeto objeto);
	NodoB* delete_nodo(NodoB* raiz, Objeto objeto);
	Objeto findNodo(NodoB* raiz);
	void Delete(NodoB* raiz);

public:
	ArbolB();
	~ArbolB();
	void insert(Objeto objeto);
	void delete_nodo(Objeto objeto);
	void Delete();

};
#endif // ARBOLB_H