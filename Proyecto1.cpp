#include <iostream>
#include "MainMenu.h"

#include <string>

#include "ArbolAVL.h"
#include "Project.h"
#include "ReadJSON.h"


using namespace std;

int main()
{
    ReadJSON* r = new ReadJSON();

    r->guardarProyecto();

    delete r;

    /*ArbolAVL* arbol = new ArbolAVL();
    Project* p = new  Project();
    Project* p1 = new  Project();
    Project* p2 = new  Project();
    Project* p3 = new  Project();
    Project* p4 = new  Project();
    p->setName("Proyecto 5 ");
    p1->setName("Proyecto 1 ");
    p2->setName("Proyecto 7 ");
    p3->setName("Proyecto 2 ");
    p4->setName("Proyecto 8 ");

    arbol->insertar(*p);
    arbol->insertar(*p1);
    arbol->insertar(*p2);
    arbol->insertar(*p3);
    arbol->insertar(*p4);

    arbol->graficar();

    delete arbol;*/

    /*Matrix* matrix= new Matrix();
    //// parametros: nombre, posX 1, posY 1
    Objeto* o = new Objeto("0");  
    o->insertPos("0", "0");
    o->insertPos("0", "1");
    o->insertPos("0", "2");
    o->insertPos("0", "3");
    o->insertPos("1", "0");
    o->insertPos("2", "0");
    o->insertPos("3", "0");
    o->insertPos("3", "1");
    o->insertPos("3", "2");
    o->insertPos("3", "3");
    o->insertPos("2", "3");
    o->insertPos("1", "3");
    o->insertPos("2", "2");
    o->insertPos("4", "2");
    o->insertPos("4", "1");
    //o->insertPos("4", "4");
    //o->insertPos("4", "1");

                   //H -> X , V -> Y
    matrix->add(o);

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
    menu->menu();*/
    //delete menu;
    return 0;
}
