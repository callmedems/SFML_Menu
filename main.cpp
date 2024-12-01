#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <string>

using namespace sf;
using namespace std;

// display the main menu
void showMenu(RenderWindow& window) {
    // Define the font
    Font font;
    if (!font.loadFromFile("assets/Roboto-Regular.ttf")) { // Replace with your font path
        cerr << "Error loading font\n";
        return;
    }

    // Menu items
    vector<string> menuItems = {"Start Game", "Options", "Exit"};
    vector<Text> menuTexts;
    int selectedItemIndex = 0;

    // Configure the menu text
    for (size_t i = 0; i < menuItems.size(); ++i) {
        Text text;
        text.setFont(font);
        text.setString(menuItems[i]);
        text.setCharacterSize(50);
        text.setFillColor(i == selectedItemIndex ? Color::Red : Color::White);
        text.setPosition(100, 100 + static_cast<float>(i) * 70); // Adjust the spacing
        menuTexts.push_back(text);
    }

    // Main loop
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::KeyPressed) {
                // Navigate up or down the menu
                if (event.key.code == Keyboard::Up) {
                    selectedItemIndex = (selectedItemIndex - 1 + menuItems.size()) % menuItems.size();
                } else if (event.key.code == Keyboard::Down) {
                    selectedItemIndex = (selectedItemIndex + 1) % menuItems.size();
                } else if (event.key.code == Keyboard::Enter) {
                    if (menuItems[selectedItemIndex] == "Start Game") {
                        cout << "Start Game selected\n";
                        // Add game start logic here
                    } else if (menuItems[selectedItemIndex] == "Options") {
                        cout << "Options selected\n";
                        // Add options logic here
                    } else if (menuItems[selectedItemIndex] == "Exit") {
                        window.close();
                    }
                }
            }
        }

        // Update text colors
        for (size_t i = 0; i < menuTexts.size(); ++i) {
            menuTexts[i].setFillColor(i == selectedItemIndex ? Color::Red : Color::White);
        }

        // Clear the window
        window.clear();

        // Draw the menu
        for (const auto& text : menuTexts) {
            window.draw(text);
        }

        // Display the window
        window.display();
    }
}

int main() {
    // Create a window
    RenderWindow window(VideoMode(800, 600), "SFML Menu Example");

    // Show the menu
    showMenu(window);

    return 0;
}
