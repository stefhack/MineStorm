#include "mainwindow.h"
//#include "dummygame.h"
#include "mindstormgame.h"
#include <QSize>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //DummyGame game(QSize(400,400));
    MindStormGame game(QSize(600,600));
    MainWindow w(&game);
    return a.exec();
}
