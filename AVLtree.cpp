#include "AVLTree.h"
#include "fontManager.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

// Constructor
AVLTree::AVLTree() : root(nullptr) {}

// Destructor
AVLTree::~AVLTree() {
    deleteTree(root);
}

// Public run method
void AVLTree::run(sf::RenderWindow &window) {
    bool running = true;

    sf::Text instructions("Presiona 'I' para insertar, 'R' para eliminar, 'Esc' para salir.", FontManager::font, 20);
    instructions.setFillColor(sf::Color::White);
    instructions.setPosition(10, 10);

    while (running) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                running = false;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
                int value;
                std::cout << "Ingresa un numero para insertar: ";
                std::cin >> value;
                root = insert(root, value);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
                int value;
                std::cout << "Ingresa un numero para eliminar: ";
                std::cin >> value;
                root = remove(root, value);
            }
        }

        window.clear();
        window.draw(instructions);
        drawTree(root, window, 400.0f, 50.0f, 200.0f);
        window.display();
    }
}

// Recursive insert
AVLTree::Node* AVLTree::insert(Node* node, int value) {
    if (!node) return new Node(value);

    if (value < node->value)
        node->left = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);
    else
        return node;

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    int balance = getBalanceFactor(node);

    if (balance > 1 && value < node->left->value)
        return rotateRight(node);

    if (balance < -1 && value > node->right->value)
        return rotateLeft(node);

    if (balance > 1 && value > node->left->value) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && value < node->right->value) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// Recursive remove
AVLTree::Node* AVLTree::remove(Node* node, int value) {
    if (!node) return node;

    if (value < node->value)
        node->left = remove(node->left, value);
    else if (value > node->value)
        node->right = remove(node->right, value);
    else {
        if (!node->left || !node->right) {
            Node* temp = node->left ? node->left : node->right;
            if (!temp) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp;
            }
            delete temp;
        } else {
            Node* temp = minValueNode(node->right);
            node->value = temp->value;
            node->right = remove(node->right, temp->value);
        }
    }

    if (!node) return node;

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    int balance = getBalanceFactor(node);

    if (balance > 1 && getBalanceFactor(node->left) >= 0)
        return rotateRight(node);

    if (balance > 1 && getBalanceFactor(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && getBalanceFactor(node->right) <= 0)
        return rotateLeft(node);

    if (balance < -1 && getBalanceFactor(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// Rotation methods
AVLTree::Node* AVLTree::rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

AVLTree::Node* AVLTree::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Utility methods
int AVLTree::getHeight(Node* node) const {
    return node ? node->height : 0;
}

int AVLTree::getBalanceFactor(Node* node) const {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

AVLTree::Node* AVLTree::minValueNode(Node* node) const {
    Node* current = node;
    while (current->left)
        current = current->left;
    return current;
}

void AVLTree::deleteTree(Node* node) {
    if (node) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

// Visualization helpers
void AVLTree::drawTree(Node* node, sf::RenderWindow &window, float x, float y, float offsetX) {
    if (!node) return;

    sf::CircleShape shape(20);
    shape.setFillColor(sf::Color::Green);
    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(2);
    shape.setPosition(x, y);

    window.draw(shape);

    sf::Text valueText;
    valueText.setFont(FontManager::font);
    valueText.setCharacterSize(16);
    valueText.setFillColor(sf::Color::White);
    valueText.setString(std::to_string(node->value));
    valueText.setPosition(x + 10, y + 5);
    window.draw(valueText);

    if (node->left) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x + 20, y + 20), sf::Color::White),
            sf::Vertex(sf::Vector2f(x - offsetX + 20, y + 100), sf::Color::White)
        };
        window.draw(line, 2, sf::Lines);
        drawTree(node->left, window, x - offsetX, y + 100, offsetX / 2);
    }

    if (node->right) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x + 20, y + 20), sf::Color::White),
            sf::Vertex(sf::Vector2f(x + offsetX + 20, y + 100), sf::Color::White)
        };
        window.draw(line, 2, sf::Lines);
        drawTree(node->right, window, x + offsetX, y + 100, offsetX / 2);
    }
}
