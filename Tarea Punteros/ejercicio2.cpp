// Ejercicio 2 Punteros

#include "iostream"
#include "stdio.h"

using namespace std;

int main()
{
    //Codigo 1
    /*int* ptrVar;
    *ptrVar = 10;
    cout<<*ptrVar;*/

    // Este codigo  crea un puntero, pero no define a donde apunta, luego procede a darle un valor
    // a esa direccion desconocida, lo que provoca un error.

    //Codigo 2
    /*int*p, n = 15;
    *p = n;
    cout<<*p<< "\n";*/

    // Este codigo funciona perfectamente (faltaba una p)

    // Codigo 3
    int* array = new int[2];
    *array = 10;
    *(array + 1) = 15;
    array[2] = 20; 

    system("pause");

    return 0;
}