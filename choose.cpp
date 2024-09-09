#include "choose.h"
#include <QMenuBar>
#include <QPainter>
#include "mybutton.h"
#include <QStyle>
#include <QTimer>
#include <QLabel>
#include "bin.h"
#include "me.h"
choose::choose(QWidget *parent)
    : QMainWindow{parent}
{
    setFixedSize(320,588);

    setWindowIcon(QIcon(":/pic/01218c590c255ea8012145501f541c.png@2o.png"));

    setWindowTitle("火影");

    QMenuBar* mb=new QMenuBar();
    setMenuBar(mb);
    QMenu* m=mb->addMenu("开始");
    QAction* a= m->addAction("退出");

    QMenu* about=mb->addMenu("关于");
    QAction* write= about->addAction("作者");

    connect(a,&QAction::triggered,[=](){
        this->close();
    });

    connect(write, &QAction::triggered, [=]() {
        Me *me=new Me("wja", "这简直就是我", ":/pic/20210405164526_33793.jpg",this);
        me->exec();
    });

    mybutton* m1=new mybutton(":/pic/back.png");
    m1->setParent(this);
    m1->setFixedSize(50,50);
    m1->setIconSize(QSize(50,50));
    m1->setStyleSheet("QPushButton { border-radius: 50px; }");
    m1->move(this->width()-m1->width(),this->height()-m1->height());

    connect(m1,&QPushButton::clicked,[=](){
        m1->zoom1();
        m1->zoom2();
        emit this->backsignal();
    });
    // mybutton* cb=new mybutton("://pic/63e4ee640c0ac.jpg");
    // cb->setFixedSize(50,50);
    // cb->setIconSize(QSize(50,50));
    // cb->setParent(this);
    for(int i=0;i<5;i++){
        for(int j=0;j<4;j++){
            mybutton* cb=new mybutton("://pic/63e4ee640c0ac.jpg");
            cb->setFixedSize(50,50);
            cb->setIconSize(QSize(50,50));
            cb->setParent(this);
            cb->move(50*j+60,50*i+200);
            connect(cb,&QPushButton::clicked,[=](){
                qDebug()<<QString("第%1关").arg(QString::number(j+i*4+1));
                bin::win=false;
                this->hide();
                p=new playsence(j+i*4+1);
                p->setGeometry(this->geometry());
                p->show();
                connect(p,&playsence::backsignal,[=](){
                    QTimer::singleShot(500,this,[=]{
                        qDebug()<<"ok";
                        this->setGeometry(p->geometry());
                        p->hide();
                        this->show();
                        delete(p);
                    });

                });
            });
            QLabel* l=new QLabel(this);
            l->setFixedSize(50,50);
            l->move(50*j+60,50*i+200);
            l->setText(QString::number(j+i*4+1));
            l->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            l->setAttribute(Qt::WA_TransparentForMouseEvents);

        }
    }



}
void choose::paintEvent(QPaintEvent*){
    QPixmap* m=new QPixmap(320,588);
    QPainter* r=new QPainter(this);
    m->load("://pic/v2-9a4b84072e308a672a63555bd56649e3_r.jpg");
    r->drawPixmap(0,0,this->width(),this->height(),*m);
    m->load("://pic//01218c590c255ea8012145501f541c.png@2o.png");
    *m=m->scaled(m->width()*0.5,m->height()*0.5);
    r->drawPixmap(0,0,*m);

}
