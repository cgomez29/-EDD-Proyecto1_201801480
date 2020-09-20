#ifndef PROJECT_H
#define PROJECT_H

#include "Matrix.h" 
#include <iostream>
#include "SimpleListArbolB.h"
#include "ArbolB.h"

using namespace std;

class Project
{
private:
	int id;
	string name;
	SimpleListArbolB* listNivel;
	int cantNiveles;

public:
	Project();
	Project(string name, SimpleListArbolB* list);
	SimpleListArbolB* getListNivel();
	int getId();
	string getName();
	void setName(string name);
	void setId(int id);
	void setList(SimpleListArbolB* list);
	int getCantNivel();
	void setCantNivel(int cant);
};

#endif // PROJECT_H

