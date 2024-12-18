#include "./Menu/menuController.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 700), "Maze Game");
    MenuController menuController(window);

    while (window.isOpen()) {
        menuController.execute();
    }

    return 0;
}