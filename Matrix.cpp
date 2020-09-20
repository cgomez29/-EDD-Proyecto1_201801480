#include "Matrix.h"

Matrix::Matrix()
{
	this->horizontal = nullptr;
	this->vertical = nullptr;
}

Matrix::~Matrix()
{

	delete listTemp;
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
		if (((string)aux->getNombre()) == x)
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
		if (((string)aux->getNombre()) == y)
		{
			return aux;
		}
		aux = (Cabecera*)aux->getDown();
	}
	return nullptr;
}

//Metodo publico, recibe parametros para crear un objeto.
void Matrix::add(int id, string nombre, string letter, string color, string x, string y)
{
	if (stoi(x) >= 0 && stoi(y) >= 0)
	{
		if (existePosicion(x, y))
		{
			Objeto* obj = new Objeto(id, nombre, letter, color, x, y);
			add(obj, x, y);

			Point p = Point(x, y);
			listTemp->add(p);
		}
	}
	
	/*cout << "-----------------" << endl;
	while (aux != nullptr)
	{
		
		cout << "X: " << aux->getValue().getX() << " Y: " << aux->getValue().getY() << endl;
		aux = aux->getSiguiente();
	}
	cout << "-----------------" << endl;*/
}

//Metodo privado para agregar un objeto a la matrix.
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


//Metodo privado para llenar los espacios vacios en la grafica de la matrix
void Matrix::setPointEmpty()
{
	//Maxima posicion en x
	int x = 0;
	//Maxima posicion en y
	int y = 0;

	Cabecera* auxV = this->vertical;
	while (auxV != nullptr)
	{
		y = y + 1;

		auxV = (Cabecera*)auxV->getDown();
	}

	Cabecera* auxH = this->horizontal;
	while (auxH != nullptr)
	{
		x = x + 1;

		auxH = (Cabecera*)auxH->getNext();
	}

	//imprime el tamaño maximo de la fila y columna
	//cout << "X max: " << x << " Y max: " << y  << endl;

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
													// j = x ; i = y
			add(-1000000, "", "", "white", to_string(j), to_string(i));
		}

	}

}

bool Matrix::existePosicion(string x, string y)
{
	NodoP* aux = listTemp->getHead();
	while (aux != NULL)
	{
		if (aux->getPoint().getX() == x && aux->getPoint().getY() == y)
		{
			return false;
		}
		aux = aux->getSiguiente();
	}
	return true; // retorna verdadero si no existe
}

void Matrix::graficar()
{
	setPointEmpty();
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
			if (((Objeto*)aux)->getId() == -1000000) 
			{
				cadena << "node" << &(*aux) << "[shape=\"point\", width = 0, fontcolor=\"white\", color=\"" << ((Objeto*)aux)->getColor() << "\", style=\"filled\", label=\"" << ((Objeto*)aux)->getName() << "\"" << ", group = " << grupos << "];\n";
			}
			else
			{
				cadena << "node" << &(*aux) << "[shape=\"circle\", fontcolor=\"white\", color=\"" << ((Objeto*)aux)->getColor() << "\", style=\"filled\", label=\"" << ((Objeto*)aux)->getName() << "\"" << ", group = " << grupos << "];\n";
			}
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
			if (((Objeto*)aux)->getId() != -1000000 && ((Objeto*)aux->getDown())->getId() == -1000000)
			{
				//cadena << "node" << &(*aux) << "->node" << &(*aux->getDown()) << "[ dir = none ];\n";
				cadena << "node" << &(*aux->getDown()) << "->node" << &(*aux) << ";\n";
			}
			else if (((Objeto*)aux)->getId() == -1000000 && ((Objeto*)aux->getDown())->getId() != -1000000)
			{
				cadena << "node" << &(*aux) << "->node" << &(*aux->getDown()) << ";\n";
				//cadena << "node" << &(*aux->getDown()) << "->node" << &(*aux) << "[ dir = none ];\n";
			}
			else if (((Objeto*)aux)->getId() == -1000000 && ((Objeto*)aux->getDown())->getId() == -1000000)
			{
				cadena << "node" << &(*aux) << "->node" << &(*aux->getDown()) << "[ dir = none ];\n";
				//cadena << "node" << &(*aux->getDown()) << "->node" << &(*aux) << "[ dir = none ];\n";
			}
			else
			{
				cadena << "node" << &(*aux) << "->node" << &(*aux->getDown()) << ";\n";
				cadena << "node" << &(*aux->getDown()) << "->node" << &(*aux) << ";\n";
			}
			
			
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
			if (((Objeto*)aux)->getId() != -1000000 &&((Objeto*)aux->getNext())->getId() == -1000000)
			{
				//cadena << "node" << &(*aux) << "->node" << &(*aux->getNext()) << "[ dir = none ];\n";
				cadena << "node" << &(*aux->getNext()) << "->node" << &(*aux) << ";\n";
			}
			else if (((Objeto*)aux)->getId() == -1000000 && ((Objeto*)aux->getNext())->getId() != -1000000)
			{
				cadena << "node" << &(*aux) << "->node" << &(*aux->getNext()) << ";\n";
				//cadena << "node" << &(*aux->getNext()) << "->node" << &(*aux) << "[ dir = none ];\n";
			}
			else if (((Objeto*)aux)->getId() == -1000000 && ((Objeto*)aux->getNext())->getId() == -1000000)
			{
				cadena << "node" << &(*aux) << "->node" << &(*aux->getNext()) << "[ dir = none ];\n";
				//cadena << "node" << &(*aux->getNext()) << "->node" << &(*aux) << "[ dir = none ];\n";
			}
			else
			{
				cadena << "node" << &(*aux) << "->node" << &(*aux->getNext()) << ";\n";
				cadena << "node" << &(*aux->getNext()) << "->node" << &(*aux) << ";\n";
			}

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

