#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <SFML/Graphics.hpp>

class LinkedList {
public:
    LinkedList();
    void run(sf::RenderWindow &window);

private:
    struct Node {
        int value;
        Node* next;
        sf::RectangleShape shape;
    };

    void insert(int value);
    void remove();
    void search(int value);
    void drawList(sf::RenderWindow &window);
    void animateInsert(Node* newNode);
    void animateRemove(Node* nodeToRemove);

    Node* head;
    sf::Text instructions;
    sf::Text searchResult;
    const float nodeWidth = 50.0f;
    const float nodeHeight = 30.0f;
    const float startX = 200.0f;
    const float startY = 200.0f;
};

#endif // LINKEDLIST_H
