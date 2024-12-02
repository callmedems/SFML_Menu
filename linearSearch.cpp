#include "linearSearch.h"
#include <iostream>

using namespace std;
using namespace sf;

linearSearch::linearSearch(RenderWindow& window) : window(window) {
    // Example array, you can modify this as needed or get input from the user
    array = { 3, 5, 7, 9, 10, 12, 14, 16, 18, 20 };
    target = -1; // Initially no target set
}

void linearSearch::setTarget(int target) {
    this->target = target;  // Set the value to search for
}

void linearSearch::visualizeSearch() {
    // Example visualization of linear search with real-time animation
    RectangleShape rect(Vector2f(40.f, 40.f));
    rect.setFillColor(Color::Green);
    rect.setPosition(100.f, 100.f);
    
    for (size_t i = 0; i < array.size(); ++i) {
        rect.setPosition(100.f + i * 50.f, 100.f);
        
        // Visualize each element being visited
        if (array[i] == target) {
            rect.setFillColor(Color::Red);  // Highlight found element
        } else {
            rect.setFillColor(Color::Blue);  // Other elements are blue
        }

        window.clear();
        window.draw(rect);
        window.display();

        // Simulate delay to show each step
        sleep(seconds(0.5f));
    }

    // Final display when search is done
    window.clear();
    for (size_t i = 0; i < array.size(); ++i) {
        rect.setPosition(100.f + i * 50.f, 100.f);
        rect.setFillColor(Color::Blue);
        window.draw(rect);
    }

    window.display();
}
