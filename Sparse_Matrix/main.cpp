# include "sparsem.h"
using namespace std;

int main(){
    //primera parte
    SparseMatrix<int> matrix(6,12);
    matrix.set(2,6,3);
    matrix.set(2,11,8);
    matrix.set(1,8,3);
    matrix.set(1,4,8);
    matrix.set(3,1,2);
    matrix.set(4,8,5);
    matrix.set(4,3,7);
    matrix.set(5,4,8);
    matrix.set(5,10,8);
    matrix.display_byrows();
    cout<<endl;
    matrix.display_bycols();
    //segunda parte

}