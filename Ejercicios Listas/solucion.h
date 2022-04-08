// Solución Diego Villena
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void Display(Node* head){
    for(Node* temp = head; temp != nullptr; temp = temp->next)
        cout<<temp->data<<" -> ";
    cout << "NULL" << endl; 
}

void push_front(Node* &head, int data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void push_back(Node* &head, int data){
    Node* newNode = new Node;
    newNode->data = data;
    if (head == nullptr){
        newNode->next = nullptr;
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = nullptr;
}

Node* reverse(Node* &lista){ //Funcion reversora de lista
    Node* current = lista;
    Node* next = nullptr;
    Node* prev = nullptr;
    while(current != nullptr){
        next = current->next; 
        current->next = prev;
        prev = current;
        current = next;
    }
    lista = prev;
    return lista;
}

//// -------------------------------------------- ///

void SortedInsert(Node* &head, int data){
    Node *newNode = new Node; // Declaramos

    // En caso de ser solo head o ser el head mayor
    if (head == nullptr){
        newNode->next = head; // El next será la cabeza
        head = newNode; // La cabeza ahora es newNode
        newNode->data = data; // Asignamos el valor
        return; // Sale de la función
    } else if (head->data >= data){
        newNode->next = head; // El next será la cabeza
        head = newNode; // La cabeza ahora es newNode
        newNode->data = data; // Asignamos el valor
        return; // Sale
    }
 
    // Encontrar la posición correcta para el nodo
    Node* temp = head; // Puntero temporal
    while (temp->next != nullptr && temp->next->data < data) { // Mientras el valor de next no sea nullptr y el valor de next no sea menor a la nueva data
        temp = temp->next; // Si es valido el temp apunta al next
    }
    
    newNode->next = temp->next; // Asignamos el next a newNode
    temp->next = newNode; // El next de temp ahora apunta a newNode
    newNode->data = data; // Asignamos el valor
}

Node* Intersect(Node* lista1, Node* lista2){
    Node* head = nullptr; // Creamos la cabeza de la lista
    
    while (lista1 != nullptr && lista2 != nullptr){
        if(lista1->data > lista2->data){
            lista2 = lista2->next;
        } else if (lista1->data < lista2->data){
            lista1 = lista1->next;
        } else {
            Node* temp = new Node; // Puntero Temporal
            temp->data = lista1->data;
            temp->next = head;
            head = temp;
            lista1 = lista1->next;
            lista2 = lista2->next;
        }
    }
    head = reverse(head);
    return head;
}