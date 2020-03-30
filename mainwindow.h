//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�mainwindow.h
// ��ǰ�汾��1.0
// ժҪ�����ļ���ʵ�ֳ�����������ඨ��
// ���ߣ�������
// ������ڣ�2018.7.30
//****************************************************************************

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "loginwindow.h"
#include "registerwindow.h"
#include "customertab.h"
#include "hotelmanaertab.h"
#include "administratortab.h"

class AbstractUser;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private:
  Ui::MainWindow *ui;
  LoginWindow* login_window_;
  RegisterWindow* register_window_;
  CustomerTab* customer_tab_;
  HotelManaerTab* hotel_manager_tab_;
  AdministratorTab* administrator_tab_;

public slots:

// �����û�ָ�룬Ϊ����ʾ���Ӧ�Ľ���
  void ShowTabForUser(AbstractUser* user_pointer);
private slots:

// �жϵ�¼������Ϊ��ͬ�εĵ�¼ִ�в�ͬ�ĳ�ʼ��
  void InitializeWindow();
};

#endif // MAINWINDOW_H
