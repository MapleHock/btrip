/********************************************************************************
** Form generated from reading UI file 'administratortab.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINISTRATORTAB_H
#define UI_ADMINISTRATORTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdministratorTab
{
public:
    QWidget *booking_tab;
    QGroupBox *workplace_group;
    QLabel *share_percent_label;
    QDoubleSpinBox *share_spinbox;
    QPushButton *check_button;
    QPushButton *hold_booking_button;
    QGroupBox *performance_groupbox;
    QLabel *total_check_label;
    QLabel *total_share_label;
    QLabel *error_booking_label;
    QTreeWidget *booking_list;
    QWidget *app_tab;
    QPushButton *hold_app_button;
    QPushButton *check_app_button;
    QLabel *check_app_label;
    QLabel *app_num_label;
    QLabel *error_application_label;
    QTreeWidget *app_treewidget;

    void setupUi(QTabWidget *AdministratorTab)
    {
        if (AdministratorTab->objectName().isEmpty())
            AdministratorTab->setObjectName(QStringLiteral("AdministratorTab"));
        AdministratorTab->resize(800, 540);
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei UI"));
        AdministratorTab->setFont(font);
        AdministratorTab->setStyleSheet(QLatin1String("QWidget {\n"
"  background-color: #eff4ff;\n"
"}"));
        booking_tab = new QWidget();
        booking_tab->setObjectName(QStringLiteral("booking_tab"));
        workplace_group = new QGroupBox(booking_tab);
        workplace_group->setObjectName(QStringLiteral("workplace_group"));
        workplace_group->setGeometry(QRect(530, 130, 231, 131));
        workplace_group->setFont(font);
        workplace_group->setStyleSheet(QLatin1String("QGroupBox \n"
"{\n"
"  border: 1px solid #1d1d1d;\n"
"  border-top: 1px solid #1d1d1d;\n"
"  padding: 5px\n"
"}\n"
"\n"
" \n"
"QGroupBox::title\n"
"{\n"
"   \n"
"border: 1px solid #1d1d1d;\n"
"    border-bottom: none;\n"
"    border-letf:none;\n"
"    border-right:none;\n"
"     padding: -20 5px;  \n"
"    \n"
"}"));
        share_percent_label = new QLabel(workplace_group);
        share_percent_label->setObjectName(QStringLiteral("share_percent_label"));
        share_percent_label->setGeometry(QRect(30, 20, 81, 41));
        share_percent_label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: none;\n"
"  border: none;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"  text-align: left;\n"
"\n"
"}\n"
"\n"
"\n"
""));
        share_spinbox = new QDoubleSpinBox(workplace_group);
        share_spinbox->setObjectName(QStringLiteral("share_spinbox"));
        share_spinbox->setGeometry(QRect(130, 30, 62, 22));
        share_spinbox->setDecimals(1);
        share_spinbox->setSingleStep(0.1);
        share_spinbox->setValue(5);
        check_button = new QPushButton(workplace_group);
        check_button->setObjectName(QStringLiteral("check_button"));
        check_button->setGeometry(QRect(20, 80, 91, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font1.setBold(true);
        font1.setWeight(75);
        check_button->setFont(font1);
        check_button->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #bdc3c7;\n"
"  border:none;\n"
"  padding: 3px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"  text-align: center;\n"
"}\n"
"\n"
"QPushButton:hover, QPushButton:pressed , QPushButton:checked\n"
"{\n"
"  background-color:  #95a5a6;\n"
"	text-align: right;\n"
"	padding-right: 20px;\n"
"\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"  background-image: url(:/qss/icon/tick.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}\n"
"QPushButton:pressed, QPushButton:checked\n"
"{\n"
"  background-image: url(:/qss/icon/tick.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}\n"
""));
        hold_booking_button = new QPushButton(workplace_group);
        hold_booking_button->setObjectName(QStringLiteral("hold_booking_button"));
        hold_booking_button->setGeometry(QRect(120, 80, 91, 31));
        hold_booking_button->setFont(font1);
        hold_booking_button->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #bdc3c7;\n"
"  border:none;\n"
"  padding: 3px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"  text-align: center;\n"
"}\n"
"\n"
"QPushButton:hover, QPushButton:pressed , QPushButton:checked\n"
"{\n"
"  background-color:  #95a5a6;\n"
"	text-align: right;\n"
"	padding-right: 20px;\n"
"\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"  background-image: url(:/qss/icon/wait.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}\n"
"QPushButton:pressed, QPushButton:checked\n"
"{\n"
"  background-image: url(:/qss/icon/wait.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}\n"
""));
        performance_groupbox = new QGroupBox(booking_tab);
        performance_groupbox->setObjectName(QStringLiteral("performance_groupbox"));
        performance_groupbox->setGeometry(QRect(540, 290, 231, 151));
        QFont font2;
        font2.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font2.setBold(false);
        font2.setWeight(50);
        performance_groupbox->setFont(font2);
        performance_groupbox->setStyleSheet(QLatin1String("QGroupBox \n"
"{\n"
"  border: 1px solid #1d1d1d;\n"
"  border-top: 1px solid #1d1d1d;\n"
"  padding: 5px\n"
"}\n"
"\n"
" \n"
"QGroupBox::title\n"
"{\n"
"   \n"
"border: 1px solid #1d1d1d;\n"
"    border-bottom: none;\n"
"    border-letf:none;\n"
"    border-right:none;\n"
"     padding: -20 5px;  \n"
"    \n"
"}"));
        total_check_label = new QLabel(performance_groupbox);
        total_check_label->setObjectName(QStringLiteral("total_check_label"));
        total_check_label->setGeometry(QRect(20, 40, 191, 21));
        total_check_label->setFont(font);
        total_check_label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: none;\n"
"  border: none;\n"
"  padding-left: 25px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"  text-align: left;\n"
"  background-image: url(:/qss/icon/tick.png);\n"
"  background-repeat:no-repeat;\n"
"  background-position: center left;\n"
"}\n"
"\n"
"\n"
""));
        total_share_label = new QLabel(performance_groupbox);
        total_share_label->setObjectName(QStringLiteral("total_share_label"));
        total_share_label->setGeometry(QRect(20, 90, 191, 21));
        total_share_label->setFont(font2);
        total_share_label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: none;\n"
"  border: none;\n"
"  padding-left: 25px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"  text-align: left;\n"
"  background-image: url(:/qss/icon/price.png);\n"
"  background-repeat:no-repeat;\n"
"  background-position: center left;\n"
"}\n"
"\n"
"\n"
""));
        error_booking_label = new QLabel(booking_tab);
        error_booking_label->setObjectName(QStringLiteral("error_booking_label"));
        error_booking_label->setGeometry(QRect(540, 60, 211, 25));
        error_booking_label->setFont(font);
        error_booking_label->setStyleSheet(QLatin1String("QLabel\n"
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
        booking_list = new QTreeWidget(booking_tab);
        booking_list->setObjectName(QStringLiteral("booking_list"));
        booking_list->setGeometry(QRect(70, 40, 371, 411));
        booking_list->setStyleSheet(QLatin1String("QTableView {\n"
"  background-color:	#ffffff;\n"
"}"));
        AdministratorTab->addTab(booking_tab, QString());
        app_tab = new QWidget();
        app_tab->setObjectName(QStringLiteral("app_tab"));
        hold_app_button = new QPushButton(app_tab);
        hold_app_button->setObjectName(QStringLiteral("hold_app_button"));
        hold_app_button->setGeometry(QRect(580, 130, 131, 51));
        hold_app_button->setFont(font1);
        hold_app_button->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #bdc3c7;\n"
"  border:none;\n"
"  padding: 3px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"  text-align: center;\n"
"}\n"
"\n"
"QPushButton:hover, QPushButton:pressed , QPushButton:checked\n"
"{\n"
"  background-color:  #95a5a6;\n"
"	text-align: right;\n"
"	padding-right: 20px;\n"
"\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"  background-image: url(:/qss/icon/wait.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}\n"
"QPushButton:pressed, QPushButton:checked\n"
"{\n"
"  background-image: url(:/qss/icon/wait.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}\n"
""));
        check_app_button = new QPushButton(app_tab);
        check_app_button->setObjectName(QStringLiteral("check_app_button"));
        check_app_button->setGeometry(QRect(580, 220, 131, 51));
        check_app_button->setFont(font1);
        check_app_button->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #bdc3c7;\n"
"  border:none;\n"
"  padding: 3px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"  text-align: center;\n"
"}\n"
"\n"
"QPushButton:hover, QPushButton:pressed , QPushButton:checked\n"
"{\n"
"  background-color:  #95a5a6;\n"
"	text-align: right;\n"
"	padding-right: 20px;\n"
"\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"  background-image: url(:/qss/icon/tick.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}\n"
"QPushButton:pressed, QPushButton:checked\n"
"{\n"
"  background-image: url(:/qss/icon/tick.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}\n"
""));
        check_app_label = new QLabel(app_tab);
        check_app_label->setObjectName(QStringLiteral("check_app_label"));
        check_app_label->setGeometry(QRect(550, 340, 111, 31));
        check_app_label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: none;\n"
"  border: none;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"}"));
        app_num_label = new QLabel(app_tab);
        app_num_label->setObjectName(QStringLiteral("app_num_label"));
        app_num_label->setGeometry(QRect(680, 350, 54, 12));
        app_num_label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: none;\n"
"  border: none;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"}"));
        error_application_label = new QLabel(app_tab);
        error_application_label->setObjectName(QStringLiteral("error_application_label"));
        error_application_label->setGeometry(QRect(550, 60, 211, 25));
        error_application_label->setStyleSheet(QLatin1String("QLabel\n"
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
        app_treewidget = new QTreeWidget(app_tab);
        app_treewidget->setObjectName(QStringLiteral("app_treewidget"));
        app_treewidget->setGeometry(QRect(80, 50, 371, 421));
        app_treewidget->setColumnCount(1);
        AdministratorTab->addTab(app_tab, QString());

        retranslateUi(AdministratorTab);

        AdministratorTab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AdministratorTab);
    } // setupUi

    void retranslateUi(QTabWidget *AdministratorTab)
    {
        AdministratorTab->setWindowTitle(QApplication::translate("AdministratorTab", "TabWidget", nullptr));
        workplace_group->setTitle(QApplication::translate("AdministratorTab", "work place", nullptr));
        share_percent_label->setText(QApplication::translate("AdministratorTab", "share percent", nullptr));
        share_spinbox->setSuffix(QApplication::translate("AdministratorTab", "%", nullptr));
        check_button->setText(QApplication::translate("AdministratorTab", "check", nullptr));
        hold_booking_button->setText(QApplication::translate("AdministratorTab", "hold", nullptr));
        performance_groupbox->setTitle(QApplication::translate("AdministratorTab", "performance today", nullptr));
        total_check_label->setText(QApplication::translate("AdministratorTab", "Total check:", nullptr));
        total_share_label->setText(QApplication::translate("AdministratorTab", "Total share:", nullptr));
        error_booking_label->setText(QApplication::translate("AdministratorTab", "error", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = booking_list->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("AdministratorTab", "booking for you to check", nullptr));
        AdministratorTab->setTabText(AdministratorTab->indexOf(booking_tab), QApplication::translate("AdministratorTab", "booking", nullptr));
        hold_app_button->setText(QApplication::translate("AdministratorTab", "Hold", nullptr));
        check_app_button->setText(QApplication::translate("AdministratorTab", "check", nullptr));
        check_app_label->setText(QApplication::translate("AdministratorTab", "Total check app:", nullptr));
        app_num_label->setText(QApplication::translate("AdministratorTab", "num", nullptr));
        error_application_label->setText(QApplication::translate("AdministratorTab", "error", nullptr));
        QTreeWidgetItem *___qtreewidgetitem1 = app_treewidget->headerItem();
        ___qtreewidgetitem1->setText(0, QApplication::translate("AdministratorTab", "application for you to check", nullptr));
        AdministratorTab->setTabText(AdministratorTab->indexOf(app_tab), QApplication::translate("AdministratorTab", "application", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdministratorTab: public Ui_AdministratorTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTRATORTAB_H
