#include "Grafos.h"
#include "fontManager.h"

// Constructor
Grafos::Grafos(int n) : nodeCount(n), adjList(n) {
    // Inicializar nodos con posiciones predefinidas
    std::vector<sf::Vector2f> positions = {
        {100, 100}, {200, 50}, {300, 100}, {150, 200}, {250, 200},
        {350, 300}, {400, 150}, {450, 250}, {500, 100}
    };

    float radius = 20.0f;
    for (int i = 0; i < n; ++i) {
        Node node;
        node.id = i;
        node.position = positions[i % positions.size()];
        node.shape = sf::CircleShape(radius);
        node.shape.setOrigin(radius, radius);
        node.shape.setPosition(node.position);
        node.shape.setFillColor(sf::Color::Blue);
        nodes.push_back(node);
    }

    // Aristas con pesos (ajusta según sea necesario)
    edges = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5},
        {5, 6}, {6, 7}, {7, 8}, {8, 0}, {2, 5}, {4, 7}
    };

    // Crear lista de adyacencia
    for (const auto& edge : edges) {
        adjList[edge.from].push_back(edge.to);
        adjList[edge.to].push_back(edge.from); // Grafo no dirigido
    }

}

// Restablece los nodos a no visitados
void Grafos::resetNodes() {
    for (auto& node : nodes) {
        node.visited = false;
        node.shape.setFillColor(sf::Color::Blue);
    }
}

// DFS (Recursivo)
void Grafos::dfsRecursive(int current, sf::RenderWindow& window) {
    nodes[current].visited = true;
    nodes[current].shape.setFillColor(sf::Color::Red); // Nodo explorado
    drawGraph(window);
    window.display();
    sf::sleep(sf::milliseconds(500)); // Pausa para visualizar

    for (int neighbor : adjList[current]) {
        if (!nodes[neighbor].visited) {
            dfsRecursive(neighbor, window);
        }
    }
}

// BFS (Iterativo)
void Grafos::bfsIterative(int start, sf::RenderWindow& window) {
    std::queue<int> q;
    q.push(start);
    nodes[start].visited = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        nodes[current].shape.setFillColor(sf::Color::Green); // Nodo explorado
        drawGraph(window);
        window.display();
        sf::sleep(sf::milliseconds(500));

        for (int neighbor : adjList[current]) {
            if (!nodes[neighbor].visited) {
                nodes[neighbor].visited = true;
                q.push(neighbor);
            }
        }
    }
}

// Dibuja el grafo
void Grafos::drawGraph(sf::RenderWindow& window) {
    window.clear(sf::Color::Black);

    // Dibujar aristas
    for (const auto& edge : edges) {
        sf::Vertex line[] = {
            sf::Vertex(nodes[edge.from].position, sf::Color::White),
            sf::Vertex(nodes[edge.to].position, sf::Color::White)
        };
        window.draw(line, 2, sf::Lines);
    }

    // Dibujar nodos
    for (const auto& node : nodes) {
        window.draw(node.shape);

        // Etiquetas de nodo
        sf::Text label;
        label.setFont(FontManager::font);
        label.setString(std::to_string(node.id + 1));
        label.setCharacterSize(15);
        label.setFillColor(sf::Color::White);
        label.setPosition(node.position.x - 10, node.position.y - 10);
        window.draw(label);
    }
}

// Ejecuta la interacción con DFS y BFS
void Grafos::run(sf::RenderWindow& window) {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Selección del nodo inicial
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                for (auto& node : nodes) {
                    if (node.shape.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        resetNodes();

                        // DFS con clic izquierdo
                        if (event.mouseButton.button == sf::Mouse::Left) {
                            dfsRecursive(node.id, window);
                        }

                        // BFS con clic derecho
                        if (event.mouseButton.button == sf::Mouse::Right) {
                            bfsIterative(node.id, window);
                        }
                    }
                }
            }
        }

        drawGraph(window);
        window.display();
    }
}
