#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    // Запуск в полноэкранном режиме без трея
    w.show();
    return a.exec();
}
