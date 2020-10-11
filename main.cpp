#include "mainwindow.h"
#include "player.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setFixedSize(1040,600);
    w.setWindowTitle("红黑夜法官");

    return a.exec();
}
