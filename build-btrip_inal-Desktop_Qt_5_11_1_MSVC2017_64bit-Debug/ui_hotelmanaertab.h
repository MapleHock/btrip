/********************************************************************************
** Form generated from reading UI file 'hotelmanaertab.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOTELMANAERTAB_H
#define UI_HOTELMANAERTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HotelManaerTab
{
public:
    QWidget *booking_tab;
    QTableWidget *receive_table;
    QTableWidget *unfinish_table;
    QPushButton *accept_button;
    QPushButton *reject_button;
    QLabel *error_booking_label;
    QPushButton *finish_button;
    QWidget *room_manage_tab;
    QTableWidget *room_table;
    QGroupBox *setprice_groupbox;
    QLineEdit *pirce_lineedit;
    QPushButton *reset_price_button;
    QPushButton *reset_price_similar_button;
    QGroupBox *searchroom_groupbox;
    QLineEdit *room_type_lineedit;
    QPushButton *search_button;
    QGroupBox *booking_group;
    QTableWidget *booking_date_list;

    void setupUi(QTabWidget *HotelManaerTab)
    {
        if (HotelManaerTab->objectName().isEmpty())
            HotelManaerTab->setObjectName(QStringLiteral("HotelManaerTab"));
        HotelManaerTab->resize(800, 540);
        QFont font;
        font.setFamily(QStringLiteral("Microsoft JhengHei UI"));
        HotelManaerTab->setFont(font);
        HotelManaerTab->setStyleSheet(QLatin1String("QWidget {\n"
"  background-color: #eff4ff;\n"
"}"));
        HotelManaerTab->setTabShape(QTabWidget::Rounded);
        HotelManaerTab->setMovable(false);
        booking_tab = new QWidget();
        booking_tab->setObjectName(QStringLiteral("booking_tab"));
        receive_table = new QTableWidget(booking_tab);
        if (receive_table->columnCount() < 6)
            receive_table->setColumnCount(6);
        receive_table->setObjectName(QStringLiteral("receive_table"));
        receive_table->setGeometry(QRect(50, 50, 311, 381));
        receive_table->setColumnCount(6);
        unfinish_table = new QTableWidget(booking_tab);
        if (unfinish_table->columnCount() < 6)
            unfinish_table->setColumnCount(6);
        unfinish_table->setObjectName(QStringLiteral("unfinish_table"));
        unfinish_table->setGeometry(QRect(470, 50, 291, 381));
        unfinish_table->setColumnCount(6);
        accept_button = new QPushButton(booking_tab);
        accept_button->setObjectName(QStringLiteral("accept_button"));
        accept_button->setGeometry(QRect(70, 450, 91, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font1.setBold(true);
        font1.setWeight(75);
        accept_button->setFont(font1);
        accept_button->setStyleSheet(QLatin1String("QPushButton\n"
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
        reject_button = new QPushButton(booking_tab);
        reject_button->setObjectName(QStringLiteral("reject_button"));
        reject_button->setGeometry(QRect(220, 450, 91, 41));
        reject_button->setFont(font1);
        reject_button->setStyleSheet(QLatin1String("QPushButton\n"
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
"  background-image: url(:/qss/icon/cross.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}\n"
"QPushButton:pressed, QPushButton:checked\n"
"{\n"
"  background-image: url(:/qss/icon/cross.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}\n"
""));
        error_booking_label = new QLabel(booking_tab);
        error_booking_label->setObjectName(QStringLiteral("error_booking_label"));
        error_booking_label->setGeometry(QRect(80, 20, 321, 25));
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
        finish_button = new QPushButton(booking_tab);
        finish_button->setObjectName(QStringLiteral("finish_button"));
        finish_button->setGeometry(QRect(570, 460, 91, 31));
        finish_button->setFont(font1);
        finish_button->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #bdc3c7;\n"
"  border:none;\n"
"  padding: 3px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"  text-align: right;\n"
"  padding-right: 20px;\n"
"  background-image: url(:/qss/icon/go_away.png);\n"
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
        HotelManaerTab->addTab(booking_tab, QString());
        room_manage_tab = new QWidget();
        room_manage_tab->setObjectName(QStringLiteral("room_manage_tab"));
        room_table = new QTableWidget(room_manage_tab);
        if (room_table->columnCount() < 4)
            room_table->setColumnCount(4);
        room_table->setObjectName(QStringLiteral("room_table"));
        room_table->setGeometry(QRect(40, 60, 311, 421));
        room_table->setColumnCount(4);
        setprice_groupbox = new QGroupBox(room_manage_tab);
        setprice_groupbox->setObjectName(QStringLiteral("setprice_groupbox"));
        setprice_groupbox->setGeometry(QRect(580, 50, 191, 101));
        QFont font2;
        font2.setFamily(QStringLiteral("Microsoft YaHei UI"));
        setprice_groupbox->setFont(font2);
        setprice_groupbox->setStyleSheet(QLatin1String("QGroupBox \n"
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
        pirce_lineedit = new QLineEdit(setprice_groupbox);
        pirce_lineedit->setObjectName(QStringLiteral("pirce_lineedit"));
        pirce_lineedit->setGeometry(QRect(10, 70, 101, 20));
        pirce_lineedit->setLayoutDirection(Qt::LeftToRight);
        pirce_lineedit->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #ecf0f1;\n"
"  border: 2px solid #2c3e50;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"}\n"
"\n"
"\n"
""));
        pirce_lineedit->setFrame(true);
        reset_price_button = new QPushButton(setprice_groupbox);
        reset_price_button->setObjectName(QStringLiteral("reset_price_button"));
        reset_price_button->setGeometry(QRect(10, 30, 75, 23));
        reset_price_button->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #bdc3c7;\n"
"	border:none;\n"
"  padding: 3px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"	text-align: center;\n"
"}\n"
"QPushButton:hover, QPushButton:pressed , QPushButton:checked\n"
"{\n"
"  background-color:  #95a5a6;\n"
"  text-align: right;\n"
"  padding-right: 5px;\n"
"\n"
"}\n"
""));
        reset_price_similar_button = new QPushButton(setprice_groupbox);
        reset_price_similar_button->setObjectName(QStringLiteral("reset_price_similar_button"));
        reset_price_similar_button->setGeometry(QRect(90, 30, 91, 21));
        reset_price_similar_button->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #bdc3c7;\n"
"	border:none;\n"
"  padding: 3px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"	text-align: center;\n"
"}\n"
"QPushButton:hover, QPushButton:pressed , QPushButton:checked\n"
"{\n"
"  background-color:  #95a5a6;\n"
"	text-align: right;\n"
"	padding-right: 5px;\n"
"\n"
"}\n"
""));
        searchroom_groupbox = new QGroupBox(room_manage_tab);
        searchroom_groupbox->setObjectName(QStringLiteral("searchroom_groupbox"));
        searchroom_groupbox->setGeometry(QRect(380, 50, 191, 101));
        searchroom_groupbox->setFont(font2);
        searchroom_groupbox->setStyleSheet(QLatin1String("QGroupBox \n"
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
        room_type_lineedit = new QLineEdit(searchroom_groupbox);
        room_type_lineedit->setObjectName(QStringLiteral("room_type_lineedit"));
        room_type_lineedit->setGeometry(QRect(30, 20, 141, 20));
        room_type_lineedit->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #ecf0f1;\n"
"  border: 2px solid #2c3e50;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"}\n"
"\n"
"\n"
""));
        search_button = new QPushButton(searchroom_groupbox);
        search_button->setObjectName(QStringLiteral("search_button"));
        search_button->setGeometry(QRect(60, 60, 91, 31));
        QFont font3;
        font3.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font3.setPointSize(9);
        font3.setBold(true);
        font3.setWeight(75);
        search_button->setFont(font3);
        search_button->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #bdc3c7;\n"
"  border:none;\n"
"  padding: 3px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"  text-align: right;\n"
"  padding-right: 20px;\n"
"  background-image: url(:/qss/icon/search.png);\n"
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
        booking_group = new QGroupBox(room_manage_tab);
        booking_group->setObjectName(QStringLiteral("booking_group"));
        booking_group->setGeometry(QRect(390, 170, 391, 301));
        QFont font4;
        font4.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font4.setBold(false);
        font4.setWeight(50);
        booking_group->setFont(font4);
        booking_group->setStyleSheet(QLatin1String("QGroupBox \n"
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
        booking_date_list = new QTableWidget(booking_group);
        if (booking_date_list->columnCount() < 1)
            booking_date_list->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        booking_date_list->setHorizontalHeaderItem(0, __qtablewidgetitem);
        booking_date_list->setObjectName(QStringLiteral("booking_date_list"));
        booking_date_list->setGeometry(QRect(70, 30, 256, 251));
        booking_date_list->setColumnCount(1);
        HotelManaerTab->addTab(room_manage_tab, QString());

        retranslateUi(HotelManaerTab);

        HotelManaerTab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(HotelManaerTab);
    } // setupUi

    void retranslateUi(QTabWidget *HotelManaerTab)
    {
        HotelManaerTab->setWindowTitle(QApplication::translate("HotelManaerTab", "TODO", nullptr));
        accept_button->setText(QApplication::translate("HotelManaerTab", "Accept", nullptr));
        reject_button->setText(QApplication::translate("HotelManaerTab", "Reject", nullptr));
        error_booking_label->setText(QApplication::translate("HotelManaerTab", "error", nullptr));
        finish_button->setText(QApplication::translate("HotelManaerTab", "finish", nullptr));
        HotelManaerTab->setTabText(HotelManaerTab->indexOf(booking_tab), QApplication::translate("HotelManaerTab", "                                                          bookings                                           ", nullptr));
        setprice_groupbox->setTitle(QApplication::translate("HotelManaerTab", "set price", nullptr));
        pirce_lineedit->setPlaceholderText(QApplication::translate("HotelManaerTab", "new price", nullptr));
        reset_price_button->setText(QApplication::translate("HotelManaerTab", "Reset Price", nullptr));
        reset_price_similar_button->setText(QApplication::translate("HotelManaerTab", "Reset similar", nullptr));
        searchroom_groupbox->setTitle(QApplication::translate("HotelManaerTab", "search", nullptr));
        room_type_lineedit->setPlaceholderText(QApplication::translate("HotelManaerTab", "room type", nullptr));
        search_button->setText(QApplication::translate("HotelManaerTab", "search", nullptr));
        booking_group->setTitle(QApplication::translate("HotelManaerTab", "booking dates", nullptr));
        QTableWidgetItem *___qtablewidgetitem = booking_date_list->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("HotelManaerTab", "date", nullptr));
        HotelManaerTab->setTabText(HotelManaerTab->indexOf(room_manage_tab), QApplication::translate("HotelManaerTab", "                                            room manage                                                             ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HotelManaerTab: public Ui_HotelManaerTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOTELMANAERTAB_H
