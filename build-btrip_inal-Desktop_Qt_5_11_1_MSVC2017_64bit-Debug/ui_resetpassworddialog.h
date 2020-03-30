/********************************************************************************
** Form generated from reading UI file 'resetpassworddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESETPASSWORDDIALOG_H
#define UI_RESETPASSWORDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ResetPasswordDialog
{
public:
    QLabel *reset_label;
    QLineEdit *again_lineedit;
    QPushButton *reset_button;
    QLabel *error_match_label;
    QLineEdit *newpassword_lineedit;
    QLineEdit *oldpasswrod_lineedit;
    QPushButton *cancel_button;

    void setupUi(QDialog *ResetPasswordDialog)
    {
        if (ResetPasswordDialog->objectName().isEmpty())
            ResetPasswordDialog->setObjectName(QStringLiteral("ResetPasswordDialog"));
        ResetPasswordDialog->resize(400, 300);
        reset_label = new QLabel(ResetPasswordDialog);
        reset_label->setObjectName(QStringLiteral("reset_label"));
        reset_label->setGeometry(QRect(30, 30, 171, 16));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft JhengHei"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        reset_label->setFont(font);
        again_lineedit = new QLineEdit(ResetPasswordDialog);
        again_lineedit->setObjectName(QStringLiteral("again_lineedit"));
        again_lineedit->setGeometry(QRect(70, 180, 221, 20));
        reset_button = new QPushButton(ResetPasswordDialog);
        reset_button->setObjectName(QStringLiteral("reset_button"));
        reset_button->setGeometry(QRect(80, 240, 75, 23));
        error_match_label = new QLabel(ResetPasswordDialog);
        error_match_label->setObjectName(QStringLiteral("error_match_label"));
        error_match_label->setGeometry(QRect(210, 210, 81, 20));
        newpassword_lineedit = new QLineEdit(ResetPasswordDialog);
        newpassword_lineedit->setObjectName(QStringLiteral("newpassword_lineedit"));
        newpassword_lineedit->setGeometry(QRect(70, 140, 221, 20));
        oldpasswrod_lineedit = new QLineEdit(ResetPasswordDialog);
        oldpasswrod_lineedit->setObjectName(QStringLiteral("oldpasswrod_lineedit"));
        oldpasswrod_lineedit->setGeometry(QRect(70, 100, 221, 20));
        cancel_button = new QPushButton(ResetPasswordDialog);
        cancel_button->setObjectName(QStringLiteral("cancel_button"));
        cancel_button->setGeometry(QRect(210, 240, 75, 23));

        retranslateUi(ResetPasswordDialog);
        QObject::connect(cancel_button, SIGNAL(clicked()), ResetPasswordDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(ResetPasswordDialog);
    } // setupUi

    void retranslateUi(QDialog *ResetPasswordDialog)
    {
        ResetPasswordDialog->setWindowTitle(QApplication::translate("ResetPasswordDialog", "Dialog", nullptr));
        reset_label->setText(QApplication::translate("ResetPasswordDialog", "Reset your password", nullptr));
        again_lineedit->setPlaceholderText(QApplication::translate("ResetPasswordDialog", "Enter your new password again", nullptr));
        reset_button->setText(QApplication::translate("ResetPasswordDialog", "Reset", nullptr));
        error_match_label->setText(QApplication::translate("ResetPasswordDialog", "error match", nullptr));
        newpassword_lineedit->setPlaceholderText(QApplication::translate("ResetPasswordDialog", "Enter your new password", nullptr));
        oldpasswrod_lineedit->setPlaceholderText(QApplication::translate("ResetPasswordDialog", "Enter your old password", nullptr));
        cancel_button->setText(QApplication::translate("ResetPasswordDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResetPasswordDialog: public Ui_ResetPasswordDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESETPASSWORDDIALOG_H
