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
    scene->setBackgroundBrush(QColor("#FFFFFF"));
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

void Widget::on_pushButton_Printer_clicked()
{
    MoveItem4 *item = new MoveItem4();        // Создаём графический элемента
    item->setPos(randomBetween(550, 500),    // Устанавливаем случайную позицию элемента
                 randomBetween(550,500));
    scene->addItem(item);   // Добавляем элемент на графическую сцену
}

void Widget::on_pushButton_Xerox_clicked()
{
    MoveItem5 *item = new MoveItem5();        // Создаём графический элемента
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

void Widget::on_comboBox_currentIndexChanged(int index)
{
    QColor color;
    switch(index) {
        case 0:
        color = QColor("black");
        break;
        case 1:
        color = QColor("red");
        break;
        case 2:
        color = QColor("blue");
        break;
        case 3:
        color = QColor("green");
        break;
    }
    dynamic_cast<MyScene*>(scene)->setColor(color);
}


void Widget::on_pushButton_3_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                     tr("Please enter your text"), QLineEdit::Normal,
                                     "Replace with your text", &ok);
    if (!ok || text.isEmpty()) return;
    QGraphicsTextItem *textItem = this->scene->addText(text);
    textItem->setFlag(QGraphicsItem::ItemIsMovable);
    textItem->setDefaultTextColor(QColor("black"));
    textItem->setPos(randomBetween(550, 500),    // Устанавливаем случайную позицию элемента
                 randomBetween(550,500));
}


void Widget::on_pushButton_4_clicked()
{
    dynamic_cast<MyScene*>(scene)->setLineActiveFlag(true);
}

