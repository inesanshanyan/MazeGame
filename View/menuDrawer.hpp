#pragma once

#include <SFML/Graphics.hpp>

#include "../Menu/menu.hpp"

class MenuDrawer {
public:
    explicit MenuDrawer(sf::RenderWindow &win);
    void drawMenu(const Menu &menu, int selectedOption);

private:
    sf::RenderWindow &window;
    sf::Font font;
    sf::Text title;
    
};


