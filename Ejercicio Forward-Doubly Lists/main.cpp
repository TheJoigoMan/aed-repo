#include <iostream>
#include "forward_list.h"
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

void testDoubly() 
{
    DLList<int> *l1 = new DLList<int>();
    DLList<int> *l2 = new DLList<int>();
    l1->push_front(5);
    l1->push_front(4);
    l1->push_front(3);
    l1->push_front(2);
    l1->push_front(1);
    l1->Display(); // 1->2->3->4->5
    l2->push_front(5);
    l2->push_front(3);
    l2->push_front(3);
    l2->push_front(2);
    l2->push_front(1);
    l2->Display(); // 1->2->3->3->5

    string s;
    (l1->isPalindrome())? s="L1 es palindromo binario\n":s="L1 no es palindromo binario\n";
    cout<<s;
    (l2->isPalindrome())? s="L2 es palindromo binario\n":s="L2 no es palindromo binario\n";
    cout<<s;
}

int main() 
{
    cout << "Intersect Lists O(n): \n";
    testIntersect();

    cout << endl << "Palindrome check: \n";
    testDoubly() ;

    return 0;
}