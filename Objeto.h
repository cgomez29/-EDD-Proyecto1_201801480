#ifndef PERSONA_H
#define PERSONA_H

#include "Nodo.h"
#include "Point.h"
#include <iostream>

using namespace std;

class Objeto:public Nodo
{
private:
	int id;
	string name;
	string letter;
	string color;

	/*xxxxxxxxxxxxxxxxx cambiar por lista*/
	string x;
	string y;
	/*SimpleList<Point>* list;*/

public:
	Objeto(string name, string x, string y);
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

	void setX(string x);
	string getX();
	void setY(string y);
	string getY();
};

#endif // PERSONA_H