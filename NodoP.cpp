#include "NodoP.h"
NodoP::NodoP(Point point)
{
    this->point = point;
}

Point NodoP::getPoint() {
    return this->point;
}

NodoP* NodoP::getSiguiente() {
    return this->siguiente;
}

void NodoP::setSiguiente(NodoP* sig) {
    this->siguiente = sig;
}

NodoP::~NodoP() {
    cout << "Nodo eliminado" << endl;
}
