#include "player.hpp"

Player::Player(int startX, int startY) : x(startX), y(startY) {  }

void Player::move(int dx, int dy, const Maze& maze) {
    int newX = x + dx;
    int newY = y + dy;

    const auto& mazeData = maze.getMaze();
    if (newX >= 0 && newX < mazeData[0].size() && newY >= 0 && newY < mazeData.size()) {
        if (mazeData[newY][newX]) {
            x = newX;
            y = newY;
        }
    }
}

int Player::getX() const {
    return x;
}

int Player::getY() const {
    return y;
}

