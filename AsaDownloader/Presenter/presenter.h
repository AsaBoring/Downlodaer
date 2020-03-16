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
    void initConnect();

public slots:
    void slotMenuBtnDownloadClick(ShadowButton * paraPtr);
    void slotMenuFinishClick(ShadowButton * paraPtr);
    void slotMenuBtnDeleteClick(ShadowButton * paraPtr);

};

#endif // PRESENTER_H
