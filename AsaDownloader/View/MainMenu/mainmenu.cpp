#include "mainmenu.h"

MainMenu::MainMenu(QWidget *parent)
    : AsaBaseFrame(parent)
{
    initSetting();
    initLayout();
}

MainMenu::~MainMenu()
{
    if(up_frame != NULL){up_frame->deleteLater();}
    if(down_frame != NULL){ down_frame->deleteLater();}
    if(v_down_layout != NULL){v_down_layout->deleteLater();}
    if(btn_deleted != NULL){btn_deleted->deleteLater();}
    if(btn_download != NULL){btn_download->deleteLater();}
    if(btn_finished != NULL){btn_finished->deleteLater();}
    if(btn_deleted != NULL){btn_deleted->deleteLater();}
}

void MainMenu::initSetting()
{
}

void MainMenu::initLayout()
{
    setRGBA(0,0,0,40);

    /*set frame*/
    up_frame = new QFrame(this);
    up_frame->setFixedSize(MENU_UP_FRAME_WID,MENU_UP_FRAME_HEI);
    up_frame->setStyleSheet("border:none;border-bottom:1px solid rgb(125,125,125);background-color:rgba(0,0,0,0)");

    down_frame = new QFrame(this);
    down_frame->setFixedSize(MENU_DOWN_FRAME_WID,MENU_DOWN_FRAME_HEI);
    down_frame->setStyleSheet("border:none;background-color:rgba(0,0,0,0)");

    /*set btn*/
    btn_download = new ShadowButton(this);
    btn_download->btn_text->setIconSize(QSize(MENU_BTN_ICON_WID,MENU_BTN_ICON_HEI));
    btn_download->btn_text->setIcon(QIcon(":/ViewResource/item_download_normal.png"));
    btn_download->btn_text->setText(MENUD_TEXT_DOWNLOAD);
    btn_download->setFixedSize(MENU_ITEM_WID,MENU_ITEM_HEI);

    btn_finished = new ShadowButton(this);
    btn_finished->btn_text->setIconSize(QSize(MENU_BTN_ICON_WID,MENU_BTN_ICON_HEI));
    btn_finished->btn_text->setIcon(QIcon(":/ViewResource/item_finished_normal.png"));
    btn_finished->btn_text->setText(MENU_TEXT_FINISHED);
    btn_finished->setFixedSize(MENU_ITEM_WID,MENU_ITEM_HEI);

    btn_deleted = new ShadowButton(this);
    btn_deleted->btn_text->setIconSize(QSize(MENU_BTN_ICON_WID,MENU_BTN_ICON_HEI));
    btn_deleted->btn_text->setIcon(QIcon(":/ViewResource/item_delete_normal.png"));
    btn_deleted->btn_text->setText(MENU_TEXT_DEELTED);
    btn_deleted->setFixedSize(MENU_ITEM_WID,MENU_ITEM_HEI);

    ptrMenuBtnList.append(btn_download);
    ptrMenuBtnList.append(btn_finished);
    ptrMenuBtnList.append(btn_deleted);

    /*set layout*/
    v_down_layout = new QVBoxLayout(this);
    v_down_layout->setSpacing(0);
    v_down_layout->setMargin(0);
    v_down_layout->addSpacing(15);
    v_down_layout->addWidget(btn_download);
    v_down_layout->addWidget(btn_finished);
    v_down_layout->addWidget(btn_deleted);
    v_down_layout->addStretch();
    down_frame->setLayout(v_down_layout);

    QLayout * ptrLayout = layout();
    delete ptrLayout;

    v_layout = new QVBoxLayout(this);
    v_layout->setSpacing(0);
    v_layout->setMargin(0);
    v_layout->addWidget(up_frame);
    v_layout->addWidget(down_frame);
    v_layout->addStretch();
    setLayout(v_layout);
}

void MainMenu::slotSetOtherBtnNormal(ShadowButton *paraPtr)
{
    for(int var = 0 ; var < ptrMenuBtnList.size() ; ++var)
    {
        if(paraPtr != ptrMenuBtnList.at(var))
        {
            ptrMenuBtnList.at(var)->setBtnNormal();
        }
    }
}
