#include "ArbolAVL.h"

ArbolAVL::ArbolAVL()
{
	this->raiz = nullptr;
}

ArbolAVL::~ArbolAVL()
{
	Delete(this->raiz);
}

NodoAVL* ArbolAVL::insertar(NodoAVL* raiz, Project project, bool& scape)
{
	NodoAVL* n1;
	if (raiz == nullptr)
	{
		raiz = new NodoAVL(project);
		scape = true;
	}
	else if (valorAscii(project.getName()) < valorAscii(raiz->getProject().getName()))
	{
		NodoAVL* izq = insertar(raiz->getLeft(), project, scape);
		raiz->setLeft(izq);

		if (scape)
		{
			switch (raiz->getFactor())
			{
			case 1:
				raiz->setFactor(0);
				scape = false;
				break;

			case 0:
				raiz->setFactor(-1);
				break;
			case -1:
				n1 = raiz->getLeft();
				if (n1->getFactor() == -1)
				{
					raiz = rotacionII(raiz, n1);
				}
				else
				{
					raiz = rotacionID(raiz, n1);
				}
				scape = false;
				//break;
			}
		}
	}
	else if (valorAscii(project.getName()) > valorAscii(raiz->getProject().getName()))
	{
		NodoAVL* der = insertar(raiz->getRigth(), project, scape);
		raiz->setRigth(der);
		if (scape)
		{
			switch (raiz->getFactor())
			{
			case 1:
				n1 = raiz->getRigth();
				if (n1->getFactor() == 1)
				{
					raiz = rotacionDD(raiz, n1);
				}
				else
				{
					raiz = rotacionDI(raiz, n1);
				}
				scape = false;
				break;
			case 0:
				raiz->setFactor(1);
				break;
			case -1:
				raiz->setFactor(0);
				scape = false;
			}
		
		}
	}
	return raiz;
}

int ArbolAVL::valorAscii(string cadena)
{
	int valor = 0;
	char caracter;
	for (int i = 0; i <= cadena.length(); i++)
	{
		caracter = cadena[i];

		valor = valor + caracter;
	}

	//cout << "valor ascii: " << valor << endl;
	return valor;
}

void ArbolAVL::insertar(Project project)
{
	bool b = false;
	bool* a = &b;
	this->raiz = insertar(this->raiz, project, *a);
}

NodoAVL* ArbolAVL::rotacionII(NodoAVL* n, NodoAVL* n1)
{
	n->setLeft(n1->getRigth());
	n1->setRigth(n);

	if (n1->getFactor() == -1)
	{
		n->setFactor(0);
		n1->setFactor(0);
	}
	else
	{
		n->setFactor(-1);
		n1->setFactor(1);
	}

	return n1;
}

void ArbolAVL::graficar()
{
	stringstream cadena;
	cadena << "digraph G{\n" << endl;
	cadena << "node[shape=\"record\"]" << endl;
	if (raiz != nullptr)
	{
		cadena << "node" << &(*this->raiz) << "[label= \"<f0>|<f1>"<< this->raiz->getProject().getName()<< "factor:" << this->raiz->getFactor()<< "|<f2>\"]" << endl;
		this->graficar(&cadena, this->raiz, this->getRaiz()->getLeft(), true);
		this->graficar(&cadena, this->raiz, this->getRaiz()->getRigth(), false);
	}

	cadena << "}" << endl;

	cout << cadena.str() << endl;

	ofstream file("salida.dot");
	file << cadena.str();
	file.close();
	system("dot -Tpng salida.dot -o imagen.png");
}

void ArbolAVL::graficar(stringstream* cadena, NodoAVL* padre, NodoAVL* actual, bool left)
{
	if (actual != nullptr)
	{
		*cadena << "node" << &(*actual) << "[label=\"<f0>|<f1>" << actual->getProject().getName() << "factor:" << actual->getFactor() << "|<f2>\"]"<< endl; 
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

NodoAVL* ArbolAVL::getRaiz()
{
	return this->raiz;
}

NodoAVL* ArbolAVL::rotacionDD(NodoAVL* n, NodoAVL* n1)
{
	n->setRigth(n1->getLeft());
	n1->setLeft(n);

	if (n1->getFactor() == 1)
	{
		n->setFactor(0);
		n1->setFactor(0);
	}
	else
	{
		n->setFactor(1);
		n1->setFactor(-1);
	}
	return n1;
}

NodoAVL* ArbolAVL::rotacionID(NodoAVL* n, NodoAVL* n1)
{
	NodoAVL* n2 = n1->getRigth();
	n->setLeft(n2->getRigth());
	n2->setRigth(n);
	n1->setRigth(n2->getLeft());
	n2->setLeft(n1);

	if (n2->getFactor() == 1)
	{
		n1->setFactor(-1);
	}
	else
	{
		n1->setFactor(0);
	}
	if (n2->getFactor() == -1)
	{
		n->setFactor(1);
	}
	else
	{
		n->setFactor(0);
	}
	n2->setFactor(0);

	return n2;
}

NodoAVL* ArbolAVL::rotacionDI(NodoAVL* n, NodoAVL* n1)
{
	NodoAVL* n2 = n1->getLeft();
	n->setRigth(n2->getLeft());
	n2->setLeft(n);
	n1->setLeft(n2->getRigth());
	n2->setRigth(n1);

	if (n2->getFactor() == 1)
	{
		n->setFactor(-1);
	}
	else
	{
		n->setFactor(0);
	}
	if (n2->getFactor() == -1)
	{
		n1->setFactor(1);
	}
	else
	{
		n1->setFactor(0);
	}

	n2->setFactor(0);
	return n2;
}

void ArbolAVL::Delete(NodoAVL* raiz)
{
	if (raiz == nullptr)
	{
		return;
	}
	Delete(raiz->getLeft());
	Delete(raiz->getRigth());
	delete raiz;
}
