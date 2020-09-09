#ifndef SIMPLELISTPROJECT_H
#define SIMPLELISTPROJECT_H
#include "NodoProject.h"
#include "Project.h"
#include <iostream>
using namespace std;

class SimpleListProject
{
private:
    NodoProject* head;
    NodoProject* tail;
public:
    SimpleListProject();
    ~SimpleListProject();
    void add(Project* project);
    NodoProject* getHead();
};

#endif // SIMPLELISTPROJECT_H
//Lista simple para proyectos