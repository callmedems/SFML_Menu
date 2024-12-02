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

    // display the submenu (virtual for extension)
    // int type to get selectedIndex in return
    virtual int show();
};

#endif // SUBMENU_H
