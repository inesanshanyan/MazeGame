#include "mainwidget.hpp"

#include <QKeyEvent>
#include <QVBoxLayout>
#include <QPainter>

MainWidget::MainWidget(QWidget *parent):
    QWidget(parent),
    maze(20, 20),
    player(0, 0),
    mazeDrawer(&maze, this),
    playerDrawer(&player, &maze, this) {

    maze.generateMaze();
    setFixedSize(maze.getMaze()[0].size() * 20, maze.getMaze().size() * 20); // main widget size
}

void MainWidget::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_Up:
        player.move(0, -1, maze);
        break;
    case Qt::Key_Down:
        player.move(0, 1, maze);
        break;
    case Qt::Key_Left:
        player.move(-1, 0, maze);
        break;
    case Qt::Key_Right:
        player.move(1, 0, maze);
        break;
    }


    playerDrawer.update();
    update();
}

void MainWidget::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
}
