#include "gifbackgroundwidget.h"

#include <QMovie>

GifBackgroundWidget::GifBackgroundWidget(QWidget *parent)
    : QWidget{parent}
{
    movie = new QMovie(this);
    connect(movie, &QMovie::frameChanged, this, [this]() {
        update(); // 触发重绘
    });
}

void GifBackgroundWidget::setGifSource(const QString &filePath) {
    movie->setFileName(filePath);
    movie->start();
}

void GifBackgroundWidget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    if (movie->isValid()) {
        painter.drawImage(rect(), movie->currentImage());
    }
}
