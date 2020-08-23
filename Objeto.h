#pragma once
#include "SimpleList.h"
#include "Point.h"
#include "Nodo.h"
#include <iostream>

using namespace std;

class Objeto:public Nodo
{
private:
	int id;
	string name;
	string letter;
	string color;
	/*SimpleList<Point>* list;*/

public:
	Objeto(string name);
	int getId();
	string getName();
	string getLetter();
	string getColor();
	//SimpleList<Point>* getList();
	void setId(int id);
	void setName(string name);
	void setLetter(string letter);
	void setColor(string color);
	//void setSimpleList(SimpleList<Point>* list);
};
