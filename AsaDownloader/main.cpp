#include "presenter.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Presenter presenter(&w);
    w.show();

    return a.exec();

}
