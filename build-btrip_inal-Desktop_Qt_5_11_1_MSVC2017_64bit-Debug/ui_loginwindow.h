/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QLineEdit *password_lineedit;
    QGroupBox *user_type_groupbox;
    QRadioButton *customer_button;
    QRadioButton *hotelmanager_button;
    QRadioButton *administrator_button;
    QPushButton *register_button;
    QLabel *Login_label;
    QPushButton *login_button;
    QLabel *register_label;
    QLineEdit *username_lineedit;
    QLabel *error_label;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QStringLiteral("LoginWindow"));
        LoginWindow->setWindowModality(Qt::WindowModal);
        LoginWindow->resize(400, 300);
        LoginWindow->setFocusPolicy(Qt::NoFocus);
        LoginWindow->setContextMenuPolicy(Qt::DefaultContextMenu);
        LoginWindow->setStyleSheet(QLatin1String("QDialog {\n"
"  background-color: #eff4ff;\n"
"}\n"
""));
        LoginWindow->setInputMethodHints(Qt::ImhNone);
        LoginWindow->setSizeGripEnabled(false);
        password_lineedit = new QLineEdit(LoginWindow);
        password_lineedit->setObjectName(QStringLiteral("password_lineedit"));
        password_lineedit->setGeometry(QRect(60, 120, 161, 25));
        password_lineedit->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #ecf0f1;\n"
"  border: 2px solid #2c3e50;\n"
"  border-radius: 8px;\n"
"  padding-left: 25px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"  text-align: left;\n"
"  padding-right: 50px;\n"
"  background-image: url(:/qss/icon/password.png);\n"
"  background-repeat:no-repeat;\n"
"  background-position: center left;\n"
"}\n"
"\n"
""));
        password_lineedit->setEchoMode(QLineEdit::Password);
        user_type_groupbox = new QGroupBox(LoginWindow);
        user_type_groupbox->setObjectName(QStringLiteral("user_type_groupbox"));
        user_type_groupbox->setGeometry(QRect(260, 190, 131, 101));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei UI"));
        user_type_groupbox->setFont(font);
        user_type_groupbox->setStyleSheet(QLatin1String("QGroupBox \n"
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
        customer_button = new QRadioButton(user_type_groupbox);
        customer_button->setObjectName(QStringLiteral("customer_button"));
        customer_button->setGeometry(QRect(10, 20, 101, 16));
        customer_button->setFont(font);
        customer_button->setFocusPolicy(Qt::ClickFocus);
        customer_button->setStyleSheet(QLatin1String("QRadioButton{\n"
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
        customer_button->setChecked(true);
        hotelmanager_button = new QRadioButton(user_type_groupbox);
        hotelmanager_button->setObjectName(QStringLiteral("hotelmanager_button"));
        hotelmanager_button->setGeometry(QRect(10, 50, 100, 16));
        hotelmanager_button->setFont(font);
        hotelmanager_button->setFocusPolicy(Qt::ClickFocus);
        hotelmanager_button->setStyleSheet(QLatin1String("QRadioButton{\n"
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
        hotelmanager_button->setChecked(false);
        administrator_button = new QRadioButton(user_type_groupbox);
        administrator_button->setObjectName(QStringLiteral("administrator_button"));
        administrator_button->setGeometry(QRect(10, 80, 100, 16));
        administrator_button->setFont(font);
        administrator_button->setFocusPolicy(Qt::ClickFocus);
        administrator_button->setStyleSheet(QLatin1String("QRadioButton{\n"
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
        administrator_button->setChecked(false);
        register_button = new QPushButton(LoginWindow);
        register_button->setObjectName(QStringLiteral("register_button"));
        register_button->setGeometry(QRect(150, 247, 91, 20));
        register_button->setFont(font);
        register_button->setFocusPolicy(Qt::ClickFocus);
        register_button->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #bdc3c7;\n"
"  border: 1px solid #2c3e50;\n"
"  border-radius: 8px;\n"
"  padding: 3px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
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
        register_button->setAutoDefault(false);
        Login_label = new QLabel(LoginWindow);
        Login_label->setObjectName(QStringLiteral("Login_label"));
        Login_label->setGeometry(QRect(40, 20, 81, 21));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft New Tai Lue"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        Login_label->setFont(font1);
        login_button = new QPushButton(LoginWindow);
        login_button->setObjectName(QStringLiteral("login_button"));
        login_button->setGeometry(QRect(70, 190, 160, 25));
        QFont font2;
        font2.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font2.setBold(true);
        font2.setWeight(75);
        login_button->setFont(font2);
        login_button->setFocusPolicy(Qt::StrongFocus);
        login_button->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"  color: #ffffff;\n"
"  background-color: #2d89ef;\n"
"	border:none;\n"
"  padding: 3px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"	text-align: center;\n"
"}\n"
"QPushButton:hover, QPushButton:pressed , QPushButton:checked\n"
"{\n"
"  background-color:  #3c5bb9;\n"
"	text-align: right;\n"
"	padding-right: 20px;\n"
"\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"  background-image: url(:/qss/icon/appbar.navigate.next.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}\n"
"QPushButton:pressed, QPushButton:checked\n"
"{\n"
"  background-image: url(:/qss/icon/appbar.navigate.next.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}"));
        login_button->setAutoDefault(false);
        register_label = new QLabel(LoginWindow);
        register_label->setObjectName(QStringLiteral("register_label"));
        register_label->setGeometry(QRect(20, 250, 131, 16));
        QFont font3;
        font3.setFamily(QStringLiteral("Microsoft JhengHei"));
        register_label->setFont(font3);
        username_lineedit = new QLineEdit(LoginWindow);
        username_lineedit->setObjectName(QStringLiteral("username_lineedit"));
        username_lineedit->setGeometry(QRect(60, 69, 161, 25));
        username_lineedit->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #ecf0f1;\n"
"  border: 2px solid #2c3e50;\n"
"  border-radius: 8px;\n"
"  padding-left: 25px;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"  text-align: left;\n"
"  padding-right: 50px;\n"
"  background-image: url(:/qss/icon/account.png);\n"
"  background-repeat:no-repeat;\n"
"  background-position: center left;\n"
"}\n"
"\n"
"\n"
""));
        error_label = new QLabel(LoginWindow);
        error_label->setObjectName(QStringLiteral("error_label"));
        error_label->setGeometry(QRect(140, 20, 211, 25));
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

        retranslateUi(LoginWindow);

        login_button->setDefault(true);


        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QApplication::translate("LoginWindow", "Login", nullptr));
        password_lineedit->setText(QString());
        password_lineedit->setPlaceholderText(QApplication::translate("LoginWindow", "Password", nullptr));
        user_type_groupbox->setTitle(QApplication::translate("LoginWindow", "user type", nullptr));
        customer_button->setText(QApplication::translate("LoginWindow", "customer", nullptr));
        hotelmanager_button->setText(QApplication::translate("LoginWindow", "hotel manager", nullptr));
        administrator_button->setText(QApplication::translate("LoginWindow", "administrator", nullptr));
        register_button->setText(QApplication::translate("LoginWindow", "Register Now", nullptr));
        Login_label->setText(QApplication::translate("LoginWindow", "Login", nullptr));
        login_button->setText(QApplication::translate("LoginWindow", "Login", nullptr));
        register_label->setText(QApplication::translate("LoginWindow", "Not a Btrip memeber?", nullptr));
        username_lineedit->setText(QString());
        username_lineedit->setPlaceholderText(QApplication::translate("LoginWindow", "Username", nullptr));
        error_label->setText(QApplication::translate("LoginWindow", "error", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
