#pragma once

#include "menu.hpp"
#include "../View/menuDrawer.hpp"

#include "../Game/basicGameController.hpp"
#include "../Game/timerGameController.hpp"

class MenuController : public AbstractController {
public:
    explicit MenuController(sf::RenderWindow &win);
    void execute() override;

private:
    sf::RenderWindow &window;
    Menu menu;
    MenuDrawer menuDrawer;
};

