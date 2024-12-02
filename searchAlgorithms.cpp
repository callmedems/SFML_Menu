#include "searchAlgorithms.h"
#include <iostream>

using namespace std;
using namespace sf;

SearchAlgorithms::SearchAlgorithms(RenderWindow& win)
    : SubMenu(win, {"Linear Search", "Binary Search", "Back"}) {
    array = {10, 20, 30, 40, 50, 60, 70, 80, 90}; // Example array
    linearSearch = new linearSearch(win, array);
}

void SearchAlgorithms::show() {
    while (window.isOpen()) {
        drawMenu();

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                return;
            }
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Up) {
                    selectedIndex = (selectedIndex - 1 + menuItems.size()) % menuItems.size();
                } else if (event.key.code == Keyboard::Down) {
                    selectedIndex = (selectedIndex + 1) % menuItems.size();
                } else if (event.key.code == Keyboard::Enter) {
                    if (menuItems[selectedIndex] == "Back") {
                        return;
                    } else if (menuItems[selectedIndex] == "Linear Search") {
                        cout << "Enter the value to search for: ";
                        int value;
                        cin >> value;
                        linearSearch->setTarget(value);
                        linearSearch->visualizeSearch();
                    }
                }
            }
        }
    }
}
