#include "Objeto.h"

Objeto::Objeto()
{
	this->id = 0;
	this->name = "";
	this->letter = "";
	this->color = "";
	this->x = "";
	this->y = "";
}

Objeto::Objeto(string name)
{
	this->id = 0;
	this->name = name;
	this->letter = "";
	this->color = "";
	this->x = "";
	this->y = "";
	
}

void Objeto::insertPos(string x, string y)
{
	Point p = Point(x, y);
	this->list->add(p);
}

int Objeto::getId()
{
	return this->id;
}

string Objeto::getName()
{
	return this->name;
}

string Objeto::getLetter()
{
	return this->letter;
}

string Objeto::getColor()
{
	return this->color;
}

SimpleList<Point>* Objeto::getList()
{
	return this->list;
}

void Objeto::setId(int id)
{
	this->id = id;
}
void Objeto::setName(string name)
{
	this->name = name;
}
void Objeto::setLetter(string letter)
{
	this->letter = letter;
}
void Objeto::setColor(string color)
{
	this->color = color;
}

void Objeto::setX(string x) { this->x = x; }
string Objeto::getX() { return this->x; }
void Objeto::setY(string y) { this->y = y; }
string Objeto::getY() { return this->y; }

void Objeto::setSimpleList(SimpleList<Point>* list)
{
	this->list = list;
}