#include "MainMenu.h"


MainMenu::MainMenu()
{
    this->controller = new ControllerProject();
    this->contadorProyecto = 1;
}


void MainMenu::menu()
{
    cout << "**************************************" << endl;
    cout << "* USAC                               *" << endl;
    cout << "* ESTRUCTURAS DE DATOS               *" << endl;
    cout << "* SECCION A:                         *" << endl;
    cout << "* Cristian Alexander Gomez Guzman    *" << endl;
    cout << "* Carnet: 201801480                  *" << endl;
    cout << "**************************************" << endl;
    int entrada = 0;
    char enter = _getch();
    //cin >> enter;
    if (enter == 13)
    {
        do
        {
            system("cls");
            cout << "1. Ver proyectos" << endl;
            cout << "2. Editar proyectos" << endl;
            cout << "3. Cargar proyectos" << endl;
            cout << "4. Graficar proyectos" << endl;
            cout << "5. Guardar proyectos" << endl;
            cout << "6. Cargar librerias" << endl;
            cout << "7. salir" << endl;
            cout << ">> ";
            cin >> entrada;

            switch (entrada)
            {
            case 1:
                verProjectos();
                break;
            case 2:
                editarProyecto();
                break;
            case 3:
                llenarArbolAVL(readJson->leerProyectos("prueba"));
                break;
            case 4:
                graficarProyectos();
                break;
            case 5:
                break;
            case 6:
                llenarArbolB(readJson->leerLibrerias("preuba"));
                break;
            }



        } while (entrada != 7);
    }

}


void MainMenu::llenarArbolB(SimpleListLibreria* list)
{
    NodoO* aux = list->getHead();
    while (aux != NULL)
    {
        treeB->insert(aux->getObjeto());
        aux = aux->getSiguiente();
    }
    treeB->graficar();
}

void MainMenu::llenarArbolAVL(SimpleListProject* list)
{
    NodoProject* aux = list->getHead();

    while (aux != NULL)
    {
        aux->getProject()->setId(contadorProyecto);
        treeAVL->insertar(aux->getProject());
        aux = aux->getSiguiente();
        contadorProyecto++;
    }
    //treeAVL->graficar();
}

void MainMenu::verProjectos()
{
    int contador = 0;
    do
    {
        system("cls");
        cout << "   VER PROYECTOS  " << endl;
        cout << "Lista de proyectos" << endl;
        treeAVL->inOrden();
        cout << endl;
        cout << "Ingrese 0 para salir" << endl;
        cout << ">> ";
        treeAVL->graficar();
        int id;
        cin >> id;

        if (id == 0)
        {
            break;
        }

    } while (contador != 0);
    

    /*if (project != NULL)
    {
        int entrada = 0;
        do
        {
            system("cls");
            cout << "1. Agregar nivel" << endl;
            cout << "2. Editar nivel" << endl;
            cout << "3. Eliminar nivel" << endl;
            cout << "4. Eliminar proyecto" << endl;
            cout << "5. Salir" << endl;
            cout << ">> ";
            cin >> entrada;

            switch (entrada)
            {
            case 1:
                agregarNiveles(project, readJson->leerNivel("prueba"));
                break;
            case 2:
                editarNivel(project);
                break;
            case 3:
                eliminarNivel(project);
                break;
            case 4:
                break;
            case 5:
                break;
            }


        } while (entrada != 5);
    
    }*/

}

void MainMenu::agregarNiveles(Project* project, SimpleListArbolB* list)
{
    NodoSLB* aux = list->getHead();

    while (aux != NULL)
    {
        project->getListNivel()->add(aux->getArbolB());
        aux->getArbolB();// graficar nivel obtenido
        aux = aux->getSiguiente();
    }

}


void MainMenu::eliminarNivel(Project* project)
{
    NodoSLB* aux = project->getListNivel()->getHead();
    int id;
    do
    {
        system("cls");
        cout << "Lista de niveles en el proyecto: " << project->getName() << endl;
        while (aux != NULL)
        {
            cout << aux->getArbolB()->getId() << ". " << aux->getArbolB()->getNombre() << endl;
            aux = aux->getSiguiente();
        }
        cout << endl;
        cout << "Ingrese el numero del nivel a eliminar" << endl;
        cout << "Ingrese 0 si desea salir" << endl;
        cout << ">> ";
        cin >> id;
        if (id == 0) { break; }

        if (project->getListNivel()->delete_item(id))
        {
            cout << "NIVEL ELIMINADO" << endl;
            cin >> id;
            break;
        }
        else {
            cout << "Elemento no encontrado!!" << endl;
            cin >> id;
            id = 1;
        }


    } while (id != 0);
}

void MainMenu::editarNivel(Project* project)
{
    
    ArbolB* nivel = NULL;
    int id;
    do
    {
        NodoSLB* aux = project->getListNivel()->getHead();
        system("cls");
        cout << "   Lista de niveles en el proyecto: " << project->getName() << endl;
        while (aux != NULL)
        {
            cout << aux->getArbolB()->getId() << ". " << aux->getArbolB()->getNombre() << endl;
            aux = aux->getSiguiente();
        }
        cout << endl;
        cout << " Ingrese el numero del nivel a editar" << endl;
        cout << " Ingrese 0 si desea salir" << endl;
        cout << ">> ";
        cin >> id;
        if (id == 0) { break; }

        aux = project->getListNivel()->getHead();
        while (aux != NULL)
        {
            if (aux->getArbolB()->getId() == id) {
                nivel = aux->getArbolB();
                id = 0;
                break;
            }
            aux = aux->getSiguiente();
        }
    } while (id != 0);

    if (nivel != NULL)
    {
        do
        {
            system("cls");
            cout << "   Nivel editando: " << nivel->getNombre() << endl;
            cout << " Objetos en el nivel:"<< endl;
            nivel->inOrden();
            cout << endl;
            cout << "1. Agregar objeto" << endl;
            cout << "2. Eliminar objeto" << endl;
            cout << "3. Eliminar pared" << endl;
            cout << "4. Copiar nivel1" << endl;
            cout << "5. Salir" << endl;
            cout << ">> ";
            cin >> id;
            switch (id)
            {
            case 1:
                break;
            case 2:
                cout << " Ingrese numero de objeto a eliminar:" << endl;
                cout << ">> ";
                cin >> id;
                nivel->delete_nodo(id);
                id = -1;
                break;
            case 3:
                eliminarPared(nivel);
                break;
            case 4:
                break;
            }


        } while (id != 5);
    }
}


void MainMenu::editarProyecto()
{
    int contador = 0;
    NodoAVL* nodoFound = nullptr;
    Project* project = NULL;
    do
    {
        system("cls");
        cout << "Lista de proyectos" << endl;
        treeAVL->inOrden();
        cout << endl;
        cout << "Ingrese el numero del proyecto a graficar" << endl;
        cout << "Ingrese 0 si desea salir" << endl;
        cout << ">> ";
        int id;
        cin >> id;

        if (id == 0)
        {
            break;
        }

        NodoAVL* nodoFound = treeAVL->buscarNodo(id);

        if (nodoFound != nullptr)
        {
            NodoSLB* headList = nodoFound->getProject()->getListNivel()->getHead();
            project = nodoFound->getProject();

            while (headList != NULL)
            {
                headList->getArbolB(); // sacar todos los nodos para graficar la matrix
                //cin >> id;
                headList = headList->getSiguiente();
            }
            contador = 0;
        }
        else
        {
            cout << "Numero no valido" << endl;
            cin >> id;
            contador = 1;
        }
    } while (contador != 0);


    if (project != NULL)
    {
        int entrada = 0;
        do
        {
            system("cls");
            cout << "1. Agregar nivel" << endl;
            cout << "2. Editar nivel" << endl;
            cout << "3. Eliminar nivel" << endl;
            cout << "4. Eliminar proyecto" << endl;
            cout << "5. Salir" << endl;
            cout << ">> ";
            cin >> entrada;

            switch (entrada)
            {
            case 1:
                agregarNiveles(project, readJson->leerNivel("prueba"));
                break;
            case 2:
                editarNivel(project);
                break;
            case 3:
                eliminarNivel(project);
                break;
            case 4:
                break;
            case 5:
                break;
            }


        } while (entrada != 5);

    }

}

void MainMenu::graficarProyectos()
{
    treeAVL->graficar();
    int contador = 0;
    do
    {
        system("cls");
        cout << "   GRAFICAR PROYECTOS  " << endl;
        cout << "Lista de proyectos" << endl;
        treeAVL->inOrden();
        cout << endl;
        cout << "Ingrese el numero del proyecto a graficar" << endl;
        cout << "Ingrese 0 si desea salir" << endl;
        cout << ">> ";
        int id;
        cin >> id;

        if (id == 0)
        {
            break;
        }

        NodoAVL* nodoFound = treeAVL->buscarNodo(id);

        if (nodoFound != nullptr)
        {
            NodoSLB* listNivel = nodoFound->getProject()->getListNivel()->getHead();
            //Recorriendo lista de proyectos (ABB)
            while (listNivel != NULL)
            {
                Matrix* matrix = new Matrix();
                NodoO* listObjetos = listNivel->getArbolB()->getListObjetos()->getHead();
                //Recorriendo lista de objetos del ABB
                while (listObjetos != NULL)
                {
                    //cout << "EFE " << listObjetos->getObjeto()->getName() << endl;
                    int id = listObjetos->getObjeto()->getId();
                    string nombre = listObjetos->getObjeto()->getName();
                    string letter = listObjetos->getObjeto()->getLetter();
                    string color = listObjetos->getObjeto()->getColor();

                    //cout << "EFE " << nombre << endl;
                    NodoP* puntos = listObjetos->getObjeto()->getList()->getHead();

                    while (puntos != NULL)
                    {
                        string x = puntos->getPoint().getX();
                        string y = puntos->getPoint().getY();
                        //cout << "EFE " <<2 x << endl;
                        matrix->add(id, nombre, letter, color, x, y);
                        puntos = puntos->getSiguiente();
                    }

                    matrix->setName(listNivel->getArbolB()->getNombre());
                    listObjetos = listObjetos->getSiguiente();
                }
                matrix->graficar();
                cin >> id;
                delete matrix;
                listNivel = listNivel->getSiguiente();
            }


            contador = 0;
        }
        else
        {
            cout << "Numero no valido" << endl;
            cin >> id;
            contador = 1;
        }
    } while (contador != 0);
}

//metodo privado para eliminar una pared recibe un nivel tipo ArbolB 
void MainMenu::eliminarPared(ArbolB* nivel)
{
    int id;
    SimpleListP* listTemp = new SimpleListP();;
    do
    {
        system("cls");
        cout << "   Eliminar Pared" << endl;
        cout << endl;
        cout << "1. Eliminar" << endl;
        cout << "2. Confirmar" << endl;
        cout << "3. Cancelar" << endl;
        cout << "4. Salir" << endl;
        cout << ">> ";
        cin >> id;
        switch (id)
        {
        case 1:
            bool bandera;
            bool regrosoAX;
            do
            {
                regrosoAX = true;
                string x = "";
                string y = "";
                cout << "   Ingrese coordenadas" << endl;
                cout << " Ingrese X:" << endl;
                cout << ">> ";
                cin >> x;
                if (isNum(x))
                {
                    bandera = false;
                }
                else
                {
                    cout << " Continuar y/n" << endl;
                    cout << ">> ";
                    string x;
                    cin >> x;
                    if (x == "y")
                    {
                        bandera = false;
                        regrosoAX = false;
                    }
                    else
                    {
                        bandera = true;
                    }
                }

                if (bandera == false && regrosoAX == true)
                {
                    cout << " Ingrese Y:" << endl;
                    cout << ">> ";
                    cin >> y;
                    if (isNum(y))
                    {
                        Point puntos = Point(x, y);
                        listTemp->add(puntos);
                        cout << " ---Coordenada agregada!---" << endl;
                    }
                    else
                    {
                        cout << " Continuar y/n" << endl;
                        cout << ">> ";
                        string x;
                        cin >> x;
                        if (x == "y")
                        {
                            bandera = false;
                        }
                        else
                        {
                            bandera = true;
                        }
                    }

                }


            } while (bandera != true);

            break;
        case 2:
            //Nodos de numeros ingresados
             NodoP* nodoPTemp;

            //Nodo de objetos de paredes, id por defecto de paredes -1
             NodoB* nodoNivel;
             if (listTemp != NULL)
             {
                 nodoPTemp = listTemp->getHead();
                 nodoNivel = nivel->buscarNodo(-1);
                 if (nodoNivel != nullptr)
                 {
                     //Lista de posiciones del objeto pared
                     SimpleListP* listOtemp = nodoNivel->getObjeto()->getList();

                     while (nodoPTemp != NULL)
                     {

                         if (listOtemp->delete_item(nodoPTemp->getPoint().getX(), nodoPTemp->getPoint().getY()))
                         {
                             cout << "Pared eliminada " << "X: " << nodoPTemp->getPoint().getX() << " Y: " << nodoPTemp->getPoint().getY() << endl;
                         }
                         else
                         {
                             cout << "Posición de pared no existe " << "X: " << nodoPTemp->getPoint().getX() << " Y: " << nodoPTemp->getPoint().getY() << endl;
                         }
                         nodoPTemp = nodoPTemp->getSiguiente();
                     }
                     string xx;
                     cin >> xx;
                 }
             }
            
            break;
        case 3:
            //cancela, no pasa nada 
            break;
        case 4:
            break;
        }


    } while (id != 4);
    delete listTemp;
}

bool MainMenu::isNum(string valor)
{
    char caracter;
    int value;
    for (int i = 0; i < valor.length(); i++)
    {
        caracter = valor[i];
        value = caracter;
        if (value >= 48 && value <= 57)
        {
            continue;
        }
        else
        {
            return false;
        }

    }
    //cout << "valor ascii: " << valor << endl;
    return true;
}