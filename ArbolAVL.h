#ifndef ARBOLAVL_H
#define ARBOLAVL_H

#include "NodoAVL.h"
#include "Project.h"
#include <iostream>
#include <ostream>
#include <sstream>
#include <fstream>
#include <stdbool.h>
#include "NodoM.h"
#include "SimpleListProject.h"

using namespace std;

class ArbolAVL
{
private:
	Project* project;
	NodoAVL* raiz;
	NodoAVL* insertar(NodoAVL* raiz, Project* project, bool& scape);
	NodoAVL* rotacionII(NodoAVL* n, NodoAVL* n1);
	NodoAVL* rotacionDD(NodoAVL* n, NodoAVL* n1);
	NodoAVL* rotacionID(NodoAVL* n, NodoAVL* n1);
	NodoAVL* rotacionDI(NodoAVL* n, NodoAVL* n1);
	void Delete(NodoAVL* raiz);
	void graficar(stringstream* cadena, NodoAVL* padre, NodoAVL* actual, bool left);
	int valorAscii(string cadena);
	void inOrden(NodoAVL* nodo);
	NodoAVL* buscarNodo(NodoAVL* root, int nombre);
	SimpleListProject* llenarLista(NodoAVL* root, SimpleListProject* list);
public:
	ArbolAVL();
	~ArbolAVL();
	void insertar(Project* project);
	NodoAVL* getRaiz();
	void graficar();
	void inOrden();
	NodoAVL* buscarNodo(string nombre);
	SimpleListProject* getListProyectos();
};

#endif // ARBOLAVL_H


