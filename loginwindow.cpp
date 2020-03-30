//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�loginwindow.cpp
// ��ǰ�汾��1.0
// ժҪ�����ļ���ʵ���û���¼����LoginWindow��ĳ�Ա����
// ���ߣ�������
// ������ڣ�2018.7.28
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

  // �Ƴ��ʺ�
  setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);

  ui->error_label->hide();

  setTabOrder(ui->username_lineedit,ui->password_lineedit);
  ui->username_lineedit->setFocus();

}

LoginWindow::~LoginWindow()
{
  delete ui;
}

// ��ת��ע�ᴰ��
void LoginWindow::on_register_button_clicked()
{
  RegisterWindow* register_window = new RegisterWindow(this);
  register_window->show();
}

// �û���¼
// ͨ���û����͵�ѡ���ڲ�ͬ���û��б����õ����������û����ҷ����Ƿ�ɹ�����Ϣ
// ������Ϣ����ʾ��label��
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

 // ͨ���û����͵�ѡ���ڲ�ͬ���û��б����õ����������û����ҷ����Ƿ�ɹ�����Ϣ
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
