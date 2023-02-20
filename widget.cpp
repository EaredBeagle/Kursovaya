#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <savefile.h>
#include <loadfile.h>

/* Функция для получения рандомного числа
 * в диапазоне от минимального до максимального
 * */
static int randomBetween(int low, int high)
{
    return (qrand() % ((high + 1) - low) + low);
}

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{


    ui->setupUi(this);



    scene = new MyScene(this);   // Инициализируем графическую сцену
    scene->setItemIndexMethod(QGraphicsScene::NoIndex); // настраиваем индексацию элементов

    this->resize(1920,1080);  // Устанавливаем размер graphicsView


    ui->graphicsView->setScene(scene);  // Устанавливаем графическую сцену в graphicsView
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    // Настраиваем рендер
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground); // Кэш фона
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    scene->setSceneRect(0,0,1920,1080); // Устанавливаем размер сцены
    scene->setBackgroundBrush(QColor("#333"));
}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_pushButton1_clicked()
{
    MoveItem1 *item = new MoveItem1();        // Создаём графический элемента
    item->setPos(randomBetween(550, 500),    // Устанавливаем случайную позицию элемента
                 randomBetween(550,500));
    scene->addItem(item);   // Добавляем элемент на графическую сцену

}

void Widget::on_pushButton2_clicked()
{
    MoveItem2 *item = new MoveItem2();        // Создаём графический элемента
    item->setPos(randomBetween(550, 500),    // Устанавливаем случайную позицию элемента
                 randomBetween(550, 500));
    scene->addItem(item);   // Добавляем элемент на графическую сцену

}

void Widget::on_pushButton3_clicked()
{
    MoveItem3 *item = new MoveItem3();        // Создаём графический элемента
    item->setPos(randomBetween(550, 500),    // Устанавливаем случайную позицию элемента
                 randomBetween(550,500));
    scene->addItem(item);   // Добавляем элемент на графическую сцену

}

void Widget::on_pushButton_clicked()
{
    this->close();
}

void Widget::on_SavePNG_clicked()
{

    // сохранить png
    QImage image(scene->width(), scene->height(), QImage::Format_ARGB32_Premultiplied);
    QPainter painter(&image);
    scene->render(&painter);

    QString fileName = QFileDialog::getSaveFileName(this, "Save base",QCoreApplication::applicationDirPath(), "") +".png";
      if (!fileName.isNull()) {
          QFile file(fileName);
          if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
              QTextStream iStream(&file);
          image.save(fileName);
          file.close();
          }
      }
}

void Widget::on_ClearScene_clicked()
{
   scene->clearScene();
   //ui->graphicsView->items().clear();
}

void Widget::on_pushButtonSave_clicked()
{
    SaveFile dialog;
    dialog.sl_saveSceneToFile(scene);
}


void Widget::on_pushButton_2_clicked()
{
    LoadFile load;
    load.sl_loadSceneToFile(scene);
    scene->update();
}

void Widget::on_checkBox_stateChanged(int arg1)
{
    set_remove = arg1;
    dynamic_cast<MyScene*>(scene)->setLineActiveFlag(arg1);
}

