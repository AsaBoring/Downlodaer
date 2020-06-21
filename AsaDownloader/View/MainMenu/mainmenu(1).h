#ifndef MAINMENU_H
#define MAINMENU_H

#include "common.h"

class MainMenu : public AsaBaseFrame
{
    Q_OBJECT
public:
    MainMenu(QWidget *parent = 0);
    ~MainMenu();

private:
    QFrame * up_frame = NULL;
    QFrame * down_frame = NULL;

    QVBoxLayout * v_layout = NULL;
    QVBoxLayout * v_down_layout = NULL;

    ShadowButton * btn_download = NULL;
    ShadowButton * btn_finished = NULL;
    ShadowButton * btn_deleted = NULL;

    ShadowButton * pointer_dark_btn = NULL;

    void initSetting();
    void initLayout();

    QList<ShadowButton *> ptrMenuBtnList;
public slots:
    void slotSetOtherBtnNormal(ShadowButton * paraPtr);

    inline ShadowButton * fetchBtnDownloadPtr(){return btn_download;}
    inline ShadowButton * fetchBtnFinishPtr(){return btn_finished;}
    inline ShadowButton * fetchBtnDeletePtr(){return btn_deleted;}

};

#endif // MAINMENU_H
