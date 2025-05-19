#ifndef TOPBARWIDGET_H
#define TOPBARWIDGET_H

#include <QWidget>
#include <QMouseEvent>

class topBarWidget : public QWidget
{
    Q_OBJECT
public:
    explicit topBarWidget(QWidget *parent = nullptr);

signals:


protected:      //重写鼠标事件，实现鼠标在顶部栏上可以实现拖拽的功能
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    bool m_isDragging = false;      //标记是否拖动
    QPoint m_dragStartPosition;     //保存鼠标按下时的初始位置（对于父窗口）
};

#endif // TOPBARWIDGET_H
