/********************************************************************************
** Form generated from reading UI file 'customertab.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMERTAB_H
#define UI_CUSTOMERTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include "rangeslider.h"

QT_BEGIN_NAMESPACE

class Ui_CustomerTab
{
public:
    QWidget *search_tab;
    QLineEdit *city_lineedit;
    QDateEdit *check_in_dateedit;
    QDateEdit *check_out_dateedit;
    QLabel *check_in_label;
    QLabel *check_out_label;
    QLCDNumber *total_day_lcd;
    QLineEdit *area_lineedit;
    QComboBox *bed_type_combobox;
    QLabel *bed_type_label;
    QPushButton *search_button;
    QPushButton *clear_all_button;
    QLabel *night_label;
    QCheckBox *window_checkBox;
    QCheckBox *bathroom_checkBox;
    QCheckBox *add_bed_checkBox;
    QLabel *notice_feature_label;
    QGroupBox *price_range_groupbox;
    RangeSlider *price_range_slider;
    QLineEdit *lowest_price_lineedit;
    QLineEdit *highest_price_lineedit;
    QLabel *wave_label;
    QLabel *and_more_label;
    QLabel *error_search_label;
    QWidget *bookings_tab;
    QCheckBox *unpayed_checkbox;
    QCheckBox *unaccepted_checkbox;
    QCheckBox *unfinfished_checkbox;
    QCheckBox *unreviewed_checkbox;
    QTableWidget *booking_table;
    QPushButton *pay_button;
    QPushButton *review_button;
    QLabel *error_label_booking;
    QSpinBox *review_spinbox;
    QWidget *account_tab;
    QLabel *username_label;
    QPushButton *about_button;
    QPushButton *check_patch_button;
    QLabel *icon_label;
    QPushButton *show_reset_button;
    QGroupBox *reset_groupbox;
    QLineEdit *oldpasswrod_lineedit;
    QLineEdit *newpassword_lineedit;
    QLineEdit *again_lineedit;
    QPushButton *reset_button;
    QLabel *error_match_label;
    QWidget *search_result_tab;
    QTableWidget *result_table;
    QPushButton *return_button;
    QFrame *line;
    QLabel *filter_label;
    QPushButton *price_filter_button;
    QPushButton *review_push_button;
    QLabel *bed_type_result_label;
    QComboBox *bed_type_result_combobox;
    QCheckBox *add_bed_result_checkBox;
    QCheckBox *window_result_checkBox;
    QCheckBox *bathroom_result_checkBox;
    QLabel *city_label;
    QLabel *total_result_label;
    QFrame *line_2;
    QLabel *notice_detail_label;

    void setupUi(QTabWidget *CustomerTab)
    {
        if (CustomerTab->objectName().isEmpty())
            CustomerTab->setObjectName(QStringLiteral("CustomerTab"));
        CustomerTab->resize(800, 540);
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font.setBold(false);
        font.setWeight(50);
        CustomerTab->setFont(font);
        CustomerTab->setAutoFillBackground(false);
        CustomerTab->setStyleSheet(QLatin1String("QWidget {\n"
"  background-color: #eff4ff;\n"
"}"));
        CustomerTab->setUsesScrollButtons(true);
        search_tab = new QWidget();
        search_tab->setObjectName(QStringLiteral("search_tab"));
        city_lineedit = new QLineEdit(search_tab);
        city_lineedit->setObjectName(QStringLiteral("city_lineedit"));
        city_lineedit->setGeometry(QRect(100, 120, 171, 27));
        city_lineedit->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #ecf0f1;\n"
"  border: 2px solid #2c3e50;\n"
"  border-radius: 8px;\n"
"  padding-left: 25px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"  text-align: left;\n"
"  padding-right: 50px;\n"
"  background-image: url(:/qss/icon/location.png);\n"
"  background-repeat:no-repeat;\n"
"  background-position: center left;\n"
"}\n"
"\n"
"\n"
""));
        check_in_dateedit = new QDateEdit(search_tab);
        check_in_dateedit->setObjectName(QStringLiteral("check_in_dateedit"));
        check_in_dateedit->setGeometry(QRect(540, 120, 110, 22));
        check_in_dateedit->setFocusPolicy(Qt::ClickFocus);
        check_in_dateedit->setStyleSheet(QLatin1String("QDateEdit\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #ecf0f1;\n"
"	border:2px solid #1d1d1d;\n"
"  padding: 3px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"	text-align: center;\n"
"}\n"
"\n"
"\n"
"  QDateEdit::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
" \n"
"    border-left-width: 1px;\n"
"    border-left-color: #1d1d1d;\n"
"    border-left-style: solid; \n"
"    border-top-right-radius: 3px; \n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QDateEdit::down-arrow {\n"
"    image: url(:/qss/icon/double_down.png);\n"
"}\n"
"\n"
"\n"
""));
        check_in_dateedit->setCalendarPopup(true);
        check_out_dateedit = new QDateEdit(search_tab);
        check_out_dateedit->setObjectName(QStringLiteral("check_out_dateedit"));
        check_out_dateedit->setEnabled(true);
        check_out_dateedit->setGeometry(QRect(540, 220, 110, 22));
        check_out_dateedit->setFocusPolicy(Qt::ClickFocus);
        check_out_dateedit->setStyleSheet(QLatin1String("QDateEdit\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #ecf0f1;\n"
"	border:2px solid #1d1d1d;\n"
"  padding: 3px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"	text-align: center;\n"
"}\n"
"\n"
"\n"
"  QDateEdit::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
" \n"
"    border-left-width: 1px;\n"
"    border-left-color: #1d1d1d;\n"
"    border-left-style: solid; \n"
"    border-top-right-radius: 3px; \n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QDateEdit::down-arrow {\n"
"    image: url(:/qss/icon/double_down.png);\n"
"}\n"
"\n"
"\n"
""));
        check_out_dateedit->setCalendarPopup(true);
        check_in_label = new QLabel(search_tab);
        check_in_label->setObjectName(QStringLiteral("check_in_label"));
        check_in_label->setGeometry(QRect(410, 120, 105, 25));
        check_in_label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: none;\n"
"  border: none;\n"
"  padding-left: 30px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"  text-align: left;\n"
"  background-image: url(:/qss/icon/checkin.png);\n"
"  background-repeat:no-repeat;\n"
"  background-position: center left;\n"
"}"));
        check_out_label = new QLabel(search_tab);
        check_out_label->setObjectName(QStringLiteral("check_out_label"));
        check_out_label->setGeometry(QRect(413, 222, 101, 25));
        check_out_label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: none;\n"
"  border: none;\n"
"  padding-left: 30px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"  text-align: left;\n"
"  background-image: url(:/qss/icon/checkout.png);\n"
"  background-repeat:no-repeat;\n"
"  background-position: center left;\n"
"}"));
        total_day_lcd = new QLCDNumber(search_tab);
        total_day_lcd->setObjectName(QStringLiteral("total_day_lcd"));
        total_day_lcd->setGeometry(QRect(550, 170, 41, 21));
        total_day_lcd->setFrameShape(QFrame::Box);
        total_day_lcd->setFrameShadow(QFrame::Plain);
        total_day_lcd->setLineWidth(2);
        total_day_lcd->setSmallDecimalPoint(false);
        total_day_lcd->setDigitCount(2);
        total_day_lcd->setProperty("intValue", QVariant(0));
        area_lineedit = new QLineEdit(search_tab);
        area_lineedit->setObjectName(QStringLiteral("area_lineedit"));
        area_lineedit->setGeometry(QRect(100, 180, 171, 27));
        area_lineedit->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #ecf0f1;\n"
"  border: 2px solid #2c3e50;\n"
"  border-radius: 8px;\n"
"  padding-left: 27px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"  text-align: left;\n"
"  padding-right: 50px;\n"
"  background-image: url(:/qss/icon/area.png);\n"
"  background-repeat:no-repeat;\n"
"  background-position: center left;\n"
"}\n"
"\n"
"\n"
""));
        bed_type_combobox = new QComboBox(search_tab);
        bed_type_combobox->addItem(QString());
        bed_type_combobox->addItem(QString());
        bed_type_combobox->addItem(QString());
        bed_type_combobox->addItem(QString());
        bed_type_combobox->setObjectName(QStringLiteral("bed_type_combobox"));
        bed_type_combobox->setGeometry(QRect(200, 230, 69, 22));
        bed_type_combobox->setStyleSheet(QLatin1String("QComboBox\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #ecf0f1;\n"
"	border:2px solid #1d1d1d;\n"
"  padding: 3px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"	text-align: center;\n"
"}\n"
"\n"
"\n"
"  QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
" \n"
"    border-left-width: 1px;\n"
"    border-left-color: #1d1d1d;\n"
"    border-left-style: solid; \n"
"    border-top-right-radius: 3px; \n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/qss/icon/double_down.png);\n"
"}\n"
"\n"
"\n"
""));
        bed_type_label = new QLabel(search_tab);
        bed_type_label->setObjectName(QStringLiteral("bed_type_label"));
        bed_type_label->setGeometry(QRect(90, 230, 91, 25));
        bed_type_label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: none;\n"
"  border: none;\n"
"  padding-left: 30px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"  text-align: left;\n"
"  background-image: url(:/qss/icon/bedtype.png);\n"
"  background-repeat:no-repeat;\n"
"  background-position: center left;\n"
"}"));
        search_button = new QPushButton(search_tab);
        search_button->setObjectName(QStringLiteral("search_button"));
        search_button->setGeometry(QRect(210, 400, 101, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font1.setBold(true);
        font1.setWeight(75);
        search_button->setFont(font1);
        search_button->setStyleSheet(QLatin1String("QPushButton\n"
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
"	padding-right: 20px;\n"
"\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"  background-image: url(:/qss/icon/search.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}\n"
"QPushButton:pressed, QPushButton:checked\n"
"{\n"
"  background-image: url(:/qss/icon/search.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}"));
        clear_all_button = new QPushButton(search_tab);
        clear_all_button->setObjectName(QStringLiteral("clear_all_button"));
        clear_all_button->setGeometry(QRect(470, 400, 91, 31));
        clear_all_button->setFont(font1);
        clear_all_button->setStyleSheet(QLatin1String("QPushButton\n"
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
"	padding-right: 20px;\n"
"\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"  background-image: url(:/qss/icon/erase.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}\n"
"QPushButton:pressed, QPushButton:checked\n"
"{\n"
"  background-image: url(:/qss/icon/erase.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}"));
        night_label = new QLabel(search_tab);
        night_label->setObjectName(QStringLiteral("night_label"));
        night_label->setGeometry(QRect(610, 170, 54, 22));
        window_checkBox = new QCheckBox(search_tab);
        window_checkBox->setObjectName(QStringLiteral("window_checkBox"));
        window_checkBox->setGeometry(QRect(210, 350, 71, 16));
        QFont font2;
        font2.setFamily(QStringLiteral("Microsoft JhengHei UI"));
        font2.setBold(true);
        font2.setWeight(75);
        window_checkBox->setFont(font2);
        window_checkBox->setChecked(true);
        window_checkBox->setTristate(false);
        bathroom_checkBox = new QCheckBox(search_tab);
        bathroom_checkBox->setObjectName(QStringLiteral("bathroom_checkBox"));
        bathroom_checkBox->setGeometry(QRect(320, 350, 71, 16));
        bathroom_checkBox->setFont(font2);
        bathroom_checkBox->setChecked(true);
        add_bed_checkBox = new QCheckBox(search_tab);
        add_bed_checkBox->setObjectName(QStringLiteral("add_bed_checkBox"));
        add_bed_checkBox->setGeometry(QRect(450, 350, 91, 16));
        add_bed_checkBox->setFont(font2);
        notice_feature_label = new QLabel(search_tab);
        notice_feature_label->setObjectName(QStringLiteral("notice_feature_label"));
        notice_feature_label->setGeometry(QRect(70, 345, 121, 25));
        notice_feature_label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: none;\n"
"  border: none;\n"
"  padding-left: 30px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"  text-align: left;\n"
"  background-image: url(:/qss/icon/star.png);\n"
"  background-repeat:no-repeat;\n"
"  background-position: center left;\n"
"}"));
        price_range_groupbox = new QGroupBox(search_tab);
        price_range_groupbox->setObjectName(QStringLiteral("price_range_groupbox"));
        price_range_groupbox->setGeometry(QRect(390, 300, 331, 35));
        price_range_groupbox->setFont(font2);
        price_range_slider = new RangeSlider(price_range_groupbox);
        price_range_slider->setObjectName(QStringLiteral("price_range_slider"));
        price_range_slider->setGeometry(QRect(0, 15, 311, 20));
        lowest_price_lineedit = new QLineEdit(search_tab);
        lowest_price_lineedit->setObjectName(QStringLiteral("lowest_price_lineedit"));
        lowest_price_lineedit->setGeometry(QRect(140, 300, 61, 20));
        lowest_price_lineedit->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #ecf0f1;\n"
"  border: 2px solid #2c3e50;\n"
"  border-radius: 8px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"}\n"
"\n"
"\n"
""));
        highest_price_lineedit = new QLineEdit(search_tab);
        highest_price_lineedit->setObjectName(QStringLiteral("highest_price_lineedit"));
        highest_price_lineedit->setGeometry(QRect(240, 300, 61, 20));
        highest_price_lineedit->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #ecf0f1;\n"
"  border: 2px solid #2c3e50;\n"
"  border-radius: 8px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"}\n"
"\n"
"\n"
""));
        wave_label = new QLabel(search_tab);
        wave_label->setObjectName(QStringLiteral("wave_label"));
        wave_label->setGeometry(QRect(215, 300, 16, 16));
        QFont font3;
        font3.setFamily(QStringLiteral("Microsoft JhengHei"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setWeight(50);
        wave_label->setFont(font3);
        and_more_label = new QLabel(search_tab);
        and_more_label->setObjectName(QStringLiteral("and_more_label"));
        and_more_label->setGeometry(QRect(310, 305, 61, 16));
        and_more_label->setFont(font2);
        error_search_label = new QLabel(search_tab);
        error_search_label->setObjectName(QStringLiteral("error_search_label"));
        error_search_label->setGeometry(QRect(100, 70, 321, 25));
        error_search_label->setStyleSheet(QLatin1String("QLabel\n"
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
        CustomerTab->addTab(search_tab, QString());
        bookings_tab = new QWidget();
        bookings_tab->setObjectName(QStringLiteral("bookings_tab"));
        unpayed_checkbox = new QCheckBox(bookings_tab);
        unpayed_checkbox->setObjectName(QStringLiteral("unpayed_checkbox"));
        unpayed_checkbox->setGeometry(QRect(650, 160, 101, 31));
        QFont font4;
        font4.setFamily(QStringLiteral("Microsoft YaHei UI"));
        unpayed_checkbox->setFont(font4);
        unpayed_checkbox->setChecked(true);
        unaccepted_checkbox = new QCheckBox(bookings_tab);
        unaccepted_checkbox->setObjectName(QStringLiteral("unaccepted_checkbox"));
        unaccepted_checkbox->setGeometry(QRect(650, 210, 101, 31));
        unaccepted_checkbox->setFont(font4);
        unaccepted_checkbox->setChecked(true);
        unfinfished_checkbox = new QCheckBox(bookings_tab);
        unfinfished_checkbox->setObjectName(QStringLiteral("unfinfished_checkbox"));
        unfinfished_checkbox->setGeometry(QRect(650, 250, 111, 31));
        unfinfished_checkbox->setFont(font4);
        unfinfished_checkbox->setChecked(true);
        unreviewed_checkbox = new QCheckBox(bookings_tab);
        unreviewed_checkbox->setObjectName(QStringLiteral("unreviewed_checkbox"));
        unreviewed_checkbox->setGeometry(QRect(650, 290, 111, 31));
        unreviewed_checkbox->setFont(font4);
        unreviewed_checkbox->setChecked(true);
        booking_table = new QTableWidget(bookings_tab);
        if (booking_table->columnCount() < 7)
            booking_table->setColumnCount(7);
        booking_table->setObjectName(QStringLiteral("booking_table"));
        booking_table->setGeometry(QRect(60, 50, 531, 411));
        booking_table->setColumnCount(7);
        pay_button = new QPushButton(bookings_tab);
        pay_button->setObjectName(QStringLiteral("pay_button"));
        pay_button->setGeometry(QRect(650, 340, 91, 41));
        QFont font5;
        font5.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font5.setPointSize(10);
        font5.setBold(true);
        font5.setWeight(75);
        pay_button->setFont(font5);
        pay_button->setStyleSheet(QLatin1String("QPushButton\n"
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
"	padding-right: 20px;\n"
"\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"  background-image: url(:/qss/icon/pay.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}\n"
"QPushButton:pressed, QPushButton:checked\n"
"{\n"
"  background-image: url(:/qss/icon/pay.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}"));
        review_button = new QPushButton(bookings_tab);
        review_button->setObjectName(QStringLiteral("review_button"));
        review_button->setGeometry(QRect(650, 400, 91, 41));
        QFont font6;
        font6.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font6.setPointSize(9);
        font6.setBold(true);
        font6.setWeight(75);
        review_button->setFont(font6);
        review_button->setStyleSheet(QLatin1String("QPushButton\n"
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
"	padding-right: 20px;\n"
"\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"  background-image: url(:/qss/icon/review.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}\n"
"QPushButton:pressed, QPushButton:checked\n"
"{\n"
"  background-image: url(:/qss/icon/review.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}"));
        error_label_booking = new QLabel(bookings_tab);
        error_label_booking->setObjectName(QStringLiteral("error_label_booking"));
        error_label_booking->setGeometry(QRect(70, 20, 481, 25));
        error_label_booking->setStyleSheet(QLatin1String("QLabel\n"
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
        review_spinbox = new QSpinBox(bookings_tab);
        review_spinbox->setObjectName(QStringLiteral("review_spinbox"));
        review_spinbox->setGeometry(QRect(710, 470, 42, 22));
        review_spinbox->setMaximum(5);
        review_spinbox->setValue(3);
        CustomerTab->addTab(bookings_tab, QString());
        account_tab = new QWidget();
        account_tab->setObjectName(QStringLiteral("account_tab"));
        username_label = new QLabel(account_tab);
        username_label->setObjectName(QStringLiteral("username_label"));
        username_label->setGeometry(QRect(130, 90, 401, 21));
        username_label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: none;\n"
"  border: none;\n"
"  padding-left: 30px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"  text-align: left;\n"
"  background-image: url(:/qss/icon/account.png);\n"
"  background-repeat:no-repeat;\n"
"  background-position: center left;\n"
"}"));
        about_button = new QPushButton(account_tab);
        about_button->setObjectName(QStringLiteral("about_button"));
        about_button->setGeometry(QRect(670, 460, 81, 31));
        about_button->setStyleSheet(QLatin1String("QPushButton\n"
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
"	padding-right: 20px;\n"
"\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"  background-image: url(:/qss/icon/about.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}\n"
"QPushButton:pressed, QPushButton:checked\n"
"{\n"
"  background-image: url(:/qss/icon/about.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}"));
        check_patch_button = new QPushButton(account_tab);
        check_patch_button->setObjectName(QStringLiteral("check_patch_button"));
        check_patch_button->setGeometry(QRect(670, 410, 81, 31));
        check_patch_button->setStyleSheet(QLatin1String("QPushButton\n"
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
"	padding-right: 20px;\n"
"\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"  background-image: url(:/qss/icon/patch.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}\n"
"QPushButton:pressed, QPushButton:checked\n"
"{\n"
"  background-image: url(:/qss/icon/patch.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}"));
        icon_label = new QLabel(account_tab);
        icon_label->setObjectName(QStringLiteral("icon_label"));
        icon_label->setGeometry(QRect(130, 150, 261, 41));
        icon_label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: none;\n"
"  border: none;\n"
"  padding-left: 30px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"  text-align: left;\n"
"  background-repeat:no-repeat;\n"
"  background-position: center left;\n"
"}"));
        show_reset_button = new QPushButton(account_tab);
        show_reset_button->setObjectName(QStringLiteral("show_reset_button"));
        show_reset_button->setGeometry(QRect(140, 220, 101, 23));
        show_reset_button->setStyleSheet(QLatin1String("QPushButton\n"
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
"\n"
"}"));
        reset_groupbox = new QGroupBox(account_tab);
        reset_groupbox->setObjectName(QStringLiteral("reset_groupbox"));
        reset_groupbox->setGeometry(QRect(190, 270, 391, 161));
        oldpasswrod_lineedit = new QLineEdit(reset_groupbox);
        oldpasswrod_lineedit->setObjectName(QStringLiteral("oldpasswrod_lineedit"));
        oldpasswrod_lineedit->setGeometry(QRect(40, 40, 221, 21));
        oldpasswrod_lineedit->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #ecf0f1;\n"
"  border: 2px solid #2c3e50;\n"
"  border-radius: 8px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"\n"
"}\n"
"\n"
"\n"
""));
        newpassword_lineedit = new QLineEdit(reset_groupbox);
        newpassword_lineedit->setObjectName(QStringLiteral("newpassword_lineedit"));
        newpassword_lineedit->setGeometry(QRect(40, 70, 221, 20));
        newpassword_lineedit->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #ecf0f1;\n"
"  border: 2px solid #2c3e50;\n"
"  border-radius: 8px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"\n"
"}\n"
"\n"
"\n"
""));
        again_lineedit = new QLineEdit(reset_groupbox);
        again_lineedit->setObjectName(QStringLiteral("again_lineedit"));
        again_lineedit->setGeometry(QRect(40, 110, 221, 20));
        again_lineedit->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #ecf0f1;\n"
"  border: 2px solid #2c3e50;\n"
"  border-radius: 8px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"\n"
"}\n"
"\n"
"\n"
""));
        reset_button = new QPushButton(reset_groupbox);
        reset_button->setObjectName(QStringLiteral("reset_button"));
        reset_button->setGeometry(QRect(290, 40, 91, 31));
        reset_button->setStyleSheet(QLatin1String("QPushButton\n"
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
"	padding-right: 20px;\n"
"\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"  background-image: url(:/qss/icon/reset_password.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}\n"
"QPushButton:pressed, QPushButton:checked\n"
"{\n"
"  background-image: url(:/qss/icon/reset_password.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}"));
        error_match_label = new QLabel(reset_groupbox);
        error_match_label->setObjectName(QStringLiteral("error_match_label"));
        error_match_label->setGeometry(QRect(290, 100, 81, 20));
        CustomerTab->addTab(account_tab, QString());
        search_result_tab = new QWidget();
        search_result_tab->setObjectName(QStringLiteral("search_result_tab"));
        search_result_tab->setEnabled(true);
        result_table = new QTableWidget(search_result_tab);
        if (result_table->columnCount() < 5)
            result_table->setColumnCount(5);
        result_table->setObjectName(QStringLiteral("result_table"));
        result_table->setGeometry(QRect(40, 50, 521, 411));
        result_table->setColumnCount(5);
        return_button = new QPushButton(search_result_tab);
        return_button->setObjectName(QStringLiteral("return_button"));
        return_button->setGeometry(QRect(670, 460, 91, 31));
        return_button->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #bdc3c7;\n"
"	border:none;\n"
"  padding: 3px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"	\n"
"text-align: right;\n"
"	padding-right: 20px;\n"
"\n"
"  background-image: url(:/qss/icon/return.png);\n"
"  background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}\n"
"QPushButton:hover, QPushButton:pressed , QPushButton:checked\n"
"{\n"
"  background-color:  #95a5a6;\n"
"	\n"
"}\n"
"\n"
""));
        line = new QFrame(search_result_tab);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(600, 10, 20, 491));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        filter_label = new QLabel(search_result_tab);
        filter_label->setObjectName(QStringLiteral("filter_label"));
        filter_label->setGeometry(QRect(643, 19, 91, 25));
        filter_label->setFont(font4);
        filter_label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: none;\n"
"  border: none;\n"
"  padding-left: 30px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"  text-align: left;\n"
"  background-image: url(:/qss/icon/filter.png);\n"
"  background-repeat:no-repeat;\n"
"  background-position: center left;\n"
"}"));
        price_filter_button = new QPushButton(search_result_tab);
        price_filter_button->setObjectName(QStringLiteral("price_filter_button"));
        price_filter_button->setGeometry(QRect(640, 60, 141, 51));
        price_filter_button->setStyleSheet(QLatin1String("QPushButton\n"
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
"	padding-right: 20px;\n"
"\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"  background-image: url(:/qss/icon/price.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}\n"
"QPushButton:pressed, QPushButton:checked\n"
"{\n"
"  background-image: url(:/qss/icon/price.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}"));
        review_push_button = new QPushButton(search_result_tab);
        review_push_button->setObjectName(QStringLiteral("review_push_button"));
        review_push_button->setGeometry(QRect(640, 130, 141, 51));
        review_push_button->setStyleSheet(QLatin1String("QPushButton\n"
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
"	padding-right: 20px;\n"
"\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"  background-image: url(:/qss/icon/comment.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}\n"
"QPushButton:pressed, QPushButton:checked\n"
"{\n"
"  background-image: url(:/qss/icon/comment.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}"));
        bed_type_result_label = new QLabel(search_result_tab);
        bed_type_result_label->setObjectName(QStringLiteral("bed_type_result_label"));
        bed_type_result_label->setGeometry(QRect(643, 190, 71, 20));
        bed_type_result_label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: none;\n"
"  border: none;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"}"));
        bed_type_result_combobox = new QComboBox(search_result_tab);
        bed_type_result_combobox->addItem(QString());
        bed_type_result_combobox->addItem(QString());
        bed_type_result_combobox->addItem(QString());
        bed_type_result_combobox->addItem(QString());
        bed_type_result_combobox->addItem(QString());
        bed_type_result_combobox->setObjectName(QStringLiteral("bed_type_result_combobox"));
        bed_type_result_combobox->setGeometry(QRect(680, 220, 69, 22));
        bed_type_result_combobox->setStyleSheet(QLatin1String("QComboBox\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #bdc3c7;\n"
"	border:2px solid #1d1d1d;\n"
"  padding: 3px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"	text-align: center;\n"
"}\n"
"\n"
"\n"
"  QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
" \n"
"    border-left-width: 1px;\n"
"    border-left-color: #1d1d1d;\n"
"    border-left-style: solid; \n"
"    border-top-right-radius: 3px; \n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/qss/icon/double_down.png);\n"
"}\n"
"\n"
"\n"
""));
        add_bed_result_checkBox = new QCheckBox(search_result_tab);
        add_bed_result_checkBox->setObjectName(QStringLiteral("add_bed_result_checkBox"));
        add_bed_result_checkBox->setGeometry(QRect(670, 360, 101, 16));
        add_bed_result_checkBox->setFont(font2);
        window_result_checkBox = new QCheckBox(search_result_tab);
        window_result_checkBox->setObjectName(QStringLiteral("window_result_checkBox"));
        window_result_checkBox->setGeometry(QRect(670, 280, 81, 20));
        window_result_checkBox->setFont(font2);
        window_result_checkBox->setStyleSheet(QLatin1String("\n"
"QCheckBox{\n"
"    spacing: 5px;\n"
"}\n"
" \n"
"QCheckBox::indicator{\n"
"    width: 15px;\n"
"    height: 15px;\n"
"}\n"
" "));
        window_result_checkBox->setChecked(true);
        window_result_checkBox->setTristate(false);
        bathroom_result_checkBox = new QCheckBox(search_result_tab);
        bathroom_result_checkBox->setObjectName(QStringLiteral("bathroom_result_checkBox"));
        bathroom_result_checkBox->setGeometry(QRect(670, 320, 81, 16));
        bathroom_result_checkBox->setFont(font2);
        bathroom_result_checkBox->setChecked(true);
        city_label = new QLabel(search_result_tab);
        city_label->setObjectName(QStringLiteral("city_label"));
        city_label->setGeometry(QRect(40, 15, 81, 25));
        city_label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: none;\n"
"  border: none;\n"
"  padding-left: 30px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"  text-align: left;\n"
"  background-image: url(:/qss/icon/location.png);\n"
"  background-repeat:no-repeat;\n"
"  background-position: center left;\n"
"}"));
        total_result_label = new QLabel(search_result_tab);
        total_result_label->setObjectName(QStringLiteral("total_result_label"));
        total_result_label->setGeometry(QRect(260, 15, 271, 25));
        total_result_label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: none;\n"
"  border: none;\n"
"  padding-left: 30px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"  text-align: left;\n"
"  background-image: url(:/qss/icon/sigama.png);\n"
"  background-repeat:no-repeat;\n"
"  background-position: center left;\n"
"}"));
        line_2 = new QFrame(search_result_tab);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(660, 450, 118, 3));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        notice_detail_label = new QLabel(search_result_tab);
        notice_detail_label->setObjectName(QStringLiteral("notice_detail_label"));
        notice_detail_label->setGeometry(QRect(80, 480, 451, 25));
        notice_detail_label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: none;\n"
"  border: none;\n"
"  padding-left: 30px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"  text-align: left;\n"
"  background-image: url(:/qss/icon/notice.png);\n"
"  background-repeat:no-repeat;\n"
"  background-position: center left;\n"
"}"));
        CustomerTab->addTab(search_result_tab, QString());

        retranslateUi(CustomerTab);

        CustomerTab->setCurrentIndex(0);
        bed_type_combobox->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(CustomerTab);
    } // setupUi

    void retranslateUi(QTabWidget *CustomerTab)
    {
        CustomerTab->setWindowTitle(QApplication::translate("CustomerTab", "TODO/setthisasname", nullptr));
        city_lineedit->setText(QString());
        city_lineedit->setPlaceholderText(QApplication::translate("CustomerTab", "City*", nullptr));
        check_in_dateedit->setDisplayFormat(QApplication::translate("CustomerTab", "MM/dd/yyyy", nullptr));
        check_out_dateedit->setDisplayFormat(QApplication::translate("CustomerTab", "MM/dd/yyyy", nullptr));
        check_in_label->setText(QApplication::translate("CustomerTab", "Check in*", nullptr));
        check_out_label->setText(QApplication::translate("CustomerTab", "Check out*", nullptr));
        area_lineedit->setPlaceholderText(QApplication::translate("CustomerTab", "Area", nullptr));
        bed_type_combobox->setItemText(0, QApplication::translate("CustomerTab", "singal", nullptr));
        bed_type_combobox->setItemText(1, QApplication::translate("CustomerTab", "double", nullptr));
        bed_type_combobox->setItemText(2, QApplication::translate("CustomerTab", "king size", nullptr));
        bed_type_combobox->setItemText(3, QApplication::translate("CustomerTab", "more..", nullptr));

        bed_type_label->setText(QApplication::translate("CustomerTab", "Bed type", nullptr));
        search_button->setText(QApplication::translate("CustomerTab", "Search", nullptr));
        clear_all_button->setText(QApplication::translate("CustomerTab", "Clear", nullptr));
        night_label->setText(QApplication::translate("CustomerTab", "night(s)", nullptr));
        window_checkBox->setText(QApplication::translate("CustomerTab", "window", nullptr));
        bathroom_checkBox->setText(QApplication::translate("CustomerTab", "bathroom", nullptr));
        add_bed_checkBox->setText(QApplication::translate("CustomerTab", "add bed", nullptr));
        notice_feature_label->setText(QApplication::translate("CustomerTab", "other features", nullptr));
        price_range_groupbox->setTitle(QApplication::translate("CustomerTab", "Price Range", nullptr));
        lowest_price_lineedit->setPlaceholderText(QApplication::translate("CustomerTab", "Lowest", nullptr));
        highest_price_lineedit->setPlaceholderText(QApplication::translate("CustomerTab", "Highest", nullptr));
        wave_label->setText(QApplication::translate("CustomerTab", "~", nullptr));
        and_more_label->setText(QApplication::translate("CustomerTab", "and more", nullptr));
        error_search_label->setText(QApplication::translate("CustomerTab", "error", nullptr));
        CustomerTab->setTabText(CustomerTab->indexOf(search_tab), QApplication::translate("CustomerTab", "              search              ", nullptr));
        unpayed_checkbox->setText(QApplication::translate("CustomerTab", "Unpayed one", nullptr));
        unaccepted_checkbox->setText(QApplication::translate("CustomerTab", "Unchecked one", nullptr));
        unfinfished_checkbox->setText(QApplication::translate("CustomerTab", "Unfinished one", nullptr));
        unreviewed_checkbox->setText(QApplication::translate("CustomerTab", "Unreviewed one", nullptr));
        pay_button->setText(QApplication::translate("CustomerTab", "pay", nullptr));
        review_button->setText(QApplication::translate("CustomerTab", "review", nullptr));
        error_label_booking->setText(QApplication::translate("CustomerTab", "error", nullptr));
        CustomerTab->setTabText(CustomerTab->indexOf(bookings_tab), QApplication::translate("CustomerTab", "           bookings          ", nullptr));
        username_label->setText(QApplication::translate("CustomerTab", "Username:", nullptr));
        about_button->setText(QApplication::translate("CustomerTab", "about", nullptr));
        check_patch_button->setText(QApplication::translate("CustomerTab", "patch", nullptr));
        icon_label->setText(QApplication::translate("CustomerTab", "Icon:", nullptr));
        show_reset_button->setText(QApplication::translate("CustomerTab", "Reset password", nullptr));
        reset_groupbox->setTitle(QApplication::translate("CustomerTab", "Reset your password", nullptr));
        oldpasswrod_lineedit->setPlaceholderText(QApplication::translate("CustomerTab", "Enter your old password", nullptr));
        newpassword_lineedit->setPlaceholderText(QApplication::translate("CustomerTab", "Enter your new password", nullptr));
        again_lineedit->setPlaceholderText(QApplication::translate("CustomerTab", "Enter your new password again", nullptr));
        reset_button->setText(QApplication::translate("CustomerTab", "Reset", nullptr));
        error_match_label->setText(QApplication::translate("CustomerTab", "error match", nullptr));
        CustomerTab->setTabText(CustomerTab->indexOf(account_tab), QApplication::translate("CustomerTab", "          account          ", nullptr));
        return_button->setText(QApplication::translate("CustomerTab", "Return", nullptr));
        filter_label->setText(QApplication::translate("CustomerTab", "Filter", nullptr));
        price_filter_button->setText(QApplication::translate("CustomerTab", "price low to high", nullptr));
        review_push_button->setText(QApplication::translate("CustomerTab", "reivew high to low", nullptr));
        bed_type_result_label->setText(QApplication::translate("CustomerTab", "bed type:", nullptr));
        bed_type_result_combobox->setItemText(0, QApplication::translate("CustomerTab", "any", nullptr));
        bed_type_result_combobox->setItemText(1, QApplication::translate("CustomerTab", "single", nullptr));
        bed_type_result_combobox->setItemText(2, QApplication::translate("CustomerTab", "double", nullptr));
        bed_type_result_combobox->setItemText(3, QApplication::translate("CustomerTab", "king size", nullptr));
        bed_type_result_combobox->setItemText(4, QApplication::translate("CustomerTab", "more", nullptr));

        add_bed_result_checkBox->setText(QApplication::translate("CustomerTab", "add bed", nullptr));
        window_result_checkBox->setText(QApplication::translate("CustomerTab", "window", nullptr));
        bathroom_result_checkBox->setText(QApplication::translate("CustomerTab", "bathroom", nullptr));
        city_label->setText(QApplication::translate("CustomerTab", "City:", nullptr));
        total_result_label->setText(QApplication::translate("CustomerTab", "Total: result", nullptr));
        notice_detail_label->setText(QApplication::translate("CustomerTab", "if you want to book or get more details, please double click its name", nullptr));
        CustomerTab->setTabText(CustomerTab->indexOf(search_result_tab), QApplication::translate("CustomerTab", "       search result       ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomerTab: public Ui_CustomerTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMERTAB_H
