#include "NodoO.h"
NodoO::NodoO(Objeto* objeto)
{
    this->objeto = objeto;
}

Objeto* NodoO::getObjeto() {
    return this->objeto;
}

NodoO* NodoO::getSiguiente() {
    return this->siguiente;
}

void NodoO::setSiguiente(NodoO* sig) {
    this->siguiente = sig;
}

NodoO::~NodoO() {
    cout << "Nodo eliminado" << endl;
}
