#include "widget.h"
#include <QtCore/QObject>
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Создаем объект secondWindow
        secondWindow *secondWin = new secondWindow();
         // Передаем указатель на secondWindow
    Widget w(secondWin);
    w.show();
    return a.exec();
}
