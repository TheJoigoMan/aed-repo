#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map> //hash
#include "chainhash.h"

using namespace std;

int main()
{
    ChainHash<int, char> hash;

    hash.set(2, 'A');
    hash.set(3, 'B');
    hash.set(6, 'C');
    hash.set(8, 'D');
    hash.set(10, 'E');
    hash.set(12, 'F');
    hash.set(13, 'G');
    hash.set(22, 'H');
    hash.set(23, 'I');
    hash.set(25, 'J');
    hash.set(26, 'K');
    hash.set(33, 'L');
    hash.set(35, 'M');
    hash.set(44, 'N');
    hash.set(56, 'O');

    cout << "Size of Hash Table: " << hash.bucket_count() << endl;

    for (unsigned i = 0; i < hash.bucket_count(); ++i)
    {
    cout << "bucket #" << i << " contains " << hash.bucket_size(i) << " elements: ";    
    for (auto it = hash.begin(i); it != hash.end(i); ++it)    
        cout << std::flush << it->first << " -> ";
    cout << std::flush<< "\n";
    }  
}