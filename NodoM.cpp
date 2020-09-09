#include "NodoM.h"

NodoM::NodoM(Matrix* matrix)
{
    this->matrix = matrix;
}

Matrix* NodoM::getMatrix() {
    return this->matrix;
}

NodoM* NodoM::getSiguiente() {
    return this->siguiente;
}

void NodoM::setSiguiente(NodoM* sig) {
    this->siguiente = sig;
}

NodoM::~NodoM() {
    cout << "Nodo eliminado" << endl;
}
