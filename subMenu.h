#ifndef SUBMENU_H
#define SUBMENU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

using namespace std;
using namespace sf;

class SubMenu {
protected:
    RenderWindow& window;
    vector<string> menuItems;
    int selectedIndex;

    void drawMenu(); // Draws the submenu items

public:
    SubMenu(RenderWindow& win, const vector<string>& items);

    virtual void show(); // Display the submenu (virtual for extension)
};

#endif // SUBMENU_H
