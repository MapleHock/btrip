//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：loginwindow.h
// 当前版本：1.0
// 摘要：本文件中实现用户登录界面LoginWindow类的定义，它用于用户登录
// 作者：吴文绪
// 完成日期：2018.7.28
//****************************************************************************

#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include "abstractuser.h"

namespace Ui {
class LoginWindow;
}
// LoginWinow类用于用户登录，并且将成功登录的用户信息以信号的形式至主窗口
class LoginWindow : public QDialog {
  Q_OBJECT

public:
  explicit LoginWindow(QWidget *parent = 0);
  ~LoginWindow();

signals:
  void SendUserPointer(AbstractUser* user_ptr);

private slots:

// 跳转到注册界面
  void on_register_button_clicked();

// 检测账户是否能登录
// 登录成功时会发送用户指针信号
  void on_login_button_clicked();

private:
  Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
