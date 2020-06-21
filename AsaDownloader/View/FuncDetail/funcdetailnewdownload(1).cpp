#include "funcdetailnewdownload.h"

FuncDetailNewDownload::FuncDetailNewDownload(QWidget *parent):
    AsaBaseFrame(parent)
{
    initSetting();
    initLayout();
    initConnect();
}

FuncDetailNewDownload::~FuncDetailNewDownload()
{
    if(h_layout != NULL){h_layout->deleteLater();}
    if(text_line != NULL){text_line->deleteLater();}
    if(btn_click != NULL){btn_click->deleteLater();}
    if(btn_cancel != NULL){btn_cancel->deleteLater();}
}

void FuncDetailNewDownload::initLayout()
{
    setFixedSize(FUNC_DETAIL_DOWNLOAD_FRAME_WID,FUNC_DETAIL_DOWNLOAD_FRAME_HEI);

    text_line = new QLineEdit(this);
    text_line->setFixedSize(FUNC_DETAIL_DOWNLOAD_EDIT_WID,FUNC_DETAIL_DOWNLOAD_EDIT_HEI);

    btn_click = new AsaButton(this);
    btn_click->setFixedSize(FUNC_DETAIL_DOWNLOAD_BTN_CLICK_WID,FUNC_DETAIL_DOWNLOAD_BTN_CLICK_HEI);
    btn_click->setText(FUNC_DETAIL_DOWNLOAD_BTN_TEXT);

    btn_cancel = new AsaButton(this);
    btn_cancel->setIcon(QIcon(":/ViewResource/btn_close_normal.png"));
    btn_cancel->setIconSize(QSize(FUNC_DETAIL_TOOLBAR_BTN_CLOSE_ICON_SIZE,FUNC_DETAIL_TOOLBAR_BTN_CLOSE_ICON_SIZE));
    btn_cancel->setGeometry(FUNC_DETAIL_DOWNLOAD_FRAME_WID-FUNC_DETAIL_TOOLBAR_BTN_CLOSE_WID,0,FUNC_DETAIL_TOOLBAR_BTN_CLOSE_WID,FUNC_DETAIL_TOOLBAR_BTN_CLOSE_HEI);

    /*set layout*/
    h_layout = new QHBoxLayout(this);
    h_layout->setMargin(0);
    h_layout->setSpacing(0);
    h_layout->addStretch();
    h_layout->addWidget(text_line);
    h_layout->addSpacing(5);
    h_layout->addWidget(btn_click);
    h_layout->addStretch();

    setLayout(h_layout);
    setStyleSheet(FUNC_DETAIL_DOWNLOAD_STYLE);
}

void FuncDetailNewDownload::initSetting()
{
    setWindowOpacity(1);
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::FramelessWindowHint);
}

void FuncDetailNewDownload::initConnect()
{
    connect(btn_click,&AsaButton::clicked,this,&FuncDetailNewDownload::slotBtnConfirmClick);
    connect(btn_cancel,&AsaButton::clicked,this,&FuncDetailNewDownload::slotBtnCancelClick);
}

void FuncDetailNewDownload::mousePressEvent(QMouseEvent *ev)
{
    if (ev->button() == Qt::LeftButton)
     {
         m_move = true;
         m_startPoint = ev->globalPos();
         m_windowPoint = frameGeometry().topLeft();
     }

    /*control widget move*/
    m_move = false;
}

void FuncDetailNewDownload::mouseMoveEvent(QMouseEvent *ev)
{
    if (ev->buttons() & Qt::LeftButton)
     {
         QPoint relativePos = ev->globalPos() - m_startPoint;
         move(m_windowPoint + relativePos);
    }
}

void FuncDetailNewDownload::mouseReleaseEvent(QMouseEvent *ev)
{
    if (ev->button() == Qt::LeftButton)
    {
        m_move = false;
    }
}

void FuncDetailNewDownload::slotBtnConfirmClick()
{
    if(text_line->text() == "")
    {
        return;
    }

    emit sendUrl(text_line->text());
    close();
}

void FuncDetailNewDownload::slotBtnCancelClick()
{
    deleteLater();
}
