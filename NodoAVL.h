#ifndef NODOAVL_H
#define NODOAVL_H

#include "Project.h"
class NodoAVL
{
private:
	Project* project;
	NodoAVL* left;
	NodoAVL* rigth;
	int factorE;

public:
	NodoAVL(Project* project);
	void setLeft(NodoAVL* left);
	NodoAVL* getLeft();
	void setRigth(NodoAVL* rigth);
	NodoAVL* getRigth();
	void setFactor(int factor);
	int getFactor();
	void setProject(Project* project);
	Project* getProject();
};

#endif // NODOAVL_H
