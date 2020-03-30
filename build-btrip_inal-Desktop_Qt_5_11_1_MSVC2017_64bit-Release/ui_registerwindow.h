/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RegisterWindow
{
public:
    QLabel *register_label;
    QLineEdit *password_lineedit;
    QPushButton *cancel_button;
    QLineEdit *check_lineedit;
    QLineEdit *username_lineedit;
    QComboBox *user_type_combobox;
    QPushButton *register_button;
    QLineEdit *belong_lineedit;
    QLabel *not_label;
    QPushButton *apply_button;
    QLabel *user_type_label;
    QLabel *error_label;

    void setupUi(QDialog *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName(QStringLiteral("RegisterWindow"));
        RegisterWindow->resize(456, 356);
        RegisterWindow->setStyleSheet(QLatin1String("QDialog {\n"
"background-color: #eff4ff;\n"
"}"));
        register_label = new QLabel(RegisterWindow);
        register_label->setObjectName(QStringLiteral("register_label"));
        register_label->setGeometry(QRect(40, 30, 81, 21));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        register_label->setFont(font);
        password_lineedit = new QLineEdit(RegisterWindow);
        password_lineedit->setObjectName(QStringLiteral("password_lineedit"));
        password_lineedit->setGeometry(QRect(110, 110, 221, 31));
        password_lineedit->setFocusPolicy(Qt::StrongFocus);
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
"\n"
""));
        password_lineedit->setEchoMode(QLineEdit::Password);
        cancel_button = new QPushButton(RegisterWindow);
        cancel_button->setObjectName(QStringLiteral("cancel_button"));
        cancel_button->setGeometry(QRect(240, 250, 91, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font1.setPointSize(10);
        cancel_button->setFont(font1);
        cancel_button->setFocusPolicy(Qt::ClickFocus);
        cancel_button->setStyleSheet(QLatin1String("QPushButton\n"
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
        cancel_button->setAutoDefault(false);
        check_lineedit = new QLineEdit(RegisterWindow);
        check_lineedit->setObjectName(QStringLiteral("check_lineedit"));
        check_lineedit->setGeometry(QRect(110, 160, 221, 31));
        check_lineedit->setFocusPolicy(Qt::StrongFocus);
        check_lineedit->setStyleSheet(QLatin1String("QLineEdit\n"
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
"\n"
""));
        check_lineedit->setEchoMode(QLineEdit::Password);
        username_lineedit = new QLineEdit(RegisterWindow);
        username_lineedit->setObjectName(QStringLiteral("username_lineedit"));
        username_lineedit->setGeometry(QRect(110, 70, 221, 31));
        username_lineedit->setFocusPolicy(Qt::StrongFocus);
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
        user_type_combobox = new QComboBox(RegisterWindow);
        user_type_combobox->addItem(QString());
        user_type_combobox->addItem(QString());
        user_type_combobox->addItem(QString());
        user_type_combobox->setObjectName(QStringLiteral("user_type_combobox"));
        user_type_combobox->setGeometry(QRect(110, 210, 81, 22));
        user_type_combobox->setFocusPolicy(Qt::StrongFocus);
        user_type_combobox->setToolTipDuration(-1);
        user_type_combobox->setAutoFillBackground(false);
        user_type_combobox->setStyleSheet(QLatin1String("QComboBox\n"
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
        user_type_combobox->setInsertPolicy(QComboBox::NoInsert);
        user_type_combobox->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
        user_type_combobox->setDuplicatesEnabled(false);
        user_type_combobox->setFrame(true);
        register_button = new QPushButton(RegisterWindow);
        register_button->setObjectName(QStringLiteral("register_button"));
        register_button->setGeometry(QRect(110, 250, 101, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font2.setPointSize(9);
        font2.setBold(true);
        font2.setWeight(75);
        register_button->setFont(font2);
        register_button->setStyleSheet(QLatin1String("QPushButton\n"
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
"  background-image: url(:/qss/icon/register.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}\n"
"QPushButton:pressed, QPushButton:checked\n"
"{\n"
"  background-image: url(:/qss/icon/register.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}"));
        register_button->setAutoDefault(false);
        belong_lineedit = new QLineEdit(RegisterWindow);
        belong_lineedit->setObjectName(QStringLiteral("belong_lineedit"));
        belong_lineedit->setEnabled(false);
        belong_lineedit->setGeometry(QRect(230, 210, 101, 20));
        belong_lineedit->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: #ecf0f1;\n"
"  border: 2px solid #2c3e50;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"}\n"
"\n"
"\n"
""));
        not_label = new QLabel(RegisterWindow);
        not_label->setObjectName(QStringLiteral("not_label"));
        not_label->setGeometry(QRect(160, 300, 151, 16));
        not_label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: none;\n"
"  border: none;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"\n"
"}"));
        apply_button = new QPushButton(RegisterWindow);
        apply_button->setObjectName(QStringLiteral("apply_button"));
        apply_button->setGeometry(QRect(320, 300, 75, 21));
        apply_button->setFocusPolicy(Qt::ClickFocus);
        apply_button->setStyleSheet(QLatin1String("QPushButton\n"
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
"}"));
        apply_button->setAutoDefault(false);
        user_type_label = new QLabel(RegisterWindow);
        user_type_label->setObjectName(QStringLiteral("user_type_label"));
        user_type_label->setGeometry(QRect(33, 210, 61, 20));
        user_type_label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"  color: #1d1d1d;\n"
"  background-color: none;\n"
"  border: none;\n"
"  font-family:\"Microsoft YaHei UI\";\n"
"\n"
"}"));
        error_label = new QLabel(RegisterWindow);
        error_label->setObjectName(QStringLiteral("error_label"));
        error_label->setGeometry(QRect(150, 30, 231, 25));
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
        register_label->raise();
        cancel_button->raise();
        not_label->raise();
        apply_button->raise();
        user_type_label->raise();
        error_label->raise();
        register_button->raise();
        belong_lineedit->raise();
        user_type_combobox->raise();
        check_lineedit->raise();
        password_lineedit->raise();
        username_lineedit->raise();

        retranslateUi(RegisterWindow);

        user_type_combobox->setCurrentIndex(-1);
        register_button->setDefault(true);


        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QDialog *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QApplication::translate("RegisterWindow", "Register", nullptr));
        register_label->setText(QApplication::translate("RegisterWindow", "Register", nullptr));
        password_lineedit->setPlaceholderText(QApplication::translate("RegisterWindow", "Password", nullptr));
        cancel_button->setText(QApplication::translate("RegisterWindow", "Cancel", nullptr));
        check_lineedit->setPlaceholderText(QApplication::translate("RegisterWindow", "Check the psassword", nullptr));
        username_lineedit->setPlaceholderText(QApplication::translate("RegisterWindow", "Username", nullptr));
        user_type_combobox->setItemText(0, QApplication::translate("RegisterWindow", "Cutomer", nullptr));
        user_type_combobox->setItemText(1, QApplication::translate("RegisterWindow", "Hotel Manger", nullptr));
        user_type_combobox->setItemText(2, QApplication::translate("RegisterWindow", "Platform Administrator", nullptr));

#ifndef QT_NO_TOOLTIP
        user_type_combobox->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        user_type_combobox->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_ACCESSIBILITY
        user_type_combobox->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        user_type_combobox->setCurrentText(QString());
        register_button->setText(QApplication::translate("RegisterWindow", "Register", nullptr));
        not_label->setText(QApplication::translate("RegisterWindow", "Not register your hotel?", nullptr));
        apply_button->setText(QApplication::translate("RegisterWindow", "apply now", nullptr));
        user_type_label->setText(QApplication::translate("RegisterWindow", "user type", nullptr));
        error_label->setText(QApplication::translate("RegisterWindow", "error", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
