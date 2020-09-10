#ifndef ARBOLB_H
#define ARBOLB_H

#include "NodoB.h"
#include <iostream>
#include "Objeto.h"
#include "Point.h"
#include "SimpleListP.h"
#include <ostream>
#include <sstream>
#include <fstream>
#include "SimpleListLibreria.h"

using namespace std;

class ArbolB
{
private:
	NodoB* raiz;
	string nombre;
	int id;
	NodoB* insert(NodoB* raiz, Objeto* objeto);
	NodoB* delete_nodo(NodoB* raiz, int id);
	Objeto* findNodo(NodoB* raiz);
	void Delete(NodoB* raiz);
	void graficar(stringstream* cadena, NodoB* padre, NodoB* actual, bool left);
	NodoB* getRaiz();
	NodoB* buscarNodo(NodoB* root, int id);
	void inOrden(NodoB* nodo);
	SimpleListLibreria* llenarLista(NodoB* root, SimpleListLibreria* list);

public:
	ArbolB();
	~ArbolB();
	void insert(int id, string name, string letter, string color, SimpleListP* list);
	void insert(Objeto* objeto);
	void delete_nodo(int id);
	void Delete();
	void graficar();
	int getId();
	void setId(int id);
	NodoB* buscarNodo(int id);
	string getNombre();
	void setNombre(string nombre);
	void inOrden();
	SimpleListLibreria* getListObjetos();

};
#endif // ARBOLB_H