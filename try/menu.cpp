#include "menu.h"

void menu(Ui::MainWindow* ui, MainWindow* thiswindow)
{
    ui->Close->setFlat(true);
    ui->Max->setFlat(true);
    ui->Min->setFlat(true);

    //关闭
    QObject::connect(ui->Close, &QPushButton::clicked, [=]() {
        thiswindow->close();
    });

    //最小化
    QObject::connect(ui->Min, &QPushButton::clicked, [=]() {
        thiswindow->showMinimized();
    });

    //最大化
    QObject::connect(ui->Max, &QPushButton::clicked, [=]() mutable {
        if (!thiswindow->isMaxWindow) {
            thiswindow->preGeometry = thiswindow->frameGeometry();
            thiswindow->move(thiswindow->clientRect.x(), thiswindow->clientRect.y());
            thiswindow->resize(thiswindow->clientRect.width(), thiswindow->clientRect.height());
            thiswindow->isMaxWindow = true;
        } else {
            thiswindow->move(thiswindow->preGeometry.x(), thiswindow->preGeometry.y());
            thiswindow->resize(thiswindow->preGeometry.width(), thiswindow->preGeometry.height());
            thiswindow->isMaxWindow = false;
        }
        thiswindow->changeIcon();
    });
}
