#include "mainwindow.h"
#include "menu.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置鼠标位于窗口边缘样式
    ui->centralwidget->setMouseTracking(true);

    //初始化图标
    ui->Close->setIcon(QIcon(":/menu/close.png"));
    ui->Max->setIcon(QIcon(":/menu/up_result.png"));
    ui->Min->setIcon(QIcon(":/menu/min.png"));

    //设置任务栏图标
    this->setWindowIcon(QIcon(":/menu/max.png"));

    //获取最大可用窗口
    desktopWidget = QApplication::desktop();
    clientRect = desktopWidget->availableGeometry();
    //设置最大窗口为最大可用窗口
    this->setMaximumSize(clientRect.width(), clientRect.height());

    //去除系统边框
    setWindowFlags(Qt::FramelessWindowHint);

    //设置个人菜单
    menu(ui, this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    //窗口拖动
    if (event->button() == Qt::LeftButton) {
        startPoint = event->globalPos();
        thisGeometry = this->frameGeometry();
        isPressButton = true;
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    if (!isPressButton) {
        if (!isMaxWindow) {
            this->setCursor(Qt::SizeHorCursor);
        }
    }
    //窗口拖动
    else if (event->button() == Qt::NoButton) {
        movePoint = event->globalPos();
        QPoint displacement = movePoint - startPoint;
        if (!isMaxWindow) {
            this->move(thisGeometry.x() + displacement.x(), thisGeometry.y() + displacement.y());
        } else {
            double a = (1.0 - double(preGeometry.width()) / double(clientRect.width()));
            double b = (1.0 - double(preGeometry.height()) / double(clientRect.height()));
            int xLocation = int(double(movePoint.x() - clientRect.x()) * a) + clientRect.x();
            int yLocation = int(double(movePoint.y() - clientRect.y()) * b) + clientRect.y();
            this->move(xLocation, yLocation);
            this->resize(preGeometry.width(), preGeometry.height());
            isMaxWindow = false;
            thisGeometry.setX(xLocation);
            thisGeometry.setY(yLocation);
        }
        changeIcon();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent* event)
{
    //窗口拖动
    thisGeometry = this->frameGeometry();
    isPressButton = false;

    //窗口拖到上方最大化
    if (thisGeometry.top() < 0 && event->globalY() <= 0) {
        preGeometry = this->frameGeometry();
        this->move(clientRect.x(), clientRect.y());
        this->resize(clientRect.width(), clientRect.height());
        isMaxWindow = true;
    }
    changeIcon();
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent* event)
{
    //双击向上还原与向下还原
    if (!isMaxWindow) {
        preGeometry = this->frameGeometry();
        this->move(clientRect.x(), clientRect.y());
        this->resize(clientRect.width(), clientRect.height());
        isMaxWindow = true;
    } else if (isMaxWindow && preGeometry.y() >= 0) {
        this->move(preGeometry.x(), preGeometry.y());
        this->resize(preGeometry.width(), preGeometry.height());
        isMaxWindow = false;
    }
    //当preGeometry.y()<0时将其y()移至0处
    else {
        int preHeight = preGeometry.height();
        preGeometry.setY(0);
        preGeometry.setHeight(preHeight);
        this->move(preGeometry.x(), preGeometry.y());
        this->resize(preGeometry.width(), preGeometry.height());
        isMaxWindow = false;
    }
    changeIcon();
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Escape) {
        this->close();
    }
}

void MainWindow::changeIcon()
{
    if (isMaxWindow) {
        ui->Max->setIcon(QIcon(":/menu/down.png"));
    } else {
        ui->Max->setIcon(QIcon(":/menu/up_result.png"));
    }
}
