//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：registerwindow.h
// 当前版本：1.0
// 摘要：本文件中实现注册窗口类的定义
// 作者：吴文绪
// 完成日期：2018.7
//****************************************************************************

#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QDialog>

namespace Ui {
class RegisterWindow;
}

// 继承QDialog编写的登入界面
class RegisterWindow : public QDialog {
  Q_OBJECT

public:
  explicit RegisterWindow(QWidget *parent = 0);
  ~RegisterWindow();

private slots:
// 撤销退出注册窗口
  void on_cancel_button_clicked();

// 表示用户注册类型
  void on_user_type_combobox_currentIndexChanged(int index);

// 注册
  void on_register_button_clicked();

// 跳转到酒店申请
  void on_apply_button_clicked();

private:
  Ui::RegisterWindow *ui;
};

#endif // REGISTERWINDOW_H
