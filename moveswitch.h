#pragma once

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsLineItem>
#include <QTimer>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <QWidget>

class MoveItem2 : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit MoveItem2(QObject *parent = 0);
    ~MoveItem2();
private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

public slots:
};
