#include <iostream>

using namespace std;

class Nodo
{
private:
    Nodo* next;
    Nodo* previous;
    Nodo* up;
    Nodo* down;

public:
    Nodo();
    void setNext(Nodo* next);
    void setPrevious(Nodo* Previous); 
    void setUp(Nodo* up);
    void setDown(Nodo* down);
    Nodo* getNext();
    Nodo* getUp();
    Nodo* getDown();
    Nodo* getPrevious();

};