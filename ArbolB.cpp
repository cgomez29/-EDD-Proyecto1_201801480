#include "ArbolB.h"

ArbolB::ArbolB()
{
	this->raiz = nullptr;
}

ArbolB::~ArbolB()
{
	Delete(this->raiz);
}

void ArbolB::Delete()
{
	Delete(this->raiz);
}

void ArbolB::Delete(NodoB* raiz)
{
	if (this->raiz) { return; }
	Delete(raiz->getLeft());
	Delete(raiz->getRigth());
	delete this->raiz;
}

void ArbolB::insert(Objeto objeto)
{
	this->raiz = insert(this->raiz, objeto);
}


NodoB* ArbolB::insert(NodoB* raiz, Objeto dato)
{
	if (raiz == nullptr)
	{
		raiz = new NodoB(dato);
	}
	else
	{
		if (dato.getId() < raiz->getObjeto().getId())
		{
			NodoB* izq = insert(raiz->getLeft(), dato);
			raiz->setLeft(izq);
		}
		else if (dato.getId() > raiz->getObjeto().getId())
		{
			NodoB* der = insert(raiz->getRigth(), dato);
			raiz->setRigth(der);
		}
	}

	return raiz;
}

void ArbolB::delete_nodo(Objeto valor)
{
	this->raiz = delete_nodo(this->raiz, valor);
}

NodoB* ArbolB::delete_nodo(NodoB* raiz, Objeto valor)
{
	if (raiz == nullptr)
	{
		return nullptr;
	}
	if (valor.getId() == raiz->getObjeto().getId())
	{
		//cuando no tiene ningun hijo
		if (raiz->getLeft() == nullptr && raiz->getRigth() == nullptr)
		{
			return nullptr;
		}
		//cuando tiene un solo hijo
		if (raiz->getRigth() == nullptr)
		{
			return raiz->getLeft();
		}
		if (raiz->getLeft() == nullptr)
		{
			return raiz->getRigth();
		}
		//cuando tiene dos hijos
		Objeto smallValue = findNodo(raiz->getRigth());
		raiz->setObjeto(smallValue);
		raiz->setRigth(delete_nodo(raiz->getRigth(), smallValue));
		return raiz;
	}

	if (valor.getId() < raiz->getObjeto().getId())
	{
		raiz->setLeft(delete_nodo(raiz->getLeft(), valor));
		return raiz;
	}
	raiz->setRigth(delete_nodo(raiz->getRigth(), valor));
	return raiz;
}

Objeto ArbolB::findNodo(NodoB* raiz)
{
	// buscando el valor mas pequeño
	if (raiz->getLeft() == nullptr)
	{
		return raiz->getObjeto();
	}
	else
	{
		return findNodo(raiz->getLeft());
	}
}

