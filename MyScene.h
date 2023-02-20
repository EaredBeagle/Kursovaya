#pragma once

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsLineItem>
#include <QPen>


class MyScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MyScene(QObject *parent = nullptr);

    void setLineActiveFlag(bool);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void clearScene();

private:
    bool is_line_active;
    QPointF first_line_coord;
    QGraphicsLineItem *line;
    bool is_mouse_pressed;
    bool is_right_mouse_button_pressed;
    QGraphicsEllipseItem *erase;
    int erase_size = 40;
};


