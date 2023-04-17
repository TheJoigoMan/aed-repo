// Solución Diego Villena
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void Display(Node* head){ // Función para mostrar las listas
    for(Node* temp = head; temp != nullptr; temp = temp->next)
        cout<<temp->data<<" -> ";
    cout << "NULL" << endl; 
}

void push_front(Node* &head, int data){ // Función Push Front
    Node* newNode = new Node; // Creamos un nodo
    newNode->data = data; // Asignamos su valor
    newNode->next = head; // Asignamos su next al valor actual de head
    head = newNode; // Asignamos head al nuevo nodo
}

void push_back(Node* &head, int data){ // Función Push Back
    Node* newNode = new Node; // Creamos un nodo
    newNode->data = data; // Asignamos su valor
    if (head == nullptr){ // Si su valor es null, añadimos directamente
        newNode->next = nullptr;
        head = newNode;
        return;
    }
    
    Node* temp = head; // Si la lista no está vacía, buscamos el final
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode; // Asignamos el next del último nodo al nuevo nodo
    newNode->next = nullptr; // Asignamos el next del nuevo nodo a null
}

void reverse(Node* &lista){ // Función reversora de lista
    Node* current = lista; // Creamos los nodos current, next y prev
    Node* next = nullptr;
    Node* prev = nullptr;
    while(current != nullptr){ // Mientras current no sea null
        next = current->next; // Next será el siguiente al actual
        current->next = prev; // El actual apunta al anterior, en el primer caso a null
        prev = current; // Prev ahora vale el actual
        current = next; // El actual ahora vale el siguiente
    }
    lista = prev; // Una vez terminado, asignamos el valor de prev al head
}

//// -------------------------------------------- ///

void SortedInsert(Node* &head, int data){ // Insertar nodos en orden
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

Node* Intersect(Node* lista1, Node* lista2){ // Intersectar nodos
    Node* head = nullptr; // Creamos la cabeza de la lista
    
    while (lista1 != nullptr && lista2 != nullptr){ // Mientras ninguno de los dos sea null
        if(lista1->data > lista2->data){ // Si lista1 es mayor a lista 2 aumenta lista 2
            lista2 = lista2->next;
        } else if (lista1->data < lista2->data){ // Si no, aumenta lista 1
            lista1 = lista1->next;
        } else { // Si no es ninguno, entonces son iguales y se añade un nuevo nodo a la nueva lista
            Node* temp = new Node; // Puntero Temporal
            temp->data = lista1->data; // Se define el valor del nuevo nodo, igual al de la intersección
            temp->next = head; // El next del nodo apunta al head
            head = temp; // Asignamos el head al nuevo nodo
            lista1 = lista1->next; // Ambas listas suben
            lista2 = lista2->next;
        }
    }
    reverse(head); // Llamamos a la función reversora
    return head; // Retornamos la nueva lista
}