#include <SFML/Graphics.hpp>
#include "mainMenu.h"
#include "subMenu.h"

using namespace std;
using namespace sf;

int main() {
    RenderWindow window(VideoMode(800, 600), "MENU PRINCIPAL");

    while (window.isOpen()) {
        MainMenu mainMenu(window);
        int choice = mainMenu.show();

        if (choice == -1 || choice == 4) {
            // Exit chosen
            window.close();
        } else {
            switch (choice) {
                case 0: {
                    // Submenu for search algorithms
                    SubMenu searchMenu(window, {"Secuencial", "Busqueda Binaria", "Regresar"});
                    searchMenu.show();
                    break;
                }
                case 1: {
                    // Submenu for sorting algorithms
                    SubMenu sortingMenu(window, {"Bubble Sort", "Selection Sort",
                        "Insertion Sort", "Merge Sort", "Quick Sort", "Regresar"});
                    sortingMenu.show();
                    break;
                }
                case 2: {
                    // Submenu for linear data structures
                    SubMenu linearStructMenu(window, {"Stacks", "Queues",
                        "Linked Lists", "Regresar"});
                    linearStructMenu.show();
                    break;
                }
                case 3: {
                    // Submenu for non-linear data structures
                    SubMenu nonLinearStructMenu(window, {"Arboles AVL", "Dijkstra",
                        "DFS", "BFS", "Regresar"});
                    nonLinearStructMenu.show();
                    break;
                }
                default:
                    break;
            }
        }
    }

    return 0;
}
