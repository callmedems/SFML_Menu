#include "quickSort.h"
#include "fontManager.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <functional>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

void QuickSort::run(RenderWindow &window) {
    int n;
    cout << "Numero de elementos del array: ";
    cin >> n;

    // Inicializamos el arreglo con el tamaño especificado
    vector<int> arr(n);

    // Pedimos al usuario que ingrese los elementos
    cout << "Introduce los " << n << " elementos del arreglo:" << endl;
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

    // Helper function for partitioning and visualization
    auto partition = [&](int low, int high) -> int {
        int pivot = arr[high];
        bars[high].setFillColor(Color::Red); // Highlight pivot
        int i = low - 1;

        for (int j = low; j < high; ++j) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);

                // Update the visual representation of the array
                swap(bars[i], bars[j]);
            }

            // Visualization
            window.clear();
            window.draw(arrayText);
            window.draw(arrayValues);
            window.draw(sortText);

            for (int k = 0; k < bars.size(); ++k) {
                if (k != high && k != i && k != j) {
                    bars[k].setFillColor(Color::Green); // Elements not being compared
                }
                window.draw(bars[k]);
            }
            window.display();
            sf::sleep(sf::milliseconds(300)); // Pause to visualize
        }

        swap(arr[i + 1], arr[high]);
        swap(bars[i + 1], bars[high]);

        return i + 1;
    };

    // Recursive quicksort implementation
    function<void(int, int)> quickSort = [&](int low, int high) {
        if (low < high) {
            int pi = partition(low, high);

            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    };

    // Start the quicksort algorithm
    quickSort(0, n - 1);

    // Final sorted array output to console
    cout << "Array ordenado: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Visualize the sorted array
    sortText.setString("Ordenamiento completado");
    window.clear();
    window.draw(arrayText);
    window.draw(arrayValues);
    window.draw(sortText);

    for (int i = 0; i < bars.size(); ++i) {
        bars[i].setFillColor(Color::Blue); // Set all bars to blue after sorting
        window.draw(bars[i]);
    }

    window.display();
    sf::sleep(sf::seconds(5)); // Pause to show the final sorted array
}
