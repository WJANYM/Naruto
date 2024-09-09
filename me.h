#ifndef ME_H
#define ME_H

#include <QDialog >

class Me : public QDialog
{
    Q_OBJECT
public:
    explicit Me(const QString &title, const QString &message, const QString &imagePath, QWidget *parent = nullptr);

signals:
};

#endif // ME_H
