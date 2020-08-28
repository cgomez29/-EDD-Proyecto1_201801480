#ifndef ARBOLAVL_H
#define ARBOLAVL_H

#include "NodoAVL.h"
#include <iostream>

using namespace std;

class ArbolAVL
{
private:
	NodoAVL* raiz;
public:
	ArbolAVL();
	~ArbolAVL();
	NodoAVL* getRaiz();
};

#endif // ARBOLAVL_H


