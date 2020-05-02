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

private:
    AsaBaseFrame * main_frame = NULL;
    MainMenu * main_menu = NULL;
    FuncDetail * func_detail = NULL;

    QHBoxLayout * h_main_layout = NULL;

    void initSetting();
    void initLayout();

public slots:
    inline AsaBaseFrame * fetchMainFramePtr(){return main_frame;}
    inline MainMenu * fetchMainMenuPtr(){return main_menu;}
    inline FuncDetail * fetchFuncDetailPtr(){return func_detail;}

};

#endif // MAINWINDOW_H
