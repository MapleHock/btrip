/********************************************************************************
** Form generated from reading UI file 'hotelapplicationstep.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOTELAPPLICATIONSTEP_H
#define UI_HOTELAPPLICATIONSTEP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>
#include <QtWidgets/QWizard>
#include <QtWidgets/QWizardPage>

QT_BEGIN_NAMESPACE

class Ui_HotelApplicationStep
{
public:
    QWizardPage *welcom_page;
    QTextBrowser *welcome_words_browser;
    QWizardPage *notice_page;
    QTextBrowser *textBrowser;
    QRadioButton *agree_radio;
    QRadioButton *reject_radio;
    QWizardPage *hotel_information_page;
    QLineEdit *name_lineedit;
    QLineEdit *city_lineedit;
    QLineEdit *area_lineedit;
    QFrame *line;
    QLineEdit *credit_lineedit;
    QLabel *hotel_policies_label;
    QTimeEdit *check_in_timeedit;
    QLabel *check_in_label;
    QLabel *check_out_label;
    QTimeEdit *check_out_timeedit;
    QSpinBox *children_adult_spinbox;
    QCheckBox *is_pet_allow_checkbox;
    QCheckBox *is_free_breakfast_checkbox;
    QLabel *label;
    QTextEdit *others_textedit;
    QFrame *line_2;
    QLabel *Amenities_label;
    QCheckBox *wifi_checkbox;
    QCheckBox *airport_checkbox;
    QCheckBox *parking_checkbox;
    QCheckBox *front24_checkbox;
    QCheckBox *nonsomking_checkbox;
    QCheckBox *luggage_storage_checkbox;
    QCheckBox *wakeup_checkbox;
    QCheckBox *cloth_service_checkbox;
    QLabel *basic_information_label;
    QLabel *error_label_info;
    QWizardPage *room_page;
    QPushButton *add_button;
    QFrame *line_3;
    QPushButton *delete_button;
    QPushButton *copy_button;
    QLabel *enter_tip_label;
    QTableWidget *rooms_list;
    QLabel *error_label_room;
    QStackedWidget *stackedWidget;
    QWidget *normal_page;
    QLineEdit *self_define_type_lineedit;
    QLineEdit *room_number_lineedit;
    QSpinBox *size_spinox;
    QSpinBox *floor_spinbox;
    QLineEdit *price_lineedit;
    QLabel *noticce_bed_type_label;
    QComboBox *bed_type_combobox;
    QCheckBox *window_checkbox;
    QCheckBox *bathroom_checkbox;
    QCheckBox *add_bed_checkbox;
    QWidget *copy_page;
    QLineEdit *copy_min_num_lineedit;
    QLabel *copy_wave_label;
    QLineEdit *copy_max_num_lineedit;
    QLineEdit *copy_floor_lineedit;
    QPushButton *copy_done_button;
    QPushButton *copy_cancel_button;
    QLabel *copy_notice_label;
    QLabel *copy_notice_label_2;
    QSpinBox *copy_row_spinbox;
    QWizardPage *finish_page;
    QLabel *wait_label;
    QLabel *notice_username_label;
    QLabel *notice_password_label;
    QLabel *username_label;
    QLabel *password_label;

    void setupUi(QWizard *HotelApplicationStep)
    {
        if (HotelApplicationStep->objectName().isEmpty())
            HotelApplicationStep->setObjectName(QStringLiteral("HotelApplicationStep"));
        HotelApplicationStep->resize(800, 600);
        welcom_page = new QWizardPage();
        welcom_page->setObjectName(QStringLiteral("welcom_page"));
        welcome_words_browser = new QTextBrowser(welcom_page);
        welcome_words_browser->setObjectName(QStringLiteral("welcome_words_browser"));
        welcome_words_browser->setGeometry(QRect(60, 20, 621, 151));
        welcome_words_browser->setFrameShape(QFrame::NoFrame);
        welcome_words_browser->setOpenLinks(true);
        HotelApplicationStep->addPage(welcom_page);
        notice_page = new QWizardPage();
        notice_page->setObjectName(QStringLiteral("notice_page"));
        textBrowser = new QTextBrowser(notice_page);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(40, 10, 681, 411));
        agree_radio = new QRadioButton(notice_page);
        agree_radio->setObjectName(QStringLiteral("agree_radio"));
        agree_radio->setGeometry(QRect(530, 440, 89, 16));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft JhengHei UI"));
        font.setBold(true);
        font.setWeight(75);
        agree_radio->setFont(font);
        agree_radio->setStyleSheet(QLatin1String("QRadioButton{\n"
"    spacing: 5px;\n"
"}\n"
" \n"
"QRadioButton::indicator{\n"
"    width: 15px;\n"
"    height: 15px;\n"
"}\n"
" \n"
"QRadioButton::indicator:checked{\n"
"    image:url(:/qss/icon/radio-on-button.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked{\n"
"    image:url(:/qss/icon/radio-off.png);\n"
"}"));
        agree_radio->setChecked(false);
        reject_radio = new QRadioButton(notice_page);
        reject_radio->setObjectName(QStringLiteral("reject_radio"));
        reject_radio->setGeometry(QRect(660, 440, 89, 16));
        reject_radio->setFont(font);
        reject_radio->setStyleSheet(QLatin1String("QRadioButton{\n"
"    spacing: 5px;\n"
"}\n"
" \n"
"QRadioButton::indicator{\n"
"    width: 15px;\n"
"    height: 15px;\n"
"}\n"
" \n"
"QRadioButton::indicator:checked{\n"
"    image:url(:/qss/icon/radio-on-button.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked{\n"
"    image:url(:/qss/icon/radio-off.png);\n"
"}"));
        reject_radio->setChecked(true);
        HotelApplicationStep->addPage(notice_page);
        hotel_information_page = new QWizardPage();
        hotel_information_page->setObjectName(QStringLiteral("hotel_information_page"));
        name_lineedit = new QLineEdit(hotel_information_page);
        name_lineedit->setObjectName(QStringLiteral("name_lineedit"));
        name_lineedit->setGeometry(QRect(20, 80, 157, 27));
        name_lineedit->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #ecf0f1;\n"
"  border: 2px solid #2c3e50;\n"
"  padding-left: 27px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"  text-align: left;\n"
"  padding-right: 50px;\n"
"  background-image: url(:/qss/icon/hotel.png);\n"
"  background-repeat:no-repeat;\n"
"  background-position: center left;\n"
"}\n"
"\n"
"\n"
""));
        city_lineedit = new QLineEdit(hotel_information_page);
        city_lineedit->setObjectName(QStringLiteral("city_lineedit"));
        city_lineedit->setGeometry(QRect(20, 130, 155, 27));
        city_lineedit->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #ecf0f1;\n"
"  border: 2px solid #2c3e50;\n"
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
        area_lineedit = new QLineEdit(hotel_information_page);
        area_lineedit->setObjectName(QStringLiteral("area_lineedit"));
        area_lineedit->setGeometry(QRect(20, 180, 155, 27));
        area_lineedit->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #ecf0f1;\n"
"  border: 2px solid #2c3e50;\n"
"  padding-left: 27px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"  text-align: left;\n"
"  background-image: url(:/qss/icon/area.png);\n"
"  background-repeat:no-repeat;\n"
"  background-position: center left;\n"
"}\n"
"\n"
"\n"
""));
        line = new QFrame(hotel_information_page);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(185, 10, 20, 451));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        credit_lineedit = new QLineEdit(hotel_information_page);
        credit_lineedit->setObjectName(QStringLiteral("credit_lineedit"));
        credit_lineedit->setGeometry(QRect(20, 290, 157, 27));
        credit_lineedit->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #ecf0f1;\n"
"  border: 2px solid #2c3e50;\n"
"  padding-left: 28px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"  text-align: left;\n"
"  padding-right: 50px;\n"
"  background-image: url(:/qss/icon/code.png);\n"
"  background-repeat:no-repeat;\n"
"  background-position: center left;\n"
"}\n"
"\n"
"\n"
""));
        hotel_policies_label = new QLabel(hotel_information_page);
        hotel_policies_label->setObjectName(QStringLiteral("hotel_policies_label"));
        hotel_policies_label->setGeometry(QRect(220, 20, 101, 16));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft JhengHei UI"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        hotel_policies_label->setFont(font1);
        check_in_timeedit = new QTimeEdit(hotel_information_page);
        check_in_timeedit->setObjectName(QStringLiteral("check_in_timeedit"));
        check_in_timeedit->setGeometry(QRect(235, 80, 118, 22));
        QFont font2;
        font2.setFamily(QStringLiteral("Microsoft YaHei UI"));
        check_in_timeedit->setFont(font2);
        check_in_timeedit->setStyleSheet(QLatin1String("QTimeEdit::up-button,QDoubleSpinBox::up-button,QSpinBox::up-button {subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/qss/icon/double-right.png);\n"
"    width: 14px;\n"
"    height: 20px;  \n"
"       \n"
"}\n"
"QTimeEdit::down-button,QDoubleSpinBox::down-button,QSpinBox::down-button {subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/qss/icon/double-left.png);\n"
"    width: 14px;\n"
"    height: 20px;\n"
"   \n"
"}\n"
"\n"
"QTimeEdit::up-button:hover,QDoubleSpinBox::up-button:hover,QSpinBox::up-button:hover {subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/qss/icon/double-right.png);\n"
"    width: 14px;\n"
"    height: 20px;\n"
"    background-color: #95a5a6;  \n"
"       \n"
"}\n"
"QTimeEdit::down-button:hover,QDoubleSpinBox::down-button:hover,QSpinBox::down-button:hover {subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/qss/icon/double-left.png);\n"
"    width: 14px;"
                        "\n"
"    height: 20px;\n"
"    background-color: #95a5a6;\n"
"}\n"
"\n"
"QTimeEdit,QDoubleSpinBox,QSpinBox {\n"
"   background-color:#ecf0f1;\n"
"   border: 2px solid #2c3e50;\n"
"   \n"
"}"));
        check_in_timeedit->setCalendarPopup(false);
        check_in_timeedit->setTime(QTime(14, 0, 0));
        check_in_label = new QLabel(hotel_information_page);
        check_in_label->setObjectName(QStringLiteral("check_in_label"));
        check_in_label->setGeometry(QRect(210, 50, 131, 25));
        check_in_label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: none;\n"
"  border: none;\n"
"  padding-left: 30px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"  text-align: left;\n"
"  background-image: url(:/qss/icon/time.png);\n"
"  background-repeat:no-repeat;\n"
"  background-position: center left;\n"
"}"));
        check_out_label = new QLabel(hotel_information_page);
        check_out_label->setObjectName(QStringLiteral("check_out_label"));
        check_out_label->setGeometry(QRect(210, 110, 151, 25));
        check_out_label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: none;\n"
"  border: none;\n"
"  padding-left: 30px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"  text-align: left;\n"
"  background-image: url(:/qss/icon/time.png);\n"
"  background-repeat:no-repeat;\n"
"  background-position: center left;\n"
"}"));
        check_out_timeedit = new QTimeEdit(hotel_information_page);
        check_out_timeedit->setObjectName(QStringLiteral("check_out_timeedit"));
        check_out_timeedit->setGeometry(QRect(240, 140, 118, 22));
        check_out_timeedit->setFont(font2);
        check_out_timeedit->setStyleSheet(QLatin1String("QTimeEdit::up-button,QDoubleSpinBox::up-button,QSpinBox::up-button {subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/qss/icon/double-right.png);\n"
"    width: 14px;\n"
"    height: 20px;  \n"
"       \n"
"}\n"
"QTimeEdit::down-button,QDoubleSpinBox::down-button,QSpinBox::down-button {subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/qss/icon/double-left.png);\n"
"    width: 14px;\n"
"    height: 20px;\n"
"   \n"
"}\n"
"\n"
"QTimeEdit::up-button:hover,QDoubleSpinBox::up-button:hover,QSpinBox::up-button:hover {subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/qss/icon/double-right.png);\n"
"    width: 14px;\n"
"    height: 20px;\n"
"    background-color: #95a5a6;  \n"
"       \n"
"}\n"
"QTimeEdit::down-button:hover,QDoubleSpinBox::down-button:hover,QSpinBox::down-button:hover {subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/qss/icon/double-left.png);\n"
"    width: 14px;"
                        "\n"
"    height: 20px;\n"
"    background-color: #95a5a6;\n"
"}\n"
"\n"
"QTimeEdit,QDoubleSpinBox,QSpinBox {\n"
"   background-color:#ecf0f1;\n"
"   border: 2px solid #2c3e50;\n"
"   \n"
"}"));
        check_out_timeedit->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        check_out_timeedit->setCurrentSection(QDateTimeEdit::HourSection);
        check_out_timeedit->setTime(QTime(12, 0, 0));
        children_adult_spinbox = new QSpinBox(hotel_information_page);
        children_adult_spinbox->setObjectName(QStringLiteral("children_adult_spinbox"));
        children_adult_spinbox->setGeometry(QRect(235, 180, 181, 21));
        QFont font3;
        font3.setFamily(QStringLiteral("Microsoft JhengHei UI"));
        children_adult_spinbox->setFont(font3);
        children_adult_spinbox->setStyleSheet(QLatin1String("QTimeEdit::up-button,QDoubleSpinBox::up-button,QSpinBox::up-button {subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/qss/icon/double-right.png);\n"
"    width: 14px;\n"
"    height: 20px;  \n"
"       \n"
"}\n"
"QTimeEdit::down-button,QDoubleSpinBox::down-button,QSpinBox::down-button {subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/qss/icon/double-left.png);\n"
"    width: 14px;\n"
"    height: 20px;\n"
"   \n"
"}\n"
"\n"
"QTimeEdit::up-button:hover,QDoubleSpinBox::up-button:hover,QSpinBox::up-button:hover {subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/qss/icon/double-right.png);\n"
"    width: 14px;\n"
"    height: 20px;\n"
"    background-color: #95a5a6;  \n"
"       \n"
"}\n"
"QTimeEdit::down-button:hover,QDoubleSpinBox::down-button:hover,QSpinBox::down-button:hover {subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/qss/icon/double-left.png);\n"
"    width: 14px;"
                        "\n"
"    height: 20px;\n"
"    background-color: #95a5a6;\n"
"}\n"
"\n"
"QTimeEdit,QDoubleSpinBox,QSpinBox {\n"
"   background-color:#ecf0f1;\n"
"   border: 2px solid #2c3e50;\n"
"   \n"
"}"));
        children_adult_spinbox->setValue(1);
        is_pet_allow_checkbox = new QCheckBox(hotel_information_page);
        is_pet_allow_checkbox->setObjectName(QStringLiteral("is_pet_allow_checkbox"));
        is_pet_allow_checkbox->setGeometry(QRect(235, 230, 161, 16));
        is_pet_allow_checkbox->setFont(font2);
        is_free_breakfast_checkbox = new QCheckBox(hotel_information_page);
        is_free_breakfast_checkbox->setObjectName(QStringLiteral("is_free_breakfast_checkbox"));
        is_free_breakfast_checkbox->setGeometry(QRect(235, 260, 161, 16));
        is_free_breakfast_checkbox->setFont(font2);
        is_free_breakfast_checkbox->setChecked(true);
        is_free_breakfast_checkbox->setTristate(false);
        label = new QLabel(hotel_information_page);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(235, 290, 111, 16));
        label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: none;\n"
"  border: none;\n"
"\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"}"));
        others_textedit = new QTextEdit(hotel_information_page);
        others_textedit->setObjectName(QStringLiteral("others_textedit"));
        others_textedit->setGeometry(QRect(235, 320, 201, 121));
        others_textedit->setStyleSheet(QLatin1String("QTextEdit\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #ecf0f1;\n"
"  border: 2px solid #2c3e50;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"}\n"
"\n"
"\n"
""));
        line_2 = new QFrame(hotel_information_page);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(460, 10, 20, 451));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        Amenities_label = new QLabel(hotel_information_page);
        Amenities_label->setObjectName(QStringLiteral("Amenities_label"));
        Amenities_label->setGeometry(QRect(500, 20, 101, 16));
        Amenities_label->setFont(font1);
        wifi_checkbox = new QCheckBox(hotel_information_page);
        wifi_checkbox->setObjectName(QStringLiteral("wifi_checkbox"));
        wifi_checkbox->setGeometry(QRect(530, 80, 111, 16));
        wifi_checkbox->setFont(font2);
        wifi_checkbox->setChecked(true);
        airport_checkbox = new QCheckBox(hotel_information_page);
        airport_checkbox->setObjectName(QStringLiteral("airport_checkbox"));
        airport_checkbox->setGeometry(QRect(530, 120, 131, 16));
        airport_checkbox->setFont(font2);
        parking_checkbox = new QCheckBox(hotel_information_page);
        parking_checkbox->setObjectName(QStringLiteral("parking_checkbox"));
        parking_checkbox->setGeometry(QRect(530, 160, 111, 16));
        parking_checkbox->setFont(font2);
        front24_checkbox = new QCheckBox(hotel_information_page);
        front24_checkbox->setObjectName(QStringLiteral("front24_checkbox"));
        front24_checkbox->setGeometry(QRect(530, 200, 121, 16));
        front24_checkbox->setFont(font2);
        front24_checkbox->setChecked(true);
        nonsomking_checkbox = new QCheckBox(hotel_information_page);
        nonsomking_checkbox->setObjectName(QStringLiteral("nonsomking_checkbox"));
        nonsomking_checkbox->setGeometry(QRect(530, 240, 151, 16));
        nonsomking_checkbox->setFont(font2);
        nonsomking_checkbox->setChecked(true);
        luggage_storage_checkbox = new QCheckBox(hotel_information_page);
        luggage_storage_checkbox->setObjectName(QStringLiteral("luggage_storage_checkbox"));
        luggage_storage_checkbox->setGeometry(QRect(530, 280, 151, 16));
        luggage_storage_checkbox->setFont(font2);
        luggage_storage_checkbox->setChecked(true);
        wakeup_checkbox = new QCheckBox(hotel_information_page);
        wakeup_checkbox->setObjectName(QStringLiteral("wakeup_checkbox"));
        wakeup_checkbox->setGeometry(QRect(530, 320, 151, 16));
        wakeup_checkbox->setFont(font2);
        wakeup_checkbox->setChecked(true);
        cloth_service_checkbox = new QCheckBox(hotel_information_page);
        cloth_service_checkbox->setObjectName(QStringLiteral("cloth_service_checkbox"));
        cloth_service_checkbox->setGeometry(QRect(530, 360, 151, 16));
        cloth_service_checkbox->setFont(font2);
        cloth_service_checkbox->setChecked(true);
        basic_information_label = new QLabel(hotel_information_page);
        basic_information_label->setObjectName(QStringLiteral("basic_information_label"));
        basic_information_label->setGeometry(QRect(10, 20, 141, 16));
        basic_information_label->setFont(font1);
        error_label_info = new QLabel(hotel_information_page);
        error_label_info->setObjectName(QStringLiteral("error_label_info"));
        error_label_info->setGeometry(QRect(500, 410, 211, 25));
        error_label_info->setStyleSheet(QLatin1String("QLabel\n"
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
        HotelApplicationStep->addPage(hotel_information_page);
        room_page = new QWizardPage();
        room_page->setObjectName(QStringLiteral("room_page"));
        add_button = new QPushButton(room_page);
        add_button->setObjectName(QStringLiteral("add_button"));
        add_button->setGeometry(QRect(340, 200, 71, 31));
        add_button->setStyleSheet(QLatin1String("QPushButton\n"
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
"  background-image: url(:/qss/icon/add.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}\n"
"QPushButton:pressed, QPushButton:checked\n"
"{\n"
"  background-image: url(:/qss/icon/tick.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}"));
        line_3 = new QFrame(room_page);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(410, 10, 20, 461));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        delete_button = new QPushButton(room_page);
        delete_button->setObjectName(QStringLiteral("delete_button"));
        delete_button->setGeometry(QRect(640, 410, 91, 31));
        delete_button->setStyleSheet(QLatin1String("QPushButton\n"
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
"  background-image: url(:/qss/icon/cross.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}\n"
"QPushButton:pressed, QPushButton:checked\n"
"{\n"
"  background-image: url(:/qss/icon/cross.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}"));
        copy_button = new QPushButton(room_page);
        copy_button->setObjectName(QStringLiteral("copy_button"));
        copy_button->setGeometry(QRect(454, 410, 131, 31));
        copy_button->setStyleSheet(QLatin1String("QPushButton\n"
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
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}\n"
"QPushButton:pressed, QPushButton:checked\n"
"{\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}"));
        enter_tip_label = new QLabel(room_page);
        enter_tip_label->setObjectName(QStringLiteral("enter_tip_label"));
        enter_tip_label->setGeometry(QRect(20, 10, 241, 16));
        QFont font4;
        font4.setFamily(QStringLiteral("Microsoft JhengHei"));
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        enter_tip_label->setFont(font4);
        rooms_list = new QTableWidget(room_page);
        if (rooms_list->columnCount() < 9)
            rooms_list->setColumnCount(9);
        rooms_list->setObjectName(QStringLiteral("rooms_list"));
        rooms_list->setGeometry(QRect(455, 20, 291, 371));
        rooms_list->setEditTriggers(QAbstractItemView::NoEditTriggers);
        rooms_list->setRowCount(0);
        rooms_list->setColumnCount(9);
        error_label_room = new QLabel(room_page);
        error_label_room->setObjectName(QStringLiteral("error_label_room"));
        error_label_room->setGeometry(QRect(30, 50, 281, 25));
        error_label_room->setStyleSheet(QLatin1String("QLabel\n"
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
        stackedWidget = new QStackedWidget(room_page);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(60, 90, 261, 391));
        normal_page = new QWidget();
        normal_page->setObjectName(QStringLiteral("normal_page"));
        self_define_type_lineedit = new QLineEdit(normal_page);
        self_define_type_lineedit->setObjectName(QStringLiteral("self_define_type_lineedit"));
        self_define_type_lineedit->setGeometry(QRect(30, 20, 164, 27));
        self_define_type_lineedit->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #ecf0f1;\n"
"  border: 2px solid #2c3e50;\n"
"  padding-left: 25px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"  text-align: left;\n"
"  padding-right: 50px;\n"
"  background-image: url(:/qss/icon/kind.png);\n"
"  background-repeat:no-repeat;\n"
"  background-position: center left;\n"
"}\n"
"\n"
"\n"
""));
        room_number_lineedit = new QLineEdit(normal_page);
        room_number_lineedit->setObjectName(QStringLiteral("room_number_lineedit"));
        room_number_lineedit->setGeometry(QRect(30, 60, 164, 27));
        room_number_lineedit->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #ecf0f1;\n"
"  border: 2px solid #2c3e50;\n"
"  padding-left: 25px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"  text-align: left;\n"
"  padding-right: 50px;\n"
"  background-image: url(:/qss/icon/number8.png);\n"
"  background-repeat:no-repeat;\n"
"  background-position: center left;\n"
"}\n"
"\n"
"\n"
""));
        size_spinox = new QSpinBox(normal_page);
        size_spinox->setObjectName(QStringLiteral("size_spinox"));
        size_spinox->setGeometry(QRect(30, 100, 164, 21));
        size_spinox->setLayoutDirection(Qt::LeftToRight);
        size_spinox->setStyleSheet(QLatin1String("QTimeEdit::up-button,QDoubleSpinBox::up-button,QSpinBox::up-button {subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/qss/icon/double-right.png);\n"
"    width: 14px;\n"
"    height: 20px;  \n"
"       \n"
"}\n"
"QTimeEdit::down-button,QDoubleSpinBox::down-button,QSpinBox::down-button {subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/qss/icon/double-left.png);\n"
"    width: 14px;\n"
"    height: 20px;\n"
"   \n"
"}\n"
"\n"
"QTimeEdit::up-button:hover,QDoubleSpinBox::up-button:hover,QSpinBox::up-button:hover {subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/qss/icon/double-right.png);\n"
"    width: 14px;\n"
"    height: 20px;\n"
"    background-color: #95a5a6;  \n"
"       \n"
"}\n"
"QTimeEdit::down-button:hover,QDoubleSpinBox::down-button:hover,QSpinBox::down-button:hover {subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/qss/icon/double-left.png);\n"
"    width: 14px;"
                        "\n"
"    height: 20px;\n"
"    background-color: #95a5a6;\n"
"}\n"
"\n"
"QTimeEdit,QDoubleSpinBox,QSpinBox {\n"
"   background-color:#ecf0f1;\n"
"   border: 2px solid #2c3e50;\n"
"   \n"
"}"));
        size_spinox->setSingleStep(5);
        size_spinox->setValue(5);
        floor_spinbox = new QSpinBox(normal_page);
        floor_spinbox->setObjectName(QStringLiteral("floor_spinbox"));
        floor_spinbox->setGeometry(QRect(30, 140, 164, 21));
        floor_spinbox->setStyleSheet(QLatin1String("QTimeEdit::up-button,QDoubleSpinBox::up-button,QSpinBox::up-button {subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/qss/icon/double-right.png);\n"
"    width: 14px;\n"
"    height: 20px;  \n"
"       \n"
"}\n"
"QTimeEdit::down-button,QDoubleSpinBox::down-button,QSpinBox::down-button {subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/qss/icon/double-left.png);\n"
"    width: 14px;\n"
"    height: 20px;\n"
"   \n"
"}\n"
"\n"
"QTimeEdit::up-button:hover,QDoubleSpinBox::up-button:hover,QSpinBox::up-button:hover {subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/qss/icon/double-right.png);\n"
"    width: 14px;\n"
"    height: 20px;\n"
"    background-color: #95a5a6;  \n"
"       \n"
"}\n"
"QTimeEdit::down-button:hover,QDoubleSpinBox::down-button:hover,QSpinBox::down-button:hover {subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/qss/icon/double-left.png);\n"
"    width: 14px;"
                        "\n"
"    height: 20px;\n"
"    background-color: #95a5a6;\n"
"}\n"
"\n"
"QTimeEdit,QDoubleSpinBox,QSpinBox {\n"
"   background-color:#ecf0f1;\n"
"   border: 2px solid #2c3e50;\n"
"   \n"
"}"));
        floor_spinbox->setMinimum(-10);
        floor_spinbox->setMaximum(80);
        floor_spinbox->setValue(1);
        price_lineedit = new QLineEdit(normal_page);
        price_lineedit->setObjectName(QStringLiteral("price_lineedit"));
        price_lineedit->setGeometry(QRect(30, 180, 164, 27));
        price_lineedit->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #ecf0f1;\n"
"  border: 2px solid #2c3e50;\n"
"  padding-left: 25px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"  text-align: left;\n"
"  padding-right: 50px;\n"
"  background-image: url(:/qss/icon/price.png);\n"
"  background-repeat:no-repeat;\n"
"  background-position: center left;\n"
"}\n"
"\n"
"\n"
""));
        noticce_bed_type_label = new QLabel(normal_page);
        noticce_bed_type_label->setObjectName(QStringLiteral("noticce_bed_type_label"));
        noticce_bed_type_label->setGeometry(QRect(20, 230, 54, 16));
        noticce_bed_type_label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: none;\n"
"  border: none;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"}"));
        bed_type_combobox = new QComboBox(normal_page);
        bed_type_combobox->addItem(QString());
        bed_type_combobox->addItem(QString());
        bed_type_combobox->addItem(QString());
        bed_type_combobox->addItem(QString());
        bed_type_combobox->setObjectName(QStringLiteral("bed_type_combobox"));
        bed_type_combobox->setGeometry(QRect(110, 230, 81, 22));
        bed_type_combobox->setStyleSheet(QLatin1String("QComboBox\n"
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
        window_checkbox = new QCheckBox(normal_page);
        window_checkbox->setObjectName(QStringLiteral("window_checkbox"));
        window_checkbox->setGeometry(QRect(40, 270, 121, 16));
        window_checkbox->setFont(font2);
        window_checkbox->setChecked(true);
        bathroom_checkbox = new QCheckBox(normal_page);
        bathroom_checkbox->setObjectName(QStringLiteral("bathroom_checkbox"));
        bathroom_checkbox->setGeometry(QRect(40, 310, 121, 16));
        bathroom_checkbox->setFont(font2);
        bathroom_checkbox->setChecked(true);
        add_bed_checkbox = new QCheckBox(normal_page);
        add_bed_checkbox->setObjectName(QStringLiteral("add_bed_checkbox"));
        add_bed_checkbox->setGeometry(QRect(40, 340, 141, 16));
        add_bed_checkbox->setFont(font2);
        add_bed_checkbox->setChecked(false);
        stackedWidget->addWidget(normal_page);
        copy_page = new QWidget();
        copy_page->setObjectName(QStringLiteral("copy_page"));
        copy_min_num_lineedit = new QLineEdit(copy_page);
        copy_min_num_lineedit->setObjectName(QStringLiteral("copy_min_num_lineedit"));
        copy_min_num_lineedit->setGeometry(QRect(40, 130, 161, 20));
        copy_min_num_lineedit->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #ecf0f1;\n"
"  border: 2px solid #2c3e50;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"}\n"
"\n"
"\n"
""));
        copy_wave_label = new QLabel(copy_page);
        copy_wave_label->setObjectName(QStringLiteral("copy_wave_label"));
        copy_wave_label->setGeometry(QRect(110, 160, 21, 16));
        copy_wave_label->setFont(font1);
        copy_max_num_lineedit = new QLineEdit(copy_page);
        copy_max_num_lineedit->setObjectName(QStringLiteral("copy_max_num_lineedit"));
        copy_max_num_lineedit->setGeometry(QRect(40, 180, 161, 20));
        copy_max_num_lineedit->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #ecf0f1;\n"
"  border: 2px solid #2c3e50;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"}\n"
"\n"
"\n"
""));
        copy_floor_lineedit = new QLineEdit(copy_page);
        copy_floor_lineedit->setObjectName(QStringLiteral("copy_floor_lineedit"));
        copy_floor_lineedit->setGeometry(QRect(40, 230, 161, 20));
        copy_floor_lineedit->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #ecf0f1;\n"
"  border: 2px solid #2c3e50;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"\n"
"}\n"
"\n"
"\n"
""));
        copy_done_button = new QPushButton(copy_page);
        copy_done_button->setObjectName(QStringLiteral("copy_done_button"));
        copy_done_button->setGeometry(QRect(30, 270, 81, 31));
        copy_done_button->setStyleSheet(QLatin1String("QPushButton\n"
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
"  background-image: url(:/qss/icon/copy.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}\n"
"QPushButton:pressed, QPushButton:checked\n"
"{\n"
"  background-image: url(:/qss/icon/copy.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}"));
        copy_cancel_button = new QPushButton(copy_page);
        copy_cancel_button->setObjectName(QStringLiteral("copy_cancel_button"));
        copy_cancel_button->setGeometry(QRect(130, 270, 81, 31));
        copy_cancel_button->setStyleSheet(QLatin1String("QPushButton\n"
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
"  background-image: url(:/qss/icon/cross.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}\n"
"QPushButton:pressed, QPushButton:checked\n"
"{\n"
"  background-image: url(:/qss/icon/cross.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}"));
        copy_notice_label = new QLabel(copy_page);
        copy_notice_label->setObjectName(QStringLiteral("copy_notice_label"));
        copy_notice_label->setGeometry(QRect(20, 20, 201, 16));
        copy_notice_label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: none;\n"
"  border: none;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"}"));
        copy_notice_label_2 = new QLabel(copy_page);
        copy_notice_label_2->setObjectName(QStringLiteral("copy_notice_label_2"));
        copy_notice_label_2->setGeometry(QRect(20, 40, 201, 16));
        copy_notice_label_2->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: none;\n"
"  border: none;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"  text-align: left;\n"
"}"));
        copy_row_spinbox = new QSpinBox(copy_page);
        copy_row_spinbox->setObjectName(QStringLiteral("copy_row_spinbox"));
        copy_row_spinbox->setGeometry(QRect(40, 90, 161, 22));
        copy_row_spinbox->setStyleSheet(QLatin1String("QTimeEdit::up-button,QDoubleSpinBox::up-button,QSpinBox::up-button {subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/qss/icon/double-right.png);\n"
"    width: 14px;\n"
"    height: 20px;  \n"
"       \n"
"}\n"
"QTimeEdit::down-button,QDoubleSpinBox::down-button,QSpinBox::down-button {subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/qss/icon/double-left.png);\n"
"    width: 14px;\n"
"    height: 20px;\n"
"   \n"
"}\n"
"\n"
"QTimeEdit::up-button:hover,QDoubleSpinBox::up-button:hover,QSpinBox::up-button:hover {subcontrol-origin:border;\n"
"    subcontrol-position:right;\n"
"    image: url(:/qss/icon/double-right.png);\n"
"    width: 14px;\n"
"    height: 20px;\n"
"    background-color: #95a5a6;  \n"
"       \n"
"}\n"
"QTimeEdit::down-button:hover,QDoubleSpinBox::down-button:hover,QSpinBox::down-button:hover {subcontrol-origin:border;\n"
"    subcontrol-position:left;\n"
"    border-image: url(:/qss/icon/double-left.png);\n"
"    width: 14px;"
                        "\n"
"    height: 20px;\n"
"    background-color: #95a5a6;\n"
"}\n"
"\n"
"QTimeEdit,QDoubleSpinBox,QSpinBox {\n"
"   background-color:#ecf0f1;\n"
"   border: 2px solid #2c3e50;\n"
"   \n"
"}"));
        copy_row_spinbox->setMinimum(1);
        stackedWidget->addWidget(copy_page);
        HotelApplicationStep->addPage(room_page);
        finish_page = new QWizardPage();
        finish_page->setObjectName(QStringLiteral("finish_page"));
        wait_label = new QLabel(finish_page);
        wait_label->setObjectName(QStringLiteral("wait_label"));
        wait_label->setGeometry(QRect(0, 80, 731, 20));
        QFont font5;
        font5.setFamily(QStringLiteral("Microsoft JhengHei UI"));
        font5.setPointSize(10);
        font5.setBold(false);
        font5.setWeight(50);
        wait_label->setFont(font5);
        notice_username_label = new QLabel(finish_page);
        notice_username_label->setObjectName(QStringLiteral("notice_username_label"));
        notice_username_label->setGeometry(QRect(90, 120, 71, 16));
        notice_username_label->setFont(font5);
        notice_password_label = new QLabel(finish_page);
        notice_password_label->setObjectName(QStringLiteral("notice_password_label"));
        notice_password_label->setGeometry(QRect(90, 150, 201, 20));
        notice_password_label->setFont(font5);
        username_label = new QLabel(finish_page);
        username_label->setObjectName(QStringLiteral("username_label"));
        username_label->setGeometry(QRect(350, 120, 71, 16));
        QFont font6;
        font6.setFamily(QStringLiteral("Microsoft JhengHei UI"));
        font6.setPointSize(10);
        font6.setBold(true);
        font6.setWeight(75);
        username_label->setFont(font6);
        password_label = new QLabel(finish_page);
        password_label->setObjectName(QStringLiteral("password_label"));
        password_label->setGeometry(QRect(350, 150, 71, 16));
        password_label->setFont(font6);
        HotelApplicationStep->addPage(finish_page);

        retranslateUi(HotelApplicationStep);

        stackedWidget->setCurrentIndex(0);
        bed_type_combobox->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(HotelApplicationStep);
    } // setupUi

    void retranslateUi(QWizard *HotelApplicationStep)
    {
        HotelApplicationStep->setWindowTitle(QApplication::translate("HotelApplicationStep", "Register your hotel at B trip", nullptr));
        welcom_page->setTitle(QApplication::translate("HotelApplicationStep", "Welcom to B trip", nullptr));
        welcom_page->setSubTitle(QString());
        welcome_words_browser->setHtml(QApplication::translate("HotelApplicationStep", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">There are few steps to send application for your hotel</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">You can follow our guide to join B trip family</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">Just follow it.</span></p>\n"
"<p style=\""
                        " margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">Here we go!</span></p></body></html>", nullptr));
        notice_page->setTitle(QString());
        textBrowser->setHtml(QApplication::translate("HotelApplicationStep", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Notice </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">xxxxxxx</p></body></html>", nullptr));
        agree_radio->setText(QApplication::translate("HotelApplicationStep", "I agree", nullptr));
        reject_radio->setText(QApplication::translate("HotelApplicationStep", "I reject", nullptr));
        name_lineedit->setText(QString());
        name_lineedit->setPlaceholderText(QApplication::translate("HotelApplicationStep", "Hotel name*", nullptr));
        city_lineedit->setText(QString());
        city_lineedit->setPlaceholderText(QApplication::translate("HotelApplicationStep", "City*", nullptr));
        area_lineedit->setText(QString());
        area_lineedit->setPlaceholderText(QApplication::translate("HotelApplicationStep", "Area*", nullptr));
        credit_lineedit->setText(QString());
        credit_lineedit->setPlaceholderText(QApplication::translate("HotelApplicationStep", "credit code*", nullptr));
        hotel_policies_label->setText(QApplication::translate("HotelApplicationStep", "Hotel Polices", nullptr));
        check_in_timeedit->setDisplayFormat(QApplication::translate("HotelApplicationStep", "h:mm", nullptr));
        check_in_label->setText(QApplication::translate("HotelApplicationStep", "check in time:", nullptr));
        check_out_label->setText(QApplication::translate("HotelApplicationStep", "check out time:", nullptr));
        check_out_timeedit->setDisplayFormat(QApplication::translate("HotelApplicationStep", "h:mm", nullptr));
        children_adult_spinbox->setSuffix(QApplication::translate("HotelApplicationStep", " child(ren) per adult", nullptr));
        children_adult_spinbox->setPrefix(QApplication::translate("HotelApplicationStep", "max ", nullptr));
        is_pet_allow_checkbox->setText(QApplication::translate("HotelApplicationStep", "is pet allowed", nullptr));
        is_free_breakfast_checkbox->setText(QApplication::translate("HotelApplicationStep", "is free breakfast", nullptr));
        label->setText(QApplication::translate("HotelApplicationStep", "other polices:", nullptr));
        Amenities_label->setText(QApplication::translate("HotelApplicationStep", "Amenities", nullptr));
        wifi_checkbox->setText(QApplication::translate("HotelApplicationStep", "is free wifi", nullptr));
        airport_checkbox->setText(QApplication::translate("HotelApplicationStep", "is airport pickup", nullptr));
        parking_checkbox->setText(QApplication::translate("HotelApplicationStep", "is free parking", nullptr));
        front24_checkbox->setText(QApplication::translate("HotelApplicationStep", "is 24hours front", nullptr));
        nonsomking_checkbox->setText(QApplication::translate("HotelApplicationStep", "is non smoking floor", nullptr));
        luggage_storage_checkbox->setText(QApplication::translate("HotelApplicationStep", "is luggage storage", nullptr));
        wakeup_checkbox->setText(QApplication::translate("HotelApplicationStep", "is wake up service", nullptr));
        cloth_service_checkbox->setText(QApplication::translate("HotelApplicationStep", "is cloth service", nullptr));
        basic_information_label->setText(QApplication::translate("HotelApplicationStep", "Basic information", nullptr));
        error_label_info->setText(QApplication::translate("HotelApplicationStep", "error", nullptr));
        add_button->setText(QApplication::translate("HotelApplicationStep", "add", nullptr));
        delete_button->setText(QApplication::translate("HotelApplicationStep", "Delete", nullptr));
        copy_button->setText(QApplication::translate("HotelApplicationStep", "Copy for similar", nullptr));
        enter_tip_label->setText(QApplication::translate("HotelApplicationStep", "enter your rooms informaion", nullptr));
        error_label_room->setText(QApplication::translate("HotelApplicationStep", "error", nullptr));
        self_define_type_lineedit->setText(QString());
        self_define_type_lineedit->setPlaceholderText(QApplication::translate("HotelApplicationStep", "room type", nullptr));
        room_number_lineedit->setText(QString());
        room_number_lineedit->setPlaceholderText(QApplication::translate("HotelApplicationStep", "room number", nullptr));
        size_spinox->setSuffix(QApplication::translate("HotelApplicationStep", " sq.m", nullptr));
        size_spinox->setPrefix(QApplication::translate("HotelApplicationStep", " size:         ", nullptr));
        floor_spinbox->setSuffix(QApplication::translate("HotelApplicationStep", " (floor)", nullptr));
        floor_spinbox->setPrefix(QApplication::translate("HotelApplicationStep", "at           ", nullptr));
        price_lineedit->setText(QString());
        price_lineedit->setPlaceholderText(QApplication::translate("HotelApplicationStep", "price", nullptr));
        noticce_bed_type_label->setText(QApplication::translate("HotelApplicationStep", "bed type:", nullptr));
        bed_type_combobox->setItemText(0, QApplication::translate("HotelApplicationStep", "single", nullptr));
        bed_type_combobox->setItemText(1, QApplication::translate("HotelApplicationStep", "double", nullptr));
        bed_type_combobox->setItemText(2, QApplication::translate("HotelApplicationStep", "king size", nullptr));
        bed_type_combobox->setItemText(3, QApplication::translate("HotelApplicationStep", "more", nullptr));

        window_checkbox->setText(QApplication::translate("HotelApplicationStep", "is with window", nullptr));
        bathroom_checkbox->setText(QApplication::translate("HotelApplicationStep", "is with bathroom", nullptr));
        add_bed_checkbox->setText(QApplication::translate("HotelApplicationStep", "is able to add bed", nullptr));
        copy_min_num_lineedit->setPlaceholderText(QApplication::translate("HotelApplicationStep", "min room number*", nullptr));
        copy_wave_label->setText(QApplication::translate("HotelApplicationStep", "~", nullptr));
        copy_max_num_lineedit->setPlaceholderText(QApplication::translate("HotelApplicationStep", "max room number*", nullptr));
        copy_floor_lineedit->setText(QString());
        copy_floor_lineedit->setPlaceholderText(QApplication::translate("HotelApplicationStep", "floor", nullptr));
        copy_done_button->setText(QApplication::translate("HotelApplicationStep", "Copy", nullptr));
        copy_cancel_button->setText(QApplication::translate("HotelApplicationStep", "Cancel", nullptr));
        copy_notice_label->setText(QApplication::translate("HotelApplicationStep", "blank with * is mandatory", nullptr));
        copy_notice_label_2->setText(QApplication::translate("HotelApplicationStep", "only pure num room can be copyed", nullptr));
        copy_row_spinbox->setSuffix(QString());
        copy_row_spinbox->setPrefix(QApplication::translate("HotelApplicationStep", "copy the room at row ", nullptr));
        finish_page->setTitle(QApplication::translate("HotelApplicationStep", "Finish", nullptr));
        finish_page->setSubTitle(QString());
        wait_label->setText(QApplication::translate("HotelApplicationStep", "please wait our checking, and you can know the checking situation through your default account.", nullptr));
        notice_username_label->setText(QApplication::translate("HotelApplicationStep", "username:", nullptr));
        notice_password_label->setText(QApplication::translate("HotelApplicationStep", "password:(remember to reset it)", nullptr));
        username_label->setText(QApplication::translate("HotelApplicationStep", "xxx", nullptr));
        password_label->setText(QApplication::translate("HotelApplicationStep", "btrip", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HotelApplicationStep: public Ui_HotelApplicationStep {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOTELAPPLICATIONSTEP_H
