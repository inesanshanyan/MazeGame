#include "menuController.hpp"

MenuController::MenuController(sf::RenderWindow &win)
    : window(win), menu(), menuDrawer(win) {

    menu.addOption("Basic Game");
    menu.addOption("Timer Game");
    menu.addOption("Exit");
}

void MenuController::execute() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up) {
                menu.moveUp();
            } else if (event.key.code == sf::Keyboard::Down) {
                menu.moveDown();
            } else if (event.key.code == sf::Keyboard::Enter) {
                if (menu.getSelectedOption() == 0) {
                    BasicGameController gameController(window);
                    gameController.execute();
                } else if (menu.getSelectedOption() == 1) {
                    TimerGameController timerController(window);
                    timerController.execute();
                } else if (menu.getSelectedOption() == 2) {
                    window.close(); 
                }
            }
        }
    }

    menuDrawer.drawMenu(menu, menu.getSelectedOption());
}
