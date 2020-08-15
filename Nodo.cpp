#include "Nodo.h"


Nodo::Nodo()
{
    this->next = nullptr;
    this->previous = nullptr;
    this->up = nullptr;
    this->down = nullptr;
}

void Nodo::setNext(Nodo* next) {
    this->next = next;
}
void Nodo::setUp(Nodo* up) {
    this->up = up;
}
void Nodo::setDown(Nodo* down)
{
    this->down = down;
}
void Nodo::setPrevious(Nodo* Previous)
{
    this->previous = previous;
}
Nodo* Nodo::getNext()
{
    return this->next;
}
Nodo* Nodo::getUp()
{
    return this->up;
}
Nodo* Nodo::getDown()
{
    return this->down;
}
Nodo* Nodo::getPrevious()
{
    return this->previous;
}