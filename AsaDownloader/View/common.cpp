#include "common.h"

AsaBaseFrame::AsaBaseFrame(QWidget *parent):
    QPushButton(parent)
{
    setStyleSheet("border:none");
}

void AsaBaseFrame::mousePressEvent(QMouseEvent *ev)
{
    m_isClickble = true;
    m_startPoint = ev->pos();
}

void AsaBaseFrame::mouseMoveEvent(QMouseEvent *ev)
{
    QPoint offset_point = ev->pos();
    if(abs(offset_point.x() - m_startPoint.x()) > 5 || abs(offset_point.y() - m_startPoint.y()))
    {
        m_isClickble = false;
    }
}

void AsaBaseFrame::mouseReleaseEvent(QMouseEvent * ev)
{
    if(m_isClickble)
    {
        if(m_isAllowClick)
        {
            emit clicked();
        }
    }
}

void AsaBaseFrame::setRGBA(int r, int g, int b, int a)
{
    setStyleSheet(QString("AsaBaseFrame{background-color:rgba(") + QString("%1,%2,%3,%4").arg(r).arg(g).arg(b).arg(a) + ")}");
    //    qDebug()<<"style is : "<<QString("background-color:rgba(") + QString("%1,%2,%3,%4").arg(r).arg(g).arg(b).arg(a) + ")";
}

/*---------------------------------------------------------------------*/

AsaButton::AsaButton(QWidget *parent):
    QPushButton(parent)
{
    setStyleSheet("background-color:black;color:white;border:1px solid");
}

void AsaButton::mousePressEvent(QMouseEvent *ev)
{
    setStyleSheet("background-color:white;color:black;border:1px solid");
    m_isClickble = true;
    m_startPoint = ev->pos();
}

void AsaButton::mouseMoveEvent(QMouseEvent *ev)
{
    setStyleSheet("background-color:white;color:black;border:1px solid");
    m_isClickble = true;
    m_startPoint = ev->pos();
}

void AsaButton::mouseReleaseEvent(QMouseEvent * ev)
{
    setStyleSheet("background-color:black;color:white;border:1px solid");
    if(m_isClickble)
    {
        emit clicked();
    }
}

/*---------------------------------------------------------------------*/

ShadowButton::ShadowButton(QWidget *parent):
    QPushButton(parent)
{
    initLayout();
    setBtnNormal();
}

void ShadowButton::initLayout()
{
    /*set btn*/
    btn_text = new QPushButton(this);
    btn_text->setFixedSize(MENU_ITEM_WID-MENU_SPACING,MENU_ITEM_HEI);
    btn_text->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    btn_text->setStyleSheet(MENU_STYLE_TEXT);

    /*set layout*/
    h_layout = new QHBoxLayout(this);
    h_layout->setMargin(0);
    h_layout->setSpacing(0);
    h_layout->addSpacing(MENU_SPACING);
    h_layout->addWidget(btn_text);

    setLayout(h_layout);
}

QString ShadowButton::produceStyle()
{
    QString ret = "center";
    switch (textAlign) {
    case 0:
        ret = "left";
        break;
    case 1:
        ret = "center";
        break;
    case 2:
        ret = "fignt";
        break;
    default:
        break;
    }
    return ret;
}

void ShadowButton::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {
        m_isClickble = true;
        m_startPoint = ev->pos();
    }
}

void ShadowButton::mouseMoveEvent(QMouseEvent *ev)
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

void ShadowButton::mouseReleaseEvent(QMouseEvent * ev)
{
    if(ev->button() == Qt::LeftButton)
    {
        if(m_isClickble)
        {
            if(m_isAllowClick)
            {
                if(m_isAllowClickShadow)
                {
                    setStyleSheet(MENU_STYLE_CLICKED(produceStyle()));
                }
                m_isSelected = true;
                enterEvent(ev);
                emit clicked();
                emit sendClicked(this);
                return;
            }
        }
    }
}

void ShadowButton::enterEvent(QEvent *ev)
{
    if(!m_isSelected)
    {
        setStyleSheet(MENU_STYLE_ENTER(produceStyle()));
    }
}

void ShadowButton::leaveEvent(QEvent *ev)
{
    if(!m_isSelected)
    {
        setStyleSheet(MENU_STYLE_NORMAL(produceStyle()));
    }
}

void ShadowButton::setBtnNormal()
{
    m_isSelected = false;
    setStyleSheet(MENU_STYLE_NORMAL(produceStyle()));
}

void ShadowButton::setTextAlign(int n)
{
    if(n >= 0 && n < 3)
    {
        textAlign = n;
    }
}

/*---------------------------------------------------------------------*/

tThread::tThread(QObject *parent):
    QThread(parent)
{

}

void tThread::run()
{
    int n = 1;
    QTimer * timer = new QTimer(this);
    QEventLoop *loop = new QEventLoop(this);
    connect(timer,&QTimer::timeout,loop,&QEventLoop::quit);
    while (n<100&&n>0) {
        if(!is_run)
        {
            continue;
        }
        timer->start(200);
        loop->exec();
        ++n;
        sendPercent(n);
    }
    loop->deleteLater();
    timer->deleteLater();
    emit sendFinish();
}

/*---------------------------------------------------------------------*/

QString formatFileSize(unsigned long long bytesEg)
{
    vector<string> vec;
    vec.push_back("B");
    vec.push_back("KB");
    vec.push_back("MB");
    vec.push_back("GB");
    vec.push_back("TB");
    vec.push_back("PB");

    uint64_asa nRemainder = 0;
    double nKeyValue  = 1024.0;
    uint64_asa nByteSize = bytesEg;
    int i = 0;

    while (nByteSize >= nKeyValue && i < vec.size())
    {
        nRemainder = (uint64_asa)nByteSize % (uint64_asa)nKeyValue;
        nByteSize = nByteSize/nKeyValue;   //nByteSize /= nKeyValue
        i++;
    }

    nByteSize = floor(nByteSize);
    string strResult = to_string((uint64_asa)nByteSize);
    if(nRemainder > 0)
    {
       strResult += "." + to_string(nRemainder).substr(0,2);
    }

    strResult += vec.at(i);
    return  QString(strResult.data());
}
