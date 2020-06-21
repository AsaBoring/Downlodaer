#include "funcdetailtoolbar.h"

FuncDetailToolBar::FuncDetailToolBar(QWidget *parent):
    AsaBaseFrame(parent)
{
    initLayout();
}

FuncDetailToolBar::~FuncDetailToolBar()
{
    if(btn_min != NULL){btn_min->deleteLater();}
    if(btn_close != NULL){btn_close->deleteLater();}
    if(up_frame != NULL){up_frame->deleteLater();}
    if(down_frame != NULL){down_frame->deleteLater();}
    if(v_layout != NULL){v_layout->deleteLater();}
    if(up_h_layout != NULL){up_h_layout->deleteLater();}
    if(down_h_layout != NULL){down_h_layout->deleteLater();}
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

    btn_new = new ShadowButton(this);
    btn_new->setFixedSize(FUNC_DETAIL_TOOLBAR_BTN_NEW_WID,FUNC_DETAIL_TOOLBAR_BTN_NEW_HEI);
    btn_new->setIcon(QIcon(":/ViewResource/btn_new_normal.png"));
    btn_new->setIconSize(QSize(FUNC_DETAIL_TOOLBAR_BTN_NEW_ICON_WID,FUNC_DETAIL_TOOLBAR_BTN_NEW_ICON_HEI));
    btn_new->setClickShadow(false);

    btn_start = new ShadowButton(this);
    btn_start->setFixedSize(FUNC_DETAIL_TOOLBAR_BTN_START_WID,FUNC_DETAIL_TOOLBAR_BTN_START_HEI);
    btn_start->setIcon(QIcon(":/ViewResource/btn_start_normal.png"));
    btn_start->setIconSize(QSize(FUNC_DETAIL_TOOLBAR_BTN_START_ICON_SIZE,FUNC_DETAIL_TOOLBAR_BTN_START_ICON_SIZE));
    btn_start->setClickShadow(false);

    btn_stop = new ShadowButton(this);
    btn_stop->setFixedSize(FUNC_DETAIL_TOOLBAR_BTN_STOP_WID,FUNC_DETAIL_TOOLBAR_BTN_STOP_HEI);
    btn_stop->setIcon(QIcon(":/ViewResource/btn_stop_normal.png"));
    btn_stop->setIconSize(QSize(FUNC_DETAIL_TOOLBAR_BTN_STOP_ICON_SIZE,FUNC_DETAIL_TOOLBAR_BTN_STOP_ICON_SIZE));
    btn_stop->setClickShadow(false);

    btn_delete = new ShadowButton(this);
    btn_delete->setFixedSize(FUNC_DETAIL_TOOLBAR_BTN_DELETE_WID,FUNC_DETAIL_TOOLBAR_BTN_DELETE_HEI);
    btn_delete->setIcon(QIcon(":/ViewResource/btn_delete_normal.png"));
    btn_delete->setIconSize(QSize(FUNC_DETAIL_TOOLBAR_BTN_DELETE_ICON_SIZE,FUNC_DETAIL_TOOLBAR_BTN_DELETE_ICON_SIZE));
    btn_delete->setClickShadow(false);

    btn_setting = new ShadowButton(this);
    btn_setting->setFixedSize(FUNC_DETAIL_TOOLBAR_BTN_SETTING_WID,FUNC_DETAIL_TOOLBAR_BTN_SETTING_HEI);
    btn_setting->setIcon(QIcon(":/ViewResource/btn_setting_normal.png"));
    btn_setting->setIconSize(QSize(FUNC_DETAIL_TOOLBAR_BTN_SETTING_ICON_SIZE,FUNC_DETAIL_TOOLBAR_BTN_SETTING_ICON_SIZE));
    btn_setting->setClickShadow(false);

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

    down_h_layout = new QHBoxLayout(this);
    down_h_layout->setMargin(0);
    down_h_layout->setSpacing(0);
    down_h_layout->addSpacing(10);
    down_h_layout->addWidget(btn_new,0,Qt::AlignBottom);
    down_h_layout->addWidget(btn_start,1,Qt::AlignBottom);
    down_h_layout->addWidget(btn_stop,2,Qt::AlignBottom);
    down_h_layout->addWidget(btn_delete,3,Qt::AlignBottom);
    down_h_layout->addWidget(btn_setting,4,Qt::AlignBottom);
    down_h_layout->addStretch();
    down_frame->setLayout(down_h_layout);

    v_layout = new QVBoxLayout(this);
    v_layout->setMargin(0);
    v_layout->setSpacing(0);
    v_layout->addStretch();
    v_layout->addWidget(up_frame);
    v_layout->addStretch();
    v_layout->addWidget(down_frame);

    setLayout(v_layout);

    ptrToolBarUpList.append(btn_min);
    ptrToolBarUpList.append(btn_close);

    ptrToolBarDownList.append(btn_new);
    ptrToolBarDownList.append(btn_start);
    ptrToolBarDownList.append(btn_stop);
    ptrToolBarDownList.append(btn_delete);
    ptrToolBarDownList.append(btn_setting);
}

void FuncDetailToolBar::slotSetUpBtnNormal(ShadowButton *paraPtr)
{
    for(int var = 0 ; var < ptrToolBarUpList.size() ; ++var)
    {
        ptrToolBarUpList.at(var)->setBtnNormal();
    }
}

void FuncDetailToolBar::slotSetDownBtnNormal(ShadowButton *paraPtr)
{
    for(int var = 0 ; var < ptrToolBarDownList.size() ; ++var)
    {
        ptrToolBarDownList.at(var)->setBtnNormal();
    }
}

QWidget *FuncDetailToolBar::getMainWindowPtr(QWidget *parent)
{
    parent = parent->parentWidget();

    if(parent->inherits("MainWindow"))
    {
        return parent;
    }else{
        return getMainWindowPtr(parent);
    }
}

void FuncDetailToolBar::mousePressEvent(QMouseEvent *ev)
{
    if (ev->button() == Qt::LeftButton)
     {
         m_move = true;
         m_startPoint = ev->globalPos();
         m_windowPoint = getMainWindowPtr(this)->frameGeometry().topLeft();
     }
}

void FuncDetailToolBar::mouseMoveEvent(QMouseEvent *ev)
{
    if (ev->buttons() & Qt::LeftButton)
     {
         QPoint relativePos = ev->globalPos() - m_startPoint;
         sendMoveMainWindow(m_windowPoint + relativePos);
    }
}

void FuncDetailToolBar::mouseReleaseEvent(QMouseEvent *ev)
{
    if (ev->button() == Qt::LeftButton)
    {
        m_move = false;
    }
}
