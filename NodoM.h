#ifndef NODOM_H
#define NODOM_H
#include <string.h>
#include <iostream>
#include <stddef.h>
#include "Matrix.h"

using namespace std;
class NodoM
{
public:
    NodoM(Matrix* matrix);
    ~NodoM();
    Matrix* getMatrix();
    NodoM* getSiguiente();
    void setSiguiente(NodoM* sig);
    void imprimir();
private:
    Matrix* matrix;
    NodoM* siguiente;
};
#endif // NODOM_H
