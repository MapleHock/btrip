/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actiontest1;
    QWidget *centralWidget;
    QPushButton *picture;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font.setBold(true);
        font.setWeight(75);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QLatin1String("\n"
"\n"
"QMenuBar {\n"
"    background-color: #ecf0f1;\n"
"    color: #1d1d1d;\n"
"    font-family: \"Microsoft YaHei UI\";\n"
"}\n"
"\n"
""));
        actiontest1 = new QAction(MainWindow);
        actiontest1->setObjectName(QStringLiteral("actiontest1"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        picture = new QPushButton(centralWidget);
        picture->setObjectName(QStringLiteral("picture"));
        picture->setEnabled(false);
        picture->setGeometry(QRect(250, 220, 271, 111));
        picture->setStyleSheet(QLatin1String("QPushButton {\n"
" background-image : url(:/qss/icon/BackGround.png);\n"
"}"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 23));
        menuBar->setLayoutDirection(Qt::RightToLeft);
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "B trip Beta 1.0", nullptr));
        actiontest1->setText(QApplication::translate("MainWindow", "test1", nullptr));
        picture->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
