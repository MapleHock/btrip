//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：loginwindow.cpp
// 当前版本：1.0
// 摘要：本文件中实现用户登录界面LoginWindow类的成员函数
// 作者：吴文绪
// 完成日期：2018.7.28
//****************************************************************************

#include "loginwindow.h"
#include "ui_loginwindow.h"

#include "registerwindow.h"

#include "abstractbooking.h"
#include "abstractuser.h"
#include "amenities.h"
#include "business.h"
#include "customer.h"
#include "hotel.h"
#include "hotelbooking.h"
#include "hotelmanager.h"
#include "hotelpolicies.h"
#include "joinapplication.h"
#include "license.h"
#include "platform.h"
#include "platformadministrator.h"
#include "room.h"

#include <QFile>

extern Platform platform;

LoginWindow::LoginWindow(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::LoginWindow)
{
  ui->setupUi(this);

  // 移除问号
  setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);

  ui->error_label->hide();

  setTabOrder(ui->username_lineedit,ui->password_lineedit);
  ui->username_lineedit->setFocus();

}

LoginWindow::~LoginWindow()
{
  delete ui;
}

// 跳转到注册窗口
void LoginWindow::on_register_button_clicked()
{
  RegisterWindow* register_window = new RegisterWindow(this);
  register_window->show();
}

// 用户登录
// 通过用户类型的选择在不同的用户列表中用迭代器遍历用户并且返回是否成功的信息
// 错误信息会显示在label上
void LoginWindow::on_login_button_clicked()
{
  if (ui->username_lineedit->text().isEmpty() ||
      ui->password_lineedit->text().isEmpty()) {
    ui->error_label->setText(tr("please complete the information"));
    ui->error_label->show();
  }

  enum UserType {CUSTOMER, HOTELMANAGER, PLATFORMADMINISTRATOR};
  UserType usertype;
  if (ui->customer_button->isChecked()) {
    usertype = CUSTOMER;
  }
  if (ui->hotelmanager_button->isChecked()) {
    usertype = HOTELMANAGER;
  }
  if (ui->administrator_button->isChecked()) {
    usertype = PLATFORMADMINISTRATOR;
  }

 // 通过用户类型的选择在不同的用户列表中用迭代器遍历用户并且返回是否成功的信息
  bool is_successful = false;
  AbstractUser* user_pointer = NULL;
  if (usertype == CUSTOMER) {
    vector<Customer*>::iterator find_user = platform.GetCustomerList().begin();
    for (; find_user != platform.GetCustomerList().end(); ++find_user) {
      if (ui->username_lineedit->text().toStdString() == (**find_user).GetUsername()) {
        is_successful =
        (**find_user).CheckPassword(ui->password_lineedit->text().toStdString());
        user_pointer = *find_user;
        break;
      }
    }
  }
  if (usertype == HOTELMANAGER) {
    vector<HotelManager*>::iterator find_user = platform.GetHotelManagerList().begin();
    for (; find_user != platform.GetHotelManagerList().end(); ++find_user) {
      if (ui->username_lineedit->text().toStdString() == (**find_user).GetUsername()) {
        is_successful =
        (**find_user).CheckPassword(ui->password_lineedit->text().toStdString());
        user_pointer = *find_user;
        break;
      }
    }
  }
  if (usertype == PLATFORMADMINISTRATOR) {
    vector<PlatformAdministrator*>::iterator find_user =
                            platform.GetPlatformAdministratorList().begin();
    for (; find_user != platform.GetPlatformAdministratorList().end(); ++find_user) {
      if (ui->username_lineedit->text().toStdString() == (**find_user).GetUsername()) {
        is_successful =
        (**find_user).CheckPassword(ui->password_lineedit->text().toStdString());
        user_pointer = *find_user;
        break;
      }
    }
  }
  if (!is_successful) {
    ui->error_label->setText(tr("password mismatch!"));
    ui->error_label->show();
  } else {
    emit SendUserPointer(user_pointer);
    close();
  }
}
