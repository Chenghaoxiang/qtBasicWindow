#include "topbarwidget.h"

topBarWidget::topBarWidget(QWidget *parent)
    : QWidget{parent}
{
    setAttribute(Qt::WA_StyledBackground, true); // 确保样式生效
    setMouseTracking(true); // 启用鼠标追踪

}

void topBarWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_isDragging = true;
        QWidget *mainWindow = window(); // 获取主窗口
        m_dragStartPosition = event->globalPosition().toPoint() - mainWindow->pos();
        event->accept();
    }
    QWidget::mousePressEvent(event);
}

void topBarWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isDragging) {
        QWidget *mainWindow = window(); // 获取主窗口
        QPoint newPos = event->globalPosition().toPoint() - m_dragStartPosition;
        mainWindow->move(newPos);
    }
    QWidget::mouseMoveEvent(event);
}

void topBarWidget::mouseReleaseEvent(QMouseEvent *event)
{
    m_isDragging = false;
    QWidget::mouseReleaseEvent(event);
}
