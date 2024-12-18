#pragma once

#include "basicGameController.hpp"
#include "../Components/timer.hpp"           
#include "../View/timerDrawer.hpp"   

#include <iostream>  

class TimerGameController : public BasicGameController {
public:
    explicit TimerGameController(sf::RenderWindow &win);
    void execute() override; 

private:
    Timer timer;          
    TimerDrawer timerDrawer;  
};
