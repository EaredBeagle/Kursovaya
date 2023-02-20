#pragma once

#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <algorithm>
#include <iostream>

#include "Line.h"
#include "movecomputer.h"
#include "moveitem.h"
#include "moveinternet.h"
#include <qnamespace.h>


class myGraphicsScene : public QGraphicsScene {
  Q_OBJECT
public:
  explicit myGraphicsScene(QObject *parent = nullptr);
  bool flag_line = false;

protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
  void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

private:
  Line* m_activeItem;
  bool flag_move = false;
  QPointF offset;
};

