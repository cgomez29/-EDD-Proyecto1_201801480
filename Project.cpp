#include "Project.h"


Project::Project()
{
	this->name = "";

}

Project::Project(string name, SimpleListM* list)
{
	this->id = 0;
	this->name = name;
	this->listNivel = list;
}

void Project::setName(string name)
{
	this->name = name;
}

SimpleListM* Project::getListNivel()
{
	return this->listNivel;
}

void Project::setList(SimpleListM* list)
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
