#include <forward_list>
#include <functional>
#include <iostream>
using namespace std;

const float maxFillfactor = 0.5;
const int maxCollision = 3;

template <typename TK, typename TV> class ChainHash {
private:
  struct Entry {
    TK key;
    TV value;
    Entry(TK _k, TV _v) {
      key = _k;
      value = _v;
    }
  };
  forward_list<Entry> *array;
  int capacity; // tamaño del hashtable
  int size;     // cantidad de entradas
  hash<TK> getHash;

public:
  ChainHash(int _capacity = 7) {
    this->capacity = _capacity;
    this->array = new forward_list<Entry>[capacity];
    this->size = 0;
  }
  float fillFactor() { return this->size / (this->capacity * maxCollision);}

  void insert(TK key, TV value) {
    size_t hashcode = getHash(key);
    int index = hashcode % capacity;
    if (fillFactor() >= maxFillfactor || distance(this->array[index].begin(), this->array[index].end()) >= maxCollision){
      rehashing();
      index = hashcode % capacity;
      cout << "Key: " << key << "; Hash: " << hashcode << "; Capacity: " << capacity << "; Index: " << index << endl;;
    }
    this->array[index].push_front(Entry(key, value));
  }

  void rehashing() {
    cout << "Rehashing..." << endl;
    int tempL = capacity;
    forward_list<Entry> *temp = array;

    // Calcula nuevo hashtable con tamaño de numero primo
    capacity = capacity * 2;
    bool flag = false;
    while(true){
        int m = capacity/2;  
        for(int i = 2; i <= m; i++)  
        {  
            if(capacity % i == 0)  
            {  
                capacity++;  
                flag = true;  
                break;  
            } 
            flag = false;  
        }  
        if (flag == false)  
            break; 
    }

    cout << "New Capacity: " << capacity << endl;
    array = new forward_list<Entry>[capacity];
    for (int i = 0; i < tempL; i++)
    {            
        array[i] = temp[i];
    }

    delete[] temp;
  }
  TV get(TK key) {
    size_t hashCode = getHash(key);
    int index = hashCode % capacity;
    try {
        if (!(array[index].empty()))
            return array[index].front().value;
        else throw "Exception Handler get(), index not found!";}
    catch (const char* msg) { cerr << endl << msg << " Key: " << key << endl; }
    return EXIT_FAILURE;
  }
  void remove(TK key) {
    size_t hashCode = getHash(key);
    int index = hashCode % capacity;
    try {
        if (!(array[index].empty()))
            array[index].clear();
        else throw "Exception Handler remove(), index not found!";}
    catch (const char* msg) { cerr << endl << msg << " Key: " << key << endl; }
  }

  int bucket_size(int index) {
    try {
        if (!(array[index].empty()))
            return distance(this->array[index].begin(), this->array[index].end());
        else throw "Exception Handler bucket_size(), index not found!";}
    catch (const char* msg) { cerr << endl << msg << endl; }
    return EXIT_FAILURE;
  }

  ///////////////////////////////////////////////////////////////
  int bucket_count() { return this->capacity; }

  typename forward_list<Entry>::iterator begin(int i_bucket) {
    return this->array[i_bucket].begin();
  }

  typename forward_list<Entry>::iterator end(int i_bucket) {
    return this->array[i_bucket].end();
  }

  ~ChainHash() { delete[] this->array; }
};