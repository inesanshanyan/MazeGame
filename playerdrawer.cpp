#include "playerdrawer.hpp"

#include <QPainter>

PlayerDrawer::PlayerDrawer(Player* player, Maze* maze, QWidget *parent)
    : QWidget(parent), player(player), maze(maze) {
    setFixedSize(maze->getMaze()[0].size() * cellSize, maze->getMaze().size() * cellSize);
    //setAttribute(Qt::WA_TransparentForMouseEvents);
    //setAttribute(Qt::WA_OpaquePaintEvent, false);
}

void PlayerDrawer::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    QColor playerColor(153, 0, 0);
    painter.setBrush(playerColor);
    painter.drawEllipse(player->getX() * cellSize, player->getY() * cellSize, cellSize, cellSize);
}
