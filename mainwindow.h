#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "player.h"
#include <QMainWindow>
#include <QPushButton>
#include <QTime>
#include <QDebug>
#include <QMessageBox>
#include <qinputdialog.h>
#include <QPainter>
#include <qdrawutil.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int st[3][5]={{0},{0},{0}};
    int m[3][5]={{0},{0},{0}};
    int k[3][5]={{0},{0},{0}};
    int bgpic;
 void paintEvent(QPaintEvent *);
    QPushButton *butten;

public slots:
    void slotstarts();

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
