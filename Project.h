#ifndef PROJECT_H
#define PROJECT_H

#include "Matrix.h" 
#include <iostream>
#include "SimpleListM.h"

using namespace std;

class Project
{
private:
	int id;
	string name;
	SimpleListM* listNivel;

public:
	Project();
	Project(string name, SimpleListM* list);
	SimpleListM* getListNivel();
	int getId();
	string getName();
	void setName(string name);
	void setId(int id);
	void setList(SimpleListM* list);
};

#endif // PROJECT_H

