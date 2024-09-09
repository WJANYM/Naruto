#ifndef CHOOSE_H
#define CHOOSE_H

#include <QMainWindow>
#include "mainwindow.h"
#include <QPaintEvent>
#include "playsence.h"

class choose : public QMainWindow
{
    Q_OBJECT
public:
    explicit choose(QWidget *parent=NULL);
    void paintEvent(QPaintEvent*);
    playsence* p;

signals:
    void backsignal();
};

#endif // CHOOSE_H
