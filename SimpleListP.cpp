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

NodoP* SimpleListP::getHead()
{
	return this->head;
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

bool SimpleListP::delete_item(string x, string y) {
    NodoP* aux = this->head;
    NodoP* ant = aux;
    while (aux != NULL) {
        if (aux->getPoint().getX() == x && aux->getPoint().getY() == y) {
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





