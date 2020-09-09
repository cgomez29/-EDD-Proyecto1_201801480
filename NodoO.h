#ifndef NODOO_H
#define NODOO_H
#include <string.h>
#include <iostream>
#include <stddef.h>
#include "Objeto.h"

using namespace std;
class NodoO
{
public:
    NodoO(Objeto* objeto);
    ~NodoO();
    Objeto* getObjeto();
    NodoO* getSiguiente();
    void setSiguiente(NodoO* sig);
private:
    Objeto* objeto;
    NodoO* siguiente;
};
#endif // NODOO_H
