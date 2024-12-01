#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <memory>

using namespace std;
using namespace sf;

class MainMenu {
    private:
        RenderWindow& window;
        vector<string> menuItems;
        int selectedIndex;

        // Helper function to draw the menu
        void drawMenu();

    public:
        MainMenu(RenderWindow& win);

        // Display the main menu and navigate to submenus
        int show();
};

#endif // MAINMENU_H