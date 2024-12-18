#include "menuDrawer.hpp"

MenuDrawer::MenuDrawer(sf::RenderWindow &win) : window(win) {
    if (!font.loadFromFile("Assets/baskerville-old-face.ttf")) {
        std::cerr << "Failed to load font!\n";
    }

    title.setFillColor(sf::Color::White);

    title.setFont(font);
    title.setString("Maze Game");
    title.setCharacterSize(45);

    double windowWidth = window.getSize().x;
    double textWidth = title.getLocalBounds().width;
    title.setPosition((windowWidth - textWidth) / 2, 100);
}

void MenuDrawer::drawMenu(const Menu &menu, int selectedOption) {
    sf::Color leafGreen(97, 104, 82);
    window.clear(leafGreen);
    window.draw(title);

    sf::Color darkGreen(46, 47, 28);

    for (size_t i = 0; i < menu.getOptionsCount(); ++i) {
        sf::Text optionText;
        optionText.setFont(font);
        optionText.setString(std::to_string(i + 1) + ". " + menu.getOptionText(i));
        optionText.setCharacterSize(35);
        
        optionText.setPosition(200, 200 + static_cast<int>(i) * 50);

        if (i == selectedOption) {
            optionText.setFillColor(darkGreen);
        } else {
            optionText.setFillColor(sf::Color::White);
        }

        window.draw(optionText);
    }

    window.display();
}
