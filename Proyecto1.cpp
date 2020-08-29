#include <iostream>
#include "MainMenu.h"

#include <string>

#include "Objeto.h"
#include "Matrix.h"

using namespace std;

int main()
{
    Matrix* matrix= new Matrix();
    //// parametros: nombre, posX 1, posY 1
    Objeto* o = new Objeto("0");
    o->insertPos("0", "0");
    o->insertPos("1", "1");

                   //H -> X , V -> Y
    matrix->add(o);

    matrix->graficar();
    delete matrix;

    

    /*Matrix* matrix= new Matrix();
    //// parametros: nombre, posX 1, posY 1
    Objeto* o = new Objeto("0", "0","0");
    Objeto* o1 = new Objeto("2", "1", "0");
    Objeto* o2 = new Objeto("3", "2", "1");
    Objeto* o3 = new Objeto("4", "2", "2");
    Objeto* o4 = new Objeto("5", "1", "3");
    Objeto* o5 = new Objeto("5", "50", "50");
    Objeto* o6 = new Objeto("5", "50", "3");
                   //H -> X , V -> Y
    matrix->add(o, "0", "0");
    matrix->add(o1, "1", "0");
    matrix->add(o2, "2", "1");
    matrix->add(o3, "2", "2");
    matrix->add(o4, "1", "3");
    matrix->add(o5, "50", "50");
    matrix->add(o6, "50", "3");
    
    matrix->graficar();
    delete matrix;*/


    /*SimpleList<Point>* list = new SimpleList<Point>();

    for (int x = 0; x<5; x++)
    {
        Point p = Point(to_string(x), to_string(x));

        list->add(p);
    }

    NodoSL<Point>* aux = list->getHead();

    while (aux != nullptr)
    {
        cout << "X " << aux->getValue().getX() << endl;
        aux = aux->getSiguiente();
    }*/


    /*MainMenu* menu = new MainMenu();
    menu->menu();
    delete menu;*/
    return 0;
}
