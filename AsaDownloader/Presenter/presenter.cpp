#include "presenter.h"

Presenter::Presenter(MainWindow *paraObj):
    QObject(paraObj)
{
    obj = paraObj;
    initConnect();
}

void Presenter::initConnect()
{
    if(!obj)
    {
        ERROR(PRESENTER_INITCONNECT_OBJ_ERROR);
        return ;
    }

    connect(obj->fetchMainMenuPtr()->fetchBtnFinishPtr(),&ShadowButton::sendClicked,this,&Presenter::slotMenuFinishClick);
    connect(obj->fetchMainMenuPtr()->fetchBtnDeletePtr(),&ShadowButton::sendClicked,this,&Presenter::slotMenuBtnDeleteClick);
    connect(obj->fetchMainMenuPtr()->fetchBtnDownloadPtr(),&ShadowButton::sendClicked,this,&Presenter::slotMenuBtnDownloadClick);

    connect(obj->fetchFuncDetailPtr()->fetchToolbarPtr(),&FuncDetailToolBar::sendMoveMainWindow,this,&Presenter::slotMoveMainWindow);
    connect(obj->fetchFuncDetailPtr()->fetchToolbarPtr()->fetchBtnMinPtr(),&ShadowButton::sendClicked,this,&Presenter::slotToolbarMinClick);
    connect(obj->fetchFuncDetailPtr()->fetchToolbarPtr()->fetchBtnClosePtr(),&ShadowButton::sendClicked,this,&Presenter::slotToolbarCloseClick);

    connect(obj->fetchFuncDetailPtr()->fetchToolbarPtr()->fetchBtnDeletePtr(),&ShadowButton::sendClicked,[=]{slotToolbarDeleteClick();});
    connect(obj->fetchFuncDetailPtr()->fetchToolbarPtr()->fetchBtnNewPtr(),&ShadowButton::sendClicked,this,&Presenter::slotToolbarNewClick);
    connect(obj->fetchFuncDetailPtr()->fetchToolbarPtr()->fetchBtnStopPtr(),&ShadowButton::sendClicked,this,&Presenter::slotToolbarStopClick);
    connect(obj->fetchFuncDetailPtr()->fetchToolbarPtr()->fetchBtnStartPtr(),&ShadowButton::sendClicked,this,&Presenter::slotToolbarStartClick);
    connect(obj->fetchFuncDetailPtr()->fetchToolbarPtr()->fetchBtnSettingPtr(),&ShadowButton::sendClicked,this,&Presenter::slotToolbarSettingClick);

    connect(obj->fetchFuncDetailPtr()->fetchItemListPtr(),&FuncDetailListWidget::sendClick,[=]{slotSetNormalDownloadItemList();});
}

void Presenter::slotMenuBtnDownloadClick(ShadowButton *paraPtr)
{
    LOG_FUNC("slotMenuBtnDownloadClick");
    obj->fetchMainMenuPtr()->slotSetOtherBtnNormal(paraPtr);

}

void Presenter::slotMenuFinishClick(ShadowButton * paraPtr)
{
    LOG_FUNC("slotMenuFinishClick");
    obj->fetchMainMenuPtr()->slotSetOtherBtnNormal(paraPtr);

}

void Presenter::slotMenuBtnDeleteClick(ShadowButton *paraPtr)
{
    LOG_FUNC("slotMenuBtnDeleteClick");
    obj->fetchMainMenuPtr()->slotSetOtherBtnNormal(paraPtr);

}

void Presenter::slotToolbarMinClick(ShadowButton *paraPtr)
{
    LOG_FUNC("slotToolbarMinClick");
    obj->fetchFuncDetailPtr()->fetchToolbarPtr()->slotSetUpBtnNormal(paraPtr);
    obj->showMinimized();
}

void Presenter::slotToolbarCloseClick(ShadowButton *paraPtr)
{
    LOG_FUNC("slotToolbarCloseClick");
    obj->fetchFuncDetailPtr()->fetchToolbarPtr()->slotSetUpBtnNormal(paraPtr);
    QMessageBox * msgBox = new QMessageBox(obj);
    if(QMessageBox::Yes == msgBox->question(obj,"Close window","Do you wanna close app?",QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes))
    {
        msgBox->deleteLater();
        obj->close();
    }
    msgBox->deleteLater();
}

void Presenter::slotMoveMainWindow(QPoint paraPoint)
{
    obj->move(paraPoint);
}

void Presenter::slotToolbarNewClick(ShadowButton *paraPtr)
{
    LOG_FUNC("slotToolbarNewClick");

    obj->fetchFuncDetailPtr()->fetchToolbarPtr()->slotSetDownBtnNormal(paraPtr);
//    FuncDetailNewDownload *download = new FuncDetailNewDownload();
//    download->raise();
//    download->show();
//    connect(download,&FuncDetailNewDownload::sendUrl,this,&Presenter::slotDownload);
//    connect(obj->fetchFuncDetailPtr()->fetchToolbarPtr()->fetchBtnClosePtr(),&ShadowButton::sendClicked,\
//                                            download,&FuncDetailNewDownload::slotBtnCancelClick);
    obj->fetchFuncDetailPtr()->fetchItemListPtr()->addDownLoadItem();
    int itemIndex = obj->fetchFuncDetailPtr()->fetchItemListPtr()->count()-1;
    QListWidgetItem * item = obj->fetchFuncDetailPtr()->fetchItemListPtr()->item(itemIndex);
    FuncDetailListItem * itemWidget = (FuncDetailListItem * )obj->fetchFuncDetailPtr()->fetchItemListPtr()->itemWidget(item);
    connect(itemWidget,&FuncDetailListItem::sendClicked,this,&Presenter::slotSetNormalDownloadItemList);
}

void Presenter::slotToolbarStartClick(ShadowButton *paraPtr)
{
    LOG_FUNC("slotToolbarStartClick");

    obj->fetchFuncDetailPtr()->fetchToolbarPtr()->slotSetDownBtnNormal(paraPtr);
    obj->fetchFuncDetailPtr()->fetchToolbarPtr()->slotSetDownBtnNormal();
    if(select_item_ptr != NULL)
    {
        int nCount = obj->fetchFuncDetailPtr()->fetchItemListPtr()->count();
        for(int var = 0 ; var < nCount ; ++var)
        {
            QListWidgetItem * item = obj->fetchFuncDetailPtr()->fetchItemListPtr()->item(var);
            FuncDetailListItem * itemWidget = (FuncDetailListItem *)obj->fetchFuncDetailPtr()->fetchItemListPtr()->itemWidget(item);
            if((FuncDetailListItem * )select_item_ptr == itemWidget)
            {
                itemWidget->slotSetDownloadStatus(DOWNLOAD_RUNNING);
            }
        }
    }
}

void Presenter::slotToolbarStopClick()
{
    LOG_FUNC("slotToolbarStopClick");

    obj->fetchFuncDetailPtr()->fetchToolbarPtr()->slotSetDownBtnNormal();
    if(select_item_ptr != NULL)
    {
        int nCount = obj->fetchFuncDetailPtr()->fetchItemListPtr()->count();
        for(int var = 0 ; var < nCount ; ++var)
        {
            QListWidgetItem * item = obj->fetchFuncDetailPtr()->fetchItemListPtr()->item(var);
            FuncDetailListItem * itemWidget = (FuncDetailListItem *)obj->fetchFuncDetailPtr()->fetchItemListPtr()->itemWidget(item);
            if((FuncDetailListItem * )select_item_ptr == itemWidget)
            {
                itemWidget->slotSetDownloadStatus(DOWNLOAD_STOP);
            }
        }
    }
}

void Presenter::slotToolbarDeleteClick()
{
    LOG_FUNC("slotToolbarDeleteClick");

    obj->fetchFuncDetailPtr()->fetchToolbarPtr()->slotSetDownBtnNormal();
    if(select_item_ptr != NULL)
    {
        QMessageBox * msgBox = new QMessageBox(obj);
        if(QMessageBox::Yes == msgBox->question(obj,"Delete confirm","Do you wanna delete this item?",\
                                                QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes)){
            slotDeleteItem(select_item_ptr);
        }
        msgBox->deleteLater();
    }
}

void Presenter::slotDeleteItem(ShadowButton *paraPtr)
{
    LOG_FUNC("slotDeleteItem");

    int nCount = obj->fetchFuncDetailPtr()->fetchItemListPtr()->count();
    for(int var = 0 ; var < nCount ; ++var)
    {
        QListWidgetItem * item = obj->fetchFuncDetailPtr()->fetchItemListPtr()->item(var);
        FuncDetailListItem * itemWidget = (FuncDetailListItem *)obj->fetchFuncDetailPtr()->fetchItemListPtr()->itemWidget(item);
        if((FuncDetailListItem * )paraPtr == itemWidget)
        {
            obj->fetchFuncDetailPtr()->fetchItemListPtr()->removeItemWidget(item);
            delete item;
            select_item_ptr = NULL;
            LOG_FUNC("Will delete file named " + itemWidget->str_fileName)
        }
    }
}

void Presenter::slotToolbarSettingClick(ShadowButton *paraPtr)
{
    LOG_FUNC("slotToolbarSettingClick");
    obj->fetchFuncDetailPtr()->fetchToolbarPtr()->slotSetDownBtnNormal(paraPtr);
}

void Presenter::slotSetNormalDownloadItemList(ShadowButton *ptr)
{
    select_item_ptr = NULL;
    int itemIndexCount = obj->fetchFuncDetailPtr()->fetchItemListPtr()->count();
    for(int var = 0 ; var < itemIndexCount ; ++var)
    {
        QListWidgetItem * item = obj->fetchFuncDetailPtr()->fetchItemListPtr()->item(var);
        FuncDetailListItem * itemWidget = (FuncDetailListItem * )obj->fetchFuncDetailPtr()->fetchItemListPtr()->itemWidget(item);
        if(itemWidget != ptr)
        {
            itemWidget->setBtnNormal();
        }else{
            select_item_ptr = ptr;
        }
    }

}

void Presenter::slotDownload(QString strUrl)
{
    LOG_FUNC("slotDownload");
    if(manager == NULL)
    {
        manager = new QNetworkAccessManager(this);
    }

    if(myfile == NULL)
    {
        myfile = new QFile(this);
    }

    QNetworkRequest request;
    request.setUrl(QUrl(strUrl));

    reply = manager->get(request);
    connect(reply,&QNetworkReply::readyRead,this,[=]{
        slotProcessReadyRead(myfile,reply);
    });                     //可读
    connect(reply,&QNetworkReply::finished,this,[=]{
        myfile->close();
    });                     //结束
    connect(reply,&QNetworkReply::downloadProgress,this,&Presenter::slotProcessDownloadProgress);  //大小
    connect(reply,QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::error),this,&Presenter::slotProcessError);  //异常

    /*set file name*/
    QStringList list = strUrl.split("/");
    QString filename = list.at(list.length()-1);
    QString file = "./" + filename;
    qDebug()<<"file name is : "<<filename;
    myfile->setFileName(file);
    bool ret = myfile->open(QIODevice::WriteOnly|QIODevice::Truncate);    //创建文件
    if(!ret)
    {
//        QMessageBox::warning(this,"warning","打开失败");
        qDebug()<<"Asa ERROR : open file failed";
        return;
    }
}

void Presenter::slotProcessReadyRead(QFile *ptrFile, QNetworkReply *ptrReply)
{
    while(!reply->atEnd())
    {
        QByteArray ba = reply->readAll();
        myfile->write(ba);
    }
}

void Presenter::slotProcessDownloadProgress(qint64 n_recv, qint64 n_all)
{

}

void Presenter::slotProcessError(QNetworkReply::NetworkError code)
{
    qDebug()<<"Asa ERROR : Download error : "<<code;
}
