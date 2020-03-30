/********************************************************************************
** Form generated from reading UI file 'detaildialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETAILDIALOG_H
#define UI_DETAILDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>

QT_BEGIN_NAMESPACE

class Ui_DetailDialog
{
public:
    QLabel *name_label;
    QPushButton *booking;
    QSpinBox *number_spin_box;
    QTreeWidget *other_treewidget;
    QLabel *review_label;
    QTableWidget *rooms_list;
    QLabel *error_label;

    void setupUi(QDialog *DetailDialog)
    {
        if (DetailDialog->objectName().isEmpty())
            DetailDialog->setObjectName(QStringLiteral("DetailDialog"));
        DetailDialog->resize(800, 600);
        DetailDialog->setStyleSheet(QLatin1String("QWidget {\n"
"	background-color: #eff4ff;\n"
"}"));
        name_label = new QLabel(DetailDialog);
        name_label->setObjectName(QStringLiteral("name_label"));
        name_label->setGeometry(QRect(50, 40, 221, 16));
        name_label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: none;\n"
"  border: none;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"}"));
        booking = new QPushButton(DetailDialog);
        booking->setObjectName(QStringLiteral("booking"));
        booking->setGeometry(QRect(450, 540, 131, 31));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font.setBold(true);
        font.setWeight(75);
        booking->setFont(font);
        booking->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #bdc3c7;\n"
"  border:none;\n"
"  padding: 3px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"  text-align: right;\n"
"  padding-right: 20px;\n"
"  background-image: url(:/qss/icon/this.png);\n"
"  background-repeat:no-repeat;\n"
"  background-position: center left;\n"
"}\n"
"\n"
"QPushButton:hover, QPushButton:pressed , QPushButton:checked\n"
"{\n"
"  background-color:  #95a5a6;\n"
"}\n"
"\n"
"\n"
""));
        number_spin_box = new QSpinBox(DetailDialog);
        number_spin_box->setObjectName(QStringLiteral("number_spin_box"));
        number_spin_box->setGeometry(QRect(610, 550, 91, 22));
        number_spin_box->setValue(1);
        other_treewidget = new QTreeWidget(DetailDialog);
        other_treewidget->setObjectName(QStringLiteral("other_treewidget"));
        other_treewidget->setGeometry(QRect(530, 140, 256, 371));
        review_label = new QLabel(DetailDialog);
        review_label->setObjectName(QStringLiteral("review_label"));
        review_label->setGeometry(QRect(510, 40, 241, 16));
        review_label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: none;\n"
"  border: none;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"}"));
        rooms_list = new QTableWidget(DetailDialog);
        if (rooms_list->columnCount() < 4)
            rooms_list->setColumnCount(4);
        rooms_list->setObjectName(QStringLiteral("rooms_list"));
        rooms_list->setGeometry(QRect(80, 140, 391, 371));
        rooms_list->setColumnCount(4);
        error_label = new QLabel(DetailDialog);
        error_label->setObjectName(QStringLiteral("error_label"));
        error_label->setGeometry(QRect(90, 540, 341, 25));
        error_label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: none;\n"
"  border: none;\n"
"  padding-left: 30px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"  text-align: left;\n"
"  background-image: url(:/qss/icon/error.png);\n"
"  background-repeat:no-repeat;\n"
"  background-position: center left;\n"
"}"));

        retranslateUi(DetailDialog);

        QMetaObject::connectSlotsByName(DetailDialog);
    } // setupUi

    void retranslateUi(QDialog *DetailDialog)
    {
        DetailDialog->setWindowTitle(QApplication::translate("DetailDialog", "Details for this hotel", nullptr));
        name_label->setText(QApplication::translate("DetailDialog", "name:", nullptr));
        booking->setText(QApplication::translate("DetailDialog", "booking this", nullptr));
        number_spin_box->setSuffix(QApplication::translate("DetailDialog", "   room(s)", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = other_treewidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("DetailDialog", "other useful details", nullptr));
        review_label->setText(QApplication::translate("DetailDialog", "review", nullptr));
        error_label->setText(QApplication::translate("DetailDialog", "error", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DetailDialog: public Ui_DetailDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILDIALOG_H
