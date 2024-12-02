#include "subMenu.h"
#include "fontManager.h"
#include <iostream>

using namespace std;
using namespace sf;

SubMenu::SubMenu(RenderWindow& win, const vector<string>& items)
    : window(win), menuItems(items), selectedIndex(0) {}

void SubMenu::drawMenu() {
    window.clear(Color::Black);


    for (size_t i = 0; i < menuItems.size(); ++i) {
        Text text(menuItems[i], FontManager::font, 30);
        text.setPosition(100, 100 + i * 50);
        text.setFillColor(i == selectedIndex ? Color::Red : Color::White);
        window.draw(text);
    }

    window.display();
}

int SubMenu::show() {
    while (window.isOpen()) {
        drawMenu();

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                return -1;
            }
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Up) {
                    selectedIndex = (selectedIndex - 1 + menuItems.size()) % menuItems.size();
                } else if (event.key.code == Keyboard::Down) {
                    selectedIndex = (selectedIndex + 1) % menuItems.size();
                } else if (event.key.code == Keyboard::Enter) {
                    if (menuItems[selectedIndex] == "Regresar") {
                        return -1; // exit submenu and a signal
                    } else {
                        return selectedIndex; // return the selected option
                    }
                }
            }
        }
    }
    return -1; // default return in case of unexpected closure
}
