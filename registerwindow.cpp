//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�registerwindow.cpp
// ��ǰ�汾��1.0
// ժҪ�����ļ���ʵ��ע�ᴰ�����Ա�����Ķ���
// ���ߣ�������
// ������ڣ�2018.7.27
//****************************************************************************

#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "hotelapplicationstep.h"
#include <QMessageBox>

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

extern Platform platform;

RegisterWindow::RegisterWindow(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::RegisterWindow) {
  ui->setupUi(this);

  // ɾ�����ڵ��ʺ�
  setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);

  ui->not_label->hide();
  ui->apply_button->hide();
  ui->error_label->hide();

  //����tab �л�˳��
  setTabOrder(ui->username_lineedit, ui->password_lineedit);
  setTabOrder(ui->password_lineedit, ui->check_lineedit);
  setTabOrder(ui->check_lineedit, ui->belong_lineedit);
  ui->username_lineedit->setFocus();
}

RegisterWindow::~RegisterWindow() {
  delete ui;
}

void RegisterWindow::on_cancel_button_clicked() {
  QDialog::close();
}

// �����û����͵Ĳ�ͬ��д��ͬ����Ϣ
void RegisterWindow::on_user_type_combobox_currentIndexChanged(int index) {
  switch (index) {
  case 0: {
    ui->belong_lineedit->setPlaceholderText(tr("\0"));
    ui->belong_lineedit->setEnabled(false);
    ui->not_label->hide();
    ui->apply_button->hide();
  }
          break;
  case 1: {
    ui->not_label->show();
    ui->apply_button->show();
    ui->belong_lineedit->setEnabled(true);
    ui->belong_lineedit->setPlaceholderText(tr("your hotel"));
    break;
  }
  case 2: {
    ui->not_label->hide();
    ui->apply_button->hide();
    ui->belong_lineedit->setEnabled(true);
    ui->belong_lineedit->setPlaceholderText(tr("your platform"));
  }
  default:
    break;
  }
  ui->user_type_label->hide();
}

// ע��
// �����˶�������Ϣ�����ԵĲ���
void RegisterWindow::on_register_button_clicked() {
  // REMARK: if the type combox change, remeber change this enum
  enum UserType {
    CUSTOMER, HOTELMANAGER, PLATFORMADMINISTRATOR
  };
  if ((ui->username_lineedit->text().isEmpty()) ||
    (ui->password_lineedit->text().isEmpty()) ||
    (ui->check_lineedit->text().isEmpty()) ||
    (ui->user_type_combobox->currentIndex() == -1) ||
    ((ui->belong_lineedit->isEnabled()) &&
    (ui->belong_lineedit->text().isEmpty()))) {
    ui->error_label->setText(tr("please complete the information"));
    ui->error_label->show();
    return;
  }

  if (ui->password_lineedit->text() != ui->check_lineedit->text()) {
    ui->error_label->setText(tr("error match for the two password"));
    return;
  }

  UserType user_type = static_cast<UserType>(ui->user_type_combobox->
    currentIndex());
  switch (user_type) {
  case CUSTOMER: {
    Customer* new_customer = new Customer(
      ui->username_lineedit->text().toStdString(),
      ui->password_lineedit->text().toStdString());
    platform.UserRegister(new_customer, Platform::CUSTOMER);
    break;
  }
  case HOTELMANAGER: {
    string hotel_name = ui->belong_lineedit->text().toStdString();
    vector<Hotel*>::iterator find_name = platform.GetHotelList().begin();
    bool isfind = false;
    for (; find_name != platform.GetHotelList().end(); ++find_name) {
      if ((*find_name)->GetName() == hotel_name) {
        isfind = true;
        break;
      }
    }
    if (!isfind) {
      ui->error_label->setText(tr("there isn't this hotel"));
      ui->error_label->show();
      return;
    }

    HotelManager* new_hotel_manager = new HotelManager(
      ui->username_lineedit->text().toStdString(),
      ui->password_lineedit->text().toStdString(),
      **find_name);
    platform.UserRegister(new_hotel_manager, Platform::HOTELMANAGER);
  }
  case PLATFORMADMINISTRATOR: {
    PlatformAdministrator* new_platformadministrator = new PlatformAdministrator(
      ui->username_lineedit->text().toStdString(),
      ui->password_lineedit->text().toStdString(),
      platform);
    platform.UserRegister(new_platformadministrator, Platform::PLATFORMADMINISTRATOR);
    break;
  }
  }
  close();
  QMessageBox::information(this, tr("succeed"), tr("Register succeed!"));
}

// ��ת���Ƶ�����
void RegisterWindow::on_apply_button_clicked() {
  HotelApplicationStep* apply = new HotelApplicationStep(this);
  apply->show();
}
