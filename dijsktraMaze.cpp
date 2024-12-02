#include "DijkstraMaze.h"
#include "fontManager.h"

using namespace std;
using namespace sf;

// Constante para representar "infinito"
const double INF = numeric_limits<double>::infinity();

// Constructor: Inicializa el grafo y posiciona los nodos
DijkstraMaze::DijkstraMaze(int n) : nodeCount(n), graph(n), previous(n, -1) {
    // Definir las posiciones manuales de los nodos
    vector<Vector2f> positions = {
        {100, 450},  // Nodo 2
        {95, 400}, // Nodo 3
        {320, 420}, // Nodo 4
        {260, 450},  // Nodo 5
        {85, 350}, // Nodo 6
        {75, 250},  // Nodo 7
        {300, 270},  // Nodo 8
        {610, 300},   // Nodo 9
        {600, 500}   // Nodo 1




    };

    // Crear los nodos con las posiciones definidas
    float radius = 15.0f;
    for (int i = 0; i < n; ++i) {
        Node node;
        node.position = positions[i];
        node.shape = CircleShape(radius);
        node.shape.setOrigin(radius, radius); // Centrar el nodo
        node.shape.setPosition(positions[i]);
        node.shape.setFillColor(Color::Blue);

        nodes.push_back(node);
    }
}

// Agregar una arista al grafo
void DijkstraMaze::addEdge(int from, int to, double weight) {
    graph[from].emplace_back(to, weight);
    graph[to].emplace_back(from, weight); // Arista bidireccional

    edges.push_back({from, to, weight});
}

// Algoritmo de Dijkstra
vector<double> DijkstraMaze::dijkstra() {
    vector<double> distances(nodeCount, INF);
    distances[origin] = 0;

    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;
    pq.push({0, origin});

    while (!pq.empty()) {
        double currentDistance = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if (currentDistance > distances[currentNode])
            continue;

        for (const auto& neighbor : graph[currentNode]) {
            int nextNode = neighbor.first;
            double edgeWeight = neighbor.second;
            double newDistance = currentDistance + edgeWeight;

            if (newDistance < distances[nextNode]) {
                distances[nextNode] = newDistance;
                previous[nextNode] = currentNode;
                pq.push({newDistance, nextNode});
            }
        }
    }

    return distances;
}

void DijkstraMaze::drawGraph(RenderWindow& window) {

    // Dibujar las aristas
    for (const auto& edge : edges) {
        Vertex line[] = {
            Vertex(nodes[edge.from].position, Color::White),
            Vertex(nodes[edge.to].position, Color::White)
        };
        window.draw(line, 2, Lines);

        // Mostrar el peso en el centro de la arista
        Vector2f midpoint = (nodes[edge.from].position + nodes[edge.to].position) / 2.0f;
        Text weightText;
        weightText.setFont(FontManager::font);
        weightText.setString(to_string(edge.weight));
        weightText.setCharacterSize(12);
        weightText.setFillColor(Color::White);
        weightText.setPosition(midpoint);
        window.draw(weightText);
    }

    // Dibujar los nodos
    for (const auto& node : nodes) {
        window.draw(node.shape);
    }
}

// Resaltar el camino más corto en la ventana
void DijkstraMaze::highlightPath(RenderWindow& window) {
    stack<int> path;
    for (int v = destination; v != origin; v = previous[v]) {
        path.push(v);
    }
    path.push(origin);

    // Dibujar las aristas del camino más corto en verde
    while (!path.empty()) {
        int current = path.top();
        path.pop();
        if (!path.empty()) {
            int next = path.top();
            Vertex line[] = {
                Vertex(nodes[current].position, Color::Green),
                Vertex(nodes[next].position, Color::Green)
            };
            window.draw(line, 2, Lines);
        }
    }
}

// Metodo para ejecutar la visualización
void DijkstraMaze::run(RenderWindow& window) {
    // Solicitar al usuario el nodo de origen y destino
    cout << "Ingrese el nodo de origen (1 a " << nodeCount << "): ";
    cin >> origin;
    cout << "Ingrese el nodo de destino (1 a " << nodeCount << "): ";
    cin >> destination;

    // Convertir índices a base 0
    origin -= 1;
    destination -= 1;

    // Ejecutar el algoritmo de Dijkstra
    vector<double> distances = dijkstra();

    // Verificar si existe un camino al destino
    if (distances[destination] == INF) {
        cout << "No hay un camino válido del nodo " << origin + 1 << " al nodo " << destination + 1 << "." << endl;
        return;
    }

    cout << "\nDistancia total: " << distances[destination] << " metros." << endl;

    // Loop principal de la ventana
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        // Dibujar el grafo y resaltar el camino
        window.clear(Color::Black);
        drawGraph(window);
        highlightPath(window);
        window.display();
    }
}
