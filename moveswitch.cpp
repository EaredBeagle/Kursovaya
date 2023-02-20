#include "moveswitch.h"
#include <QPainter>

MoveItem2::MoveItem2(QObject *parent) :
    QObject(parent), QGraphicsItem()
{

}

MoveItem2::~MoveItem2()
{

}

QRectF MoveItem2::boundingRect() const
{
    return QRectF (-30,-30,160,100);
}

void MoveItem2::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QImage image(":/Загрузки/free-icon-network-switch-5517192.png");
    QRect recr(-30,-30,160,100);
    painter->drawImage(recr,image);

}

void MoveItem2::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    /* Устанавливаем позицию графического элемента
     * в графической сцене, транслировав координаты
     * курсора внутри графического элемента
     * в координатную систему графической сцены
     * */
    this->setPos(mapToScene(event->pos()));

}

void MoveItem2::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    /* При нажатии мышью на графический элемент
     * заменяем курсор на руку, которая держит этот элемента
     * */
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void MoveItem2::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    /* При отпускании мышью элемента
     * заменяем на обычный курсор стрелку
     * */
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}
