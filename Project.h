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
	SimpleList<Matrix>* listNivel = new SimpleList<Matrix>();

public:
	Project();
	void setName(string name);
	void addNivel(Matrix nivel);
	SimpleList<Matrix>* getListNivel();
	string getName();
};

#endif // PROJECT_H

