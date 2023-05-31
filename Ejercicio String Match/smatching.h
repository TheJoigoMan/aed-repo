#include <iostream>
#include <vector>

using namespace std;

const string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 ";
int num_char = alfabeto.size();

int* buildPositions(string patron);

template <typename T>
void inocente(vector<T> &result, string Texto, string Patron){
    for( int j = 0; j < Texto.size()-Patron.size(); j++ ){
        int i = 0;
        while ( Patron[i] == Texto[i+j] && i<Patron.size() )
            i++;

        if ( i == Patron.size() )
            result.push_back(j);
    }
}

template <typename T>
void BoyerMoore(vector<T> &result, string Texto, string Patron){
    int n = Texto.size();
    int m = Patron.size();
    int *positions = buildPositions(Patron);
    
    for (int i = 0; i <= n-m; i++) {
        int j = m-1;
        while (j >= 0 && Patron[j] == Texto[i+j]) {
            j--;
        }
        
        if (j < 0) {
            result.push_back(i);
            i += (i + m < n)? m-positions[Texto[i + m]] : 1;
        } else {
            i += max(1, j - positions[Texto[i+j]]);
        }
    }
}

int* buildPositions(string patron){
    int *positions = new int[num_char];
    for ( int i = 0; i < num_char; i++ )
        positions[i] = -1;

    for ( int i = 0; i < patron.size(); i++ )
        positions[patron[i]] = i;
    
    return positions;
}