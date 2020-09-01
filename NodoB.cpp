#include "NodoB.h"

NodoB::NodoB(Objeto dato)
{
	this->objeto = dato;
	this->left = nullptr;
	this->rigth = nullptr;
}

void NodoB::setObjeto(Objeto dato)
{
	this->objeto = dato;
}

void NodoB::setLeft(NodoB* left)
{
	this->left = left;
}

void NodoB::setRigth(NodoB* rigth)
{
	this->rigth = rigth;
}

NodoB* NodoB::getLeft()
{
	return this->left;
}

NodoB* NodoB::getRigth()
{
	return this->rigth;
}

Objeto NodoB::getObjeto()
{
	return this->objeto;
}