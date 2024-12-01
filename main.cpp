#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "searchAlgorithms/linearSearch.h"

#pragma execution_character_set("utf-8") // Para los caracteres especiales

// Función para dibujar el menú
void drawMenu(sf::RenderWindow& window, const std::vector<std::string>& options, int selectedIndex, const std::string& title) {
    window.clear(sf::Color::Black);

    sf::Font font;
    if (!font.loadFromFile("assets/Roboto-Regular.ttf")) {
        std::cerr << "Error al cargar la fuente." << std::endl;
        return;
    }

    // Título del menú
    sf::Text titleText(title, font, 40);
    titleText.setFillColor(sf::Color::White);
    titleText.setStyle(sf::Text::Bold);
    titleText.setPosition(100, 50);
    window.draw(titleText);

    // Opciones del menú
    for (size_t i = 0; i < options.size(); ++i) {
        sf::Text option(options[i], font, 30);
        option.setPosition(200, 150 + i * 50);

        if (i == selectedIndex) {
            option.setFillColor(sf::Color::Red);
        } else {
            option.setFillColor(sf::Color::White);
        }

        window.draw(option);
    }

    window.display();
}

// Menú de algoritmos de búsqueda
void searchMenu(sf::RenderWindow& window) {
    std::vector<std::string> options = {
        "1. Busqueda Lineal",
        "2. Volver"
    };

    int selectedIndex = 0;
    while (true) {
        drawMenu(window, options, selectedIndex, "Algoritmos de Busqueda");

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    selectedIndex = (selectedIndex - 1 + options.size()) % options.size();
                } else if (event.key.code == sf::Keyboard::Down) {
                    selectedIndex = (selectedIndex + 1) % options.size();
                } else if (event.key.code == sf::Keyboard::Enter) {
                    if (selectedIndex == 0) {
                        // Call linearSearch
                        std::vector<int> arr = {10, 20, 30, 40, 50};
                        int target;
                        std::cout << "Ingrese el elemento a buscar: ";
                        std::cin >> target;

                        sf::Font font;
                        if (!font.loadFromFile("assets/Roboto-Regular.ttf")) {
                            std::cerr << "Error al cargar la fuente." << std::endl;
                            return;
                        }

                        int result = linearSearch(arr, target, window, font);

                        // Display result
                        std::string message = (result != -1)
                            ? "Elemento encontrado en el indice: " + std::to_string(result)
                            : "Elemento no encontrado.";

                        std::cout << message << std::endl;

                        // Show result in SFML window
                        window.clear(sf::Color::Black);
                        sf::Text resultText(message, font, 30);
                        resultText.setFillColor(sf::Color::White);
                        resultText.setPosition(100, 200);
                        window.draw(resultText);
                        window.display();

                        sf::sleep(sf::seconds(3)); // Wait before returning
                        return; // Return to the previous menu
                    } else if (selectedIndex == 1) {
                        return; // Go back to the previous menu
                    }
                }
            }
        }
    }
}


// Menú principal para elegir los algoritmos
void mainMenu(sf::RenderWindow& window) {
    std::vector<std::string> options = {
        "1. Algoritmos de Busqueda",
        "2. Algoritmos de Ordenamiento",
        "3. Estructuras Lineales",
        "4. Estructuras No Lineales",
        "5. Salir"
    };

    int selectedIndex = 0;

    while (window.isOpen()) {
        drawMenu(window, options, selectedIndex, "Proyecto SFML - Menu Principal");

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    selectedIndex = (selectedIndex - 1 + options.size()) % options.size();
                } else if (event.key.code == sf::Keyboard::Down) {
                    selectedIndex = (selectedIndex + 1) % options.size();
                } else if (event.key.code == sf::Keyboard::Enter) {
                    switch (selectedIndex) {
                        case 0:
                            searchMenu(window); // Llama al submenú de búsqueda
                            break;
                        case 1:
                            std::cout << "Seleccionaste: Algoritmos de Ordenamiento\n";
                            break;
                        case 2:
                            std::cout << "Seleccionaste: Estructuras Lineales\n";
                            break;
                        case 3:
                            std::cout << "Seleccionaste: Estructuras No Lineales\n";
                            break;
                        case 4:
                            std::cout << "Saliendo del programa...\n";
                            window.close();
                            break;
                    }
                }
            }
        }
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 500), "Proyecto SFML - Menu");
    window.setFramerateLimit(60);
    mainMenu(window);  // Llama al menú principal
    return 0;
}
