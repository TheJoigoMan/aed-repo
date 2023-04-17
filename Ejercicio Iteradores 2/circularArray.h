#include <iostream>
using namespace std;

template<class T>
class CircularArray;

template <class T>
class ArrayCIterator
{
private:
    int current;
    CircularArray<T> *circularArray;

public:
    ArrayCIterator(){
        current = -1;
        circularArray = nullptr;
    }
    ArrayCIterator(int index, CircularArray<T> *_circularArray){
        current = index;
        circularArray = _circularArray;
    }

    bool operator != (const ArrayCIterator &other){
        return current != other.current;
    }

    ArrayCIterator& operator++(){
        current = circularArray->next(current); // obtenemos el next del array a partit del current y obtenemos el valor
        return *this; // retornamos el valor
    }

    ArrayCIterator& operator--(){
        current = circularArray->prev(current); // obtenemos el anterior del array a partit del current y obtenemos el valor
        return *this; // retornamos el valor
    }

    T& operator*(){
        return circularArray->array[current]; // obtenemos y retornamos el valor de current en array
    }
};

template <class T>
class CircularArray
{
public:
    typedef ArrayCIterator<T> iterator;
    iterator begin(){
        return iterator(this->front, this);
    }
    iterator end(){
        return iterator(next(this->back), this);
    }

private:
    T *array;
    int capacity;
    int back, front;

public:
    CircularArray();
    CircularArray(int _capacity);
    virtual ~CircularArray();
    void push_back(T data);
    void push_front(T data);
    bool is_full();
    bool is_empty();
    
    // Tools
    T& operator[](int);
    void display();

private:
    int next(int);
    int prev(int);
    friend class ArrayCIterator<T>;
};

// CircularArray();
template <class T>
CircularArray<T>::CircularArray()
{
	CircularArray(10);
}

// CircularArray(int _capacity);
template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
	this->capacity = _capacity;
	this->front = this->back = -1;
	this->array = new T[_capacity];
}

// virtual ~CircularArray();
template <class T>
CircularArray<T>::~CircularArray()
{ 
	delete[] array;
}

// void push_back(T data);
template <class T>
void CircularArray<T>::push_back(T data)
{
	if(is_full()) throw "The array is full";
	if(is_empty()) front = back = 0;
	else back = next(back);
	array[back] = data;
}

// void push_front(T data);
template <class T>
void CircularArray<T>::push_front(T data)
{
	if(is_full()) throw "The array is full";
	if(is_empty()) front = back = 0;
	else front = prev(front);
	array[front] = data;
}

//bool is_full();
template <class T>
bool CircularArray<T>::is_full()
{
	return front == next(back) && !is_empty();
}

//bool is_empty();
template <class T>
bool CircularArray<T>::is_empty()
{
	return front == -1;
}

// int next(int);
template <class T>
int CircularArray<T>::next(int index){
	return (index + 1) % capacity;
}

//int prev(int);
template <class T>
int CircularArray<T>::prev(int index){    
	return (index==0)? capacity - 1: index -1;
}

template <class T>
T& CircularArray<T>::operator[](int pos)
{
	if(pos >= capacity) throw "index out of range";
	return array[(front + pos) % capacity];
}

template <class T>
void CircularArray<T>::display()
{    
    for (int i = 0; i < capacity; i++)
        cout<<(*this)[i]<<",";        
    cout<<endl;
}