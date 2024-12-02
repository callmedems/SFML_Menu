#ifndef DIJKSTRA_MAZE_H
#define DIJKSTRA_MAZE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <iostream>
#include <cmath>

using namespace std;
using namespace sf;

class DijkstraMaze {
private:
    struct Node {
        Vector2f position; // Posición del nodo
        CircleShape shape; // Representación gráfica del nodo
    };

    struct Edge {
        int from, to;        // Nodos conectados por la arista
        double weight;       // Peso de la arista
    };

    vector<Node> nodes; // Lista de nodos
    vector<vector<pair<int, double>>> graph; // Representación del grafo
    vector<Edge> edges; // Lista de aristas
    vector<int> previous; // Vector para reconstruir el camino más corto
    int nodeCount; // Número de nodos en el grafo
    int origin, destination; // Nodos de origen y destino

    // Métodos privados para funcionalidad interna
    void drawGraph(RenderWindow& window); // Dibujar el grafo
    void highlightPath(RenderWindow& window); // Resaltar el camino más corto
    vector<double> dijkstra(); // Algoritmo de Dijkstra

public:
    DijkstraMaze(int n); // Constructor para inicializar el grafo
    void addEdge(int from, int to, double weight); // Agregar una arista al grafo
    void run(RenderWindow& window); // Ejecutar la visualización
};

#endif // DIJKSTRA_MAZE_H
