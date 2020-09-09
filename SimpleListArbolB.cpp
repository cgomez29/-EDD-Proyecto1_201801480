#include "SimpleListArbolB.h"
SimpleListArbolB::SimpleListArbolB()
{
    this->head = NULL;
    this->tail = NULL;
    this->tam = 0;
}

void SimpleListArbolB::add(ArbolB* arbolB) {
    NodoSLB* nuevo = new NodoSLB(arbolB);
    if (head == NULL) {
        nuevo->getArbolB()->setId(1);
        this->head = nuevo;
        this->tail = nuevo;
        tam++;
    }
    else {
        tam++;
        nuevo->getArbolB()->setId(tam);
        this->tail->setSiguiente(nuevo);
        this->tail = nuevo;
    }
}

void SimpleListArbolB::imprimir() {
    NodoSLB* aux = this->head;
    while (aux != NULL) {
        cout << "Nombre nivel: " << aux->getArbolB()->getNombre() << endl;
        aux = aux->getSiguiente();
    }
}

NodoSLB* SimpleListArbolB::getHead()
{
    return this->head;
}

int SimpleListArbolB::size() {
    return this->tam;
}


SimpleListArbolB::~SimpleListArbolB() {
    NodoSLB* aux = this->head;
    NodoSLB* temporal;
    while (aux != NULL) {
        temporal = aux->getSiguiente();
        delete aux;
        aux = temporal;
    }
}

bool SimpleListArbolB::delete_item(int i) {
    NodoSLB* aux = this->head;
    NodoSLB* ant = aux;
    while (aux != NULL) {
        if (aux->getArbolB()->getId() == i) {
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



