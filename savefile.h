#ifndef SAVEFILE_H
#define SAVEFILE_H
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

class SaveFile : public QDialog
{
    Q_OBJECT
public:
    SaveFile(QWidget *parent = 0);
    ~SaveFile();

public slots:
    void sl_saveSceneToFile(QGraphicsScene *scene);

private:
};
#endif // SAVEFILE_H
