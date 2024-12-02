#ifndef AVLTREE_H
#define AVLTREE_H

#include <SFML/Graphics.hpp>

// Clase AVLTree
class AVLTree {
public:
    // Constructor y destructor
    AVLTree();
    ~AVLTree();

    // Método principal para ejecutar la visualización
    void run(sf::RenderWindow &window);

private:
    // Estructura para representar un nodo en el árbol
    struct Node {
        int value;
        int height;
        Node* left;
        Node* right;

        Node(int val) : value(val), height(1), left(nullptr), right(nullptr) {}
    };

    Node* root; // Raíz del árbol

    // Métodos de utilidad para el manejo del árbol
    Node* insert(Node* node, int value);
    Node* remove(Node* node, int value);
    Node* rotateRight(Node* y);
    Node* rotateLeft(Node* x);
    int getHeight(Node* node) const;
    int getBalanceFactor(Node* node) const;
    Node* minValueNode(Node* node) const;
    void deleteTree(Node* node);

    // Métodos de visualización
    void drawTree(Node* node, sf::RenderWindow &window, float x, float y, float offsetX);
};

#endif // AVLTREE_H
