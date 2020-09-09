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
	int xAscii = stoi(x);
	if (this->horizontal == nullptr)
	{
		Cabecera* nueva = new Cabecera(x);
		this->horizontal = nueva;
		return nueva;
	}

	Cabecera* aux = this->horizontal;
	if (xAscii <= stoi(aux->getNombre()))
	{
		Cabecera* nueva = new Cabecera(x);
		nueva->setNext(aux);
		this->horizontal->setPrevious(nueva);
		this->horizontal = nueva;
		return nueva;
	}
	while (aux->getNext() != nullptr)
	{
		if (xAscii > stoi(aux->getNombre()) && xAscii  <= stoi(((Cabecera*)aux->getNext())->getNombre()))
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
	int yAscii = stoi(y);
	if (this->vertical == nullptr)
	{
		Cabecera* nueva = new Cabecera(y);
		this->vertical = nueva;
		return nueva;
	}

	Cabecera* aux = this->vertical;
	if ( yAscii <= stoi(aux->getNombre()))
	{
		Cabecera* nueva = new Cabecera(y);
		nueva->setDown(aux);
		this->vertical->setUp(nueva);
		this->vertical = nueva;
		return nueva;
	}
	while (aux->getDown() != nullptr)
	{
		if (yAscii > stoi(aux->getNombre()) && yAscii <= stoi(((Cabecera*)aux->getDown())->getNombre()))
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
	int xAscii = stoi(x);
	if (cabecera->getNext() == nullptr)
	{
		return cabecera;
	}
	Nodo* aux = cabecera->getNext();

	if (xAscii <= stoi(((Objeto*)aux)->getX()))
	{
		return cabecera;
	}

	while (aux->getNext() != nullptr)
	{
		if (xAscii > stoi(((Objeto*)aux)->getX()) && xAscii <= stoi(((Objeto*)aux->getNext())->getX()))
		{
			return aux;
		}
		aux = aux->getNext();
	}

	return aux;
}

Nodo* Matrix::getUltimoV(Cabecera* cabecera, string y)
{
	int yAscii = stoi(y);
	if (cabecera->getDown() == nullptr)
	{
		return cabecera;
	}
	Nodo* aux = cabecera->getDown();

	if (yAscii <= stoi(((Objeto*)aux)->getY()))
	{
		return cabecera;
	}

	while (aux->getDown() != nullptr)
	{
		if (yAscii > stoi(((Objeto*)aux)->getY()) && yAscii <= stoi(((Objeto*)aux->getDown())->getY()))
		{
			return aux;
		}
		aux = aux->getDown();
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

void Matrix::add(int id, string nombre, string letter, string color, string x, string y)
{

	Objeto* obj = new Objeto(id, nombre, letter, color, x, y);

	
	add(obj, x, y);

	/*cout << "-----------------" << endl;
	while (aux != nullptr)
	{
		
		cout << "X: " << aux->getValue().getX() << " Y: " << aux->getValue().getY() << endl;
		aux = aux->getSiguiente();
	}
	cout << "-----------------" << endl;*/
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


/*void Matrix::graficar()
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
		cadena << "node" << &(*vertical) << "[label=\"" << ((Cabecera*)vertical)->getNombre() << "\", group=" << grupos << "];\n";
		vertical = vertical->getDown();
	}

	grupos++;
	horizontal = this->horizontal;
	int temp = grupos;
	while (horizontal != nullptr)
	{
		cadena << "node" << &(*horizontal) << "[label=\"" << ((Cabecera*)horizontal)->getNombre() << "\", group=" << grupos << "];\n"; 
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

	//vertical = this->vertical;
	horizontal = this->horizontal;
	while (horizontal != nullptr)
	{
		Nodo* aux = horizontal->getDown();

		while (aux != nullptr)
		{
			cadena << "node" << &(*aux) << "[shape=\"circle\", fontcolor=\"white\", color=\"" << ((Objeto*)aux)->getColor() << "\", style=\"filled\", label=\"" << ((Objeto*)aux)->getName() << "\"" << ", group = " << grupos << "];\n";
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
*/
void Matrix::graficar()
{
	int grupos = 0;
	Nodo* vertical;
	Nodo* horizontal;
	ostringstream cadena;
	cadena << "digraph G{" << endl << "node[shape=\"box\"];\n graph[splines=\"ortho\"];" << endl;
	cadena << "nodo[label=\"Nivel " << getName() <<"\"; group=0];\n";
	vertical = this->vertical;
	while (vertical != nullptr)
	{
		cadena << "node" << &(*vertical) << "[label=\"" << ((Cabecera*)vertical)->getNombre() << "\", group=" << grupos << "];\n";
		vertical = vertical->getDown();
	}

	grupos++;
	horizontal = this->horizontal;
	int temp = grupos;
	while (horizontal != nullptr)
	{
		cadena << "node" << &(*horizontal) << "[label=\"" << ((Cabecera*)horizontal)->getNombre() << "\", group=" << grupos << "];\n";
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

	//vertical = this->vertical;
	horizontal = this->horizontal;
	while (horizontal != nullptr)
	{
		Nodo* aux = horizontal->getDown();

		while (aux != nullptr)
		{
			cadena << "node" << &(*aux) << "[shape=\"circle\", fontcolor=\"white\", color=\"" << ((Objeto*)aux)->getColor() << "\", style=\"filled\", label=\"" << ((Objeto*)aux)->getName() << "\"" << ", group = " << grupos << "];\n";
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

	string nameFile = getName() + ".dot";
	string comando = "dot -Tpng " + getName() + ".dot -o " + "Nivel" + getName() + ".png";
	string path = "Nivel" + getName() + ".png";
	ofstream file(nameFile);
	file << cadena.str();
	file.close();
	system(comando.c_str());
	system(path.c_str());
}


void Matrix::setName(string name)
{
	this->name = name;
}

string Matrix::getName()
{
	return this->name;
}

void Matrix::setId(int id)
{
	this->id = id;
}

int Matrix::getId()
{
	return this->id;
}

