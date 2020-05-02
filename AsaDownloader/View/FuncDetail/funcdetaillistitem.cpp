#include "funcdetaillistitem.h"

FuncDetailListItem::FuncDetailListItem(QWidget *parent):
    ShadowButton(parent)
{
    initLayout();
    initConnect();
}

FuncDetailListItem::~FuncDetailListItem()
{
    if(h_layout != NULL){h_layout->deleteLater();}

    if(btn_pic != NULL){btn_pic->deleteLater();}

    if(frame_fileInfo != NULL){frame_fileInfo->deleteLater();}
    if(btn_name != NULL){btn_name->deleteLater();}
    if(btn_fileSize != NULL){btn_fileSize->deleteLater();}
    if(v_fileInfo_layout != NULL){v_fileInfo_layout->deleteLater();}

    if(frame_downloadInfo != NULL){frame_downloadInfo->deleteLater();}
    if(pb_percent != NULL){pb_percent->deleteLater();}
    if(btn_speed != NULL){btn_speed->deleteLater();}
    if(btn_time != NULL){btn_time->deleteLater();}
    if(v_downloadInfo_layout != NULL){v_downloadInfo_layout->deleteLater();}
    if(h_downloadDown_layout != NULL){h_downloadDown_layout->deleteLater();}

    if(btn_status != NULL){btn_status->deleteLater();}
    if(download_thread != NULL){download_thread->deleteLater();}
}

void FuncDetailListItem::initLayout()
{
    /*Clear the original layout*/
    QLayout * ptrLayout = layout();
    delete ptrLayout;
    btn_text->deleteLater();

    /*set pic*/
    btn_pic = new QToolButton(this);
    btn_pic->setFixedSize(FUNC_DETAIL_ITEM_PIC_WID,FUNC_DETAIL_ITEM_PIC_WID);
    btn_pic->setIconSize(QSize(FUNC_DETAIL_ITEM_PIC_WID,FUNC_DETAIL_ITEM_PIC_WID));
    btn_pic->setIcon(QIcon(":/ViewResource/lb_blankImage.png"));
    btn_pic->setAttribute(Qt::WA_TransparentForMouseEvents, true);

    /*set file info*/
    frame_fileInfo = new QFrame(this);
    frame_fileInfo->setFixedSize(FUNC_DETAIL_ITEM_FILE_INFO_WID,FUNC_DETAIL_ITEM_FILE_INFO_HEI);
    frame_fileInfo->setAttribute(Qt::WA_TransparentForMouseEvents, true);

    btn_name = new QPushButton(this);
    btn_name->setText(str_fileName);
    btn_name->setFixedSize(FUNC_DETAIL_ITEM_FILE_INFO_WID,25);
    btn_name->setStyleSheet("text-align:left");
    QFont font;
    font.setPixelSize(12);
    btn_name->setFont(font);
    btn_name->setAttribute(Qt::WA_TransparentForMouseEvents, true);

    btn_fileSize = new QPushButton(this);
    btn_fileSize->setText(str_fileSize);
    btn_fileSize->setFixedSize(FUNC_DETAIL_ITEM_FILE_INFO_WID,25);
    btn_fileSize->setStyleSheet("text-align:left");
    btn_fileSize->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    btn_fileSize->setText(str_fileSize);

    v_fileInfo_layout = new QVBoxLayout(this);
    v_fileInfo_layout->setSpacing(0);
    v_fileInfo_layout->setMargin(0);
    v_fileInfo_layout->addStretch();
    v_fileInfo_layout->addWidget(btn_name);
    v_fileInfo_layout->addWidget(btn_fileSize);
    v_fileInfo_layout->addStretch();

    frame_fileInfo->setLayout(v_fileInfo_layout);

    /*set download info*/
    frame_downloadInfo = new QFrame(this);
    frame_downloadInfo->setFixedSize(FUNC_DETAIL_ITEM_DOWNLOAD_INFO_WID,FUNC_DETAIL_ITEM_DOWNLOAD_INFO_HEI);
    frame_downloadInfo->setAttribute(Qt::WA_TransparentForMouseEvents, true);

    pb_percent = new QProgressBar(this);
    pb_percent->setFixedSize(FUNC_DETAIL_ITEM_PROGRESSBAR_WID,FUNC_DETAIL_ITEM_PROGRESSBAR_HEI);
    pb_percent->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    pb_percent->setOrientation(Qt::Horizontal);
    pb_percent->setAlignment(Qt::AlignCenter);
    pb_percent->setMinimum(0);
    pb_percent->setMaximum(100);
    pb_percent->setValue(0);
    pb_percent->setFormat("0%");

    btn_time = new QPushButton(this);
    btn_time->setFixedSize(FUNC_DETAIL_ITEM_PROGRESSBAR_WID/2,FUNC_DETAIL_ITEM_DOWNLOAD_INFO_DOWN_HEI);
    btn_time->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    btn_time->setStyleSheet("text-align:left");
    btn_time->setText(str_download_time);

    btn_speed = new QPushButton(this);
    btn_speed->setFixedSize(FUNC_DETAIL_ITEM_PROGRESSBAR_WID/2,FUNC_DETAIL_ITEM_DOWNLOAD_INFO_DOWN_HEI);
    btn_speed->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    btn_speed->setStyleSheet("text-align:right");
    btn_speed->setText(str_speed);

    frame_downloadInfo_down = new QFrame(this);
    frame_downloadInfo_down->setFixedSize(FUNC_DETAIL_ITEM_DOWNLOAD_INFO_WID,FUNC_DETAIL_ITEM_DOWNLOAD_INFO_DOWN_HEI);
    frame_downloadInfo_down->setAttribute(Qt::WA_TransparentForMouseEvents, true);

    h_downloadDown_layout = new QHBoxLayout(this);
    h_downloadDown_layout->setSpacing(0);
    h_downloadDown_layout->setMargin(0);
    h_downloadDown_layout->addStretch();
    h_downloadDown_layout->addWidget(btn_time);
    h_downloadDown_layout->addWidget(btn_speed);
    h_downloadDown_layout->addStretch();

    frame_downloadInfo_down->setLayout(h_downloadDown_layout);

    v_downloadInfo_layout = new QVBoxLayout(this);
    v_downloadInfo_layout->setSpacing(0);
    v_downloadInfo_layout->setMargin(0);
    v_downloadInfo_layout->addStretch();
    v_downloadInfo_layout->addWidget(pb_percent);
    v_downloadInfo_layout->addWidget(frame_downloadInfo_down);
    v_downloadInfo_layout->addStretch();

    frame_downloadInfo->setLayout(v_downloadInfo_layout);

    /*set status*/
    btn_status = new QPushButton(this);
    btn_status->setFixedSize(FUNC_DETAIL_ITEM_STATUS_WID,FUNC_DETAIL_ITEM_STATUS_HEI);
    btn_status->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    btn_status->setText(str_status);
    QFont status_font;
    status_font.setPixelSize(12);
    btn_status->setFont(status_font);

    /*set layout*/
    h_layout = new QHBoxLayout(this);
    h_layout->setAlignment(btn_pic,Qt::AlignCenter);
    h_layout->setSpacing(0);
    h_layout->setMargin(0);
    h_layout->addSpacing(10);
    h_layout->addWidget(btn_pic,0,Qt::AlignCenter);
    h_layout->addSpacing(5);
    h_layout->addWidget(frame_fileInfo);
    h_layout->addWidget(frame_downloadInfo);
    h_layout->addWidget(btn_status);
    h_layout->addStretch();

    setLayout(h_layout);

    /*test set progress bar percent value*/
    download_thread = new tThread;

}

void FuncDetailListItem::initConnect()
{
    connect(download_thread,&tThread::sendPercent,this,&FuncDetailListItem::slotSetProgress);
    download_thread->start();
    connect(download_thread,&tThread::sendFinish,this,&FuncDetailListItem::slotDownloadFinish);
}

void FuncDetailListItem::slotSetFileName(QString strFileName)
{
    str_fileName = strFileName;
    btn_name->setText(str_fileName);
}

void FuncDetailListItem::slotSetFileSize(uint64_t nSize)
{
    QString strFileSize = formatFileSize(nSize);
    btn_fileSize->setText(strFileSize);
    qDebug()<<"strFileSize is : "<<strFileSize;
}

void FuncDetailListItem::slotSetDownloadTime(QString strTime)
{
    str_download_time = strTime;
}

void FuncDetailListItem::slotSetDownloadSpeed(int nSpeed)
{
    str_speed = nSpeed;
}

void FuncDetailListItem::slotSetStatus(DOWNLOAD_STATUS n)
{
    switch (n) {
    case DOWNLOAD_RUNNING:
        str_status = "正在下载";
        break;
    case DOWNLOAD_STOP:
        str_status = "暂停下载";
        break;
    case DOWNLOAD_DOWN:
        str_status = "下载完成";
        break;
    case DOWNLOAD_ERROR:
        str_status = "异常错误";
        break;
    default:
        break;
    }

    btn_status->setText(str_status);
    repaint();
}

void FuncDetailListItem::slotSetProgress(int nPercent)
{
    if(nPercent < 0 || nPercent > 100)
    {
        return;
    }

    QString strPercent = QString("%1%").arg(nPercent);
    pb_percent->setFormat(strPercent);
    pb_percent->setValue(nPercent);
}

void FuncDetailListItem::slotSetDownloadStatus(DOWNLOAD_STATUS nPara)
{
    if(nPara == download_status || download_status == DOWNLOAD_DOWN)
    {
        return;
    }
    download_status = nPara;

    slotSetStatus(download_status);
    if(download_status == DOWNLOAD_STOP)
    {
        download_thread->stop_run();
    }else if(download_status == DOWNLOAD_RUNNING){
        qDebug()<<"will set item running ";
        download_thread->start_run();
    }
}

void FuncDetailListItem::slotDownloadFinish()
{
    slotSetDownloadStatus(DOWNLOAD_DOWN);
}

