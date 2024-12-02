#include "insertionSort.h"
#include "fontManager.h"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
using namespace sf;

void InsertionSort::run(RenderWindow &window) {
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

    // Insertion Sort algorithm with visualization
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Highlight the element being inserted
        bars[i].setFillColor(Color::Red);

        // Visualize the sorting process
        while (j >= 0 && arr[j] > key) {
            // Move elements that are greater than the key
            arr[j + 1] = arr[j];
            j = j - 1;

            // Update the visual representation of the array
            bars[j + 1].setSize(Vector2f(barWidth, arr[j + 1] * 10));
            bars[j].setSize(Vector2f(barWidth, arr[j] * 10));

            // Update bars and draw them
            window.clear();
            window.draw(arrayText);
            window.draw(arrayValues);
            window.draw(sortText);

            // Draw bars
            for (int k = 0; k < bars.size(); ++k) {
                if (k != i && k != j) {
                    bars[k].setFillColor(Color::Green); // Elements not being compared
                }
                window.draw(bars[k]);
            }

            window.display();
            sf::sleep(sf::milliseconds(500)); // Pause to show the comparison
        }

        arr[j + 1] = key;

        // Set the sorted element to blue
        bars[j + 1].setFillColor(Color::Blue);
    }

    // Final sorted array output to console
    cout << "Array ordenado: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Visualize the sorted array with a final delay
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
