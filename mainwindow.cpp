#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include "mybutton.h"
#include "choose.h"
#include <QTimer>
#include "me.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    setFixedSize(320,588);

    setWindowIcon(QIcon(":/pic/01218c590c255ea8012145501f541c.png@2o.png"));

    setWindowTitle("火影");

    connect(ui->actionquit,&QAction::triggered,[=](){
        this->close();
    });

    connect(ui->actionwriter, &QAction::triggered, [=]() {
        Me *me=new Me("wja", "这简直就是我", ":/pic/20210405164526_33793.jpg",this);
        me->exec();
    });

    mybutton* m1=new mybutton("://pic/5ac8-hzmafvn3745605.jpg");
    m1->setParent(this);
    m1->setFixedSize(200,100);
    m1->setIconSize(QSize(200,100));
    m1->setStyleSheet("QPushButton { border-radius: 50px; }");
    m1->move(this->width()/2-m1->width()/2,this->height()*0.8);

    choose* c=new choose(this);

    connect(m1,&QPushButton::clicked,[=](){
            c->setGeometry(this->geometry());
            m1->zoom1();
            m1->zoom2();
            QTimer::singleShot(500,this,[=]{
            c->show();
            this->hide();

        });
    });

    connect(c,&choose::backsignal,[=](){

        QTimer::singleShot(500,this,[=]{
            this->setGeometry(c->geometry());
            c->hide();
            this->show();

        });

    });
}

void MainWindow::paintEvent(QPaintEvent* e){
    QPixmap* m=new QPixmap(320,588);
    QPainter* r=new QPainter(this);
    m->load("://pic/3978-hzrevqa1535225.png");
    r->drawPixmap(0,0,this->width(),this->height(),*m);
    m->load("://pic//01218c590c255ea8012145501f541c.png@2o.png");
    *m=m->scaled(m->width()*0.5,m->height()*0.5);
    r->drawPixmap(0,0,*m);
}



MainWindow::~MainWindow()
{
    delete ui;
}
