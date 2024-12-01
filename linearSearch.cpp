#include "linearSearch.h"
#include <thread>
#include <chrono>
#include <iostream>

using namespace std;

// Constructor
LinearSearch::LinearSearch(RenderWindow& win, const std::vector<int>& arr, int tgt)
    : window(win), array(arr), target(tgt), resultIndex(-1) {}

// Helper to draw the array
void LinearSearch::drawArray(int currentIndex, int targetIndex) {
    window.clear(Color::Black);

    float barWidth = 50;
    float barSpacing = 10;
    float startX = (window.getSize().x - (barWidth + barSpacing) * array.size()) / 2;

    for (size_t i = 0; i < array.size(); ++i) {
        RectangleShape bar(Vector2f(barWidth, array[i] * 10));
        bar.setPosition(startX + i * (barWidth + barSpacing), window.getSize().y - bar.getSize().y - 50);

        if (i == targetIndex) {
            bar.setFillColor(Color::Green); // Permanent highlight for found element
        } else if (i == currentIndex) {
            bar.setFillColor(Color::Red); // Temporary highlight for the current element
        } else {
            bar.setFillColor(Color::White); // Default color
        }

        window.draw(bar);
    }

    window.display();
}

// Perform linear search with visualization
void LinearSearch::search() {
    for (size_t i = 0; i < array.size(); ++i) {
        drawArray(i, -1);

        // Simulate delay for animation
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        if (array[i] == target) {
            resultIndex = i;
            drawArray(i, i);
            break;
        }
    }

    // Final state: reset or highlight found element
    if (resultIndex == -1) {
        drawArray(-1, -1); // No match found
    }
}

// Get the result index
int LinearSearch::getResultIndex() const {
    return resultIndex;
}