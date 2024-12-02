#include "linkedLists.h"
#include "fontManager.h"
#include <iostream>
#include <SFML/Graphics.hpp>

LinkedList::LinkedList() : head(nullptr) {}

void LinkedList::run(sf::RenderWindow &window) {
    bool running = true;
        // Configuración de los textos
        instructions.setFont(FontManager::font);
        instructions.setCharacterSize(20);
        instructions.setFillColor(sf::Color::White);
        instructions.setString("Presiona 'I' para insertar, 'R' para eliminar, 'S' para buscar, 'Esc' para salir.");
        instructions.setPosition(10, 10);

        searchResult.setFont(FontManager::font);
        searchResult.setCharacterSize(20);
        searchResult.setFillColor(sf::Color::Yellow);
        searchResult.setPosition(10, 50);

        while (running) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    running = false;
                }
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::I) {
                        int value;
                        std::cout << "Ingresa un numero para insertar: ";
                        std::cin >> value;
                        insert(value);
                    }
                    if (event.key.code == sf::Keyboard::R) {
                        remove();
                    }
                    if (event.key.code == sf::Keyboard::S) {
                        int value;
                        std::cout << "Ingresa un numero para buscar: ";
                        std::cin >> value;
                        search(value);
                    }
                }
            }

            window.clear();
            window.draw(instructions);
            window.draw(searchResult);
            drawList(window);
            window.display();
        }
    }

void LinkedList::insert(int value) {
    Node* newNode = new Node{value, nullptr};
    newNode->shape.setSize(sf::Vector2f(nodeWidth, nodeHeight));
    newNode->shape.setFillColor(sf::Color::Green);

    // Determine position of the new node
    if (head == nullptr) {
        head = newNode;
        newNode->shape.setPosition(startX, startY);
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->shape.setPosition(temp->shape.getPosition().x + nodeWidth + 10, temp->shape.getPosition().y);
    }

    // Optional: Add a visual effect
    animateInsert(newNode);
}

void LinkedList::remove() {
    if (head != nullptr) {
        Node* temp = head;
        head = head->next;

        // Animate removal
        animateRemove(temp);
        delete temp;
    }
}

void LinkedList::search(int value) {
    Node* temp = head;
    bool found = false;

    while (temp != nullptr) {
        if (temp->value == value) {
            found = true;
            break;
        }
        temp = temp->next;
    }

    searchResult.setString(found ?
        "Found value: " + std::to_string(value) :
        "Value not found: " + std::to_string(value));
}

void LinkedList::drawList(sf::RenderWindow &window) {
    Node* temp = head;

    while (temp != nullptr) {
        window.draw(temp->shape);

        // Draw value text
        sf::Text valueText;
        valueText.setFont(FontManager::font);
        valueText.setCharacterSize(16);
        valueText.setFillColor(sf::Color::White);
        valueText.setString(std::to_string(temp->value));
        valueText.setPosition(temp->shape.getPosition().x + 15, temp->shape.getPosition().y + 5);
        window.draw(valueText);

        // Draw arrow to the next node
        if (temp->next != nullptr) {
            sf::Vertex arrow[] = {
                sf::Vertex(sf::Vector2f(temp->shape.getPosition().x + nodeWidth, temp->shape.getPosition().y + nodeHeight / 2)),
                sf::Vertex(sf::Vector2f(temp->next->shape.getPosition().x, temp->next->shape.getPosition().y + nodeHeight / 2))
            };
            window.draw(arrow, 2, sf::Lines);
        }

        temp = temp->next;
    }
}

void LinkedList::animateInsert(Node* newNode) {
    sf::Clock clock;
    sf::Vector2f startPos = newNode->shape.getPosition();
    sf::Vector2f endPos = startPos;

    // Ensure it starts offscreen for the animation
    newNode->shape.setPosition(startPos.x, startPos.y - 100);

    while (clock.getElapsedTime().asSeconds() < 1.0f) {
        float t = clock.getElapsedTime().asSeconds();
        float interpolatedY = startPos.y - 100 + t * 100; // Smoothly move down
        newNode->shape.setPosition(startPos.x, interpolatedY);
    }

    newNode->shape.setPosition(endPos);
}

void LinkedList::animateRemove(Node* nodeToRemove) {
    sf::Clock clock;
    sf::Color color = nodeToRemove->shape.getFillColor();

    while (clock.getElapsedTime().asSeconds() < 1.0f) {
        float t = clock.getElapsedTime().asSeconds();
        nodeToRemove->shape.setFillColor(sf::Color(
            color.r, color.g, color.b, static_cast<sf::Uint8>((1 - t) * 255))); // Fade out
    }
}
