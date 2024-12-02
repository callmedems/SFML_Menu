#include "Queues.h"
#include "fontManager.h"
#include <iostream>
#include <SFML/Graphics.hpp>

void Queues::run(sf::RenderWindow &window) {
    bool running = true;
    sf::Text instructions("Press 'E' to enqueue, 'D' to dequeue, 'Esc' to exit.", FontManager::font, 20);
    instructions.setPosition(10, 10);
    instructions.setFillColor(sf::Color::White);

    // Setup labels for front and rear
    frontLabel.setFont(FontManager::font);
    frontLabel.setCharacterSize(16);
    frontLabel.setFillColor(sf::Color::Cyan);

    rearLabel.setFont(FontManager::font);
    rearLabel.setCharacterSize(16);
    rearLabel.setFillColor(sf::Color::Magenta);

    while (running) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                running = false;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
                int value = rand() % 10 + 1; // Generate random value for enqueue
                enqueue(value);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                dequeue();
            }
        }

        window.clear();
        window.draw(instructions);
        drawQueue(window);
        window.display();
    }
}

void Queues::enqueue(int value) {
    queue.push(value);

    // Create a new block for the queue
    sf::RectangleShape block(sf::Vector2f(blockWidth, blockHeight));
    block.setFillColor(sf::Color::Green);
    block.setPosition(startX + blocks.size() * (blockWidth + 10), startY);
    blocks.push_back(block);
}

void Queues::dequeue() {
    if (!queue.empty()) {
        queue.pop();
        blocks.erase(blocks.begin()); // Remove the visual representation of the front block

        // Shift remaining blocks visually
        for (size_t i = 0; i < blocks.size(); ++i) {
            blocks[i].setPosition(startX + i * (blockWidth + 10), startY);
        }
    }
}

void Queues::drawQueue(sf::RenderWindow &window) {
    // Draw the blocks
    for (const auto &block : blocks) {
        window.draw(block);
    }

    // Draw values on the blocks
    sf::Text blockText;
    blockText.setFont(FontManager::font);
    blockText.setCharacterSize(16);
    blockText.setFillColor(sf::Color::White);

    for (size_t i = 0; i < blocks.size(); ++i) {
        blockText.setString(std::to_string(queue.front() + i));
        blockText.setPosition(blocks[i].getPosition().x + 15, blocks[i].getPosition().y + 5);
        window.draw(blockText);
    }

    // Draw front and rear labels
    if (!blocks.empty()) {
        frontLabel.setString("Front");
        frontLabel.setPosition(blocks.front().getPosition().x, blocks.front().getPosition().y - 30);
        window.draw(frontLabel);

        rearLabel.setString("Rear");
        rearLabel.setPosition(blocks.back().getPosition().x, blocks.back().getPosition().y - 30);
        window.draw(rearLabel);
    }
}
