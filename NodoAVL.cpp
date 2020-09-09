#include "NodoAVL.h"

NodoAVL::NodoAVL(Project* project)
{
	this->project = project;
	this->left = nullptr;
	this->rigth = nullptr;
	this->factorE = 0;
}

void NodoAVL::setLeft(NodoAVL* left)
{
	this->left = left;
}

NodoAVL* NodoAVL::getLeft()
{
	return this->left;
}

void NodoAVL::setRigth(NodoAVL* rigth)
{
	this->rigth = rigth;
}

NodoAVL* NodoAVL::getRigth()
{
	return this->rigth;
}

void NodoAVL::setFactor(int factor)
{
	this->factorE = factor;
}

int NodoAVL::getFactor()
{
	return this->factorE;
}

void NodoAVL::setProject(Project* project)
{
	this->project = project;
}

Project* NodoAVL::getProject()
{
	return this->project;
}

