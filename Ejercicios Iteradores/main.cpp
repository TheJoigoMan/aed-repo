#include <iostream>
#include "circulararray.h"

int main() 

{
    CircularArray<int> myarray(5);
    myarray.push_back(10);
    myarray.push_back(5);
    myarray.push_back(3);
    myarray.push_back(8);
    myarray.push_back(9);
    myarray.pop_front();
    myarray.pop_front();
    myarray.push_back(11);

    CircularArray<int>::iterator ptr;
    for (ptr = myarray.begin(); ptr != myarray.end(); ++ptr)
        cout<<*ptr<<", ";//3,8,9,11

    cout<<endl;
    return 0;
}