#include "presenter.h"

Presenter::Presenter(MainWindow *paraObj):
    QObject(paraObj)
{
    obj = paraObj;
    initConnect();
}

void Presenter::initConnect()
{
    if(!obj)
    {
        ERROR(PRESENTER_INITCONNECT_OBJ_ERROR);
        return ;
    }

    connect(obj->main_menu->btn_download,&ShadowButton::sendClicked,this,&Presenter::slotMenuBtnDownloadClick);
    connect(obj->main_menu->btn_finished,&ShadowButton::sendClicked,this,&Presenter::slotMenuFinishClick);
    connect(obj->main_menu->btn_deleted,&ShadowButton::sendClicked,this,&Presenter::slotMenuBtnDeleteClick);

}

void Presenter::slotMenuBtnDownloadClick(ShadowButton *paraPtr)
{
    LOG_FUNC("slotMenuBtnDownloadClick");
    obj->main_menu->slotSetOtherBtnNormal(paraPtr);

}

void Presenter::slotMenuFinishClick(ShadowButton * paraPtr)
{
    LOG_FUNC("slotMenuFinishClick");
    obj->main_menu->slotSetOtherBtnNormal(paraPtr);

}

void Presenter::slotMenuBtnDeleteClick(ShadowButton *paraPtr)
{
    LOG_FUNC("slotMenuBtnDeleteClick");
    obj->main_menu->slotSetOtherBtnNormal(paraPtr);

}
