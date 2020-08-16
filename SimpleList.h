#include "NodoSL.h"
#include "NodoSL.cpp"
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
