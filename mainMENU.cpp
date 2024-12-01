#include "mainMenu.h"
#include <iostream>

using namespace std;
using namespace sf;

MainMenu::MainMenu(RenderWindow& win) : window(win), selectedIndex(0) {
    menuItems = {"Algoritmos de Busqueda", "Algoritmos de Ordenamiento", "Estructuras Lineales",
                 "Estructuras No Lineales", "Salir"};
}

void MainMenu::drawMenu() {
    window.clear(Color::Black);

    Font font;
    if (!font.loadFromFile("assets/Roboto-Regular.ttf")) {
        cerr << "Error loading font\n";
        return;
    }

    for (size_t i = 0; i < menuItems.size(); ++i) {
        Text text(menuItems[i], font, 30);
        text.setPosition(100, 100 + i * 50);
        text.setFillColor(i == selectedIndex ? Color::Red : Color::White);
        window.draw(text);
    }

    window.display();
}

int MainMenu::show() {
    while (window.isOpen()) {
        drawMenu();

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                return -1; // Exit signal
            }
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Up) {
                    selectedIndex = (selectedIndex - 1 + menuItems.size()) % menuItems.size();
                } else if (event.key.code == Keyboard::Down) {
                    selectedIndex = (selectedIndex + 1) % menuItems.size();
                } else if (event.key.code == Keyboard::Enter) {
                    return selectedIndex; // Return user choice
                }
            }
        }
    }

    return -1; // Default return in case of unexpected closure
}
