#ifndef OBJETO_H
#define OBJETO_H

#include "Nodo.h"
#include "Point.h"
#include "SimpleListP.h"
#include <iostream>

using namespace std;

class Objeto :public Nodo
{
private:
	int id;
	string name;
	string letter;
	string color;
	string x;
	string y;
	SimpleListP* list;

public:
	Objeto();
	Objeto(int id, string nombre, string letter, string color, SimpleListP* list);
	Objeto(int id, string nombre, string letter, string color, string x, string y);
	Objeto(string name);
	int getId();
	string getName();
	string getLetter();
	string getColor();
	SimpleListP* getList();
	void setId(int id);
	void setName(string name);
	void setLetter(string letter);
	void setColor(string color);
	void insertPos(string x, string y);
	void setSimpleList(SimpleListP* list);

	void setX(string x);
	string getX();
	void setY(string y);
	string getY();
};

#endif // OBJETO_H