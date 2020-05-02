#include "funcdetaillistwidget.h"

FuncDetailListWidget::FuncDetailListWidget(QWidget *parent):
    QListWidget(parent)
{
    initSetting();
    initLayout();
}

FuncDetailListWidget::~FuncDetailListWidget()
{

}

void FuncDetailListWidget::initSetting()
{

    setStyleSheet("FuncDetailListWidget{background-color:transparent}");

    setFixedSize(FUNC_DETAIL_WID,FUNC_DETAIL_HEI-FUNC_DETAIL_TOOLBAR_HEI);
    setSelectionMode(QAbstractItemView::NoSelection);
    setCurrentRow(1);
    setAutoScroll(true);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QFile file(":/ViewResource/funcDetail_listwidget.qss");
    file.open(QFile::ReadOnly);
//    QString str_string = file.readAll();
//    qDebug()<<"str_string is : "<<str_string;
    QString str_string = "width:8px;\
                          background:rgba(0,0,0,25%);\
                          margin:0px,0px,0px,0px;\
                          padding-top:9px;\
                          padding-bottom:9px;\
                          border-radius:4px;";
    verticalScrollBar()->setStyleSheet(str_string);
}

void FuncDetailListWidget::initLayout()
{

}

void FuncDetailListWidget::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {
        m_isClickble = true;
        m_startPoint = ev->pos();
    }
}

void FuncDetailListWidget::mouseMoveEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {
        QPoint offset_point = ev->pos();
        if(abs(offset_point.x() - m_startPoint.x()) > 5 || abs(offset_point.y() - m_startPoint.y()))
        {
            m_isClickble = false;
        }
    }
}

void FuncDetailListWidget::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {

        if(m_isClickble)
        {
            emit sendClick();
        }
    }
}

void FuncDetailListWidget::addDownLoadItem()
{
    FuncDetailListItem * widget_item = new FuncDetailListItem(this);
    widget_item->setFixedSize(FUNC_DETAIL_ITEM_WID,FUNC_DETAIL_ITEM_HEI);

    QListWidgetItem * item1 = new QListWidgetItem(this);
    item1->setSizeHint(QSize(FUNC_DETAIL_ITEM_WID,FUNC_DETAIL_ITEM_HEI));

    setItemWidget(item1,widget_item);
}

void FuncDetailListWidget::deleteDownLoadItem()
{

}
