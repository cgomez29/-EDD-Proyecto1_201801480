#include "Cabecera.h"

Cabecera::Cabecera(string nombre)
{
	this->nombre = nombre;
}

void Cabecera::setNombre(string nombre)
{
	this->nombre = nombre;
}

string Cabecera::getNombre()
{
	return this->nombre;
}