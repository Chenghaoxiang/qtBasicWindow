#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gifbackgroundwidget.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void on_ptn_max_clicked();

private:
    Ui::MainWindow *ui;
    GifBackgroundWidget *background;
    QRect stackNormalGeometry;

    void initMainwindow();
    void initBackground();
    void setMainwindowStack();
    void transparentComponent();
};
#endif // MAINWINDOW_H
