#ifndef FUNCDETAIL_H
#define FUNCDETAIL_H

#include "common.h"
#include "funcdetailtoolbar.h"
#include "funcdetaillistwidget.h"
#include "funcdetailnewdownload.h"

class FuncDetail : public AsaBaseFrame
{
    Q_OBJECT
public:
    FuncDetail(QWidget *parent = 0);
    ~FuncDetail();

private:
    FuncDetailToolBar * tool_bar = NULL;
    FuncDetailListWidget * list_widget = NULL;

    QVBoxLayout * v_layout = NULL;

private:
    void initSetting();
    void initLayout();

public slots:
    void slotShowDownloadFrame();

    inline FuncDetailToolBar * fetchToolbarPtr(){return tool_bar;}
    inline FuncDetailListWidget * fetchItemListPtr(){return list_widget;}

};

#endif // FUNCDETAIL_H
