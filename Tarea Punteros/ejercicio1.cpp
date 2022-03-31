// Ejercicio 1 Punteros

#include "iostream"
#include "stdio.h"

using namespace std;

int main()
{
    int a; //Ingresar Valor de A
    cout << "Ingrese Valor de a: ";
    cin >> a;

    int * ptr = &a; //Guarda la direccion de a

    cout << "Valor de a: " << a << "\n";
    cout << "Valor de &a (direccion): " << ptr << "\n";
    cout << "Valor de &ptr (direccion): " << &ptr << "\n";

    system("pause"); // Pausa

    return 0;
}