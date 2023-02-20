#ifndef WIDGET_H
#define WIDGET_H

#include <ui_widget.h>
#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include <QResizeEvent>

#include <movecomputer.h>
#include<moveinternet.h>
#include <moveswitch.h>
#include <MyScene.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:


    void on_pushButton_clicked();

    void on_pushButton1_clicked();

    void on_pushButton2_clicked();

    void on_SavePNG_clicked();

    void on_ClearScene_clicked();

    void on_pushButton3_clicked();

    void on_pushButtonSave_clicked();

    void on_pushButton_2_clicked();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::Widget *ui;
    MyScene* scene;
    int set_remove = 0;
};

#endif // WIDGET\_H
