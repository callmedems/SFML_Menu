#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include <SFML/Graphics.hpp>
#include <iostream>

class FontManager {
public:
    // Miembro estático de la clase FontManager
    static sf::Font font;

    // Función para cargar la fuente
    static bool loadFont(const std::string& fontPath) {
        if (!font.loadFromFile(fontPath)) {
            std::cerr << "Error al cargar la fuente!" << std::endl;
            return false;
        }
        return true;
    }
};


#endif //FONTMANAGER_H
