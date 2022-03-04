/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QWidget *mainwidget;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *mainLayout;
    QWidget *titleBar;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *Min;
    QPushButton *Max;
    QPushButton *Close;
    QWidget *mainDisplayWidget;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *displayLayout;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 900);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        mainwidget = new QWidget(centralwidget);
        mainwidget->setObjectName(QString::fromUtf8("mainwidget"));
        verticalLayout_6 = new QVBoxLayout(mainwidget);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        mainLayout = new QVBoxLayout();
        mainLayout->setSpacing(0);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        mainLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        mainLayout->setContentsMargins(2, 2, 2, 2);
        titleBar = new QWidget(mainwidget);
        titleBar->setObjectName(QString::fromUtf8("titleBar"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(titleBar->sizePolicy().hasHeightForWidth());
        titleBar->setSizePolicy(sizePolicy);
        titleBar->setMinimumSize(QSize(0, 42));
        titleBar->setMaximumSize(QSize(16777215, 42));
        horizontalLayout = new QHBoxLayout(titleBar);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(622, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Min = new QPushButton(titleBar);
        Min->setObjectName(QString::fromUtf8("Min"));
        Min->setMinimumSize(QSize(32, 32));
        Min->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(Min);

        Max = new QPushButton(titleBar);
        Max->setObjectName(QString::fromUtf8("Max"));
        Max->setMinimumSize(QSize(32, 32));
        Max->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(Max);

        Close = new QPushButton(titleBar);
        Close->setObjectName(QString::fromUtf8("Close"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Close->sizePolicy().hasHeightForWidth());
        Close->setSizePolicy(sizePolicy1);
        Close->setMinimumSize(QSize(32, 32));
        Close->setStyleSheet(QString::fromUtf8(""));
        Close->setCheckable(false);
        Close->setAutoRepeat(false);
        Close->setAutoExclusive(false);

        horizontalLayout->addWidget(Close);


        mainLayout->addWidget(titleBar);

        mainDisplayWidget = new QWidget(mainwidget);
        mainDisplayWidget->setObjectName(QString::fromUtf8("mainDisplayWidget"));
        verticalLayout_5 = new QVBoxLayout(mainDisplayWidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        displayLayout = new QVBoxLayout();
        displayLayout->setObjectName(QString::fromUtf8("displayLayout"));
        displayLayout->setSizeConstraint(QLayout::SetFixedSize);

        verticalLayout_5->addLayout(displayLayout);


        mainLayout->addWidget(mainDisplayWidget);


        verticalLayout_6->addLayout(mainLayout);


        verticalLayout->addWidget(mainwidget);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Min->setText(QString());
        Max->setText(QString());
        Close->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
