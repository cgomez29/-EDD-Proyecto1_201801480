#ifndef SIMPLELISTM_H
#define SIMPLELISTM_H
#include "NodoM.h"
#include "Matrix.h"
#include <iostream>
using namespace std;

class SimpleListM
{
private:
    NodoM* head;
    NodoM* tail;
    int tam;
public:
    SimpleListM();
    ~SimpleListM();
    int size();
    void add(Matrix* matrix);
    bool delete_item(int i);
    void imprimir();
    NodoM* getHead();
};

#endif // SIMPLELISTP_H
