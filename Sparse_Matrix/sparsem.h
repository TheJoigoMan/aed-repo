#include <iostream>
#include <vector>

using namespace std;

template <class T>
class SparseMatrix {
    private:
        struct Node {
            public:
                T data;
                int pos_row;
                int pos_col;
                Node* next_row;
                Node* next_col;

                Node()
                {
                    pos_col = pos_row = -1;
                    next_col = next_row = nullptr;
                }

                Node(int i, int j, T value)
                {
                    pos_row = i;
                    pos_col = j;
                    data = value;
                    next_col = next_row = nullptr;
                }
        };

        vector<Node*> rows;
        vector<Node*> cols;
        int n_cols;
        int n_rows;
    public:
        SparseMatrix(int nr, int nc) 
        {
            n_cols = nc;
            n_rows = nr;
            
            for(int c = 0; c < nc; c++)
                cols.push_back(nullptr);
            
            for(int r = 0; r < nr; r++)
                rows.push_back(nullptr);
        }     

        void set(int i, int j, T value)
        {
            if(i < 0 || i >= n_rows || j < 0 || j >= n_cols) return;
            Node* nuevo = new Node(i, j, value);   

            // 1- trabajo en filas    
            Node* ant = getPrevCol(i, j);
            if(ant == nullptr){
                nuevo->next_row = rows[i];
                rows[i] = nuevo;
            }
            else if(ant->pos_col == j)
            {
                ant->data = value;
                //delete nuevo;
            }
            else
            {
                nuevo->next_row = ant->next_row;
                ant->next_row = nuevo;
            }
   
            // 1- trabajo en columnas
            Node* ant_r = getPrevRow(i, j);
            if(ant_r == nullptr){
                nuevo->next_col = cols[j];
                cols[j] = nuevo;
            }
            else if(ant_r->pos_row == i)
            {
                ant_r->data = value;
                //delete nuevo;
            }
            else
            {
                nuevo->next_col = ant_r->next_col;
                ant_r->next_col = nuevo;
            }
        }

        void display_byrows()
        {
            for(int i=0;i<n_rows;i++)
            {
                cout<<i<<":: ";
                Node* temp = rows[i];
                while(temp != nullptr) 
                {
                    cout<<"("<<temp->pos_row<<","<<temp->pos_col<<","<<temp->data<<") ->";
                    temp = temp->next_row;
                }
                cout<<endl;
            }
        }

        void display_bycols(){
            for(int i=0; i<n_cols; i++)
                cout << i << "      ";
            cout << endl;
            
            for(int i=0; i<n_cols; i++)
            {
                cout << i << ":: ";
                Node* temp = cols[i];
                while(temp != nullptr)
                {
                    cout << "("<<temp->pos_row<<","<<temp->pos_col<<","<<temp->data<<") ->";
                    temp = temp->next_col;
                }
                cout << endl;
            }
        }  

    private:
        Node *getPrevCol(int i, int j)
        {
            Node *ant = nullptr;
            Node *temp = rows[i];

            while( temp != nullptr && j > temp->pos_col )
            {
                ant = temp;
                temp = temp->next_row;
            }
            return ant;
        }

        Node *getPrevRow(int i, int j)
        {
            Node *ant = nullptr;
            Node *temp = cols[j];

            while( temp != nullptr && i > temp->pos_row )
            {
                ant = temp;
                temp = temp->next_col;
            }
            return ant;
        }
};