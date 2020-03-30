//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�mainwindow.cpp
// ��ǰ�汾��1.0
// ժҪ�����ļ���ʵ�ֳ���������ĳ�Ա������ʵ��
// ���ߣ�������
// ������ڣ�2018.7.30
//****************************************************************************

#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customertab.h"

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

#include "btripdatabase.h"
extern Platform platform;

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);
  customer_tab_ = NULL;
  hotel_manager_tab_ = NULL;
  administrator_tab_ = NULL;
  setCentralWidget(ui->picture);
  InitializeWindow();

}

// ��������ʱ�رճ������ݿ�
MainWindow::~MainWindow() {
  BtripDatabase btrip_database(&platform, "btrip.db");
  btrip_database.CreateConnect();
  QMessageBox::StandardButton answer = QMessageBox::question(NULL, "Update database",
                                "Do you want to update those change to database?",
                           QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
  if(answer == QMessageBox::Yes) {
    btrip_database.UpdataDatabase();
  }
  delete ui;
}

void MainWindow::ShowTabForUser(AbstractUser* user_pointer) {
// ͨ��dynamic_cast��ת������ж��û����ͣ���Ϊ����ʾ��Ӧ�Ľ���
  Customer* customer = dynamic_cast<Customer*>(user_pointer);
  HotelManager* hotel_manager = dynamic_cast<HotelManager*>(user_pointer);
  PlatformAdministrator* platform_administrator =
                           dynamic_cast<PlatformAdministrator*>(user_pointer);

  if (customer != NULL) {
    customer_tab_ = new CustomerTab(customer, this);
    setCentralWidget(customer_tab_);
  }
  if (hotel_manager != NULL) {
    hotel_manager_tab_ = new HotelManaerTab(hotel_manager, this);
    setCentralWidget(hotel_manager_tab_);
  }
  if (platform_administrator != NULL) {
    administrator_tab_ = new AdministratorTab(platform_administrator, this);
    setCentralWidget(administrator_tab_);
  }

//�����˻�������²˵�����ʽ�͹���
  ui->menuBar->clear();
  QMenu* account_menu = new QMenu(QString::fromStdString(user_pointer->GetUsername()),
                                     ui->menuBar);
  ui->menuBar->addMenu(account_menu);
  QAction* exit_action = new QAction(tr("exit"), account_menu);
  connect(exit_action, &QAction::triggered,
          this, &MainWindow::InitializeWindow);
  account_menu->addAction(exit_action);

  if(!user_pointer->IsActived()) {
    QAction* block_action = new QAction(tr("blocked"), account_menu);
    account_menu->addAction(block_action);
  }
}

void MainWindow::InitializeWindow() {
  if (centralWidget() != ui->picture) {
    takeCentralWidget();
  }
  ui->menuBar->clear();

 // ����һ�����ҵĲ˵�account ��Ӷ��� Login Register
  QMenu* account_menu = new QMenu(tr("account"), ui->menuBar);
  ui->menuBar->addMenu(account_menu);
  QAction* login_action = new QAction(tr("Login"), account_menu);
  login_window_ = new LoginWindow(this);
  connect(login_action, &QAction::triggered,
          login_window_, &QDialog::show);
  account_menu->addAction(login_action);
  QAction* register_action = new QAction(tr("Register"), account_menu);
  register_window_ = new RegisterWindow(this);
  connect(register_action, &QAction::triggered,
          register_window_, &QDialog::show);
  account_menu->addAction(register_action);

// ��¼���ں�������֮�����ô����û�ָ����źŲ�
  connect(login_window_, &LoginWindow::SendUserPointer,
          this, &MainWindow::ShowTabForUser);
}

