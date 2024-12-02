// linearSearch.cpp
#include "linearSearch.h"
#include "fontManager.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
using namespace sf;

void LinearSearch::run(RenderWindow &window) {
    vector<int> arr = {10, 20, 30, 40, 50}; // Array ejemplo
    cout << "Este es el array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int target;
    cout << "Introduce el numero a buscar: ";
    cin >> target;

    // Crear un array de "rectángulos" que representan los elementos
    vector<RectangleShape> bars;
    float barWidth = 50.0f;
    float gap = 10.0f;
    for (int i = 0; i < arr.size(); ++i) { // Ahora empieza desde 0
        RectangleShape bar(Vector2f(barWidth, arr[i] * 10)); // La altura está basada en el valor del arreglo
        bar.setPosition(100 + i * (barWidth + gap), 500 - bar.getSize().y); // Posicionamiento
        bars.push_back(bar);
    }

    Text searchText("Buscando...", FontManager::font, 20);
    searchText.setPosition(10, 10);
    searchText.setFillColor(Color::White);

    // Crear el texto para mostrar el arreglo en pantalla
    Text arrayText("El arreglo es: ", FontManager::font, 20);
    arrayText.setPosition(10, 40);
    arrayText.setFillColor(Color::White);

    // texto con elementos del array
    stringstream ss;
    for (int i = 0; i < arr.size(); ++i) {
        ss << arr[i] << " ";
    }

    Text arrayValues(ss.str(), FontManager::font, 20);
    arrayValues.setPosition(100, 100);
    arrayValues.setFillColor(Color::White);

    int currentIndex = 0;
    bool found = false;
    string resultMessage = "Buscando...";

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();

        // mostramos arreglo en pantalla:
        window.draw(arrayText);
        window.draw(arrayValues);

        searchText.setString(resultMessage);
        window.draw(searchText);

        // Actualizar la visualización en cada paso del algoritmo
        for (int i = 0; i < bars.size(); ++i) {
            if (i == currentIndex) {
                bars[i].setFillColor(Color::Red); // Resaltar el elemento actual
            } else {
                bars[i].setFillColor(Color::Green); // Elementos no visitados
            }
            window.draw(bars[i]);
        }

        window.display();

        // Algoritmo de búsqueda lineal
        if (currentIndex < arr.size()) {
            if (arr[currentIndex] == target) {
                found = true;
                cout << "Elemento encontrado en el indice: " << currentIndex+1 << endl; // Mostrar en consola
            } else {
                currentIndex++;
            }
        }

        if (found) {
            // Esperar un poco para mostrar el resultado antes de regresar al menú
            sf::sleep(sf::seconds(2)); // Pausar 2 segundos para visualizar el mensaje
            break; // Si se encuentra el elemento, termina el ciclo
        }

        // Pausar un poco para la visualización
        sf::sleep(sf::milliseconds(500));
    }

    if (!found) {
        resultMessage = "Elemento no encontrado";
        window.clear();
        window.draw(arrayText);
        window.draw(arrayValues);
        window.draw(searchText);
        window.display();
        cout << "Elemento no encontrado." << endl; // Mostrar en consola
        sf::sleep(sf::seconds(2)); // Pausar para que se vea el mensaje
    }
}
