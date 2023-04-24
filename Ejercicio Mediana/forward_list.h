#ifndef FORWARD_H
#define FORWARD_H
#include <iostream>

// Forward list with simple node structure
template <typename T>
class ForwardList {
    private:
        struct Node {
            T data;
            Node* next;

            Node(){
                next = nullptr;
            }

            Node(T value){
                data = value;
                next = nullptr;
            }

            void killSelf(){
                delete next;
                delete this;
            }
        };

    private:
        Node* head;

    public:
        ForwardList(){
            head = nullptr;
        }

        ~ForwardList(){ 
         	clear();
            delete head;         
        }

        void push_front(T data){
            Node *nodo = new Node(data);
            nodo->next = head;
            head = nodo;
        }

        void clear(){
            if (head == nullptr)
                return;
            else {
                Node *temp = head;
                Node *current = head;
                while (temp->next != nullptr){
                    current = temp->next;
                    delete temp;
                    temp = current;
                }
                delete temp; // Corrección
                head = nullptr;
            }
        }

        std::string name(){
            return "ForwardList";
        }

        void Display(){ // Función para mostrar las listas
            for(Node* temp = head; temp != nullptr; temp = temp->next)
                std::cout<<temp->data<<" -> ";
            std::cout << "NULL" << std::endl; 
        }

        // SOLUCIÓN
        float mediana(){ // Asumimendo que son listas ordenadas ascendentes
            // Usamos la técnica de la tortuga y el conejo
            Node* tortuga = head;
            Node* conejo = head;
            // Tortuga avanza uno, conejo avanza 2
            while (conejo != nullptr && conejo->next != nullptr) {
                tortuga = tortuga->next;
                conejo = conejo->next->next;
            }
            // Si el conejo es nullptr, significa que la mediana se debe promediar
            if (conejo == nullptr) {
                return (tortuga->data + tortuga->next->data) / 2.0;
            } else {    // Si no, el conejo está en el último valor y la mediana es el valor de la tortuga
                return tortuga->data;
            }
        }
};

#endif