#ifndef NODOPROJECT_H
#define NODOPROJECT_H
#include <string.h>
#include <iostream>
#include <stddef.h>
#include "Project.h"

using namespace std;
class NodoProject
{
public:
    NodoProject(Project* project);
    ~NodoProject();
    Project* getProject();
    NodoProject* getSiguiente();
    void setSiguiente(NodoProject* sig);
private:
    Project* project;
    NodoProject* siguiente;
};
#endif // NODOPROJECT_H
