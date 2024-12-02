#ifndef GRAFOS_H
#define GRAFOS_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;
using namespace sf;

struct Node {
    CircleShape shape;
    Vector2f position;
    int id;
    bool visited = false; // Para resaltar durante la búsqueda
};

struct Edge {
    int from;
    int to;
    float weight;
};

class Grafos {
private:
    vector<Node> nodes;               // Lista de nodos
    vector<Edge> edges;               // Lista de aristas
    vector<vector<int>> adjList; // Lista de adyacencia para las búsquedas

    int nodeCount;                         // Cantidad de nodos

    // Métodos internos
    void resetNodes();
    void dfsRecursive(int current, RenderWindow& window);
    void bfsIterative(int start, RenderWindow& window);
    void drawGraph(RenderWindow& window);

public:
    Grafos(int n);
    void run(RenderWindow& window);
};

#endif // GRAFOS_H
