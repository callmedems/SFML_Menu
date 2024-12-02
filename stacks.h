#ifndef STACKS_H
#define STACKS_H

#include <SFML/Graphics.hpp>
#include <vector>

class Stacks {
public:
    void run(sf::RenderWindow &window);
private:
    void push(int value);
    void pop();
    void drawStack(sf::RenderWindow &window);

    std::vector<int> stack; // stack storing integer values
    std::vector<sf::RectangleShape> blocks; // visual representation of stack elements
    const float blockWidth = 50.0f;  // Width of each block
    const float blockHeight = 30.0f; // Height of each block
};

#endif // STACKS_H
