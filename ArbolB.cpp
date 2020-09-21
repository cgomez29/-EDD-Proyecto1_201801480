#include "ArbolB.h"

ArbolB::ArbolB()
{
	this->raiz = nullptr;
}

ArbolB::~ArbolB()
{
	Delete(this->raiz);
}

void ArbolB::Delete()
{
	Delete(this->raiz);
}

void ArbolB::Delete(NodoB* raiz)
{
	if (this->raiz) { return; }
	Delete(raiz->getLeft());
	Delete(raiz->getRigth());
	delete this->raiz;
}

void ArbolB::setRaizNull()
{
	this->raiz = nullptr;
}

void ArbolB::insert(int id, string name, string letter, string color, SimpleListP* list)
{
	Objeto* objeto = new Objeto(id, name, letter, color, list);
	this->raiz = insert(this->raiz, objeto);
}

void ArbolB::insert(Objeto* objeto)
{
	this->raiz = insert(this->raiz, objeto);
}

NodoB* ArbolB::insert(NodoB* raiz, Objeto* dato)
{
	if (raiz == nullptr)
	{
		raiz = new NodoB(dato);
	}
	else
	{
		if (dato->getId() < raiz->getObjeto()->getId())
		{
			NodoB* izq = insert(raiz->getLeft(), dato);
			raiz->setLeft(izq);
		}
		else if (dato->getId() > raiz->getObjeto()->getId())
		{
			NodoB* der = insert(raiz->getRigth(), dato);
			raiz->setRigth(der);
		}
	}

	return raiz;
}

//Metodo publico para la eliminacion de un nodo por id
void ArbolB::delete_nodo(int id)
{
	this->raiz = delete_nodo(this->raiz, id);

}

//Metodo privado para la eliminacion de un nodo por id
NodoB* ArbolB::delete_nodo(NodoB* raiz, int id)
{
	if (raiz == nullptr)
	{
		return nullptr;
	}
	if (id == raiz->getObjeto()->getId())
	{
		//cuando no tiene ningun hijo
		if (raiz->getLeft() == nullptr && raiz->getRigth() == nullptr)
		{
			return nullptr;
		}
		//cuando tiene un solo hijo
		if (raiz->getRigth() == nullptr)
		{
			return raiz->getLeft();
		}
		if (raiz->getLeft() == nullptr)
		{
			return raiz->getRigth();
		}
		//cuando tiene dos hijos
		Objeto* smallValue = findNodo(raiz->getRigth());
		raiz->setObjeto(smallValue);
		raiz->setRigth(delete_nodo(raiz->getRigth(), smallValue->getId()));
		return raiz;
	}

	if (id < raiz->getObjeto()->getId())
	{
		raiz->setLeft(delete_nodo(raiz->getLeft(), id));
		return raiz;
	}
	raiz->setRigth(delete_nodo(raiz->getRigth(), id));
	return raiz;
}

Objeto* ArbolB::findNodo(NodoB* raiz)
{
	// buscando el valor mas pequeño
	if (raiz->getLeft() == nullptr)
	{
		return raiz->getObjeto();
	}
	else
	{
		return findNodo(raiz->getLeft());
	}
}

void ArbolB::graficar()
{
	stringstream cadena;
	cadena << "digraph G{\n" << endl;
	cadena << "node[shape=\"record\"]" << endl;
	if (raiz != nullptr)
	{
		cadena << "node" << &(*this->raiz) << "[color=\"" << raiz->getObjeto()->getColor() << "\",label= \"<f0>|<f1>" << "Letra: " << this->raiz->getObjeto()->getLetter() << " Nombre: " << " X: " << this->raiz->getObjeto()->getName() << " ID: " << this->raiz->getObjeto()->getId() << "|<f2>\"]" << endl;
		this->graficar(&cadena, this->raiz, this->getRaiz()->getLeft(), true);
		this->graficar(&cadena, this->raiz, this->getRaiz()->getRigth(), false);
	}

	cadena << "}" << endl;

	cout << cadena.str() << endl;

	ofstream file("treeB.dot");
	file << cadena.str();
	file.close();
	system("dot -Tpng treeB.dot -o treeB.png");
	system("treeB.png");
}

void ArbolB::graficar(stringstream* cadena, NodoB* padre, NodoB* actual, bool left)
{
	if (actual != nullptr)
	{
		*cadena << "node" << &(*actual) << "[color=\"" << actual->getObjeto()->getColor() <<"\",label=\"<f0>|<f1>" << actual->getObjeto()->getColor() << "\",label= \"<f0>|<f1>" << "Letra: " << actual->getObjeto()->getLetter() << " Nombre: " << " X: " << actual->getObjeto()->getName() << " ID: " << actual->getObjeto()->getId() << "|<f2>\"]" << endl;
		if (left)
		{
			*cadena << "node" << &(*padre) << ":f0->node" << &(*actual) << ":f1" << endl;
		}
		else
		{
			*cadena << "node" << &(*padre) << ":f2->node" << &(*actual) << ":f1" << endl;
		}

		graficar(cadena, actual, actual->getLeft(), true);
		graficar(cadena, actual, actual->getRigth(), false);
	}
}


NodoB* ArbolB::getRaiz()
{
	return this->raiz;
}

//metodo privado para buscar un nodo
NodoB* ArbolB::buscarNodo(NodoB* root, int id)
{
	if (root == nullptr)
	{
		return nullptr;
	}
	if (root->getObjeto()->getId() == id)
	{
		return root;
	}

	if (root->getObjeto()->getId() > id)
	{
		return buscarNodo(root->getLeft(), id);
	}
	
	return buscarNodo(root->getRigth(), id);

}

//metodo publico para buscar un nodo
NodoB* ArbolB::buscarNodo(int id)
{
	return buscarNodo(this->raiz, id);
}


void ArbolB::inOrden(NodoB* nodo)
{
	//izquierdo, raiz, derecha
	if (nodo != nullptr)
	{
		inOrden(nodo->getLeft());
		if (nodo->getObjeto()->getId() != -1 && nodo->getObjeto()->getId() != -2)
		{
			cout << nodo->getObjeto()->getId2() << ". " << nodo->getObjeto()->getName() << " Punto: " << " X: " << nodo->getObjeto()->getList()->getHead()->getPoint().getX() << " Y: " << nodo->getObjeto()->getList()->getHead()->getPoint().getY() << endl;
		}
		inOrden(nodo->getRigth());
	}
}


void ArbolB::inOrden()
{
	inOrden(this->raiz);
}


//Metodo public que devuelve en una lista todos los objetos cargados en el arbol binario
SimpleListLibreria* ArbolB::getListObjetos()
{
	SimpleListLibreria* list = new SimpleListLibreria();
	list = llenarLista(this->raiz, list);
	return list;
}

//Metodo privado que llena una lista de todos los objetos que tiene un arbol
SimpleListLibreria* ArbolB::llenarLista(NodoB* root, SimpleListLibreria* list)
{
	if (root != nullptr)
	{
		llenarLista(root->getLeft(), list);
		list->add(root->getObjeto());
		llenarLista(root->getRigth(), list);
	}
	else if (root == nullptr)
	{
		return list;
	}

}

int ArbolB::getId()
{
	return this->id;
}

void ArbolB::setId(int id)
{
	this->id = id;
}

string ArbolB::getNombre()
{
	return this->nombre;
}

void ArbolB::setNombre(string nombre)
{
	this->nombre = nombre;
}