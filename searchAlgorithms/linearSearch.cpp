//
// Created by demmi on 11/24/2024.
//
// LinearSearchSFML.cpp
#include "linearSearch.h"
#include <SFML/Graphics.hpp>
#include <thread> // For sleep
#include <chrono> // For delays

int linearSearch(const std::vector<int>& arr, int target, sf::RenderWindow& window, sf::Font& font) {
    for (int i = 0; i < arr.size(); ++i) {
        // Clear the window
        window.clear(sf::Color::Black);

        // Draw each element in the array as a bar
        for (size_t j = 0; j < arr.size(); ++j) {
            sf::RectangleShape bar(sf::Vector2f(50, -arr[j] * 5)); // Bar height scales with value
            bar.setPosition(100 + j * 60, 400);                   // Adjust position
            bar.setFillColor((j == i) ? sf::Color::Red : sf::Color::White); // Highlight current element
            window.draw(bar);

            // Draw text showing the value
            sf::Text valueText(std::to_string(arr[j]), font, 20);
            valueText.setPosition(100 + j * 60, 410);
            valueText.setFillColor(sf::Color::White);
            window.draw(valueText);
        }

        // Display the frame
        window.display();
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Delay for visualization

        // Check if the current element matches the target
        if (arr[i] == target) {
            return i; // Return the index if found
        }
    }

    return -1; // Return -1 if the element is not found
}
