#ifndef BIN_H
#define BIN_H

#include <QPushButton>
#include <QMouseEvent>
class bin : public QPushButton
{
    Q_OBJECT
public:
    explicit bin(QString );
    void changeflag();
    void mousePressEvent(QMouseEvent*);

    QTimer* t1;
    QTimer* t2;
    int x;
    int y;
    bool flag;
    static bool win;

signals:
};

#endif // BIN_H
