#include <vector>
#include <list>

using namespace std;

const int maxCollisions = 1;
const double maxFillFactor = 0.8;

template<typename TK, typename TV>
class ChainHash {
private:    
    struct Entry{
		TK key;
		TV value, first;
		Entry(TK _k, TV _v) {
			key = _k;
			value = _v;
			first = _v;
		}
		size_t hashcode;		
	};
	list<Entry> *array;
	int capacity;	// tamaño del array
    int size;		// cantidad de elementos totales

public:
	// Default Constructor (size 5)
    ChainHash(int _capacity = 5){
		capacity = _capacity;
		array = new list<Entry>[capacity];
		size = 0;
	}

	// Default Destructor
	~ChainHash() {
		delete[] this->array;
	}

	/////////////////////////////////////////////////////////
	// ITERADORES

	// Iterador para indicar el inicio
	typename list<Entry>::iterator begin(int i_bucket) {
		return this->array[i_bucket].begin();
	}

	// Iterador para indicar el final
	typename list<Entry>::iterator end(int i_bucket) {
		return this->array[i_bucket].end();
	}

	/////////////////////////////////////////////////////////
	// Funciones de tamaño

	// Función para devolver el tamaño de un bucket
	int bucket_size(int index) {
		// Utilizamos un Handler para buscar en caso de errores
		try {
			if (!(array[index].empty()))
				return distance(this->array[index].begin(), this->array[index].end()); // Retornamos el tamaño del bucket
			else throw "Exception Handler bucket_size(), index is empty!";}
		catch (const char* msg) {} //cerr << endl << msg << endl; } // Comentado para simplificar consola
		return 0;
	}

	// Función para devolver la cantidad de buckets en el hash table
	int bucket_count() {
		return this->capacity;
	}

	/////////////////////////////////////////////////////////
	// Funciones del Hash Table

	// Inserta elementos
	void set(TK key, TV value){
		size_t hashcode = getHashCode(key); // Obtiene el hash code
		int index = hashcode % capacity;	// Obtiene el index
		double test = fillFactor();
		int test2 = distance(array[index].begin(), array[index].end());
		// Revisamos si el fillFactor es mayor al establecido
		if (fillFactor() >= maxFillFactor){
			rehashing(); // Realizamos rehashing
			cout << "Origin >> Key: " << key << "; Hash: " << hashcode << "; Capacity: " << capacity << "; Index: " << index << endl; // Notificamos valores
			set(key, value); // Llamamos de nuevo a la función para que inserte los valores y haga rehashing de ser necesario
			return; // Retorna
		} 
        while(!(this->array[index].empty())) // Si no esta vacío, pasamos al siguiente index
            index++;
		array[index].push_back(Entry(key, value)); // Empujamos el valor en su posición indicada
		size++;
	}

	// Obtiene el dato según el key
	TV get(TK key){
		size_t hashCode = getHashCode(key); // Obtiene el hash code
		int index = hashCode % capacity;	// Obtiene el index
		// Utilizamos un Handler para buscar en caso de errores
		try {
			if (!(array[index].empty())) 
				return array[index].front().value; // Retornamos el front del array en ese index
			else throw "Exception Handler get(), index is empty!";}
		catch (const char* msg) { cerr << endl << msg << " Key: " << key << endl;}
		return EXIT_FAILURE;
	}

	void remove(TK key){
		size_t hashCode = getHashCode(key); // Obtiene el hash code
		int index = hashCode % capacity;	// Obtiene el index
		// Utilizamos un Handler para buscar en caso de errores
		try {
			if (!(array[index].empty()))
				array[index].pop_front(); // Liberamos el primer valor guardado (?)
			else throw "Exception Handler remove(), index is empty!";}
		catch (const char* msg) { cerr << endl << msg << " Key: " << key << endl;}
	}

	// Operador []
	TV& operator[](int index){
		// Utilizamos un Handler para buscar en caso de errores
		try {
			if (!(array[index].empty()))
				return array[index].front().value; // Retornamos el front del array en ese index
			else throw "Exception Handler operator[], index is empty!";}
		catch (const char* msg) { cerr << endl << msg << " Index: " << index << endl;}
	}

private:
	double fillFactor(){
		return double(size) / capacity;
	}

    // Hashing modificado con h(x) = x mod n
	size_t getHashCode(TK key){
		return key % capacity;
	}

	// Función de rehashing para reordenar los buckets
	void rehashing(){
		cout << "Rehashing..." << endl; // Notifica un rehashing
		int tempL = capacity;
		list<Entry> *temp = array;	// Copiamos el array

		// Calcula nuevo hashtable con el doble que el hash original
		capacity *= 2;
		bool primo = false;	// flag temporal para detectar primo
		// Detector de números primos
		while(!primo){
			int m = capacity/2;			// m vale la mitad de capacidad
			for(int i = 2; i <= m; i++){// Revisamos todas las posibles divisiones
				if(capacity % i == 0){	// Revisamos que sea primo
					capacity++;			// Si no es, se le suma uno
					primo = false;  	// Bajamos la bandera de primo
					break;				// Salimos del for
				} 
				primo = true;  			// Primo solo vale true fuera del for si se pasan todas las pruebas del for
			}
		}
		cout << "New Capacity: " << capacity << endl; 	// Notificamos la nueva capacidad
		array = new list<Entry>[capacity];				// Creamos un nuevo array con la capacidad
		
		// Creamos temporales para el index y el hashcode
		int index;
		size_t hashcode;
		// Con un for llenamos los valores en sus nuevas posiciones
		for (int i = 0; i < tempL; i++){ // Hasta el capacity del array anterior
			try {
				if (!(temp[i].empty())){
					hashcode = getHashCode(temp[i].front().key);
					index = hashcode % capacity;	// Obtiene el nuevo index
					array[index] = temp[i];
				} else throw "Exception Handler rehashing(), index ";}
			catch (const char* msg) {} // cerr << endl << msg << i << " is empty!" << endl;} // Comentado para simplificar consola
		}
		delete[] temp;
        cout << "Redrawing..." << endl;
        for (unsigned i = 0; i < capacity; ++i){
            cout << "bucket #" << i << " contains " << this->bucket_size(i) << " elements: ";    
            for (auto it = this->begin(i); it != this->end(i); ++it)    
                cout << std::flush << it->first << " -> ";
            cout << std::flush<< "\n";
        }  
	}
};