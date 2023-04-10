#include "movecomputer.h"
#include <QPainter>

MoveItem1::MoveItem1(QObject *parent) :
    QObject(parent), QGraphicsItem()
{

}

MoveItem1::~MoveItem1()
{

}

QRectF MoveItem1::boundingRect() const
{
    return QRectF (-30,-30,100,100);
}

void MoveItem1::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QImage image("://img/computer.svg");
    QRect recr(-30,-30,100,100);
    painter->drawImage(recr,image);

}

void MoveItem1::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    /* Устанавливаем позицию графического элемента
     * в графической сцене, транслировав координаты
     * курсора внутри графического элемента
     * в координатную систему графической сцены
     * */
    this->setPos(mapToScene(event->pos()));
}

void MoveItem1::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    /* При нажатии мышью на графический элемент
     * заменяем курсор на руку, которая держит этот элемента
     * */
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void MoveItem1::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    /* При отпускании мышью элемента
     * заменяем на обычный курсор стрелку
     * */
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}
