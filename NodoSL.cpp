#include "NodoSL.h"

template<class T>
NodoSL<T>::NodoSL(T valor) {
    this->valor = valor;
    this->siguiente = nullptr;
}

template<class T>
T NodoSL<T>::getValue() {
    return this->valor;
}


template<class T>
void NodoSL<T>::setValue(T valor) {
    this->valor = valor;
}

template <class T>
void NodoSL<T>::setSiguiente(NodoSL* siguiente) {
    this->siguiente = siguiente;
}

template<class T>
NodoSL<T>* NodoSL<T>::getSiguiente() {
    return  this->siguiente;
}