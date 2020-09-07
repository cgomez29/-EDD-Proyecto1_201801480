#include "Project.h"


Project::Project()
{
	this->name = "";

}

Project::Project(string name, SimpleList<Matrix>* list)
{
	this->name = name;
	this->listNivel = list;
}

void Project::setName(string name)
{
	this->name = name;
}

SimpleList<Matrix>* Project::getListNivel()
{
	return this->listNivel;
}

void Project::setList(SimpleList<Matrix>* list)
{
	this->listNivel = list;
}


string Project::getName()
{
	return this->name;
}
