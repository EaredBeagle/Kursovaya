#include <iostream>
#include "savefile.h"
#include "QtWidgets/qapplication.h"
#include "QtWidgets/qgraphicsitem.h"
#include "widget.h"
#include "MyScene.h"
#include <QFileDialog>

#include <QDir>
#include <QFile>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QList>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QXmlStreamWriter>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

SaveFile::SaveFile(QWidget *parent) : QDialog(parent) { resize(270, 200); }

SaveFile::~SaveFile() {}

void SaveFile::sl_saveSceneToFile(QGraphicsScene *scene) {
  QJsonArray figures;

  foreach (QGraphicsItem *item, scene->items()) {
    QJsonObject jsonFigure;
    if (dynamic_cast<MoveItem1 *>(item) != nullptr) {
      MoveItem1 *moveitem1 = (MoveItem1 *)item;
      jsonFigure["xCoordinates"] = moveitem1->x();
      jsonFigure["yCoordinates"] = moveitem1->y();
      jsonFigure["type"] = 1;
    } else if (dynamic_cast<MoveItem2 *>(item) != nullptr) {
      MoveItem2 *moveitem2 = (MoveItem2 *)item;
      jsonFigure["xCoordinates"] = moveitem2->x();
      jsonFigure["yCoordinates"] = moveitem2->y();
      jsonFigure["type"] = 2;
    } else if (dynamic_cast<MoveItem3 *>(item) != nullptr) {
        MoveItem3 *moveitem3 = (MoveItem3 *)item;
        jsonFigure["xCoordinates"] = moveitem3->x();
        jsonFigure["yCoordinates"] = moveitem3->y();
        jsonFigure["type"] = 3;
    }
    else if (dynamic_cast<MoveItem4 *>(item) != nullptr) {
        MoveItem4 *moveitem4 = (MoveItem4 *)item;
        jsonFigure["xCoordinates"] = moveitem4->x();
        jsonFigure["yCoordinates"] = moveitem4->y();
        jsonFigure["type"] = 4;
    }
    else if (dynamic_cast<MoveItem5 *>(item) != nullptr) {
        MoveItem5 *moveitem5 = (MoveItem5 *)item;
        jsonFigure["xCoordinates"] = moveitem5->x();
        jsonFigure["yCoordinates"] = moveitem5->y();
        jsonFigure["type"] = 5;
    }
    else if (dynamic_cast<QGraphicsLineItem *>(item) != nullptr) {
        QGraphicsLineItem *line = dynamic_cast<QGraphicsLineItem *>(item);
        jsonFigure["startXCoordinates"] = line->line().x1();
        jsonFigure["startYCoordinates"] = line->line().y1();
        jsonFigure["endXCoordinates"] = line->line().x2();
        jsonFigure["endYCoordinates"] = line->line().y2();
        jsonFigure["type"] = 0;
        jsonFigure["color"] = line->pen().color().name();
    }
    else if (dynamic_cast<QGraphicsTextItem *>(item) != nullptr) {
        QGraphicsTextItem *textItem = dynamic_cast<QGraphicsTextItem *>(item);
        jsonFigure["xCoordinates"] = textItem->x();
        jsonFigure["yCoordinates"] = textItem->y();
        jsonFigure["text"] = textItem->toPlainText();
        jsonFigure["type"] = 6;
    }
    figures.append(jsonFigure);
  }

  QJsonDocument document(figures);
  QByteArray bytes = document.toJson(QJsonDocument::Indented);

  QString fileName = QFileDialog::getSaveFileName(
      this, "Save base", QCoreApplication::applicationDirPath(),
      "") + ".json";
  if (!fileName.isNull()) {
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
      QTextStream iStream(&file);
      iStream << bytes;
      file.close();
    } else {
      std::cout << "file open failed" << std::endl;
    }
  }
}
