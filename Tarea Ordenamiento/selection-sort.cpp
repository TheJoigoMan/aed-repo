// Codigo para Selection Sort en C++
#include <iostream>
#include <chrono>
#include <conio.h>

using namespace std;
using namespace chrono;

////////////////////////////// Funciones del Algoritmo Selection Sort /////////////////////////////////////

///////////////// Funcion Swap ///////////////////
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
///////////////// Funcion selectionSort ///////////////////
void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
        if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
        // Swap the found minimum element with the first element 
        swap(&arr[min_idx], &arr[i]); 
    } 
} 

////////////////// Funciones de Utilidad y medicion ////////////////////

// Function to print an array //
void printArray(int arr[], int size) 
{ 
    cout << "[";
    for (int i=0; i < size; i++){
        cout << arr[i];
        if (i != size-1){
            cout << ", ";
        }
    }
    cout << "]" << endl << endl;
} 

// Codigo principal
int main()
{
    // Declaracion de variables
    int n; // Tamaño del array
    int count = 0; // Cuenta de operaciones
    char key; // Variable de tecla
        
    while(true){
        count++; // Aumentamos la cuenta
        // Solicitamos el valor de n
        cout << endl << "//////////////////// Operacion #" << count << " //////////////////////" << endl;
        cout << endl << "Ingrese el numero de elementos del array: ";
        cin >> n;

        int *arr = new int[n]; // Array

        // Obtenemos los valores aleatorios para el array
        for(int i=0; i<n; i++){
            arr[i]=rand()%1000; // Cambiar segun el rango de numeros deseado
        }

        // Mostramos la cantidad de elementos del array
        cout << endl << "El Array consta de " << n << " elementos." << endl;

        // Mostramos el array original
        if(n <= 100){
            cout << "El Array aleatorio es: \n";
            printArray(arr, n);
        }

        //Tomamos el tiempo de inicio de computacion
        auto start = high_resolution_clock::now();

        // Ejecutamos el algoritmo desde 0
        selectionSort(arr, n); 

        // Tomamos el tiempo final de computacion
        auto stop = high_resolution_clock::now();
        
        // Obtenemos el tiempo de computacion mediante resta
        auto duration = duration_cast<microseconds>(stop - start);
        
        // Resultados

        if(n <= 100){
            cout << "El Array resultante es: \n";
            printArray(arr, n); // Mostramos el array resultante
        }

        cout << "Tiempo total de computacion: " << duration.count() << " microsegundos." << endl << endl; // Mostramos la duracion total de computacion
        
        delete [] arr; // Liberamos memoria


        while(true){
            cout << "¿Desea reiniciar? (y/n)" << endl;
            key = getch();
            if(key == 'y'||key == 'Y'){
                break;
            } else if(key == 'n'||key == 'N'){
                return 1;
            } else {
                cout << "Entrada invalida, pruebe de nuevo." << endl << endl;
            }
        }
    }
    return 0;
}