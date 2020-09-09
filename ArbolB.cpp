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

void ArbolB::delete_nodo(Objeto* valor)
{
	this->raiz = delete_nodo(this->raiz, valor);
}

NodoB* ArbolB::delete_nodo(NodoB* raiz, Objeto* valor)
{
	if (raiz == nullptr)
	{
		return nullptr;
	}
	if (valor->getId() == raiz->getObjeto()->getId())
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
		raiz->setRigth(delete_nodo(raiz->getRigth(), smallValue));
		return raiz;
	}

	if (valor->getId() < raiz->getObjeto()->getId())
	{
		raiz->setLeft(delete_nodo(raiz->getLeft(), valor));
		return raiz;
	}
	raiz->setRigth(delete_nodo(raiz->getRigth(), valor));
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
		cadena << "node" << &(*this->raiz) << "[color=\"" << raiz->getObjeto()->getColor() << "\",label= \"<f0>|<f1>" << this->raiz->getObjeto()->getName()<< "|<f2>\"]" << endl;
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

void ArbolB::graficar(stringstream* cadena, NodoB* padre, NodoB* actual, bool left)
{
	if (actual != nullptr)
	{
		*cadena << "node" << &(*actual) << "[color=\"" << actual->getObjeto()->getColor() <<"\",label=\"<f0>|<f1>" << actual->getObjeto()->getName() << "|<f2>\"]" << endl;
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
		cout << nodo->getObjeto()->getId() << ". " << nodo->getObjeto()->getName() << endl;
		inOrden(nodo->getRigth());
	}
}

void ArbolB::inOrden()
{
	inOrden(this->raiz);
}