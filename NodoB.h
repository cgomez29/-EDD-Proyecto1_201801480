#ifndef NODOB_H
#define NODOB_H

#include "Objeto.h"

class NodoB
{
private:
	Objeto objeto;
	NodoB* left;
	NodoB* rigth;

public:
	NodoB(Objeto objeto);
	void setObjeto(Objeto objeto);
	void setLeft(NodoB* left);
	void setRigth(NodoB* rigth);
	NodoB* getLeft();
	NodoB* getRigth();
	Objeto getObjeto();
};

#endif // NODOB_H