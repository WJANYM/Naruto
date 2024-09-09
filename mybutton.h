#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include <QPropertyAnimation>

class mybutton : public QPushButton
{
    Q_OBJECT
public:
    mybutton(QString start,QString end = "");
    void zoom1();
    void zoom2();


    QPropertyAnimation* m_animation;
public slots:


private:
    QString imagePathStart;
    QString imagePathEnd;



};

#endif // MYBUTTON_H
