#include "funcdetail.h"

FuncDetail::FuncDetail(QWidget *parent):
    AsaBaseFrame(parent)
{
    initSetting();
    initLayout();
}

FuncDetail::~FuncDetail()
{
    if(tool_bar != NULL){tool_bar->deleteLater();}
    if(v_layout != NULL){v_layout->deleteLater();}    
    if(list_widget != NULL){list_widget->deleteLater();}
}

void FuncDetail::initSetting()
{
    setRGBA(204,255,245,80);
}

void FuncDetail::initLayout()
{
    /*set toolbar*/
    tool_bar = new FuncDetailToolBar(this);
    tool_bar->setFixedSize(FUNC_DETAIL_TOOLBAR_WID,FUNC_DETAIL_TOOLBAR_HEI);
    tool_bar->setStyleSheet("FuncDetailToolBar{border:none;border-bottom:1px solid rgb(125,125,125);background-color:rgba(0,0,0,0)}");

    /*set list widget*/
    list_widget = new FuncDetailListWidget(this);
    list_widget->setFixedSize(FUNC_DETAIL_WID,FUNC_DETAIL_HEI-FUNC_DETAIL_TOOLBAR_HEI);
    list_widget->raise();
    list_widget->show();

    /*set layout*/
    v_layout = new QVBoxLayout(this);
    v_layout->setMargin(0);
    v_layout->setSpacing(0);
    v_layout->addWidget(tool_bar);
    v_layout->addWidget(list_widget);

    setLayout(v_layout);
}

void FuncDetail::slotShowDownloadFrame()
{

}
