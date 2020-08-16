#include "SimpleList.h"

template<class T>
SimpleList<T>::SimpleList()
{
    this->head = nullptr;
    this->tail = nullptr;
}

template<class T>
SimpleList<T>::~SimpleList() {
    NodoSL<T>* aux = this->top;
    NodoSL<T>* tmp = nullptr;
    while (aux != nullptr) {
        tmp = aux->getSiguiente();
        delete aux;
        aux = tmp;
    }
}


template<class T>
void SimpleList<T>::add(T valor) {
       NodoSL<T>* nuevo = new NodoSL<T>(valor);
    if (this->head == nullptr) {
        this->head = nuevo;
        this->tail = nuevo;
    }
    else {
        tail->setSiguiente(nuevo);
        tail = nuevo;
    }
}


template<class T>
NodoSL<T>* SimpleList<T>::getHead() {
    return this->head;
}

template<class T>
void SimpleList<T>::vaciar() {
    NodoSL<T>* aux = this->head;
    NodoSL<T>* tmp;
    while (aux != nullptr) {
        tmp = aux->getSiguiente();
        delete aux;
        aux = tmp;
    }
}