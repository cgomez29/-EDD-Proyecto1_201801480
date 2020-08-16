#include "Libreria.h"

Libreria::Libreria()
{
	this->id = 0;
	this->name = "";
	this->letter = "";
	this->color = "";
	this->list = NULL;
}

int Libreria::getId()
{
	return this->id;
}

string Libreria::getName()
{
	return this->name;
}

string Libreria::getLetter()
{
	return this->letter;
}

string Libreria::getColor()
{
	return this->color;
}

SimpleList<Point>* Libreria::getList()
{
	return this->list;
}

void Libreria::setId(int id)
{
	this->id = id;
}
void Libreria::setName(string name)
{
	this->name = name;
}
void Libreria::setLetter(string letter)
{
	this->letter = letter;
}
void Libreria::setColor(string color)
{
	this->color = color;
}
void Libreria::setSimpleList(SimpleList<Point>* list)
{
	this->list = list;
}