#pragma once

#include "maze.hpp"

#include <QWidget>

class MazeDrawer : public QWidget {
    Q_OBJECT

public:
    MazeDrawer(Maze* maze, QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Maze* maze;
};


