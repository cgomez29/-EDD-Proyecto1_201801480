#include "NodoProject.h"
NodoProject::NodoProject(Project* project)
{
    this->project = project;
}

Project* NodoProject::getProject() {
    return this->project;
}

NodoProject* NodoProject::getSiguiente() {
    return this->siguiente;
}

void NodoProject::setSiguiente(NodoProject* sig) {
    this->siguiente = sig;
}

NodoProject::~NodoProject() {
    cout << "Nodo eliminado" << endl;
}
