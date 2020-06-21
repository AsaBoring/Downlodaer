#ifndef FUNCDETAILLISTWIDGET_H
#define FUNCDETAILLISTWIDGET_H

#include "common.h"
#include "funcdetaillistitem.h"

class FuncDetailListWidget : public QListWidget
{
    Q_OBJECT
public:
    FuncDetailListWidget(QWidget * parent = 0);
    ~FuncDetailListWidget();

private:
    void initSetting();
    void initLayout();

    bool m_isClickble = true;
    QPoint m_startPoint;

protected:
    void mousePressEvent(QMouseEvent * ev);
    void mouseMoveEvent(QMouseEvent * ev);
    void mouseReleaseEvent(QMouseEvent * ev);

public slots:
    void addDownLoadItem();
    void deleteDownLoadItem();

signals:
    void sendClick();
};

#endif // FUNCDETAILLISTWIDGET_H
