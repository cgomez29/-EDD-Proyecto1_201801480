#ifndef PROJECT_H
#define PROJECT_H

#include <iostream>
#include "Matrix.h"

using namespace std;

class Project
{
private:
	string name;
	//SimpleList<Matrix> listNivel;

public:
	void setName(string name);
	void addNivel(Matrix nivel);
	string getName();
};

#endif // PROJECT_H

