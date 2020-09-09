#ifndef PROJECT_H
#define PROJECT_H

#include "Matrix.h" 
#include <iostream>
#include "SimpleListM.h"

using namespace std;

class Project
{
private:
	string name;
	SimpleListM* listNivel;

public:
	Project();
	Project(string name, SimpleListM* list);
	SimpleListM* getListNivel();
	string getName();
	void setName(string name);

	void setList(SimpleListM* list);
};

#endif // PROJECT_H

