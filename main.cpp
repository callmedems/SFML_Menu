#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include "fontManager.h"
#include "mainMenu.h"
#include "subMenu.h"
#include "linearSearch.h"
#include "binarySearch.h"
#include "bubbleSort.h"
#include "selectionSort.h"

using namespace std;
using namespace sf;

int main() {
    int choice, subChoice;
    RenderWindow window(VideoMode(800, 800), "MENU PRINCIPAL");

    // cargar la fuente
    if (!FontManager::loadFont("assets/Roboto-Regular.ttf")) {
        return 1;  // Salir si no se pudo cargar la fuente
    }

    while (window.isOpen()) {
        MainMenu mainMenu(window);
        choice = mainMenu.show();

        if (choice == -1 || choice == 4) {
            // Exit chosen
            window.close();
        } else {
            switch (choice) {
                case 0: {
                    // Submenu for search algorithms
                    SubMenu searchMenu(window, {"Secuencial", "Busqueda Binaria", "Regresar"});
                    subChoice = searchMenu.show();

                    if (subChoice == 0) {
                        // Linear search call
                        LinearSearch linearSearch;
                        linearSearch.run(window);  // Ahora el arreglo es ingresado por el usuario
                    } else if (subChoice == 1) {
                        // Binary search call
                        BinarySearch binarySearch;
                        binarySearch.run(window);
                    } else { // Regresar
                        break;
                    }
                    break;
                }

                case 1: {
                    // Submenu for sorting algorithms
                    SubMenu sortingMenu(window, {"Bubble Sort", "Selection Sort",
                        "Insertion Sort", "Merge Sort", "Quick Sort", "Regresar"});
                    subChoice = sortingMenu.show();

                    if (subChoice == 0) {
                        // Bubble Sort call
                        BubbleSort bubbleSort;
                        bubbleSort.run(window);
                    } else if (subChoice == 1) {
                        // Selection Sort call
                        SelectionSort selectionSort;
                        selectionSort.run(window);
                    } else if (subChoice == 2) {
                        // Insertion Sort call
                    } else if (subChoice == 3) {
                        // Merge Sort call
                    } else if (subChoice == 4) {
                        // Quick Sort call
                    } else { // Regresar
                        break;
                    }
                    break;
                }

                case 2: {
                    // Submenu for linear data structures
                    SubMenu linearStructMenu(window, {"Stacks", "Queues", "Linked Lists", "Regresar"});
                    subChoice = linearStructMenu.show();

                    if (subChoice == 0) {
                        // Stacks call
                    } else if (subChoice == 1) {
                        // Queues call
                    } else if (subChoice == 2) {
                        // Linked Lists call
                    } else { // Regresar
                        break;
                    }
                    break;
                }

                case 3: {
                    // Submenu for non-linear data structures
                    SubMenu nonLinearStructMenu(window, {"Arboles AVL", "Dijkstra", "DFS", "BFS", "Regresar"});
                    subChoice = nonLinearStructMenu.show();

                    if (subChoice == 0) {
                        // AVL Trees call
                    } else if (subChoice == 1) {
                        // Dijkstra call
                    } else if (subChoice == 2) {
                        // DFS call
                    } else { // Regresar
                        break;
                    }
                    break;
                }

                default:
                    break;
            }
        }
    }
    return 0;
}
