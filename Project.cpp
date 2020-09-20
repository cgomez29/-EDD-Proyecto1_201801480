#include "Project.h"


Project::Project()
{
	this->name = "";

}

Project::Project(string name, SimpleListArbolB* list)
{
	this->id = 0;
	this->name = name;
	this->listNivel = list;
}

void Project::setName(string name)
{
	this->name = name;
}

SimpleListArbolB* Project::getListNivel()
{
	return this->listNivel;
}

void Project::setList(SimpleListArbolB* list)
{
	this->listNivel = list;
}

string Project::getName()
{
	return this->name;
}

int Project::getId()
{
	return this->id;
}

void Project::setId(int id)
{
	this->id = id;
}

int Project::getCantNivel()
{
	return this->cantNiveles;
}

void Project::setCantNivel(int cant)
{
	this->cantNiveles = cant;
}