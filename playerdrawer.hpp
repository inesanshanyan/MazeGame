#pragma once

#include "player.hpp"
#include "maze.hpp"

#include <QWidget>

class PlayerDrawer : public QWidget {
    Q_OBJECT
public:
    PlayerDrawer(Player* player, Maze* maze, QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;

private:
    Player* player;
    Maze* maze;
    const int cellSize = 20;
};


