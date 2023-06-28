#ifndef FW_H
#define FW_H
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// std::numeric_limits<int>::max()
int INF = std::numeric_limits<int>::max(); // Define INF

struct Edge
{   
    char init;
    char end;
    int weight;
};

vector<vector<int>> FloydWarshall(vector<char> vertices,vector<Edge> aristas)
{
    // cout << "Inicia FloydWarshall" << endl;
    int n = vertices.size();

    // Un vector para el guardar el recorrido y otro para operar
    vector<vector<int>> temp(n, vector<int>(n, INF)); // Inicia el vector en infinito
    vector<vector<int>> tour(n, vector<int>(n, INF)); // Inicia el vector en infinito
    
    // De un vertice a si mismo es 0
    for (int i = 0; i < n; i++)
        temp[i][i] = 0;
    
    for (Edge e : aristas){
        temp[e.init - '1'][e.end - '1'] = e.weight; // guardamos los ponderados de las aristas en el tour
        tour[e.init - '1'][e.end - '1'] = e.end - '1'; // guardamos el camino
    }
    
    // Floyd Warshall algorithm
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (temp[i][k] != INF && temp[k][j] != INF && temp[i][k] + temp[k][j] < temp[i][j]){
                    temp[i][j] = temp[i][k] + temp[k][j];   // algoritmo para el tour
                    tour[i][j] = tour[i][k];                // guardamos el path
                }
    // cout << "Termina FloydWarshall" << endl;
    return tour;
}

void displayPath(vector<vector<int>> tour, char init, char end){
    // cout << "Inicia displayPath" << endl;
    int i = init - '1'; // Convierte char a int
    int j = end - '1';

    if (tour[i][j] == INF) {
        cout << "No existe camino de " << init << " a " << end << endl;
        return;
    }

    cout << "Camino de " << init << " a " << end << endl;
    cout << init << " -> ";
    while(i != j)
    {
        cout << char(tour[i][j] + '1') << " -> ";
        i = tour[i][j];
    }
    cout << "NULL" << endl << endl;    
    // cout << "Termina displayPath" << endl;
}  
#endif