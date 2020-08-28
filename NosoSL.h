#ifndef NODOSL_H
#define NODOSL_H

#include <iostream>
using namespace std;

template<class T>
class NodoSL
{
private:
    T valor;
    NodoSL* siguiente;

public:
    NodoSL(T valor);
    void setValue(T valor);
    T getValue();
    void setSiguiente(NodoSL* siguiente);
    NodoSL* getSiguiente();

};

#endif //NONOSL_H
