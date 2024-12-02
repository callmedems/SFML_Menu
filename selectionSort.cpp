#include "selectionSort.h"
#include "fontManager.h"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
using namespace sf;

void SelectionSort::run(RenderWindow &window) {
    int n;
    cout << "Numero de elementos del array: ";
    cin >> n;

    // Inicializamos el arreglo con el tamaño especificado
    vector<int> arr(n);

    // Pedimos al usuario que ingrese los elementos
    cout << "Introduce los " << n << " elementos del array:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "El array es: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Visual representation of the array (bars)
    vector<RectangleShape> bars;
    float barWidth = 50.0f;
    float gap = 10.0f;
    for (int i = 0; i < arr.size(); ++i) {
        RectangleShape bar(Vector2f(barWidth, arr[i] * 10)); // Height based on array value
        bar.setPosition(100 + i * (barWidth + gap), 500 - bar.getSize().y);
        bars.push_back(bar);
    }

    Text sortText("Ordenando...", FontManager::font, 20);
    sortText.setPosition(10, 10);
    sortText.setFillColor(Color::White);

    // Text to show array on screen
    Text arrayText("El array es: ", FontManager::font, 20);
    arrayText.setPosition(10, 40);
    arrayText.setFillColor(Color::White);

    stringstream ss;
    for (int i = 0; i < arr.size(); ++i) {
        ss << arr[i] << " ";
    }

    Text arrayValues(ss.str(), FontManager::font, 20);
    arrayValues.setPosition(100, 100);
    arrayValues.setFillColor(Color::White);

    // Selection Sort algorithm with visualization
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;

        // Visualize the sorting process
        for (int j = i + 1; j < n; ++j) {
            // Highlight the elements being compared
            bars[j].setFillColor(Color::Red);
            bars[minIdx].setFillColor(Color::Red);

            window.clear();
            window.draw(arrayText);
            window.draw(arrayValues);
            window.draw(sortText);

            // Draw bars
            for (int k = 0; k < bars.size(); ++k) {
                if (k != j && k != minIdx) {
                    bars[k].setFillColor(Color::Green); // Elements not being compared
                }
                window.draw(bars[k]);
            }

            window.display();

            sf::sleep(sf::milliseconds(500)); // Pause to show the comparison

            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }

            // Reset bar colors after comparison
            bars[j].setFillColor(Color::Green);
        }

        // Swap the minimum element with the first unsorted element
        if (minIdx != i) {
            swap(arr[i], arr[minIdx]);

            // Update the bar heights visually
            bars[i].setSize(Vector2f(barWidth, arr[i] * 10));
            bars[minIdx].setSize(Vector2f(barWidth, arr[minIdx] * 10));
        }

        // Set the sorted element to blue
        bars[i].setFillColor(Color::Blue);
    }

    // Final sorted array output to console
    cout << "Array ordenado: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Visualize the sorted array with a final delay
    sortText.setString("¡Ordenamiento completado!");
    window.clear();
    window.draw(arrayText);
    window.draw(arrayValues);
    window.draw(sortText);

    for (int i = 0; i < bars.size(); ++i) {
        bars[i].setFillColor(Color::Blue); // Set all bars to blue after sorting
        window.draw(bars[i]);
    }

    window.display();
    sf::sleep(sf::seconds(2)); // Pause to show the final sorted array
}
