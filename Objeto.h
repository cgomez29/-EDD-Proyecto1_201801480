#ifndef OBJETO_H
#define OBJETO_H

#include "Nodo.h"
#include "Point.h"
#include "NosoSL.h"
#include "NosoSL.cpp"
#include "SimpleList.h"
#include "SimpleList.cpp"
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
	SimpleList<Point>* list;

public:
	Objeto();
	Objeto(int id, string nombre, string letter, string color, SimpleList<Point>* list);
	Objeto(string name);
	int getId();
	string getName();
	string getLetter();
	string getColor();
	SimpleList<Point>* getList();
	void setId(int id);
	void setName(string name);
	void setLetter(string letter);
	void setColor(string color);
	void insertPos(string x, string y);
	void setSimpleList(SimpleList<Point>* list);

	void setX(string x);
	string getX();
	void setY(string y);
	string getY();
};

#endif // OBJETO_H