#pragma once

#include <SFML/System.hpp>

class Timer {
public:
    Timer();               

    void start(float duration);  
    void stop();                 
    void reset();               

    double getRemainingTime() const;  
    bool isTimeUp() const;          
    bool isTimerRunning() const; 
     
    
    int getInitTime() const;  


private:
    sf::Clock clock;      
    bool isRunning;        
    double elapsedTime;     
    double countdownDuration; 
    
    double initTime;

};
