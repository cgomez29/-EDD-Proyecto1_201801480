#include "SimpleList.h"

template<class T>
SimpleList<T>::SimpleList()
{
    this->head = nullptr;
    this->tail = nullptr;
}

template<class T>
SimpleList<T>::~SimpleList() {
    NodoSL<T>* aux = this->head;
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
/*
template<class T>
void SimpleList<T>::remove(T val) {
    if (head == 0){
        //std::cout << "List is empty.\n";
    }
    else 
    {
        NodoSL<T> cur = this.head;
        NodoSL<T> tmp = this.head;

        while (cur->getValue() != val) {
            tmp = cur;
            cur = cur->getSiguiente();
        }
        if (cur == 0) 
        {
            //std::cout << "Item doesn't exist.\n";
        }
        else if (cur == head) {
            head = head->getSiguiente();
            delete cur;
            //std::cout << "Head was deleted.\n";
        }
        else {
            tmp->setSiguiente(cur->getSiguiente());
            delete cur;
            //std::cout << "Selected item was deleted.\n";
        }
    }
}*/


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
