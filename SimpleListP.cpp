#include "SimpleListP.h"
SimpleListP::SimpleListP()
{
    this->head = NULL;
    this->tail = NULL;
    this->tam = 0;
}

void SimpleListP::add(Point point) {
    NodoP* nuevo = new NodoP(point);
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

void SimpleListP::imprimir() {
    NodoP* aux = this->head;
    while (aux != NULL) {
        cout << "X: " << aux->getPoint().getX() << " Y: " << aux->getPoint().getY() << endl;
        aux = aux->getSiguiente();
    }
}

int SimpleListP::size() {
    return this->tam;
}


SimpleListP::~SimpleListP() {
    NodoP* aux = this->head;
    NodoP* temporal;
    while (aux != NULL) {
        temporal = aux->getSiguiente();
        delete aux;
        aux = temporal;
    }
}

void SimpleListP::delete_item(int i) {
    NodoP* aux = this->head;
    NodoP* ant = aux;
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





