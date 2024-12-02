#ifndef QUEUES_H
#define QUEUES_H

#include <SFML/Graphics.hpp>
#include <queue>

class Queues {
public:
    void run(sf::RenderWindow &window);

private:
    void enqueue(int value);
    void dequeue();
    void drawQueue(sf::RenderWindow &window);

    std::queue<int> queue; // Queue to store integers
    std::vector<sf::RectangleShape> blocks; // Visual representation of the queue
    sf::Text frontLabel;
    sf::Text rearLabel;

    const float blockWidth = 50.0f; // Width of each block
    const float blockHeight = 30.0f; // Height of each block
    const float startX = 200.0f; // Starting X position of the queue
    const float startY = 300.0f; // Y position of the queue
};

#endif // QUEUES_H
