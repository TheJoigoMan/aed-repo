#include "chainhash.h"
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  ChainHash<string, int> mymap;
  mymap.insert("luis", 10);
  mymap.insert("fernanda", 1);
  mymap.insert("roberto", 5);
  mymap.insert("luis", 3);
  //cout << "Bucket 1 size: " << mymap.bucket_size(1) << endl;
  //mymap.insert("luis", 2); // Rehashing test
  mymap.insert("sara", 6);
  mymap.insert("diego", 8);
  mymap.remove("roberto");
  mymap.remove("vanessa");
  cout<<"sara: "<<mymap.get("sara")<<endl;
  cout<<"roberto:"<<mymap.get("roberto")<<endl;

  std::cout << "mymap's buckets contain:\n";
  for (unsigned i = 0; i < mymap.bucket_count(); i++) {
    std::cout << "bucket #" << i << " contains:";
    for (auto local_it = mymap.begin(i); local_it != mymap.end(i); local_it++)
      std::cout << " -> " << local_it->key << ": " << local_it->value;
    std::cout << std::endl;
  }

  /*//Iterador del hash
  std::cout << "mymap contains:";
  for ( auto it = mymap.begin(); it != mymap.end(); ++it )
      std::cout << " " << it->first << ":" << it->second;
  std::cout << std::endl;*/
}