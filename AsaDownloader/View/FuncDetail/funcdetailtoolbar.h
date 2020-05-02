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

    ShadowButton * btn_new;
    ShadowButton * btn_start;
    ShadowButton * btn_stop;
    ShadowButton * btn_delete;
    ShadowButton * btn_setting;

    QFrame * up_frame = NULL;
    QFrame * down_frame = NULL;

    QVBoxLayout * v_layout = NULL;
    QHBoxLayout * up_h_layout = NULL;
    QHBoxLayout * down_h_layout = NULL;

    QList<ShadowButton *> ptrToolBarUpList;
    QList<ShadowButton *> ptrToolBarDownList;

    bool m_move = false;
    QPoint m_startPoint;
    QPoint m_windowPoint;

    void initLayout();
public slots:
    void slotSetUpBtnNormal(ShadowButton *paraPtr);
    void slotSetDownBtnNormal(ShadowButton *paraPtr = NULL);

    QWidget * getMainWindowPtr(QWidget * parent);

    inline ShadowButton * fetchBtnMinPtr(){return btn_min;}
    inline ShadowButton * fetchBtnClosePtr(){return btn_close;}
    inline ShadowButton * fetchBtnNewPtr(){return btn_new;}
    inline ShadowButton * fetchBtnStartPtr(){return btn_start;}
    inline ShadowButton * fetchBtnStopPtr(){return btn_stop;}
    inline ShadowButton * fetchBtnDeletePtr(){return btn_delete;}
    inline ShadowButton * fetchBtnSettingPtr(){return btn_setting;}

protected:
    void mousePressEvent(QMouseEvent * ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent * ev);

signals:
    void sendMoveMainWindow(QPoint pointMove);
};

#endif // FUNCDETAILTOOLBAR_H
