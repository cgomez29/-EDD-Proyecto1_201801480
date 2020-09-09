#ifndef SIMPLELISTP_H
#define SIMPLELISTP_H
#include "NodoP.h"
#include "Point.h"
#include <iostream>
using namespace std;

class SimpleListP
{
private:
    NodoP* head;
    NodoP* tail;
    int tam;
public:
    SimpleListP();
    ~SimpleListP();
    int size();
    void add(Point point);
    void delete_item(int i);
    void imprimir();
};

#endif // SIMPLELISTP_H
