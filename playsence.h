#ifndef PLAYSENCE_H
#define PLAYSENCE_H

#include <QMainWindow>
#include "bin.h"
class playsence : public QMainWindow
{
    Q_OBJECT
public:
    explicit playsence(int num);

    int playchoose;
    bin* barr[4][4];
    bool iswin;
    void paintEvent(QPaintEvent*);
signals:
    void backsignal();
};

#endif // PLAYSENCE_H
