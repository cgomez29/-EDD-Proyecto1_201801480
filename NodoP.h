#ifndef NODOP_H
#define NODOP_H
#include <string.h>
#include <iostream>
#include <stddef.h>
#include "Point.h"

using namespace std;
class NodoP
{
public:
    NodoP(Point point);
    ~NodoP();
    Point getPoint();
    NodoP* getSiguiente();
    void setSiguiente(NodoP* sig);
    void imprimir();
private:
    Point point;
    NodoP* siguiente;
};
#endif // NODOP_H
