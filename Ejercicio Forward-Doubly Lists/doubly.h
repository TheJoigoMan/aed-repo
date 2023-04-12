// Doubly Linked List
#include <iostream>
using namespace std;

template <typename T>
class DLList {
    private:
        struct Node {
            T data;
            Node* next;
            Node* prev;

            Node(){
                next = new Node();
                prev = new Node();
            }

            Node(T value){
                data = value;
            }

            void killSelf(){
                delete next;
                delete prev;
                delete this;
            }  
        };

    private:
        Node* head;
        Node* tail;
        int nodes;

    public:
        DLList() {
            head = tail = nullptr;
            nodes = 0;
        }

        ~DLList(){ 
         	clear();
            delete head;
            delete tail;
            delete this;
        }

        T front(){
            return head->data;
        }

        T back(){
            return tail->data;
        }

        void push_front(T data){
            Node *nodo = new Node(data);

            if (this->is_empty()){
                nodo->prev = nullptr;
                nodo->next = nullptr;
                tail = nodo;
            } else {
                head->prev = nodo;
                nodo->next = head;
            }

            head = nodo;
            nodes++;
        }

        void push_back(T data){
            if (this->is_empty())
                push_front(data);
            else {
                Node *nodo = new Node(data);
                nodo->next = nullptr;
                nodo->prev = tail;
                tail->next = nodo;
                tail = nodo;
            }
                nodes++;
        }

        /*
        T pop_front(){
            T data = front();
            if (size() == 1)
                delete head;
            else
            {
                Node *temp = head;
                head = head->next;
                delete temp;
            }

            nodes--;
            return data;
        }

        T pop_back(){
            T data = back();

            if (size() == 1)
                pop_front();
            else
            {
                Node<T> *temp = head;
                while (temp->next != tail)
                    temp = temp->next;

                tail = temp;
                tail->next = nullptr;
                delete temp;
            }

            nodes--;
            return data;
        }

        T insert(T data, int pos){
            if (pos == 0)
                push_front(data);
            else if (pos == size() - 1)
                push_back(data);
            else
            {
                Node *nodo = new Node(data);
                Node<T> *temp = head;

                for (int i = 0; i < pos - 1; ++i)
                    temp = temp->next;

                nodo->next = temp->next;
                temp->next = nodo;
                nodes++;
            }

            return data;
        }

        bool remove(int pos){
            throw ("sin definir");
        }

        T& operator[](int pos){
            Node<T> *tmp = head;
            for (int i = 0; i < pos; i++)
                tmp = tmp->next;
            return tmp->data;
        }
        
        void sort(){
            if (!this->is_empty() || this->nodes != 1){
                mergeSort(this->head,front,back);
                this->tail = this->head;
                while(this->tail->next!=nullptr){
                    this->tail = this->tail->next;
                }
            }
            Node<T> *temp_a = head;
            Node<T> *temp_b = nullptr;
            for (int i = 0; i < nodes; ++i)
            {
                // loop para comparar elementos del array
                for (int j = 0; j < nodes - i; ++j)
                {
                    // comparar 2 elementos adyacentes
                    if (temp_a->data > temp_a->next->data)
                    {
                        // swap si los elementos no están en el orden deseado
                        temp_b = temp_a;
                        temp_a = temp_a->next;
                        temp_a->next = temp_b;
                    }
                }
            }
        }

        bool is_sorted(){
            Node<T> *temp = head;
            while (temp->next->next != nullptr)
            {
                if (temp->data > temp->next->data)
                    return false;
                temp = temp->next;
            }
            return true;
        }

        void reverse(){
            throw ("sin definir");
        }
        */

        bool is_empty(){
            return head == nullptr;
        }

        int size(){
            return nodes;
        }

        void clear(){
            while (nodes > 1)
            {
                Node *temp = head;
                head = head->next;
                delete temp;
                nodes--;
            }
            head = nullptr;
        }

        bool isPalindrome(){
            if (this->is_empty())
                return true;
            
            Node* temp1 = head;
            Node* temp2 = tail;
            bool even1;
            bool even2;

            while(temp1!=nullptr && temp2!=nullptr){
                even1 = (temp1->data % 2 == 0);
                even2 = (temp2->data % 2 == 0);
                if(even1 != even2)
                    return false;
                temp1 = temp1->next;
                temp2 = temp2->prev;
            }
            return true;
        }

        void Display(){ // Función para mostrar las listas
            for(Node* temp = head; temp != nullptr; temp = temp->next)
                cout<<temp->data<<" -> ";
            cout << "NULL" << endl; 
        }

        std::string name(){
            return "DLList";
        }
};

/*
template <typename T>
DLList<T>* union_list(DLList<T>* l1, DLList<T>* l2){
    DLList<int> *l3 = new DLList<int>();

    while(l1 != nullptr){
        while(l1 != nullptr && l1->data >= l2->data){
            push_front(l3, l1->data);
            l1 = l1->next;
            //cout <<"l3: "; display(l3);
        }
        while(l1 != nullptr && l2 != nullptr && l2->data >= l1->data){
            push_front(l3, l2->data);
            l2 = l2->next;
            //cout <<"l3: "; display(l3);
        }
    }
    while(l2 != nullptr){
        push_front(l3, l2->data);
        l2 = l2->next;
        //cout <<"l3: "; display(l3);
    }

    return l3;
}
*/