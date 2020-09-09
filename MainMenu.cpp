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
                break;
            case 3:
                llenarArbolAVL(readJson->leerProyectos("prueba"));
                break;
            case 4:
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
}

void MainMenu::verProjectos()
{
    int contador = 0;

    do
    {
        system("cls");
        cout << "Lista de proyectos" << endl;
        treeAVL->inOrden();
        cout << endl;
        cout << "Ingrese el numero del proyecto a graficar" << endl;
        cout << ">> ";
        int id;
        cin >> id;

        NodoAVL* aux = treeAVL->buscarNodo(id);

        if (aux != nullptr)
        {
            NodoM* headList = aux->getProject()->getListNivel()->getHead();
        
            while (headList != NULL)
            {
                headList->getMatrix()->graficar();
                cin >> id;
                headList = headList->getSiguiente();
            }
        
        }
        else
        {
            cout << "Numero no valido" << endl;
            cin >> id;
            contador = 1;
        }
    } while (contador != 0);
    
}