#ifndef PROJECT_H
#define PROJECT_H

#include "Matrix.h" 
#include "NosoSL.h"
#include "SimpleList.h"
#include <iostream>

using namespace std;

class Project
{
private:
	string name;
	SimpleList<Matrix>* listNivel;

public:
	Project();
	Project(string name, SimpleList<Matrix>* list);
	SimpleList<Matrix>* getListNivel();
	string getName();
	void setName(string name);

	void setList(SimpleList<Matrix>* list);
};

#endif // PROJECT_H

