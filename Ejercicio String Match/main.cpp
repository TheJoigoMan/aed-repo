#include <iostream>
#include <chrono>
#include <ctime>
#include <unistd.h>
#include "smatching.h"
#include <cmath>
#include <vector>

using namespace std;

string generarTexto(size_t N){    
	string resultado = "";
	for (size_t i = 0; i < N; i++)
		resultado += alfabeto[rand() %  alfabeto.size()];
	return resultado;
}

void testInocente(string Texto, string Patron)
{    
	auto start = std::chrono::steady_clock::now();

	//execute the algorithm
	vector<int> result;

	inocente(result, Texto, Patron);

	auto end = std::chrono::steady_clock::now();
	//show the elapsed time
	cout << "Elapsed time in milliseconds: "
		<< chrono::duration_cast<chrono::microseconds>(end - start).count()
		<< " ms" << endl;
}

void testBoyerMoore(string Texto, string Patron)
{    
	auto start = std::chrono::steady_clock::now();

	//execute the algorithm
	vector<int> result;
	
	BoyerMoore(result, Texto, Patron);

	auto end = std::chrono::steady_clock::now();
	//show the elapsed time
	cout << "Elapsed time in milliseconds: "
		<< chrono::duration_cast<chrono::microseconds>(end - start).count()
		<< " ms" << endl;
}

int main()
{    
	srand(time(NULL));
	for(size_t i=2;i<=7;i++) {
		size_t N = pow(10, i);
		int m = 10;
		string Texto = generarTexto(N);
		string Patron = generarTexto(m);   
		cout<<"-- N="<<N<<endl; 
		testInocente(Texto, Patron);
		testBoyerMoore(Texto, Patron);
		cout<<endl;
	}
	return 0;
}