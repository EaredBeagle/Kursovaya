#include "MyScene.h"
#include <iostream>

MyScene::MyScene(QObject *parent)
  : QGraphicsScene{parent}
{
    is_line_active = false;
    first_line_coord = {-1, -1};
    is_mouse_pressed = false;
    is_right_mouse_button_pressed = false;
    line = nullptr;
    erase = new QGraphicsEllipseItem(0, 0, erase_size, erase_size);
    this->addItem(erase);
    erase->hide();
    this->color = QColor("black");
}

void MyScene::setLineActiveFlag(bool flag)
{
    is_line_active = flag;
    std::cout << "I'm here!" << std::endl;
}

void MyScene::setColor(QColor color)
{
    this->color = color;
}

void MyScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (is_line_active & Qt::LeftButton) {
        first_line_coord = event->scenePos();
        is_mouse_pressed = true;
    }
    if(!is_line_active && event->button() & Qt::RightButton){
        is_right_mouse_button_pressed = true;
        erase->setPos(event->scenePos().x() - erase_size / 2., event->scenePos().y() - erase_size / 2.);
    }

    QGraphicsScene::mousePressEvent(event);
}

void MyScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (is_line_active && is_mouse_pressed && first_line_coord != QPointF{-1, -1}) {
        if (line != nullptr) delete line;
        line = new QGraphicsLineItem(QLineF(first_line_coord, event->scenePos()));
        line->setFlag(QGraphicsItem::ItemIsMovable);
        QPen pen(this->color);
        pen.setWidth(5);// Толщина линии
        line->setPen(pen);
        this->addItem(line);
    }
    if (is_right_mouse_button_pressed) {
        erase->setPos(event->scenePos().x() - erase_size / 2., event->scenePos().y() - erase_size / 2.);
        QList<QGraphicsItem *> items_for_erase = this->collidingItems(erase);
        std::cout << items_for_erase.size() << std::endl;
        for (auto i : items_for_erase) delete i;
    }

    QGraphicsScene::mouseMoveEvent(event);
}

void MyScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (is_line_active && first_line_coord != QPoint{-1, -1}) {
        if (line != nullptr) delete line;
        line = new QGraphicsLineItem(QLineF(first_line_coord, event->scenePos()));
        line->setFlag(QGraphicsItem::ItemIsMovable);
        QPen pen(this->color);
        pen.setWidth(5);// Толщина линии
        line->setPen(pen);
        this->addItem(line);
        line = nullptr;
        first_line_coord = {-1, -1};
    }
    is_line_active = false;
    is_mouse_pressed = false;
    is_right_mouse_button_pressed = false;
    QGraphicsScene::mouseReleaseEvent(event);
}

void MyScene::clearScene() {
    QGraphicsScene::clear();
    erase = new QGraphicsEllipseItem(0, 0, erase_size, erase_size);
    this->addItem(erase);
    erase->hide();
}
