// Solución Diego Villena
#include <iostream>
#include "forward_list.h"
using namespace std;

int main() 
{
    ForwardList<int>* lista1 = new ForwardList<int>();
    lista1->push_front(64);
    lista1->push_front(32);
    lista1->push_front(16);
    lista1->push_front(8);
    lista1->push_front(4);
    lista1->push_front(2);
    cout << "Lista: "; lista1->Display(); // Revisar lista1
    cout << "Mediana: " << lista1->mediana() << endl;; // Mostramos la mediana
    delete lista1;
    return 0;
}
