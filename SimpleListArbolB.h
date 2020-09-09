#ifndef SIMPLELISTARBOLB_H
#define SIMPLELISTARBOLB_H
#include "NodoSLB.h"
#include "ArbolB.h"
#include <iostream>
using namespace std;

class SimpleListArbolB
{
private:
    NodoSLB* head;
    NodoSLB* tail;
    int tam;
public:
    SimpleListArbolB();
    ~SimpleListArbolB();
    int size();
    void add(ArbolB* arbolB);
    bool delete_item(int i);
    void imprimir();
    NodoSLB* getHead();
};

#endif // SIMPLELISTARBOLB_H
