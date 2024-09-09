#include "mybutton.h"
#include <QDebug>
#include <QPixmap>

mybutton::mybutton(QString start,QString end)
    : QPushButton()
    , imagePathStart(start)
    , imagePathEnd(end)
{
    QPixmap m;
    bool judge = m.load(imagePathStart);
    if (!judge) {
        qDebug() << "Failed to load image:" << imagePathStart;
    }
    else {
        this->setFixedSize(m.width(), m.height());
        this->setIcon(m);
        this->setIconSize(QSize(m.width(), m.height()));
        // qDebug()<<"d";
    }
    // show();

}
void mybutton::zoom1(){
    QPropertyAnimation* animation =new QPropertyAnimation(this,"geometry");

    animation->setDuration(500);

    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));

    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));

    animation->setEasingCurve(QEasingCurve::OutBounce);

    animation->start();
}

void mybutton::zoom2(){
    QPropertyAnimation* animation =new QPropertyAnimation(this,"geometry");

    animation->setDuration(500);

    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));

    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));

    animation->setEasingCurve(QEasingCurve::OutBounce);

    animation->start();
}
