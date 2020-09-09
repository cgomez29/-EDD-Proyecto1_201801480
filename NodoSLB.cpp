#include "NodoSLB.h"
NodoSLB::NodoSLB(ArbolB* arbolB)
{
    this->arbolB = arbolB;
}

ArbolB* NodoSLB::getArbolB() {
    return this->arbolB;
}

NodoSLB* NodoSLB::getSiguiente() {
    return this->siguiente;
}

void NodoSLB::setSiguiente(NodoSLB* sig) {
    this->siguiente = sig;
}

NodoSLB::~NodoSLB() {
    cout << "Nodo eliminado" << endl;
}
