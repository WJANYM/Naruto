#ifndef DATABIN_H
#define DATABIN_H

#include <QObject>
#include <QMap>

class databin : public QObject
{
    Q_OBJECT
public:
    explicit databin(QObject *parent = nullptr);

    QMap<int,QVector<QVector<int>>> dataarr;
signals:
};

#endif // DATABIN_H
