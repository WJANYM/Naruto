#include "me.h"
#include <QApplication>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPixmap>
#include <QHBoxLayout>

Me::Me(const QString &title, const QString &message, const QString &imagePath, QWidget *parent)
    : QDialog(parent) {
    setWindowTitle(title);

    // 创建布局
    QVBoxLayout *layout = new QVBoxLayout(this);

    // 添加图片
    QPixmap pixmap(imagePath);
    pixmap=pixmap.scaled(300,300);
    QLabel *imageLabel = new QLabel;
    imageLabel->setPixmap(pixmap);
    layout->addWidget(imageLabel);

    // 添加文本消息
    QLabel *messageLabel = new QLabel(message);
    layout->addWidget(messageLabel);

    // 添加按钮
    QPushButton *okButton = new QPushButton("确定");
    layout->addWidget(okButton);

    // 连接按钮的点击信号与对话框的接受槽
    connect(okButton, &QPushButton::clicked, this, [=](){
        this->close();
    });

    setLayout(layout);
}
