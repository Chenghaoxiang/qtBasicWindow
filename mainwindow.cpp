#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gifbackgroundwidget.h"

#include <QGraphicsBlurEffect>
#include <QPainterPath>
#include <QPushButton>
#include <QUrl>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initBackground();
    initMainwindow();
    setMainwindowStack();
    transparentComponent();

    connect(ui->ptn_close,&QPushButton::clicked,this,&QMainWindow::close);      //close
    connect(ui->ptn_min,&QPushButton::clicked,this,&QMainWindow::showMinimized);    //min
}
//设置布局能够透明
void MainWindow::transparentComponent(){
    ui->menuwidget->setAttribute(Qt::WA_TranslucentBackground);
    ui->menuwidget->setStyleSheet("background: transparent;");
}
void MainWindow::initMainwindow(){
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
}

void MainWindow::setMainwindowStack(){

    // 对遮罩层应用模糊效果
    QGraphicsBlurEffect *blurEffect = new QGraphicsBlurEffect;
    blurEffect->setBlurRadius(1); // 模糊强度
    ui->stackwidget->setGraphicsEffect(blurEffect);

    // 生成圆角遮罩
    QPainterPath path;
    int radius = 8; // 圆角半径
    path.addRoundedRect(rect(), radius, radius);
    setMask(QRegion(path.toFillPolygon().toPolygon()));
}
void MainWindow::initBackground(){
    // 创建背景控件并覆盖整个窗口
    background = new GifBackgroundWidget(this);
    background->setGifSource(":/1.gif");
    background->setGeometry(this->rect()); // 初始填充

    // 确保背景在最底层
    background->lower();
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);
    background->setGeometry(rect()); // 背景随窗口缩放
}


void MainWindow::on_ptn_max_clicked()
{
    if (isFullScreen()) {       //如果是全屏就变回正常尺寸
        showNormal();
        setMainwindowStack();   //重绘遮罩
        ui->stackwidget->setGeometry(stackNormalGeometry);
        show();
    } else {                    //如果是正常尺寸就变全屏
        stackNormalGeometry = ui->stackwidget->geometry();
        setMask(QRegion());   // 移除遮罩以允许全屏绘制
        showFullScreen();
        ui->stackwidget->setGeometry(rect());
    }
}

