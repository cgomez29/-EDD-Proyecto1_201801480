#include "SimpleListLibreria.h"

SimpleListLibreria::SimpleListLibreria()
{
    this->head = NULL;
    this->tail = NULL;
}

void SimpleListLibreria::add(Objeto* objeto) {
    NodoO* nuevo = new NodoO(objeto);
    if (head == NULL) {
        this->head = nuevo;
        this->tail = nuevo;
    }
    else {
        this->tail->setSiguiente(nuevo);
        this->tail = nuevo;
    }
}



SimpleListLibreria::~SimpleListLibreria() {
    NodoO* aux = this->head;
    NodoO* temporal;
    while (aux != NULL) {
        temporal = aux->getSiguiente();
        delete aux;
        aux = temporal;
    }
}

NodoO* SimpleListLibreria::getHead()
{
    return this->head;
}

/*void SimpleListM::delete_item(int i) {
    NodoM* aux = this->head;
    NodoM* ant = aux;
    if (i < 0) { return; }
    while (aux != NULL) {
        if (i == 0) {
            this->tam--;
            ant->setSiguiente(aux->getSiguiente());
            if (aux == this->head) {
                this->head = aux->getSiguiente();
            }
            else if (aux == this->tail) {
                this->tail = ant;
            }
            delete aux;
            return;
        }
        i--;
        ant = aux;
        aux = aux->getSiguiente();
    }
}*/