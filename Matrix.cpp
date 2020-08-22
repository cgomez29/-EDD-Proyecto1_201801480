#include "Matrix.h"

Matrix::Matrix()
{
	this->horizontal = nullptr;
	this->vertical = nullptr;
}

Matrix::~Matrix()
{
	Nodo* aux, * aux2, * tmp, * tmp2, *extra, *extra2;
	aux = this->vertical;
	tmp = this->horizontal;
	while (aux != nullptr)
	{
		extra = aux->getDown();
		aux2 = aux->getNext();
		while (aux2 != nullptr)
		{
			extra2 = aux2->getNext();
			delete aux;
		} 
		delete aux;
		aux = extra;
	}

	while (tmp != nullptr)
	{
		tmp2 = tmp->getNext();
		delete tmp;
		tmp = tmp2;
	}
};

Cabecera* Matrix::crearHorizontal(string x)
{
	if (this->horizontal == nullptr)
	{
		Cabecera* nueva = new Cabecera(x);
		this->horizontal = nueva;
		return nueva;
	}

	Cabecera* aux = this->horizontal;
	if (x.compare(aux->getNombre()) < 0)
	{
		Cabecera* nueva = new Cabecera(x);
		nueva->setNext(aux);
		this->horizontal->setPrevious(nueva);
		this->horizontal = nueva;
		return nueva;
	}
	while (aux->getNext() != nullptr)
	{
		if (x.compare(aux->getNombre()) > 0 && x.compare(((Cabecera*)aux->getNext())->getNombre()) <=0)
		{
			Cabecera* nuevo = new Cabecera(x);
			Cabecera* tmp = (Cabecera*)aux->getNext();
			tmp->setPrevious(nuevo);
			nuevo->setNext(tmp);
			aux->setNext(nuevo);
			nuevo->setPrevious(aux);
			return nuevo;
		}
		aux = (Cabecera*)aux->getNext();
	}

	Cabecera* nuevo = new Cabecera(x);
	aux->setNext(nuevo);
	nuevo->setPrevious(aux);
	return nuevo;
}

Cabecera* Matrix::crearVertical(string y)
{
	if (this->vertical == nullptr)
	{
		Cabecera* nueva = new Cabecera(y);
		this->vertical = nueva;
		return nueva;
	}

	Cabecera* aux = this->vertical;
	if (y.compare(aux->getNombre()) < 0)
	{
		Cabecera* nueva = new Cabecera(y);
		nueva->setDown(aux);
		this->vertical->setUp(nueva);
		this->vertical = nueva;
		return nueva;
	}
	while (aux->getDown() != nullptr)
	{
		if (y.compare(aux->getNombre()) > 0 && y.compare(((Cabecera*)aux->getDown())->getNombre()) <= 0)
		{
			Cabecera* nuevo = new Cabecera(y);
			Cabecera* tmp = (Cabecera*)aux->getDown();
			tmp->setUp(nuevo);
			nuevo->setDown(tmp);
			aux->setDown(nuevo);
			nuevo->setUp(aux);
			return nuevo;
		}
		aux = (Cabecera*)aux->getDown();
	}

	Cabecera* nuevo = new Cabecera(y);
	aux->setDown(nuevo);
	nuevo->setUp(aux);
	return nuevo;
}

Nodo* getUltimoH(Cabecera* cabecera, string x)
{
	if (cabecera->getNext() == nullptr)
	{
		return cabecera;
	}
	Nodo* aux = cabecera->getNext();
	while (aux->getNext() != nullptr)
	{
		if (x.compare(((Objeto*)aux)->getName()) <= 0)
		{
			return aux;
		}
		aux = aux->getNext();
	}
	if (x.compare(((Objeto*)aux)->getName()) <= 0)
	{
		return aux->getPrevious();
	}
	return aux;
}

Nodo* getUltimoV(Cabecera* cabecera, string y)
{
	if (cabecera->getDown() == nullptr)
	{
		return cabecera;
	}
	Nodo* aux = cabecera->getDown();
	while (aux->getDown() != nullptr)
	{
		if (y.compare(((Objeto*)aux)->getName()) <= 0)
		{
			return aux;
		}
		aux = aux->getDown();
	}
	if (y.compare(((Objeto*)aux)->getName()) <= 0)
	{
		return aux->getUp();
	}
	return aux;
}


Cabecera* Matrix::getHorizontal(string x)
{
	if (this->horizontal == nullptr)
	{
		return nullptr;
	}
	Cabecera* aux = this->horizontal;
	while (aux != nullptr)
	{
		if (((string)aux->getNombre()).compare(y) == 0)
		{
			return aux;
		}
		aux = (Cabecera*)aux->getNext();
	}
	return nullptr;

}

Cabecera* Matrix::getVertical(string y)
{
	if (this->vertical == nullptr)
	{
		return nullptr;
	}
	Cabecera* aux = this->vertical;
	while (aux != nullptr)
	{
		if (((string)aux->getNombre()).compare(y) == 0)
		{
			return aux;
		}
		aux =(Cabecera*)aux->getDown();
	}
	return nullptr;
}

void Matrix::add(Objeto* obj)
{

	
}
