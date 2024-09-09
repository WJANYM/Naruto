#include "bin.h"
#include <QTimer>
// bin::bin(QObject *parent)
//     : QObject{parent}
// {}

bin::bin(QString path){
    QPixmap m;
    bool judge = m.load(path);
    if (!judge) {
        qDebug() << "Failed to load image:" << path;
    }
    else {
        this->setFixedSize(m.width(), m.height());
        this->setIcon(m);
        this->setIconSize(QSize(m.width(), m.height()));
        // qDebug()<<"d";
    }
    t1=new QTimer(this);
    t2=new QTimer(this);
    connect(t1,&QTimer::timeout,this,[=](){
        QIcon i=QIcon(":/pic/pic-tb.jpg");
        this->setFixedSize(50,50);
        this->setIconSize(QSize(50,50));
        this->setIcon(i);
        t1->stop();
    });
    connect(t2,&QTimer::timeout,this,[=](){
        QIcon i=QIcon("://pic/pic-d1.jpg");
        this->setFixedSize(50,50);
        this->setIconSize(QSize(50,50));
        this->setIcon(i);
        t2->stop();
    });

}

void bin::changeflag(){
    if(flag){
        this->flag=0;
        t1->start(30);
    }
    else{
        this->flag=1;
        t2->start(30);
    }
}

void bin::mousePressEvent(QMouseEvent* e){
    if(bin::win){
        // qDebug()<<'o';
        return;
    }
    else{
        QPushButton::mousePressEvent(e);
    }
}
