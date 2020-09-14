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
    bool delete_item(string x, string y);
    void imprimir();
    NodoP* getHead();
};

#endif // SIMPLELISTP_H
