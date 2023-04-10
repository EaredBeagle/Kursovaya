#include "loadfile.h"
#include "QtWidgets/qapplication.h"
#include "QtWidgets/qgraphicsitem.h"
#include "widget.h"
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

LoadFile::LoadFile() {}

LoadFile::~LoadFile() {}

void LoadFile::sl_loadSceneToFile(MyScene *scene) {
  //std::cout << "LOAD\n";
  QString fileName = QFileDialog::getOpenFileName(
      this, "Load base", QCoreApplication::applicationDirPath(),
      "");
  if (!fileName.isNull()) {
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly)) {
      QByteArray bytes = file.readAll();
      file.close();

      QJsonParseError jsonError;
      QJsonDocument document = QJsonDocument::fromJson(bytes, &jsonError);
      if (document.isArray()) {
        QJsonArray jsonArr = document.array();
        scene->clearScene();
        int start_x, start_y, end_x, end_y;
        QString color;
        QGraphicsLineItem* figure;
        MoveItem1 *moveitem1;
        MoveItem2 *moveitem2;
        MoveItem3 *moveitem3;
        MoveItem4 *moveitem4;
        MoveItem5 *moveitem5;
        QPen pen;
        pen.setWidth(5);// Толщина линии

        for (int i = 0; i < jsonArr.count(); ++i) {
          QJsonObject jsonObj = jsonArr.at(i).toObject();
          int type = jsonObj.take("type").toInt();

          switch (type) {
            case 0:
              // Line
              start_x = jsonObj.take("startXCoordinates").toInt();
              start_y = jsonObj.take("startYCoordinates").toInt();
              end_x = jsonObj.take("endXCoordinates").toInt();
              end_y = jsonObj.take("endYCoordinates").toInt();
              color = jsonObj.take("color").toString();
              figure = new QGraphicsLineItem(QLineF(QPointF(start_x, start_y), QPointF(end_x, end_y)));
              pen.setColor(color);
              figure->setFlag(QGraphicsItem::ItemIsMovable);
              figure->setPen(pen);
              scene->addItem(figure);
              break;
            case 1:
              // MoveItem
              start_x = jsonObj.take("xCoordinates").toInt();
              start_y = jsonObj.take("yCoordinates").toInt();
              moveitem1 = new MoveItem1();        // Создаём графический элемент стелажа
              moveitem1->setPos(start_x, start_y);
              scene->addItem(moveitem1);   // Добавляем элемент на графическую сцену
              break;
            case 2:
              // moveTable
              start_x = jsonObj.take("xCoordinates").toInt();
              start_y = jsonObj.take("yCoordinates").toInt();
              moveitem2 = new MoveItem2();        // Создаём графический элемент стелажа
              moveitem2->setPos(start_x, start_y);
              scene->addItem(moveitem2);   // Добавляем элемент на графическую сцену
              break;
            case 3:
              // moveCash
              start_x = jsonObj.take("xCoordinates").toInt();
              start_y = jsonObj.take("yCoordinates").toInt();
              moveitem3 = new MoveItem3();        // Создаём графический элемент стелажа
              moveitem3->setPos(start_x, start_y);
              moveitem3->update();
              scene->addItem(moveitem3);   // Добавляем элемент на графическую сцену
              break;
            case 4:
              // movePrinter
              start_x = jsonObj.take("xCoordinates").toInt();
              start_y = jsonObj.take("yCoordinates").toInt();
              moveitem4 = new MoveItem4();        // Создаём графический элемент стелажа
              moveitem4->setPos(start_x, start_y);
              moveitem4->update();
              scene->addItem(moveitem4);   // Добавляем элемент на графическую сцену
              break;
            case 5:
              // moveXerox
              start_x = jsonObj.take("xCoordinates").toInt();
              start_y = jsonObj.take("yCoordinates").toInt();
              moveitem5 = new MoveItem5();        // Создаём графический элемент стелажа
              moveitem5->setPos(start_x, start_y);
              moveitem5->update();
              scene->addItem(moveitem5);   // Добавляем элемент на графическую сцену
              break;
            case 6:
              // text
              start_x = jsonObj.take("xCoordinates").toInt();
              start_y = jsonObj.take("yCoordinates").toInt();
              QString text = jsonObj.take("text").toString();
              QGraphicsTextItem *textItem = scene->addText(text);
              textItem->setFlag(QGraphicsItem::ItemIsMovable);
              textItem->setDefaultTextColor(QColor("black"));
              textItem->setPos(start_x, start_y);
          }
        }
      }
    }
  }
}
