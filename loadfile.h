#ifndef LOADFILE_H
#define LOADFILE_H
#include "QtWidgets/qgraphicsitem.h"
#include <QDialog>
#include "MyScene.h"

class QGraphicsScene;
class moveTable;
class MoveItem;
class moveCash;
class line;
class QGraphicsView;
class QVBoxLayout;

class LoadFile : public QDialog
{
    Q_OBJECT
public:
    LoadFile();
    ~LoadFile();
    void sl_loadSceneToFile(MyScene *scene);
signals:
     void signalFromElem(QGraphicsItem *pressElem); // сигнал для удаления
};

#endif // LOADFILE_H
