#include <SFML/Graphics.hpp>
#include "mainMenu.h"
#include "subMenu.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "MENU PRINCIPAL");

    while (window.isOpen()) {
        MainMenu mainMenu(window);
        int choice = mainMenu.show();

        if (choice == -1 || choice == 4) {
            // Exit chosen
            window.close();
        } else {
            // Submenu categories
            if (choice == 0) {
                SubMenu searchMenu(window, {"Secuencial", "Busqueda Binaria", "Regresar"});
                searchMenu.show();
            } else if (choice == 1) {
                SubMenu sortingMenu(window, {"Bubble Sort", "Selection Sort",
                    "Insertion Sort", "Merge Sort", "Quick Sort", "Regresar"});
                sortingMenu.show();
            } else if (choice == 2) {
                SubMenu linearStructMenu(window, {"Stacks", "Queues",
                    "Linked Lists", "Regresar"});
                linearStructMenu.show();
            } else if (choice == 3) {
                SubMenu nonLinearStructMenu(window, {"Arboles AVL", "Dijkstra",
                    "DFS", "BFS", "Regresar"});
                nonLinearStructMenu.show();
            }
        }
    }

    return 0;
}
