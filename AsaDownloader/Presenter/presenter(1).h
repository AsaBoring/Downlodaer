#ifndef PRESENTER_H
#define PRESENTER_H

#define ERROR(A) qDebug()<<"Asa ERROR :"<<A;
#define LOG_FUNC(A) qDebug()<<"Asa func "<<A;

enum ERROR_CODE{
    SUCCESS,
    PRESENTER_INITCONNECT_OBJ_ERROR
};

#include "mainwindow.h"

class Presenter : public QObject
{
    Q_OBJECT
public:
    Presenter(MainWindow *paraObj = nullptr);

private:
    MainWindow *obj = NULL;

    QFile *myfile = NULL;
    QNetworkAccessManager *manager = NULL;
    QNetworkReply *reply = NULL;
    ShadowButton * select_item_ptr = NULL;

    void initConnect();

public slots:
    void slotMenuBtnDownloadClick(ShadowButton * paraPtr);
    void slotMenuFinishClick(ShadowButton * paraPtr);
    void slotMenuBtnDeleteClick(ShadowButton * paraPtr);
    void slotToolbarMinClick(ShadowButton * paraPtr);
    void slotToolbarCloseClick(ShadowButton * paraPtr);
    void slotMoveMainWindow(QPoint paraPoint);
    void slotToolbarNewClick(ShadowButton * paraPtr);
    void slotToolbarStartClick(ShadowButton * paraPtr);
    void slotToolbarStopClick();
    void slotToolbarDeleteClick();
    void slotDeleteItem(ShadowButton * paraPtr);
    void slotToolbarSettingClick(ShadowButton * paraPtr);
    void slotSetNormalDownloadItemList(ShadowButton * ptr = NULL);

    /*http download*/
    void slotDownload(QString strUrl);
    void slotProcessReadyRead(QFile * ptrFile , QNetworkReply * ptrReply);
    void slotProcessDownloadProgress(qint64 n_recv, qint64 n_all);
    void slotProcessError(QNetworkReply::NetworkError code);
};

#endif // PRESENTER_H
