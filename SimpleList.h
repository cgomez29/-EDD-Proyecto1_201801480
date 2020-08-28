#ifndef SIMPLELIST_H
#define SIMPLELIST_H

#include "NosoSL.h"

#include <iostream>
using namespace std;
template<class T>
class SimpleList
{
private:
    NodoSL<T>* head;
    NodoSL<T>* tail;
public:
    SimpleList();
    ~SimpleList();
    void add(T valor);
    //void delete_nodo(T valor);
    NodoSL<T>* getHead();
    void vaciar();
};

#endif //SIMPLELIST_H

