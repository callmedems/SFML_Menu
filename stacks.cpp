#include "Stacks.h"
#include "fontManager.h"
#include <iostream>
#include <SFML/Graphics.hpp>

void Stacks::run(sf::RenderWindow &window) {
    bool running = true;
    sf::Text instructions("Presiona 'P' para  'push', 'O' para 'pop', 'Esc' para salir.", FontManager::font, 20);
    instructions.setPosition(10, 10);
    instructions.setFillColor(sf::Color::White);

    while (running) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                running = false;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
                int value = rand() % 10 + 1; // Generate a random value for push
                push(value);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
                pop();
            }
        }

        window.clear();
        window.draw(instructions);
        drawStack(window);
        window.display();
    }
}

void Stacks::push(int value) {
    stack.push_back(value);

    // Create a new block for the stack
    sf::RectangleShape block(sf::Vector2f(blockWidth, blockHeight));
    block.setFillColor(sf::Color::Green);
    block.setPosition(400, 500 - stack.size() * blockHeight);
    blocks.push_back(block);
}

void Stacks::pop() {
    if (!stack.empty()) {
        stack.pop_back();
        blocks.pop_back(); // Remove the visual representation of the block
    }
}

void Stacks::drawStack(sf::RenderWindow &window) {
    for (const auto &block : blocks) {
        window.draw(block);
    }

    // Draw numbers on blocks
    sf::Text blockText;
    blockText.setFont(FontManager::font);
    blockText.setCharacterSize(16);
    blockText.setFillColor(sf::Color::White);

    for (size_t i = 0; i < stack.size(); ++i) {
        blockText.setString(std::to_string(stack[i]));
        blockText.setPosition(blocks[i].getPosition().x + 15, blocks[i].getPosition().y + 5);
        window.draw(blockText);
    }
}
