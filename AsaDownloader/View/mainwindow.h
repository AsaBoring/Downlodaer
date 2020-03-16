#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "common.h"
#include "MainMenu/mainmenu.h"
#include "FuncDetail/funcdetail.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    AsaBaseFrame * main_frame = NULL;
    MainMenu * main_menu = NULL;
    FuncDetail * func_detail = NULL;

    QHBoxLayout * h_main_layout = NULL;

private:
    void initSetting();
    void initLayout();

protected:
};

#endif // MAINWINDOW_H
