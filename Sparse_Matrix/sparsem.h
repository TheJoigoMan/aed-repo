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
        };

        vector<Node*> rows;
        vector<Node*> cols;
        int n_cols;
        int n_rows;
   public:
      SparseMatrix(int nc, int nr) {
          //TODO: inicializar rows y cols en nullptr
      }     

      void set(int i, int j, T value){
          //TODO
          if(i < 0 || i >= n_rows || j < 0 || j >= n_cols) return;
          Node* head_row = this->rows[i];
          
          
      }

      void display_byrows(){
          //mostrar por fila
      }

      void display_bycols(){
          //mostrar por fila
      }  

      ~SparseMatrix(){
          //TODO
      }
};
