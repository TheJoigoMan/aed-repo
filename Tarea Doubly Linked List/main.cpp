#include <iostream>
#include "doubly.h"
using namespace std;

void testIntersect(){
    Node* lista1 = nullptr;
    push_front(lista1, 64);
    push_front(lista1, 32);
    push_front(lista1, 16);
    push_front(lista1, 8);
    push_front(lista1, 4);
    push_front(lista1, 2);
    Display(lista1); // Revisar lista1

    Node* lista2 = nullptr;
    push_back(lista2, 16);
    push_back(lista2, 32);
    push_back(lista2, 64);
    push_back(lista2, 128);
    push_back(lista2, 256);
    Display(lista2); // Revisar lista2

    Node* lista3 = Intersect(lista1, lista2); // O(n)
    Display(lista3); // 16 -> 32 -> 64 -> NULL
}

int main() 
{
    cout << "Intersect Lists O(n): \n";
    testIntersect();

    return 0;
}