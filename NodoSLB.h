//Nodo para lista simple de arboles binarios
#ifndef NODOSLB_H
#define NODOSLB_H
#include <string.h>
#include <iostream>
#include <stddef.h>
#include "ArbolB.h"

using namespace std;
class NodoSLB
{
public:
    NodoSLB(ArbolB* arbolB);
    ~NodoSLB();
    ArbolB* getArbolB();
    NodoSLB* getSiguiente();
    void setSiguiente(NodoSLB* sig);
    void imprimir();
private:
    ArbolB* arbolB;
    NodoSLB* siguiente;
};
#endif // NODOSLB_H
