#pragma once

#include "abstractController.hpp"
#include "basicGame.hpp"
#include "../View/basicGameDrawer.hpp"


class BasicGameController : public AbstractController {
public:
    explicit BasicGameController(sf::RenderWindow &win);
    void execute() override;
    
protected:
    sf::RenderWindow &window;
    BasicGame game;
    BasicGameDrawer drawer;
};