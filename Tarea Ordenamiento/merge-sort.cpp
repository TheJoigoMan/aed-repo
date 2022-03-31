// Codigo para Merge Sort en C++
#include <iostream>
#include <chrono>
#include <conio.h>

using namespace std;
using namespace chrono;

////////////////////////////// Funciones del Algoritmo Merge Sort /////////////////////////////////////

///////////////// Funcion Merge ///////////////////
//.         array.    ,     izquierda  ,     mitad    , derecha
void merge(int array[], int const left, int const mid, int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    // Create temp arrays
    int *leftArray = new int[subArrayOne],
            *rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    int indexOfSubArrayOne = 0, // Initial index of first sub-array
    indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

///////////////// Funcion MergeSort ///////////////////
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
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
        mergeSort(arr, 0, n - 1);

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
                cout << "Entrada invalida, pruebe de nuevo." << endl;
            }
        }
    }
    return 0;
}