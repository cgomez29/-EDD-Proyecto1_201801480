#include "Matrix.h"

Matrix::Matrix()
{
	this->horizontal = nullptr;
	this->vertical = nullptr;
}

Matrix::~Matrix()
{
}

Cabecera* Matrix::crearHorizontal(string x)
{
	if (this->horizontal == nullptr)
	{
		Cabecera* nueva = new Cabecera(x);
		this->horizontal = nueva;
		return nueva;
	}
	else
	{
	}

}
Cabecera* Matrix::crearVertical(string y)
{

}

Cabecera* Matrix::getHorizontal(string x)
{
	return this->horizontal;

}

Cabecera* Matrix::getVertical(string y)
{
	return this->vertical;
}