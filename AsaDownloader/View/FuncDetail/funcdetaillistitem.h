#ifndef FUNCDETAILLISTITEM_H
#define FUNCDETAILLISTITEM_H

#include "common.h"

class FuncDetailListItem : public ShadowButton
{
    Q_OBJECT
public:
    FuncDetailListItem(QWidget * parent = 0);
    ~FuncDetailListItem();

private:
    void initLayout();
    void initConnect();

    QHBoxLayout * h_layout = NULL;

    /*pic*/
    QToolButton * btn_pic = NULL;

    /*file info*/
    QFrame * frame_fileInfo = NULL;
    QPushButton * btn_name = NULL;
    QPushButton * btn_fileSize = NULL;
    QVBoxLayout * v_fileInfo_layout = NULL;

    /*download info*/
    QFrame * frame_downloadInfo = NULL;
    QFrame * frame_downloadInfo_down = NULL;
    QProgressBar * pb_percent = NULL;
    QPushButton * btn_time = NULL;
    QPushButton * btn_speed = NULL;
    QVBoxLayout * v_downloadInfo_layout = NULL;
    QHBoxLayout * h_downloadDown_layout = NULL;

    /*status*/
    QPushButton * btn_status = NULL;

    tThread * download_thread = NULL;

    DOWNLOAD_STATUS download_status;
public:
    QString str_fileName = "qt-opensource-windows-x86-msva2015_64-5.9.0.exe";
    QString str_fileSize = "正在计算...";
    QString str_download_time = "00:01:52";
    QString str_speed = "4.71M/s";
    QString str_status = "正在下载";

public slots:
    void slotSetFileName(QString strFileName);
    void slotSetFileSize(uint64_t nSize);   //byte
    void slotSetDownloadTime(QString strTime);
    void slotSetDownloadSpeed(int nSpeed);
    void slotSetStatus(DOWNLOAD_STATUS n);          //0 正在下载 , 1暂停下载 ， 2下载完成 , 3异常错误
    void slotSetProgress(int nPercent);
    void slotSetDownloadStatus(DOWNLOAD_STATUS nPara);
    void slotDownloadFinish();

};
#endif // FUNCDETAILLISTITEM_H
