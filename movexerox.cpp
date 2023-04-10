#include "movexerox.h"
#include <QPainter>

MoveItem5::MoveItem5(QObject *parent) :
    QObject(parent), QGraphicsItem()
{

}

MoveItem5::~MoveItem5()
{

}

QRectF MoveItem5::boundingRect() const
{
    return QRectF (-30,-30,100,100);
}

void MoveItem5::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QImage image("://img/xerox.svg");
    QRect recr(-30,-30,100,100);
    painter->drawImage(recr,image);

}

void MoveItem5::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    /* Устанавливаем позицию графического элемента
     * в графической сцене, транслировав координаты
     * курсора внутри графического элемента
     * в координатную систему графической сцены
     * */
    this->setPos(mapToScene(event->pos()));

}

void MoveItem5::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    /* При нажатии мышью на графический элемент
     * заменяем курсор на руку, которая держит этот элемента
     * */
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void MoveItem5::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    /* При отпускании мышью элемента
     * заменяем на обычный курсор стрелку
     * */
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}
