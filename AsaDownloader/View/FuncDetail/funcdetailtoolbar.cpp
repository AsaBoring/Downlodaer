#include "funcdetailtoolbar.h"

FuncDetailToolBar::FuncDetailToolBar(QWidget *parent):
    AsaBaseFrame(parent)
{
    initLayout();
}

FuncDetailToolBar::~FuncDetailToolBar()
{
    if(btn_min != NULL){delete btn_min;}
    if(btn_close != NULL){delete btn_close;}
    if(up_frame != NULL){delete up_frame;}
    if(down_frame != NULL){delete down_frame;}
    if(v_layout != NULL){delete v_layout;}
    if(up_h_layout != NULL){delete up_h_layout;}
    if(down_h_layout != NULL){delete down_h_layout;}
}

void FuncDetailToolBar::initLayout()
{
    qDebug()<<"FuncDetailToolBar::initLayout";
    /*set btn*/
    btn_min = new ShadowButton(this);
    btn_min->setFixedSize(FUNC_DETAIL_TOOLBAR_BTN_MIN_WID,FUNC_DETAIL_TOOLBAR_BTN_MIN_HEI);
    btn_min->setIcon(QIcon(":/ViewResource/btn_min_normal.png"));
    btn_min->setIconSize(QSize(FUNC_DETAIL_TOOLBAR_BTN_MIN_ICON_SIZE,FUNC_DETAIL_TOOLBAR_BTN_MIN_ICON_SIZE));
    btn_min->setClickShadow(false);

    btn_close = new ShadowButton(this);
    btn_close->setFixedSize(FUNC_DETAIL_TOOLBAR_BTN_CLOSE_WID,FUNC_DETAIL_TOOLBAR_BTN_CLOSE_HEI);
    btn_close->setIcon(QIcon(":/ViewResource/btn_close_normal.png"));
    btn_close->setIconSize(QSize(FUNC_DETAIL_TOOLBAR_BTN_CLOSE_ICON_SIZE,FUNC_DETAIL_TOOLBAR_BTN_CLOSE_ICON_SIZE));
    btn_close->setClickShadow(false);

    btn_min->setStyleSheet("border:none;");
    btn_close->setStyleSheet("border:none;");

    /*set frame*/
    up_frame = new QFrame(this);
    up_frame->setFixedSize(FUNC_DETAIL_TOOLBAR_UP_FRAME_WID,FUNC_DETAIL_TOOLBAR_UP_FRAME_HEI);

    down_frame = new QFrame(this);
    down_frame->setFixedSize(FUNC_DETAIL_TOOLBAR_DOWN_FRAME_WID,FUNC_DETAIL_TOOLBAR_DOWN_FRAME_HEI);

    /*set layout*/
    up_h_layout = new QHBoxLayout(this);
    up_h_layout->setMargin(0);
    up_h_layout->setSpacing(0);
    up_h_layout->addStretch();
    up_h_layout->addWidget(btn_min);
    up_h_layout->addSpacing(10);
    up_h_layout->addWidget(btn_close);
    up_h_layout->addSpacing(5);
    up_frame->setLayout(up_h_layout);

    v_layout = new QVBoxLayout(this);
    v_layout->setMargin(0);
    v_layout->setSpacing(0);
    v_layout->addStretch();
    v_layout->addWidget(up_frame);
    v_layout->addWidget(down_frame);
    v_layout->addStretch();

    setLayout(v_layout);
}
