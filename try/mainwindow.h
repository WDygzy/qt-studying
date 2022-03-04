#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Python.h"
#include <QDebug>
#include <QDesktopWidget>
#include <QMainWindow>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    //重构
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseDoubleClickEvent(QMouseEvent* event);
    void keyPressEvent(QKeyEvent* event);

    //当前窗口
    QRect thisGeometry;
    //之前窗口
    QRect preGeometry;

    //窗口拖动起始终止坐标
    QPoint startPoint;
    QPoint movePoint;

    //判断按下位置是否为widget
    bool isPressButton = false;
    //判断当前是否为最大窗口
    bool isMaxWindow = false;

    //获取最大可用窗口
    QDesktopWidget* desktopWidget;
    QRect clientRect;

    //改变还原图标
    void changeIcon();

    //设置鼠标位于边缘处的样
    int mouseState;
    int MOUSE_LEFT = 1, MOUSE_TOP = 2, MOUSE_RIGHT = 4, MOUSE_BOTTOM = 8,
        MOUSE_LEFT_TOP = 3, MOUSE_LEFT_BOTTOM = 9, MOUSE_RIGHT_TOP = 6, MOUSE_RIGHT_BOTTOM = 12;

private:
    Ui::MainWindow* ui;
};
#endif // MAINWINDOW_H
