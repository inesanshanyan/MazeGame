#include "timer.hpp"

Timer::Timer() : isRunning(false), elapsedTime(0), countdownDuration(0), initTime(11) {}

void Timer::start(float duration) {
    countdownDuration = duration;  
    clock.restart();               
    isRunning = true;
}

void Timer::stop() {
    if (isRunning) {
        elapsedTime = clock.getElapsedTime().asSeconds();  
        isRunning = false;
    }
}

void Timer::reset() {
    clock.restart();  
    elapsedTime = 0;
    isRunning = true;
}

double Timer::getRemainingTime() const {
    if (isRunning) {
        double timeLeft = countdownDuration - clock.getElapsedTime().asSeconds();
        return timeLeft > 0 ? timeLeft : 0; 
    }
    return countdownDuration - elapsedTime;  
}

bool Timer::isTimeUp() const {
    return getRemainingTime() <= 0;
}

bool Timer::isTimerRunning() const {
    return isRunning;
}

int Timer::getInitTime() const {
    return initTime;
}