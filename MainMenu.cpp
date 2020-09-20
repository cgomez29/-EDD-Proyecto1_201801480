#include "MainMenu.h"


MainMenu::MainMenu()
{
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
            cout << "7. Reportes" << endl;
            cout << "8. salir" << endl;
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
                guardarProyectos();
                break;
            case 6:
                llenarArbolB(readJson->leerLibrerias("preuba"));
                break;
            case 7:
                reportes();
                break;
            }



        } while (entrada != 8);
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

//Metodo para llenar el arbolAVL de proyectos
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
            //graficando nivel para saber los puntos a eliminar
            graficarNivel(nivel);
            cout << "1. Agregar objeto" << endl;
            cout << "2. Eliminar objeto" << endl;
            cout << "3. Eliminar pared" << endl;
            cout << "4. Salir" << endl;
            cout << ">> ";
            cin >> id;
            switch (id)
            {
            case 1:
                //metodo para agregar objeto
                agregarObjeto();
                break;
            case 2:
                eliminarObjeto(nivel);
                id = -1;
                break;
            case 3:
                eliminarPared(nivel);
                break;
            }


        } while (id != 4);
    }
}

void MainMenu::graficarNivel(ArbolB* nivel)
{
    Matrix* matrix = new Matrix();
    NodoO* listObjetos = nivel->getListObjetos()->getHead();
    //Recorriendo lista de objetos del ABB
    while (listObjetos != NULL)
    {
        //cout << "EFE " << listObjetos->getObjeto()->getName() << endl;
        int id = listObjetos->getObjeto()->getId();
        string nombre = listObjetos->getObjeto()->getName();
        string letter = listObjetos->getObjeto()->getLetter();
        string color = listObjetos->getObjeto()->getColor();

        NodoP* puntos = listObjetos->getObjeto()->getList()->getHead();

        while (puntos != NULL)
        {
            string x = puntos->getPoint().getX();
            string y = puntos->getPoint().getY();
            matrix->add(id, nombre, letter, color, x, y);
            puntos = puntos->getSiguiente();
        }

        matrix->setName(nivel->getNombre());
        listObjetos = listObjetos->getSiguiente();
    }
    matrix->graficar();
    delete matrix;
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
        int id = -1;
        try
        {
            cin >> id;

        }
        catch (const std::exception&)
        {
            id = -1;
        }
        
        if (id == 0)
        {
            break;
        }

        string nombre = "";
        // Redundante, pero para lograr solo colocar el numero y buscarlo se necesito de una lista
        NodoProject* pro = treeAVL->getListProyectos()->getHead();
        while (pro != NULL)
        {
            if (pro->getProject()->getId() == id)
            {
                nombre = pro->getProject()->getName();
            }
            pro = pro->getSiguiente();
        }

        NodoAVL* nodoFound = treeAVL->buscarNodo(nombre);

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
            cout << "5. Copiar nivel" << endl;
            cout << "6. Salir" << endl;
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
                copiarNivel(project);
                break;
            case 6:
                break;
            }


        } while (entrada != 6);

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
        int id = -1;
        try
        {
            cin >> id;

        }
        catch (const std::exception&)
        {
            id = -1;
        }

        if (id == 0)
        {
            break;
        }

        string nombre = "";
        // Redundante, pero para lograr solo colocar el numero y buscarlo se necesito de una lista
        NodoProject* pro = treeAVL->getListProyectos()->getHead();
        while (pro != NULL)
        {
            if (pro->getProject()->getId() == id)
            {
                nombre = pro->getProject()->getName();
            }
            pro = pro->getSiguiente();
        }

        NodoAVL* nodoFound = treeAVL->buscarNodo(nombre);

        if (nodoFound != nullptr)
        {
            
            NodoSLB* listNivel = nodoFound->getProject()->getListNivel()->getHead();
            //Recorriendo lista de proyectos (ABB)
            while (listNivel != NULL)
            {
                Matrix* matrix = new Matrix();
                NodoO* listObjetos = listNivel->getArbolB()->getListObjetos()->getHead();
                listNivel->getArbolB()->graficar();
                //Recorriendo lista de objetos del ABB
                while (listObjetos != NULL)
                {
                    //cout << "EFE " << listObjetos->getObjeto()->getName() << endl;
                    int id = listObjetos->getObjeto()->getId();
                    string nombre = listObjetos->getObjeto()->getName();
                    string letter = listObjetos->getObjeto()->getLetter();
                    string color = listObjetos->getObjeto()->getColor();

                    NodoP* puntos = listObjetos->getObjeto()->getList()->getHead();

                    while (puntos != NULL)
                    {
                        string x = puntos->getPoint().getX();
                        string y = puntos->getPoint().getY();
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


            contador = 1;
        }
        else
        {
            cout << "Numero no valido" << endl;
            cin >> id;
            contador = 1;
        }
    } while (contador != 0);
}

//Metodo para agregar un objeto
void MainMenu::agregarObjeto()
{
    cout << "   Agregar objeto" << endl;
    cout << "Lista de objetos en librerias externa" << endl;
    treeB->inOrden();
    cout << endl;
    int x;

    try
    {
        cin >> x;
    }
    catch (const std::exception&)
    {
        x = -1;
    }

}

void MainMenu::copiarNivel(Project* project)
{
    NodoSLB* aux = project->getListNivel()->getHead();
    int id;
    int id2;
    ArbolB* head1 = NULL;
    ArbolB* head2 = NULL;

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
        cout << "Ingrese el numero del nivel a copiar" << endl;
        cout << "Ingrese 0 si desea salir" << endl;
        cout << ">> ";
        cin >> id;
        if (id == 0) { break; }
        
        bool numExiste = false;
        bool numExiste2 = false;
        aux = project->getListNivel()->getHead();
        while (aux != NULL)
        {
            if (aux->getArbolB()->getId() == id)
            {
                head1 = aux->getArbolB();
                numExiste = true;
                break;
            }
            aux = aux->getSiguiente();
        }

        if (numExiste)
        { 
            cout << "Ingrese el numero del nivel destino: " << endl;
            cout << ">> ";
            cin >> id2;
            aux = project->getListNivel()->getHead();
            while (aux != NULL)
            {
                if (aux->getArbolB()->getId() == id2)
                {
                    head2 = aux->getArbolB(); 
                    numExiste2 = true;
                    break;
                }
                aux = aux->getSiguiente();
            }

            if (numExiste2)
            {
                head2->Delete();
                head2->setRaizNull();
                //Lista de objeto origen para incertara arbol (nivel) destino
                NodoO* nodoO = head1->getListObjetos()->getHead();

                while (nodoO != NULL)
                {
                    Objeto* obj = nodoO->getObjeto();
                    NodoP* list1 = obj->getList()->getHead();
                    SimpleListP* newList = new SimpleListP();

                    while (list1 != NULL)
                    {
                        Point pnew = Point(list1->getPoint().getX(), list1->getPoint().getY());
                        newList->add(pnew);
                        list1 = list1->getSiguiente();
                    }
                    Objeto* newObj = new Objeto(obj->getId(), obj->getName(), obj->getLetter(), obj->getColor(), newList);
                    newObj->setId2(obj->getId2());

                    head2->insert(newObj);
                    nodoO = nodoO->getSiguiente();
                }

                int xsd;
                system("cls");
                cout << "Copia realizada!!" << endl;
                cout << "Presione un numero para continuar.." << endl;
                cout << ">>";
                cin >> xsd;
                id = 0;
               

            }
            else
            {
                cout << "Nivel no existe: " << id << endl;
                cout << "Presione un numero para continuar.." << endl;
                int xsd;
                cin >> xsd;
                id = 1;
            }
        }
        else {
            cout << "Nivel no existe: " << id << endl;
            cout << "Presione un numero para continuar.." << endl;
            int xsd;
            cin >> xsd;
            id = 1;
        }

    } while (id != 0);
}

//metodo privado para eliminar un objeto de un nivel de tipoArbolB
void MainMenu::eliminarObjeto(ArbolB* nivel)
{
    system("cls");
    nivel->inOrden();
    cout << endl;
    cout << " Ingrese numero de objeto a eliminar:" << endl;
    cout << ">> ";
    int id;
    cin >> id;
    NodoO* auxO;
    auxO = nivel->getListObjetos()->getHead();
    bool isdelete;
    isdelete = false;
    while (auxO != NULL)
    {
        if (auxO->getObjeto()->getId2() == id) {
            nivel->delete_nodo(id);
            isdelete = true;
        }
        auxO = auxO->getSiguiente();
    }
    if (!isdelete)
    {
        cout << " Objeto eliminado" << endl;
        int cds;
        cin >> cds;
    }
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

void MainMenu::guardarProyectos()
{
    // se envia la lista de proyectos
    readJson->guardarProyecto(treeAVL->getListProyectos()->getHead());
}


void MainMenu::reportes()
{
    string entrada = "";
    int en = 0;
    do
    {
        system("cls");
        cout << "     REPORTES" << endl;
        cout << "1. Proyectos con mayor numero de niveles (descendente)" << endl;
        cout << "2. Proyectos con mayor numero de niveles (ascendente)" << endl;
        cout << "3. En un proyecto.." << endl;
        cout << "4. Salir" << endl;
        cout << ">> ";
        cin >> entrada;
        
        if (valorAscii(entrada))
        {
            en = stoi(entrada);
            switch (en)
            {
            case 1:
                //nivelDesc();
                break;
            case 2:
                //nivelAsc();
                break;
            case 3:
                reportInPorject();
                break;
            }
        }
        else
        {
            en = -1;
        }
    } while (en != 4);
}

void MainMenu::reportInPorject()
{
    int contador = 0;
    NodoAVL* nodoFound = nullptr;
    do
    {
        system("cls");
        cout << "Lista de proyectos" << endl;
        treeAVL->inOrden();
        cout << endl;
        cout << "Ingrese el numero del proyecto" << endl;
        cout << "Ingrese 0 si desea salir" << endl;
        cout << ">> ";
        int id = -1;
        try
        {
            cin >> id;

        }
        catch (const std::exception&)
        {
            id = -1;
        }

        if (id == 0)
        {
            break;
        }

        string nombre = "";
        // Redundante, pero para lograr solo colocar el numero y buscarlo se necesito de una lista
        NodoProject* pro = treeAVL->getListProyectos()->getHead();
        while (pro != NULL)
        {
            if (pro->getProject()->getId() == id)
            {
                nombre = pro->getProject()->getName();
            }
            pro = pro->getSiguiente();
        }

        NodoAVL* nodoFound = treeAVL->buscarNodo(nombre);

        if (nodoFound != nullptr)
        {
            int paredeNew;
            int windowNew;
            NodoSLB* listNivel;
            int paredeOld;
            int windowOld;
            ArbolB* treeBGrap;
            string entrada = "";
            int en = 0;
            do
            {
                system("cls");
                cout << "  Proyecto: " << nodoFound->getProject()->getName() << endl;
                cout << "1. Nivel con mas espacio" << endl;
                cout << "2. Nivel con menos paredes" << endl;
                cout << "3. Nivel con mas paredes" << endl;
                cout << "4. Nivel con mas espacio y mas ventanas" << endl;
                cout << "5. Nivel con mas espacio y menos ventanas" << endl;
                cout << "6. Salir" << endl;
                cout << ">> ";
                cin >> entrada;

                if (valorAscii(entrada))
                {
                    en = stoi(entrada);
                    switch (en)
                    {
                    case 1:
                        paredeNew = 0;
                        treeBGrap = nullptr;
                        paredeOld = 0;
                        listNivel = nodoFound->getProject()->getListNivel()->getHead();
                        //Recorriendo lista de proyectos (ABB)

                        while (listNivel != NULL)
                        {
                            paredeNew = 0;
                            Matrix* matrix = new Matrix();
                            NodoO* listObjetos = listNivel->getArbolB()->getListObjetos()->getHead();
                            //listNivel->getArbolB()->graficar();
                            //Recorriendo lista de objetos del ABB
                            while (listObjetos != NULL)
                            {
                                //cout << "EFE " << listObjetos->getObjeto()->getName() << endl;
                                int id = listObjetos->getObjeto()->getId();
                                string nombre = listObjetos->getObjeto()->getName();
                                string letter = listObjetos->getObjeto()->getLetter();
                                string color = listObjetos->getObjeto()->getColor();

                                NodoP* puntos = listObjetos->getObjeto()->getList()->getHead();

                                while (puntos != NULL)
                                {
                                    string x = puntos->getPoint().getX();
                                    string y = puntos->getPoint().getY();
                                    matrix->add(id, nombre, letter, color, x, y);
                                    puntos = puntos->getSiguiente();
                                }

                                matrix->setName(listNivel->getArbolB()->getNombre());
                                listObjetos = listObjetos->getSiguiente();
                            }
                            matrix->setPointEmpty();
                            paredeNew = matrix->getCoutEspacio();

                            if (paredeNew >= paredeOld)
                            {
                                paredeOld = paredeNew;
                                treeBGrap = listNivel->getArbolB();
                            }
                            listNivel = listNivel->getSiguiente();
                        }
                        if (treeBGrap != nullptr)
                        {
                            graficarNivel(treeBGrap);
                        }

                        break;
                    case 2:

                        paredeNew = 0;
                        treeBGrap = nullptr;
                        paredeOld = 50000;
                        listNivel = nodoFound->getProject()->getListNivel()->getHead();
                        //Recorriendo lista de proyectos (ABB)
                        while (listNivel != NULL)
                        {
                            paredeNew = 0;
                            NodoO* listObjetos = listNivel->getArbolB()->getListObjetos()->getHead();
                            //Recorriendo lista de objetos del ABB
                            while (listObjetos != NULL)
                            {
                                NodoP* puntos = listObjetos->getObjeto()->getList()->getHead();

                                while (puntos != NULL)
                                {
                                    if (listObjetos->getObjeto()->getId() == -1)
                                    {
                                        paredeNew++;
                                    }

                                    puntos = puntos->getSiguiente();
                                }

                                if (listObjetos->getObjeto()->getId() == -1)
                                {
                                    if (paredeNew <= paredeOld)
                                    {
                                        paredeOld = paredeNew;
                                        treeBGrap = listNivel->getArbolB();
                                    }
                                }
                                listObjetos = listObjetos->getSiguiente();
                            }
                            //matrix->graficar();
                            listNivel = listNivel->getSiguiente();
                        }

                        if (treeBGrap != nullptr)
                        {
                            graficarNivel(treeBGrap);
                        }
                        break;
                    case 3:
                        paredeNew = 0;
                        treeBGrap = nullptr;
                        paredeOld = 0;
                        listNivel = nodoFound->getProject()->getListNivel()->getHead();
                        //Recorriendo lista de proyectos (ABB)
                        while (listNivel != NULL)
                        {
                            paredeNew = 0;
                            NodoO* listObjetos = listNivel->getArbolB()->getListObjetos()->getHead();
                            //Recorriendo lista de objetos del ABB
                            while (listObjetos != NULL)
                            {
                                NodoP* puntos = listObjetos->getObjeto()->getList()->getHead();

                                while (puntos != NULL)
                                {
                                    if (listObjetos->getObjeto()->getId() == -1)
                                    {
                                        paredeNew++;
                                    }

                                    puntos = puntos->getSiguiente();
                                }

                                if (listObjetos->getObjeto()->getId() == -1)
                                {
                                    if (paredeNew >= paredeOld)
                                    {
                                        paredeOld = paredeNew;
                                        treeBGrap = listNivel->getArbolB();
                                    }
                                }
                                listObjetos = listObjetos->getSiguiente();
                            }
                            //matrix->graficar();
                            listNivel = listNivel->getSiguiente();
                        }

                        if (treeBGrap != nullptr)
                        {
                            graficarNivel(treeBGrap);
                        }
                        break;
                    case 4:
                        paredeNew = 0;
                        treeBGrap = nullptr;
                        paredeOld = 0;
                        windowOld = 0;
                        windowNew = 0;
                        listNivel = nodoFound->getProject()->getListNivel()->getHead();
                        //Recorriendo lista de proyectos (ABB)

                        while (listNivel != NULL)
                        {
                            windowNew = 0;
                            Matrix* matrix = new Matrix();
                            NodoO* listObjetos = listNivel->getArbolB()->getListObjetos()->getHead();
                            //listNivel->getArbolB()->graficar();
                            //Recorriendo lista de objetos del ABB
                            while (listObjetos != NULL)
                            {
                                //cout << "EFE " << listObjetos->getObjeto()->getName() << endl;
                                int id = listObjetos->getObjeto()->getId();
                                string nombre = listObjetos->getObjeto()->getName();
                                string letter = listObjetos->getObjeto()->getLetter();
                                string color = listObjetos->getObjeto()->getColor();

                                NodoP* puntos = listObjetos->getObjeto()->getList()->getHead();

                                while (puntos != NULL)
                                {
                                    if (listObjetos->getObjeto()->getId() == -2)
                                    {
                                        windowNew++;
                                    }
                                    string x = puntos->getPoint().getX();
                                    string y = puntos->getPoint().getY();
                                    matrix->add(id, nombre, letter, color, x, y);
                                    puntos = puntos->getSiguiente();
                                }


                                if (listObjetos->getObjeto()->getId() == -2)
                                {
                                    if (windowNew >= windowOld)
                                    {
                                        windowOld = windowNew;
                                    }
                                }
                                matrix->setName(listNivel->getArbolB()->getNombre());
                                listObjetos = listObjetos->getSiguiente();
                            }
                            matrix->setPointEmpty();
                            paredeNew = matrix->getCoutEspacio();

                            if (paredeNew >= paredeOld && windowNew >= windowOld)
                            {
                                paredeOld = paredeNew;
                                treeBGrap = listNivel->getArbolB();
                            }
                            listNivel = listNivel->getSiguiente();
                        }
                        if (treeBGrap != nullptr)
                        {
                            graficarNivel(treeBGrap);
                        }


                        break;
                    case 5:

                        paredeNew = 0;
                        treeBGrap = nullptr;
                        paredeOld = 0;
                        windowOld = 50000;
                        windowNew = 0;
                        listNivel = nodoFound->getProject()->getListNivel()->getHead();
                        //Recorriendo lista de proyectos (ABB)

                        while (listNivel != NULL)
                        {
                            windowNew = 0;
                            Matrix* matrix = new Matrix();
                            NodoO* listObjetos = listNivel->getArbolB()->getListObjetos()->getHead();
                            //listNivel->getArbolB()->graficar();
                            //Recorriendo lista de objetos del ABB
                            while (listObjetos != NULL)
                            {
                                //cout << "EFE " << listObjetos->getObjeto()->getName() << endl;
                                int id = listObjetos->getObjeto()->getId();
                                string nombre = listObjetos->getObjeto()->getName();
                                string letter = listObjetos->getObjeto()->getLetter();
                                string color = listObjetos->getObjeto()->getColor();

                                NodoP* puntos = listObjetos->getObjeto()->getList()->getHead();

                                while (puntos != NULL)
                                {
                                    if (listObjetos->getObjeto()->getId() == -2)
                                    {
                                        windowNew++;
                                    }
                                    string x = puntos->getPoint().getX();
                                    string y = puntos->getPoint().getY();
                                    matrix->add(id, nombre, letter, color, x, y);
                                    puntos = puntos->getSiguiente();
                                }


                                if (listObjetos->getObjeto()->getId() == -2)
                                {
                                    cout << "weDNEW : " << windowNew;
                                    cout << "weDOLD : " << windowOld;
                                    int xsd;
                                    cin >> xsd;
                                    if (windowNew <= windowOld)
                                    {
                                        windowOld = windowNew;
                                    }
                                }
                                matrix->setName(listNivel->getArbolB()->getNombre());
                                listObjetos = listObjetos->getSiguiente();
                            }
                            matrix->setPointEmpty();
                            paredeNew = matrix->getCoutEspacio();

                            if (paredeNew >= paredeOld && windowNew <= windowOld)
                            {
                                paredeOld = paredeNew;
                                treeBGrap = listNivel->getArbolB();
                            }
                            listNivel = listNivel->getSiguiente();
                        }
                   
                        if (treeBGrap != nullptr)
                        {
                            graficarNivel(treeBGrap);
                        }



                        break;
                    }
                }
                else
                {
                    en = -1;
                }
            } while (en != 6);


        }
        else
        {
            cout << "Numero no valido" << endl;
            cin >> id;
            contador = 1;
        }
    } while (contador != 0);
   
}

void MainMenu::nivelDesc()
{
    int contador;
    NodoProject* project = treeAVL->getListProyectos()->getHead();
    while (project != NULL)
    {
        contador = 0;
        //Nodo Simple List de arbol binario
        NodoSLB* niveles = project->getProject()->getListNivel()->getHead();
        while (niveles != NULL)
        {
            contador++;
            niveles = niveles->getSiguiente();
        }

        project->getProject()->setCantNivel(contador);
        project = project->getSiguiente();
    }
}

void MainMenu::nivelAsc()
{
    int contador;
    int coutProject = 0;

    NodoProject* project = treeAVL->getListProyectos()->getHead();
    while (project != NULL)
    {
        contador = 0;
        //Nodo Simple List de arbol binario
        NodoSLB* niveles = project->getProject()->getListNivel()->getHead();
        while (niveles != NULL)
        {
            contador++;
            niveles = niveles->getSiguiente();
        }

        coutProject++;
        project->getProject()->setCantNivel(contador);
        project = project->getSiguiente();
    }

}

bool MainMenu::valorAscii(string cadena)
{
    int valor = 0;
    char caracter;
    for (int i = 0; i <= cadena.length(); i++)
    {
        caracter = cadena[i];
        valor = valor + caracter;
    }

    if ((valor >= 48 && valor <= 57))
    {
        return true;
    }
    else
    {
        return false;
    }
}
