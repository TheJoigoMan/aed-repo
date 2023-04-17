#include <iostream>
#include "solucion.h"

void testSortedInsert()
{
    Node* head = nullptr;
    SortedInsert(head, 2);
    Display(head);//2
    SortedInsert(head, 5);
    Display(head);//2->5
    SortedInsert(head, 1);
    Display(head);//1->2->5
    SortedInsert(head, 10); 
    Display(head);//1->2->5->10
    SortedInsert(head, 4);
    Display(head);//1->2->4->5->10
}

void testIntersect(){
    Node* lista1 = nullptr;
    push_front(lista1, 7);
    push_front(lista1, 5);
    push_front(lista1, 3);
    push_front(lista1, 1);
    Display(lista1); // Chequear lista1

    Node* lista2 = nullptr;
    push_back(lista2, 2);
    push_back(lista2, 5);
    push_back(lista2, 6);
    push_back(lista2, 7);
    push_back(lista2, 9);
    Display(lista2); // Chequear lista2

    Node* lista3 = Intersect(lista1, lista2);//O(n)
    Display(lista3);//5->7
}

int main() 
{
    cout << "Sorted Insert: \n";
    testSortedInsert();
    cout << endl;

    cout << "Intersect Lists O(n): \n";
    testIntersect();

    return 0;
}
