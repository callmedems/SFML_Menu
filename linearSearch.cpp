#include "LinearSearch.h"
#include <iostream>

LinearSearch::LinearSearch(sf::RenderWindow& win)
    : window(win), target(-1), found(false), currentIndex(0) {
    if (!font.loadFromFile("arial.ttf")) {
        std::cout << "Error loading font!" << std::endl;
    }
    statusText.setFont(font);
    statusText.setCharacterSize(20);
    statusText.setFillColor(sf::Color::White);
    statusText.setPosition(10.f, 10.f);
}

void LinearSearch::setTarget(int t) {
    target = t;
    found = false;
    currentIndex = 0;
}

void LinearSearch::setArray(const std::vector<int>& arr) {
    array = arr;
}

void LinearSearch::search() {
    if (currentIndex < array.size()) {
        if (array[currentIndex] == target) {
            found = true;
        } else {
            currentIndex++;
        }
    }
}

void LinearSearch::render() {
    window.clear();

    float width = window.getSize().x / array.size();
    float height = window.getSize().y - 100.f;

    for (size_t i = 0; i < array.size(); ++i) {
        sf::RectangleShape rect(sf::Vector2f(width - 5, height - 50));
        rect.setPosition(i * width, 50);

        if (i == currentIndex) {
            rect.setFillColor(sf::Color::Green); // Highlight current element
        } else if (found && array[i] == target) {
            rect.setFillColor(sf::Color::Red); // Permanently highlight the found element
        } else {
            rect.setFillColor(sf::Color::Blue); // Default color
        }
        window.draw(rect);

        // Display the value
        sf::Text text(std::to_string(array[i]), font, 20);
        text.setPosition(i * width + 10, height - 40);
        text.setFillColor(sf::Color::White);
        window.draw(text);
    }

    // Display status message
    window.draw(statusText);

    window.display();
}

bool LinearSearch::isFound() const {
    return found;
}

bool LinearSearch::isSearching() const {
    return !found && currentIndex < array.size();
}

void LinearSearch::displayMessage(const std::string& message) {
    statusText.setString(message);
}

void LinearSearch::handleTextInput(sf::Event event) {
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode == 8) { // Backspace key
            if (!statusText.getString().isEmpty()) {
                std::string str = statusText.getString();
                str.pop_back();
                statusText.setString(str);
            }
        } else if (event.text.unicode < 128) {
            statusText.setString(statusText.getString() + static_cast<char>(event.text.unicode));
        }
    }
}
