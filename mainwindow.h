//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：mainwindow.h
// 当前版本：1.0
// 摘要：本文件中实现程序主界面的类定义
// 作者：吴文绪
// 完成日期：2018.7.30
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

// 输入用户指针，为其显示其对应的界面
  void ShowTabForUser(AbstractUser* user_pointer);
private slots:

// 判断登录次数，为不同次的登录执行不同的初始化
  void InitializeWindow();
};

#endif // MAINWINDOW_H
