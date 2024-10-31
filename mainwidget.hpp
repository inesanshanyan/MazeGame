#pragma once

#include "maze.hpp"
#include "player.hpp"
#include "mazedrawer.hpp"
#include "playerdrawer.hpp"

#include <QWidget>
#include <QKeyEvent>

class MainWidget : public QWidget {
    Q_OBJECT
public:
    MainWidget(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    Maze maze;
    Player player;
    MazeDrawer mazeDrawer;
    PlayerDrawer playerDrawer;
};


