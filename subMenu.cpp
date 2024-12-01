#include "SubMenu.h"
#include <iostream>

using namespace std;
using namespace sf;

SubMenu::SubMenu(RenderWindow& win, const vector<string>& items)
    : window(win), menuItems(items), selectedIndex(0) {}

void SubMenu::drawMenu() {
    window.clear(Color::Black);

    Font font;
    if (!font.loadFromFile("arial.ttf")) {
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

void SubMenu::show() {
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
                        return; // Exit submenu
                    } else {
                        cout << "Selected: " << menuItems[selectedIndex] << endl;
                    }
                }
            }
        }
    }
}
