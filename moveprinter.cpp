#include "moveprinter.h"
#include <QPainter>

MoveItem4::MoveItem4(QObject *parent) :
    QObject(parent), QGraphicsItem()
{

}

MoveItem4::~MoveItem4()
{

}

QRectF MoveItem4::boundingRect() const
{
    return QRectF (-30,-30,100,100);
}

void MoveItem4::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QImage image("://img//PrinterKiller-Printer.svg");
    QRect recr(-30,-30,90,90);
    painter->drawImage(recr,image);

}

void MoveItem4::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    /* Устанавливаем позицию графического элемента
     * в графической сцене, транслировав координаты
     * курсора внутри графического элемента
     * в координатную систему графической сцены
     * */
    this->setPos(mapToScene(event->pos()));
}

void MoveItem4::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    /* При нажатии мышью на графический элемент
     * заменяем курсор на руку, которая держит этот элемента
     * */
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void MoveItem4::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    /* При отпускании мышью элемента
     * заменяем на обычный курсор стрелку
     * */
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}
