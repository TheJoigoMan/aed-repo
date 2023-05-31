#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <unistd.h>
#include <cmath>

using namespace std;

string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
int num_char = alfabeto.size();

string generarTexto(int N){
    string texto = "";    
    for(int i=0;i<N;i++)
        texto += alfabeto[rand() % num_char];
    return texto;
}

void testIntuitivo(string texto, string patron)
{
    auto start = std::chrono::steady_clock::now();
    vector<int> result;

    for( int j = 0; j < texto.size()-patron.size(); j++ )
    {
        int i = 0;
        while( patron[i] == texto[i+j] && i<patron.size() )
            i++;

        if ( i == patron.size() )
            result.push_back(j);
    }
    /*
    for ( int k = 0; k<result.size(); k++ )
        cout << result[k] << ", ";
    cout << endl;
    */
    auto end = std::chrono::steady_clock::now();
    cout<< "Intuitivo "<<chrono::duration_cast<chrono::microseconds>(end-start).count()<<endl;
}

int* buildPositions( string patron )
{
    int *positions = new int[num_char];
    for ( int i = 0; i < num_char; i++ )
        positions[i] = -1;

    for ( int i = 0; i < patron.size(); i++ )
        positions[patron[i]] = i;
    
    return positions;
}

void testBoyerMoore(string texto, string patron)
{
    auto start = std::chrono::steady_clock::now();
    
    int n = texto.size();
    int m = patron.size();
    int *positions = buildPositions(patron);
    vector<int> result;

    for ( int i = 0; i < n-m; i++ )//corregir
    {
        int j = m-1;
        while ( j >= 0 && patron[j] == texto[i+j] )
            j--;
        
        if ( j < 0 ) // corregir
            i += (i + m < n)? m-positions[texto[i + m]] : 1;//hay mas casos
        else
        {
            result.push_back(i);
            i = i + m;
        }
    }
    auto end = std::chrono::steady_clock::now();
    cout<< "Boyer-Moore "<<chrono::duration_cast<chrono::microseconds>(end-start).count()<<endl;
}

int main()
{
    srand(time(NULL));
    for(int i=2;i<=6;i++){
        int N = pow(10, i);
        string texto = generarTexto(N);
        string patron = generarTexto(10);   
        cout<<"-- N="<<N<<endl; 
        testIntuitivo(texto, patron);//0,10
        testBoyerMoore(texto, patron);//0,10
        cout<<endl;
    }
}