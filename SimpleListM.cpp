#include "SimpleListM.h"
SimpleListM::SimpleListM()
{
    this->head = NULL;
    this->tam = 0;
}

void SimpleListM::add(Matrix* matrix) {
    NodoM* nuevo = new NodoM(matrix);
    if (head == NULL) {
        this->head = nuevo;
        this->tail = nuevo;
        tam++;
    }
    else {
        this->tail->setSiguiente(nuevo);
        this->tail = nuevo;
        tam++;
    }
}

void SimpleListM::imprimir() {
    NodoM* aux = this->head;
    while (aux != NULL) {
        cout << "Nombre nivel: " << aux->getMatrix()->getName() << endl;
        aux = aux->getSiguiente();
    }
}

int SimpleListM::size() {
    return this->tam;
}


SimpleListM::~SimpleListM() {
    NodoM* aux = this->head;
    NodoM* temporal;
    while (aux != NULL) {
        temporal = aux->getSiguiente();
        delete aux;
        aux = temporal;
    }
}

void SimpleListM::delete_item(int i) {
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
}





