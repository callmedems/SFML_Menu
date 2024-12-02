#include "binarySearch.h"
#include "fontManager.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;
using namespace sf;

void BinarySearch::run(RenderWindow &window) {
    vector<int> arr = {10, 30, 20, 50, 40}; // Example array
    sort(arr.begin(), arr.end()); // Sort the array before binary search
    cout << "Este es el array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\nIntroduce el numero a buscar: ";
    int target;
    cin >> target;

    // Visual representation of array (bars)
    vector<RectangleShape> bars;
    float barWidth = 50.0f;
    float gap = 10.0f;
    for (int i = 0; i < arr.size(); ++i) {
        RectangleShape bar(Vector2f(barWidth, arr[i] * 10)); // Height based on array value
        bar.setPosition(100 + i * (barWidth + gap), 500 - bar.getSize().y);
        bars.push_back(bar);
    }

    Text searchText("Buscando...", FontManager::font, 20);
    searchText.setPosition(10, 10);
    searchText.setFillColor(Color::White);

    // Text to show array on screen
    Text arrayText("El arreglo es: ", FontManager::font, 20);
    arrayText.setPosition(10, 40);
    arrayText.setFillColor(Color::White);

    stringstream ss;
    for (int i = 0; i < arr.size(); ++i) {
        ss << arr[i] << " ";
    }

    Text arrayValues(ss.str(), FontManager::font, 20);
    arrayValues.setPosition(100, 100);
    arrayValues.setFillColor(Color::White);

    int left = 0, right = arr.size() - 1;
    int mid;
    bool found = false;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();

        // Display the array and bars
        window.draw(arrayText);
        window.draw(arrayValues);
        window.draw(searchText);

        // Draw bars with coloring
        for (int i = 0; i < bars.size(); ++i) {
            if (i == mid) {
                bars[i].setFillColor(Color::Red); // Highlight the middle element
            } else if (i >= left && i <= right) {
                bars[i].setFillColor(Color::Yellow); // Range being searched
            } else {
                bars[i].setFillColor(Color::Green); // Other elements
            }
            window.draw(bars[i]);
        }

        window.display();

        // Perform Binary Search
        if (left <= right) {
            mid = left + (right - left) / 2; // Calculate middle index

            if (arr[mid] == target) {
                bars[mid].setFillColor(Color::Blue); // Highlight the found element
                found = true;
                // Output to console where the element is found
                cout << "Elemento encontrado en el indice " << mid+1 << endl;
                break; // If the element is found, exit the loop
            } else if (arr[mid] > target) {
                right = mid - 1; // Search the left half
            } else {
                left = mid + 1; // Search the right half
            }
        } else {
            searchText.setString("Elemento no encontrado");
            break; // Exit the loop if the element is not found
        }

        sf::sleep(sf::milliseconds(500)); // Pause to show the animation
    }

    if (found) {
        // Wait for a few seconds to show the result
        sf::sleep(sf::seconds(2));
    }
}
