#include <iostream>
using namespace std;

void display(Node* head){
    while(head != nullptr){
        cout<<head->data<<"->";
        head = head -> next;
    }
    cout<<endl;
}

void push_front(Node* &head, int data){
    Node* nodo = new Node;
    nodo->data = data;
    nodo->next = head;
    head = nodo;
}

void invertir(Node* &head){
    Node* current = head;
    Node* prev = nullptr;
    Node* head_invertido = nullptr;
    while(current != nullptr){
        prev = current->next;
        current->next = head_invertido;
        head_invertido = current;
        current = prev;
    }
    head = head_invertido;
}

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