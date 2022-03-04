#include "mainwindow.h"
#include "menu.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置鼠标位于窗口边缘样式
    setMouseTracking(true);
    ui->centralwidget->setMouseTracking(true);
    ui->mainwidget->setMouseTracking(true);
    ui->mainDisplayWidget->setMouseTracking(true);
    ui->titleBar->setMouseTracking(true);
    ui->Close->setMouseTracking(true);
    ui->Min->setMouseTracking(true);
    ui->Max->setMouseTracking(true);

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
    //边缘时鼠标样式改变
    if (!isPressButton) {
        mouseState = 0;
        if (!isMaxWindow && abs(event->globalX() - this->frameGeometry().left()) <= 2) {
            mouseState |= MOUSE_LEFT;
        }
        if (!isMaxWindow && abs(event->globalX() - this->frameGeometry().right()) <= 2) {
            mouseState |= MOUSE_RIGHT;
        }
        if (!isMaxWindow && abs(event->globalY() - this->frameGeometry().top()) <= 2) {
            mouseState |= MOUSE_TOP;
        }
        if (!isMaxWindow && abs(event->globalY() - this->frameGeometry().bottom()) <= 2) {
            mouseState |= MOUSE_BOTTOM;
        }
        if (mouseState == MOUSE_LEFT_TOP || mouseState == MOUSE_RIGHT_BOTTOM) {
            this->setCursor(Qt::SizeFDiagCursor);
        } else if (mouseState == MOUSE_LEFT_BOTTOM || mouseState == MOUSE_RIGHT_TOP) {
            this->setCursor(Qt::SizeBDiagCursor);
        } else if (mouseState == MOUSE_LEFT || mouseState == MOUSE_RIGHT) {
            this->setCursor(Qt::SizeHorCursor);
        } else if (mouseState == MOUSE_TOP || mouseState == MOUSE_BOTTOM) {
            this->setCursor(Qt::SizeVerCursor);
        } else {
            unsetCursor();
        }
    }
    //窗口拖动
    else {
        if (mouseState != 0) {
            movePoint = event->globalPos();
            if (mouseState & MOUSE_LEFT) {
                thisGeometry.setLeft(movePoint.x());
            }
            if (mouseState & MOUSE_RIGHT) {
                thisGeometry.setRight(movePoint.x());
            }
            if (mouseState & MOUSE_TOP) {
                thisGeometry.setTop(movePoint.y());
            }
            if (mouseState & MOUSE_BOTTOM) {
                thisGeometry.setBottom(movePoint.y());
            }
            this->move(thisGeometry.x(), thisGeometry.y());
            this->resize(thisGeometry.width(), thisGeometry.height());
            isMaxWindow = false;
        } else {
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
}

void MainWindow::mouseReleaseEvent(QMouseEvent* event)
{
    //窗口拖动
    thisGeometry = this->frameGeometry();
    isPressButton = false;

    //窗口拖到上方最大化
    if (thisGeometry.top() <= 0 && event->globalY() <= 0) {
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
