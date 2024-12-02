#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include "fontManager.h"
#include "mainMenu.h"
#include "subMenu.h"
#include "linearSearch.h"
#include "binarySearch.h"
#include "bubbleSort.h"
#include "insertionSort.h"
#include "selectionSort.h"
#include "mergeSort.h"
#include "quickSort.h"
#include "stacks.h"
#include "Queues.h"
#include "linkedLists.h"
#include "AVLtree.h"

using namespace std;
using namespace sf;

int main() {
    int choice, subChoice;
    RenderWindow window(VideoMode(800, 600), "MENU PRINCIPAL");

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
                        InsertionSort insertionSort;
                        insertionSort.run(window);
                    } else if (subChoice == 3) {
                        // Merge Sort call
                        MergeSort mergeSort;
                        mergeSort.run(window);
                    } else if (subChoice == 4) {
                        // Quick Sort call
                        QuickSort quickSort;
                        quickSort.run(window);
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
                        Stacks stack;
                        stack.run(window);
                    } else if (subChoice == 1) {
                        // Queues call
                        Queues queue;
                        queue.run(window);
                    } else if (subChoice == 2) {
                        // Linked Lists call
                        LinkedList linkedlist;
                        linkedlist.run(window);
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
                        AVLTree avl;
                        avl.run(window);
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
