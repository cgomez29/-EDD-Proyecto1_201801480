#include "SimpleListM.h"
SimpleListM::SimpleListM()
{
    this->head = NULL;
    this->tail = NULL;
    this->tam = 0;
}

void SimpleListM::add(Matrix* matrix) {
    NodoM* nuevo = new NodoM(matrix);
    if (head == NULL) {
        nuevo->getMatrix()->setId(1);
        this->head = nuevo;
        this->tail = nuevo;
        tam++;
    }
    else {
        tam++;
        nuevo->getMatrix()->setId(tam);
        this->tail->setSiguiente(nuevo);
        this->tail = nuevo;
    }
}

void SimpleListM::imprimir() {
    NodoM* aux = this->head;
    while (aux != NULL) {
        cout << "Nombre nivel: " << aux->getMatrix()->getName() << endl;
        aux = aux->getSiguiente();
    }
}

NodoM* SimpleListM::getHead()
{
    return this->head;
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

bool SimpleListM::delete_item(int i) {
    NodoM* aux = this->head;
    NodoM* ant = aux;
    while (aux != NULL) {
        if (aux->getMatrix()->getId() == i) {
            //this->tam--;
            ant->setSiguiente(aux->getSiguiente());
            if (aux == this->head) {
                this->head = aux->getSiguiente();
            }
            else if (aux == this->tail) {
                this->tail = ant;
            }
            delete aux;
            return true;
        }
        ant = aux;
        aux = aux->getSiguiente();
    }
    return false;
}





