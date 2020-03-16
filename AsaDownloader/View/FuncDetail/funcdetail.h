#ifndef FUNCDETAIL_H
#define FUNCDETAIL_H

#include "common.h"
#include "funcdetailtoolbar.h"

class FuncDetail : public AsaBaseFrame
{
    Q_OBJECT
public:
    FuncDetail(QWidget *parent = 0);
    ~FuncDetail();

public:
    FuncDetailToolBar * tool_bar = NULL;

    QVBoxLayout * v_layout = NULL;
private:
    void initSetting();
    void initLayout();
};

#endif // FUNCDETAIL_H
