/*
    Implementación del iterador de un array circular
*/
#include <iostream>
#include "circularArray.h"

using namespace std;

int main()
{
    CircularArray<int> arr(5); 

    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(6);
    arr.push_front(10);
    //arr.push_front(12);
    //arr.display(); // 12,10,2,4,6

    // Declaring iterator to a vector
    CircularArray<int>::iterator ptr;
    // Displaying vector elements using begin() and end()
    for (ptr = arr.begin(); ptr != arr.end(); ++ptr)
        cout << *ptr << "->";
    cout << "NULL" << endl;
    //12,10,2,4,6
    
    return 0; 
}