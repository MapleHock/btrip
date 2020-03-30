//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�loginwindow.h
// ��ǰ�汾��1.0
// ժҪ�����ļ���ʵ���û���¼����LoginWindow��Ķ��壬�������û���¼
// ���ߣ�������
// ������ڣ�2018.7.28
//****************************************************************************

#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include "abstractuser.h"

namespace Ui {
class LoginWindow;
}
// LoginWinow�������û���¼�����ҽ��ɹ���¼���û���Ϣ���źŵ���ʽ��������
class LoginWindow : public QDialog {
  Q_OBJECT

public:
  explicit LoginWindow(QWidget *parent = 0);
  ~LoginWindow();

signals:
  void SendUserPointer(AbstractUser* user_ptr);

private slots:

// ��ת��ע�����
  void on_register_button_clicked();

// ����˻��Ƿ��ܵ�¼
// ��¼�ɹ�ʱ�ᷢ���û�ָ���ź�
  void on_login_button_clicked();

private:
  Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
