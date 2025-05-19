#ifndef GIFBACKGROUNDWIDGET_H
#define GIFBACKGROUNDWIDGET_H

#include <QWidget>
#include <QPainter>

class GifBackgroundWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GifBackgroundWidget(QWidget *parent = nullptr);
    void setGifSource(const QString &filePath);     //设置背景gif的图片

signals:

protected:
    void paintEvent(QPaintEvent *event) override;       //重写paintEvent显示绘制

private:
    QMovie *movie;
};

#endif // GIFBACKGROUNDWIDGET_H
