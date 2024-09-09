#include "playsence.h"
#include <QPushButton>
#include <QMenuBar>
#include "mybutton.h"
#include <QPainter>
#include <QTimer>
#include <QLabel>
#include "databin.h"
#include "me.h"
// #include "bin.h"
// playsence::playsence(QWidget *parent)
//     : QMainWindow{parent}
// {}

bool bin::win=false;
playsence::playsence(int num){
    this->playchoose=num;
    qDebug()<<QString("第%1关").arg(num);

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

    QPixmap pwin=QPixmap("://pic/_aigei_com.png");
    QLabel* lwin=new QLabel(this);
    pwin=pwin.scaled(150,75);
    lwin->setPixmap(pwin);
    lwin->setGeometry(0,0,150,75);
    lwin->move(this->width()/2-lwin->width()/2,-90);

    databin d;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            qDebug()<<d.dataarr[i*4+j+1][i][j];

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            QLabel* l=new QLabel();
            QPixmap m2=QPixmap("://pic/63e4ee640c0ac.jpg");
            m2=m2.scaled(50,50);
            l->setPixmap(m2);
            l->setGeometry(0,0,50,50);
            l->move(57+i*50,200+j*50);
            l->setParent(this);
            bin* b=new bin("://pic/pic-tb.jpg");
            b->setParent(this);
            b->setFixedSize(50,50);
            b->setIconSize(QSize(50,50));
            b->move(57+i*50,200+j*50);
            b->x=j;
            b->y=i;
            b->flag=(bool)d.dataarr[num][i][j];
            if(b->flag){
                b->setIcon(QIcon("://pic/pic-d1.jpg"));
                b->setIconSize(QSize(50,50));
            }
            this->barr[b->x][b->y]=b;
            QVector<QPair<int,int>>dir={{-1,0},{0,-1},{1,0},{0,1}};
            connect(b,&QPushButton::clicked,[=](){
                b->changeflag();
                for(int i=0;i<4;i++){
                    int x=b->x+dir[i].first;
                    int y=b->y+dir[i].second;
                    // qDebug()<<x<<' '<<y;
                    if(x<4&&y<4&&x>=0&&y>=0){
                        this->barr[x][y]->changeflag();
                        // qDebug()<<"d";

                    }

                }
                this->iswin=true;
                for(int i=0;i<4;i++){
                    for(int j=0;j<4;j++){
                        if(barr[i][j]->flag==false){
                            this->iswin=false;
                            break;
                        }
                    }
                }
                if(iswin){
                    qDebug()<<"ok";
                    bin::win=true;

                    QPropertyAnimation* animation=new QPropertyAnimation(lwin,"geometry");
                    animation->setDuration(1000);

                    animation->setStartValue(QRect(this->width()/2-lwin->width()/2,-90,150,75));

                    animation->setEndValue(QRect(this->width()/2-lwin->width()/2,90,150,75));

                    animation->setEasingCurve(QEasingCurve::OutBounce);

                    animation->start();
                    if(num==20){
                        Me* final=new Me("","恭喜你过关了,现在我们可以刷题了","");
                        final->exec();
                    }
                }

            });
        }
    }
}

void playsence::paintEvent(QPaintEvent*){
    QPixmap* m=new QPixmap(320,588);
    QPainter* r=new QPainter(this);
    m->load("://pic/2-20050F91Ga91.jpg");
    r->drawPixmap(0,0,this->width(),this->height(),*m);
    m->load("://pic//01218c590c255ea8012145501f541c.png@2o.png");
    *m=m->scaled(m->width()*0.5,m->height()*0.5);
    r->drawPixmap(0,0,*m);

}
