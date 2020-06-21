#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    initSetting();
    initLayout();
}

MainWindow::~MainWindow()
{
    if(main_frame != NULL){main_frame->deleteLater();}
    if(main_menu != NULL){main_menu->deleteLater();}
    if(func_detail != NULL){func_detail->deleteLater();}
    if(h_main_layout != NULL){h_main_layout->deleteLater();}
}

void MainWindow::initSetting()
{
    setWindowFlags(Qt::FramelessWindowHint);
    setFixedSize(MAIN_WINDOW_WID,MAIN_WINDOW_HEI);
}

void MainWindow::initLayout()
{
    /*set main window*/

    /*set frame*/
    main_frame = new AsaBaseFrame(this);
    main_frame->setFixedSize(MAIN_WINDOW_WID,MAIN_WINDOW_HEI);
    main_frame->setIconSize(QSize(MAIN_WINDOW_WID,MAIN_WINDOW_HEI));
    main_frame->setIcon(QIcon(":/ViewResource/backGround.png"));

    main_menu = new MainMenu(this);
    main_menu->setFixedSize(MAIN_MENU_FRAME_WID,MAIN_MENU_FRAME_HEI);

    func_detail = new FuncDetail(this);
    func_detail->setFixedSize(FUNC_DETAIL_WID,FUNC_DETAIL_HEI);

    /*set layout*/
    h_main_layout = new QHBoxLayout(this);
    h_main_layout->setSpacing(0);
    h_main_layout->setMargin(0);
    h_main_layout->addStretch();
    h_main_layout->addWidget(main_menu);
    h_main_layout->addWidget(func_detail);
    h_main_layout->addStretch();

    main_frame->setLayout(h_main_layout);
}
