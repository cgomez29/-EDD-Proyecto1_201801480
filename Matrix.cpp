#include "Matrix.h"

Matrix::Matrix()
{
	this->horizontal = nullptr;
	this->vertical = nullptr;
}

Matrix::~Matrix()
{
	Nodo* aux, * aux2, * tmp, * tmp2, * extra, * extra2;
	aux = this->vertical;
	tmp = this->horizontal;
	while (aux != nullptr)
	{
		extra = aux->getDown();
		aux2 = aux->getNext();
		while (aux2 != nullptr)
		{
			extra2 = aux2->getNext();
			delete aux2;
			aux2 = extra2;
		}
		delete aux;
		aux = extra;
	}

	while (tmp != nullptr)
	{
		tmp2 = tmp->getNext();
		delete tmp;
		tmp = tmp2;
	}
}

Cabecera* Matrix::crearHorizontal(string x)
{
	if (this->horizontal == nullptr)
	{
		Cabecera* nueva = new Cabecera(x);
		this->horizontal = nueva;
		return nueva;
	}

	Cabecera* aux = this->horizontal;
	if (x.compare(aux->getNombre()) < 0)
	{
		Cabecera* nueva = new Cabecera(x);
		nueva->setNext(aux);
		this->horizontal->setPrevious(nueva);
		this->horizontal = nueva;
		return nueva;
	}
	while (aux->getNext() != nullptr)
	{
		if (x.compare(aux->getNombre()) > 0 && x.compare(((Cabecera*)aux->getNext())->getNombre()) <= 0)
		{
			Cabecera* nuevo = new Cabecera(x);
			Cabecera* tmp = (Cabecera*)aux->getNext();
			tmp->setPrevious(nuevo);
			nuevo->setNext(tmp);
			aux->setNext(nuevo);
			nuevo->setPrevious(aux);
			return nuevo;
		}
		aux = (Cabecera*)aux->getNext();
	}

	Cabecera* nuevo = new Cabecera(x);
	aux->setNext(nuevo);
	nuevo->setPrevious(aux);
	return nuevo;
}

Cabecera* Matrix::crearVertical(string y)
{
	if (this->vertical == nullptr)
	{
		Cabecera* nueva = new Cabecera(y);
		this->vertical = nueva;
		return nueva;
	}

	Cabecera* aux = this->vertical;
	if (y.compare(aux->getNombre()) < 0)
	{
		Cabecera* nueva = new Cabecera(y);
		nueva->setDown(aux);
		this->vertical->setUp(nueva);
		this->vertical = nueva;
		return nueva;
	}
	while (aux->getDown() != nullptr)
	{
		if (y.compare(aux->getNombre()) > 0 && y.compare(((Cabecera*)aux->getDown())->getNombre()) <= 0)
		{
			Cabecera* nuevo = new Cabecera(y);
			Cabecera* tmp = (Cabecera*)aux->getDown();
			tmp->setUp(nuevo);
			nuevo->setDown(tmp);
			aux->setDown(nuevo);
			nuevo->setUp(aux);
			return nuevo;
		}
		aux = (Cabecera*)aux->getDown();
	}

	Cabecera* nuevo = new Cabecera(y);
	aux->setDown(nuevo);
	nuevo->setUp(aux);
	return nuevo;
}

//cabecera, nombre del objeto
Nodo* Matrix::getUltimoH(Cabecera* cabecera, string x)
{
	if (cabecera->getNext() == nullptr)
	{
		return cabecera;
	}
	Nodo* aux = cabecera->getNext();
	while (aux->getNext() != nullptr)
	{
		if (x.compare(((Objeto*)aux)->getX()) <= 0)
		{
			return aux;
		}
		aux = aux->getNext();
	}
	if (x.compare(((Objeto*)aux)->getX()) <= 0)
	{
		return aux->getPrevious();
	}
	return aux;
}

Nodo* Matrix::getUltimoV(Cabecera* cabecera, string y)
{
	if (cabecera->getDown() == nullptr)
	{
		return cabecera;
	}
	Nodo* aux = cabecera->getDown();
	while (aux->getDown() != nullptr)
	{
		if (y.compare(((Objeto*)aux)->getY()) <= 0)
		{
			return aux;
		}
		aux = aux->getDown();
	}
	if (y.compare(((Objeto*)aux)->getY()) <= 0)
	{
		return aux->getUp();
	}
	return aux;
}


Cabecera* Matrix::getHorizontal(string x)
{
	if (this->horizontal == nullptr)
	{
		return nullptr;
	}
	Cabecera* aux = this->horizontal;
	while (aux != nullptr)
	{
		if (((string)aux->getNombre()).compare(x) == 0)
		{
			return aux;
		}
		aux = (Cabecera*)aux->getNext();
	}
	return nullptr;

}

Cabecera* Matrix::getVertical(string y)
{
	if (this->vertical == nullptr)
	{
		return nullptr;
	}
	Cabecera* aux = this->vertical;
	while (aux != nullptr)
	{
		if (((string)aux->getNombre()).compare(y) == 0)
		{
			return aux;
		}
		aux = (Cabecera*)aux->getDown();
	}
	return nullptr;
}

void Matrix::add(Objeto* obj)
{
	NodoSL<Point>* aux = obj->getList()->getHead();
	string x = "";
	string y = "";
	Objeto* obj2;

	while (aux != nullptr)
	{
		obj2 = new Objeto(obj->getName());
		x = aux->getValue().getX();
		y = aux->getValue().getY();
		obj2->setColor(obj->getColor());
		obj2->setLetter(obj->getLetter());

		obj2->setX(x);
		obj2->setY(y);

		add(obj2, x, y);

		aux = aux->getSiguiente();
	}
}

void Matrix::add(Objeto* obj, string x, string y)
{
	Cabecera* vertical = this->getVertical(y);
	Cabecera* horizontal = this->getHorizontal(x);

	if (vertical == nullptr)
	{
		vertical = crearVertical(y);
	}
	if (horizontal == nullptr)
	{
		horizontal = crearHorizontal(x);
	}

	Nodo* left = getUltimoH(vertical, x);
	Nodo* up = getUltimoV(horizontal, y);

	if (left->getNext() == nullptr) //->getNext()
	{
		left->setNext(obj);
		obj->setPrevious(left);
	}
	else
	{
		Nodo* temp = left->getNext();
		left->setNext(obj);
		obj->setPrevious(left);
		temp->setPrevious(obj);
		obj->setNext(temp);
	}

	if (up->getDown() == nullptr) //->getDown()
	{
		up->setDown(obj);
		obj->setUp(up);
	}
	else
	{
		Nodo* temp = up->getDown();
		up->setDown(obj);
		obj->setUp(up);
		temp->setUp(obj);
		obj->setDown(temp);
	}
}


void Matrix::graficar()
{
	int grupos = 0;
	Nodo* vertical;
	Nodo* horizontal;
	ostringstream cadena;
	cadena << "digraph G{" << endl << "node[shape=\"box\"];\n graph[splines=\"ortho\"];" << endl;
	cadena << "nodo[label=\"matrix\"; group=0];\n";
	vertical = this->vertical;
	while (vertical != nullptr)
	{
		cadena << "node" << &(*vertical) << "[label=\"" << ((Cabecera*)vertical)->getNombre() << "\", group=" << grupos << "];\n"; // << 
		vertical = vertical->getDown();
	}

	grupos++;
	horizontal = this->horizontal;
	int temp = grupos;
	while (horizontal != nullptr)
	{
		cadena << "node" << &(*horizontal) << "[label=\"" << ((Cabecera*)horizontal)->getNombre() << "\", group=" << grupos << "];\n"; //<<
		horizontal = horizontal->getNext();
		grupos++;
	}
	grupos = temp;

	vertical = this->vertical;
	while (vertical->getDown() != nullptr)
	{
		cadena << "node" << &(*vertical) << "->node" << &(*vertical->getDown()) << ";\n";
		cadena << "node" << &(*vertical->getDown()) << "->node" << &(*vertical) << ";\n";
		vertical = vertical->getDown();
	}

	horizontal = this->horizontal;
	while (horizontal->getNext() != nullptr)
	{
		cadena << "node" << &(*horizontal) << "->node" << &(*horizontal->getNext()) << ";\n";
		cadena << "node" << &(*horizontal->getNext()) << "->node" << &(*horizontal) << ";\n";
		horizontal = horizontal->getNext();
	}

	vertical = this->vertical;
	horizontal = this->horizontal;
	while (horizontal != nullptr)
	{
		Nodo* aux = horizontal->getDown();

		while (aux != nullptr)
		{
			cadena << "node" << &(*aux) << "[shape=\"circle\", color=\"green\", label=\"" << ((Objeto*)aux)->getName() << "\"" << ", group = " << grupos << "];\n";
			aux = aux->getDown();
		}
		grupos++;
		horizontal = horizontal->getNext();
	}

	horizontal = this->horizontal;
	while (horizontal != nullptr)
	{
		Nodo* aux = horizontal;

		while (aux->getDown() != nullptr)
		{
			cadena << "node" << &(*aux) << "->node" << &(*aux->getDown()) << ";\n";
			cadena << "node" << &(*aux->getDown()) << "->node" << &(*aux) << ";\n";
			aux = aux->getDown();
		}
		horizontal = horizontal->getNext();
	}

	vertical = this->vertical;
	while (vertical != nullptr)
	{
		Nodo* aux = vertical;
		while (aux->getNext() != nullptr)
		{
			cadena << "node" << &(*aux) << "->node" << &(*aux->getNext()) << ";\n";
			cadena << "node" << &(*aux->getNext()) << "->node" << &(*aux) << ";\n";
			aux = aux->getNext();
		}
		vertical = vertical->getDown();
	}

	if (this->vertical != nullptr)
	{
		//nodoo
		cadena << "nodo->node" << &(*this->vertical) << "\n";
		cadena << "nodo->node" << &(*this->horizontal) << "\n";
		//frank
		cadena << "{rank=\"same\";nodo;node" << &(*this->horizontal);
		horizontal = this->horizontal;
		while (horizontal != nullptr)
		{
			//nodo
			cadena << ";node" << &(*horizontal);
			horizontal = horizontal->getNext();
		}
		cadena << "};" << endl;
	}

	vertical = this->vertical;
	while (vertical != nullptr)
	{
		Nodo* aux = vertical->getNext();

		cadena << "{rank=\"same\";node" << &(*vertical);
		while (aux != nullptr)
		{
			cadena << ";node" << &(*aux);
			aux = aux->getNext();
		}
		cadena << "};" << endl;
		vertical = vertical->getDown();
	}

	cadena << "}" << endl;
	cout << cadena.str() << endl;

}