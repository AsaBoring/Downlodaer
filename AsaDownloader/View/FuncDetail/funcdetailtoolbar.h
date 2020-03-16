#ifndef FUNCDETAILTOOLBAR_H
#define FUNCDETAILTOOLBAR_H

#include "common.h"

class FuncDetailToolBar : public AsaBaseFrame
{
    Q_OBJECT
public:
    FuncDetailToolBar(QWidget * parent = nullptr);
    ~FuncDetailToolBar();

private:
    ShadowButton * btn_min;
    ShadowButton * btn_close;

    QFrame * up_frame = NULL;
    QFrame * down_frame = NULL;

    QVBoxLayout * v_layout = NULL;
    QHBoxLayout * up_h_layout = NULL;
    QHBoxLayout * down_h_layout = NULL;

    void initLayout();
};

#endif // FUNCDETAILTOOLBAR_H
