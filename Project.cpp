#include "Project.h"

void Project::setName(string name)
{
	this->name = name;
}

void Project::addNivel(Matrix nivel)
{
	this->listNivel->add(nivel);
}

SimpleList<Matrix>* Project::getListNivel()
{
	return this->listNivel;
}


string Project::getName()
{
	return this->name;
}
