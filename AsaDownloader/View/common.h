#ifndef COMMON_H
#define COMMON_H

#include <QIcon>
#include <QSize>
#include <QFrame>
#include <QImage>
#include <QLabel>
#include <QDebug>
#include <QPixmap>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QPushButton>
#include <QMainWindow>

/*main window*/
#define MAIN_WINDOW_WID 940
#define MAIN_WINDOW_HEI 630
#define MAIN_MENU_FRAME_WID 200
#define MAIN_MENU_FRAME_HEI 630
#define FUNC_DETAIL_WID MAIN_WINDOW_WID - MAIN_MENU_FRAME_WID
#define FUNC_DETAIL_HEI 630

/*main menu*/
#define MENU_UP_FRAME_WID 200
#define MENU_UP_FRAME_HEI 70
#define MENU_DOWN_FRAME_WID 200
#define MENU_DOWN_FRAME_HEI MAIN_MENU_FRAME_HEI - MENU_UP_FRAME_HEI
#define MENU_ITEM_WID 200
#define MENU_ITEM_HEI 36
#define MENU_BTN_ICON_WID 21
#define MENU_BTN_ICON_HEI 22
#define MENU_SPACING 40
#define MENU_STYLE_ENTER(A)  "ShadowButton{text-align:" + QString(A) + ";background-color:rgba(0,0,0,20);color:white;font-size:13px}"
#define MENU_STYLE_NORMAL(A) "ShadowButton{text-align:" + QString(A) + ";background-color:rgba(0,0,0,0);color:white;font-size:13px}"
#define MENU_STYLE_CLICKED(A) "ShadowButton{text-align:" + QString(A) + ";background-color:rgba(0,0,0,100);color:white;font-size:13px}"
#define MENU_STYLE_TEXT "text-align:left;background-color:rgba(0,0,0,0);color:white;font-size:13px"
#define MENUD_TEXT_DOWNLOAD tr("正在下载")
#define MENU_TEXT_FINISHED tr("已完成")
#define MENU_TEXT_DEELTED tr("垃圾箱")

/*func detail*/
#define FUNC_DETAIL_TOOLBAR_WID 740
#define FUNC_DETAIL_TOOLBAR_HEI 70
#define FUNC_DETAIL_TOOLBAR_UP_FRAME_WID 740
#define FUNC_DETAIL_TOOLBAR_UP_FRAME_HEI 30
#define FUNC_DETAIL_TOOLBAR_DOWN_FRAME_WID 740
#define FUNC_DETAIL_TOOLBAR_DOWN_FRAME_HEI 40
#define FUNC_DETAIL_TOOLBAR_BTN_CLOSE_WID 25
#define FUNC_DETAIL_TOOLBAR_BTN_CLOSE_HEI 20
#define FUNC_DETAIL_TOOLBAR_BTN_CLOSE_ICON_SIZE 12
#define FUNC_DETAIL_TOOLBAR_BTN_MIN_WID 25
#define FUNC_DETAIL_TOOLBAR_BTN_MIN_HEI 20
#define FUNC_DETAIL_TOOLBAR_BTN_MIN_ICON_SIZE 12

class AsaBaseFrame : public QPushButton
{
    Q_OBJECT
public:
    AsaBaseFrame(QWidget * parent = nullptr);
private:
    bool m_isAllowClick = false;
    bool m_isClickble = true;
    QPoint m_startPoint;
protected:
    void mousePressEvent(QMouseEvent * ev);
    void mouseMoveEvent(QMouseEvent * ev);
    void mouseReleaseEvent(QMouseEvent * ev);

public slots:
    inline void setIsAllowClick(bool para){m_isAllowClick = para;}

    void setRGBA(int r = 0 , int g = 0 , int b = 0 , int a = 0);        //0~255
};


class AsaButton : public QPushButton
{
    Q_OBJECT
public:
    AsaButton(QWidget * parent = nullptr);
private:
    bool m_isClickble = true;
    QPoint m_startPoint;
protected:
    void mousePressEvent(QMouseEvent * ev);
    void mouseMoveEvent(QMouseEvent * ev);
    void mouseReleaseEvent(QMouseEvent * ev);
};


class ShadowButton : public QPushButton
{
    Q_OBJECT
public:
    ShadowButton(QWidget * parent = nullptr);

    QPushButton * btn_text;
private:
    int textAlign = 1;
    bool m_isAllowClick = true;
    bool m_isClickble = true;
    bool m_isSelected = false;
    bool m_isAllowClickShadow = true;
    QPoint m_startPoint;

    QHBoxLayout * h_layout;

    void initLayout();
    QString produceStyle();
protected:
    void mousePressEvent(QMouseEvent * ev);
    void mouseMoveEvent(QMouseEvent * ev);
    void mouseReleaseEvent(QMouseEvent * ev);
    void enterEvent(QEvent * ev);
    void leaveEvent(QEvent * ev);
public slots:
    void setBtnNormal();
    void setTextAlign(int n); //0 left,1 center,2 right

    inline void setClickShadow(bool para){m_isAllowClickShadow = para;}
signals:
    void sendClicked(ShadowButton * paraPtr);

};
#endif // COMMON_H
