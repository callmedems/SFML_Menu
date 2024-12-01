#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "MainMenu.h"
#include "SubMenu.h"

using namespace std;
using namespace sf;

int main() {
    RenderWindow window(VideoMode(800, 600), "MENU PRINCIPAL");

    while (window.isOpen()) {
        MainMenu mainMenu(window);
        int choice = mainMenu.show();

        if (choice == -1 || choice == 4) {
            // exit has been chosen
            window.close();
        } else {
            // Submenu categories
            if (choice == 0) {
                SubMenu searchMenu(window, {"Secuencial", "Busqueda Binaria", "Back"});
                searchMenu.show();
            } else if (choice == 1) {
                SubMenu sortingMenu(window, {"Bubble Sort", "Selection Sort",
                    "Insertion Sort", "Merge Sort", "Quick Sort", "Back"});
                sortingMenu.show();
            } else if (choice == 2) {
                SubMenu linearStructMenu(window, {"Stacks", "Queues",
                    "Linked Lists", "Back"});
                linearStructMenu.show();
            } else if (choice == 3) {
                SubMenu nonLinearStructMenu(window, {"Arboles AVL", "Dijkstra",
                    "DFS", "BFS", "Back"});
                nonLinearStructMenu.show();
            }
        }
    }

    return 0;
}
