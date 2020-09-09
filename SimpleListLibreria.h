#ifndef SIMPLELISTLIBRERIA_H
#define SIMPLELISTLIBRERIA_H
#include "NodoO.h"
#include "Objeto.h"
#include <iostream>
using namespace std;

class SimpleListLibreria
{
private:
    NodoO* head;
    NodoO* tail;
public:
    SimpleListLibreria();
    ~SimpleListLibreria();
    void add(Objeto* objeto);
    NodoO* getHead();
};

#endif // SIMPLELISTLIBRERIA_H
//Lista simple para objetos