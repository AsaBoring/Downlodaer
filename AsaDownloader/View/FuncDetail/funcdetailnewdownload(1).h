#ifndef FUNCDETAILNEWDOWNLOAD_H
#define FUNCDETAILNEWDOWNLOAD_H

#include "common.h"

class FuncDetailNewDownload : public AsaBaseFrame
{
    Q_OBJECT
public:
    FuncDetailNewDownload(QWidget * parent = nullptr);
    ~FuncDetailNewDownload();

private:
    QHBoxLayout * h_layout = NULL;
    QLineEdit * text_line = NULL;
    AsaButton * btn_click = NULL;
    AsaButton * btn_cancel = NULL;

    bool m_move = false;
    QPoint m_startPoint;
    QPoint m_windowPoint;

    void initLayout();
    void initSetting();
    void initConnect();

protected:
    void mousePressEvent(QMouseEvent * ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent * ev);

public slots:
    void slotBtnConfirmClick();
    void slotBtnCancelClick();

signals:
    void sendUrl(QString strUrl);
};

#endif // FUNCDETAILNEWDOWNLOAD_H
