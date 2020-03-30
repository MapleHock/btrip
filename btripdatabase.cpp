//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�btripdatabase.h
// ��ǰ�汾��1.0
// ժҪ�����ļ���ʵ�ֶ�BtripDatabase�ĳ�Ա�����Ķ��塣
//      ������Ҫ���ڷ�װ��������������Ҫ���ϴ��������ݵĲ�����
//      ����Ҫ�������ϴ����أ���Ҫͨ�����ڴ�/���ݿ��Ա�ı���ʵ�֡�
// ���ߣ�������
// ������ڣ�2018.7
//****************************************************************************

#include "btripdatabase.h"

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

#include<QSqlQuery>
#include<QVariantList>
#include<QDebug>
#include<QSqlError>

// BtripDatabase���캯���������ƽָ̨��Ͷ�Ӧ�ļ��������ݿ����һ��ʵ���У�
// �Ա�ʵ���ϴ�����
// ���������������ָ�롣
BtripDatabase::BtripDatabase(Platform* platform,
             const QString& database_name)
  : platform_(platform), database_name_(database_name) {}

BtripDatabase::~BtripDatabase() {}

// �������ݿ����ӣ������ɹ�����true
bool BtripDatabase::CreateConnect() {
  database_ = QSqlDatabase::addDatabase("QSQLITE");
  database_.setDatabaseName(database_name_);
  return (database_.open());
}

// �����ݿ������ϴ����ڴ棬ȫ�������ϴ��ɹ�����true
// ���ݳ���Ľṹ�����ϴ�˳��Ϊ��customer���ݣ�administrator���ݣ�hotel���ݣ�
// hotelmanger���ݣ�room���ݣ� booking���ݣ�JoinApplication����
// ǰ���ߵ��������ݿ��Ե��������ߵ������У�����credit_codeΪHotel���������������ر�
// �������˳�򲻿ɵ���
// �����е�����Platform�����س�Ա��������Щ������Ҫ��˼·�����õ�������Hotellist����
// ����������������ݽ�����������
// ��������������Ҫ�ɵ������ͷŵĿռ�
bool BtripDatabase::Upload() {
QSqlQuery query;

//************customer��������**************************************************

    if (!query.exec("select * from customer")) {
      return false;
    }
    while (query.next()) {
      Customer* new_one = new Customer(query.value("username").toString().toStdString(),
                                   query.value("password").toString().toStdString());
      platform_->GetCustomerList().push_back(new_one);
    }
//***************administrator��������******************************************

  if (!query.exec("select * from administrator")) {
    return false;
  }
  while (query.next()) {
    PlatformAdministrator* new_one = new PlatformAdministrator(
                             query.value("username").toString().toStdString(),
                             query.value("password").toString().toStdString(),
                             *platform_);
    platform_->GetPlatformAdministratorList().push_back(new_one);
  }

//**************hotel��������***************************************************

  if (!query.exec("select * from hotel")) {
    return false;
  }
  while (query.next()) {
    Hotel* new_one = new Hotel(
                        query.value("name").toString().toStdString(),
                        query.value("city").toString().toStdString(),
                        "temp",
                        query.value("credit_code").toString().toStdString());
    platform_->GetHotelList().push_back(new_one);
  }

//****************manager��������***********************************************

  if (!query.exec("select * from manager")) {
    return false;
  }
  while (query.next()) {
    platform_->InsertManager(query.value("username").toString().toStdString(),
                             query.value("password").toString().toStdString(),
                             query.value("credit_code").toString().toStdString());
  }

//***************room��������***************************************************

  if (!query.exec("select * from room")) {
    return false;
  }
  while (query.next()) {
    platform_->InsertRoom(query.value("credit_code").toString().toStdString(),
                          query.value("room_number").toString().toStdString(),
                          query.value("room_type").toString().toStdString(),
                          query.value("price").toInt(),
                          query.value("bed_type").toInt());
  }

//**********************booking��������****************************************
  if (!query.exec("select * from booking")) {
    return false;
  }
  while (query.next()) {
    platform_->InsertBooking(query.value("serial").toInt(),
                             QDate::fromString(query.value("create_date").toString()),
                             QDate::fromString(query.value("check_in").toString()),
                             QDate::fromString(query.value("check_out").toString()),
                             query.value("unit_price").toInt(),
                             query.value("share").toInt(),
                             query.value("is_payed").toBool(),
                             query.value("is_checked").toBool(),
                             query.value("is_accepted").toBool(),
                             query.value("is_finish").toBool(),
                             query.value("customer_name").toString().toStdString(),
                             query.value("hotel_code").toString().toStdString());
  }

//***************************application��������********************************
  if (!query.exec("select * from app")) {
    return false;
  }
  while (query.next()) {
    platform_->InsertApplicatioin(query.value("business_credit").toString().toStdString(),
                                  query.value("is_pass").toBool(),
                                  query.value("type").toInt(),
                                  QDate::fromString((query.value("created_date").toString())));
  }
  return true;
}

// ���ڴ������ϴ������ݿ⣬ȫ�������ϴ��ɹ�����true
// Ϊ������չ�ԣ�����������dynamic_cast���������ת�����������ݷ��࣬�����ڽ�����
// ҵ����չʱ��Դ����Ļ���������������
bool BtripDatabase::UpdataDatabase() {
  QSqlQuery query;
//*************customer�����ϴ�**********************************************

  query.exec("DELETE from customer");
  QString create_customer = "create table IF NOT EXISTS "
                             "customer (username varchar,"
                            "password varchar)";
  QString insert_customer = "insert into customer values(?,?)";
  query.prepare(create_customer);
  if (!query.exec()) {
    return false;
  }
  query.prepare(insert_customer);
  QVariantList customers_name;
  QVariantList customers_password;
  for (vector<Customer*>::iterator find_customer = platform_->GetCustomerList().begin();
       find_customer != platform_->GetCustomerList().end();
       ++find_customer) {
    customers_name.append(QString::fromStdString((*find_customer)->GetUsername()));
    customers_password.append(QString::fromStdString((*find_customer)->GetPassword()));
  }
  query.addBindValue(customers_name);
  query.addBindValue(customers_password);
  if (!query.execBatch()) {
    return false;
  }
//*****************manager�����ϴ�**********************************************
  query.exec("DELETE from manager");
  QString create_manager = "create table IF NOT EXISTS "
                           "manager (username varchar,"
                                    "password varchar,"
                                    "credit_code varchar)";
  QString insert_manager = "insert into manager values(?,?,?)";
  query.prepare(create_manager);
  if (!query.exec()) {
    return false;
  }
  query.prepare(insert_manager);
  QVariantList manager_name;
  QVariantList manager_password;
  QVariantList belong_credit_code;
  for (vector<HotelManager*>::iterator find = platform_->GetHotelManagerList().begin();
       find != platform_->GetHotelManagerList().end();
       ++find) {
    manager_name.append(QString::fromStdString((*find)->GetUsername()));
    manager_password.append(QString::fromStdString((*find)->GetPassword()));
    belong_credit_code.append(QString::fromStdString((*find)->GetHotelBelong().GetCreditCode()));
  }
  query.addBindValue(manager_name);
  query.addBindValue(manager_password);
  query.addBindValue(belong_credit_code);
  if (!query.execBatch()) {
    return false;
  }
//***********************administrator�����ϴ�*********************************
  query.exec("DELETE from administrator");
  QString create_administrator = "create table IF NOT EXISTS "
                           "administrator (username varchar,"
                                          "password varchar)";
  QString insert_administrator = "insert into administrator values(?,?)";
  query.prepare(create_administrator);
  if (!query.exec()) {
    return false;
  }
  query.prepare(insert_administrator);
  QVariantList administrator_name;
  QVariantList administrator_password;
  for (vector<PlatformAdministrator*>::iterator find = platform_->GetPlatformAdministratorList().begin();
       find != platform_->GetPlatformAdministratorList().end();
       ++find) {
    administrator_name.append(QString::fromStdString((*find)->GetUsername()));
    administrator_password.append(QString::fromStdString((*find)->GetPassword()));
  }
  query.addBindValue(administrator_name);
  query.addBindValue(administrator_password);

  if (!query.execBatch()) {
    return false;
  }
//**********************booking*�����ϴ�****************************************

  query.exec("DELETE from booking");
  QString create_booking = "create table IF NOT EXISTS "
                           "booking (serial int,"
                                     "create_date varchar,"
                                     "check_in varchar,"
                                     "check_out varchar,"
                                     "unit_price int,"
                                     "share int,"
                                     "is_payed boolen,"
                                     "is_checked boolen,"
                                     "is_accepted boolen,"
                                     "is_finish boolen,"
                                     "customer_name varchar,"
                                     "hotel_code varchar)";
  QString insert_booking = "insert into booking values(?,?,?,?,?,?,?,?,?,?,?,?)";
  query.prepare(create_booking);
  if (!query.exec()) {
    return false;
  }
  query.prepare(insert_booking);
  QVariantList serial;
  QVariantList create_date;
  QVariantList check_in;
  QVariantList check_out;
  QVariantList unit_price;
  QVariantList share;
  QVariantList is_payed;
  QVariantList is_checked;
  QVariantList is_accepted;
  QVariantList is_finsh;
  QVariantList customer_name;
  QVariantList hotel_code;
  list<AbstractBooking*> total = platform_->GetBookings();
  for (list<AbstractBooking*>::iterator find = total.begin();
       find != total.end();
       ++find) {
    HotelBooking* the = dynamic_cast<HotelBooking*>(*find);
    if (the == NULL) {
      break;
    }

    serial.append(static_cast<long long>(the->GetSerialNumber()));
    create_date.append(the->GetCreatedDate().toString());
    check_in.append(the->GetCheckInDate().toString());
    check_out.append(the->GetCheckOutDate().toString());
    unit_price.append(the->GetUnitPrice());
    share.append(the->GetSharePercent());
    is_payed.append(the->IsPayed());
    is_accepted.append(the->IsAcceptedByBusiness());
    is_checked.append(the->IsCheckedByPlatform());
    is_finsh.append(the->IsFinished());
    customer_name.append(QString::fromStdString(the->GetCustomer().GetUsername()));
    hotel_code.append(QString::fromStdString(the->GetBusiness().GetCreditCode()));
  }
  query.addBindValue(serial);
  query.addBindValue(create_date);
  query.addBindValue(check_in);
  query.addBindValue(check_out);
  query.addBindValue(unit_price);
  query.addBindValue(share);
  query.addBindValue(is_payed);
  query.addBindValue(is_checked);
  query.addBindValue(is_accepted);
  query.addBindValue(is_finsh);
  query.addBindValue(customer_name);
  query.addBindValue(hotel_code);

  if (!query.execBatch()) {
    qDebug() << query.lastError();
    return false;
  }
//*************************application�����ϴ�********************************
  query.exec("DELETE from app");
  QString create_app = "create table IF NOT EXISTS "
                           "app (business_credit varchar,"
                                "is_pass boolean,"
                                 "type int,"
                                 "created_date varchar)";
  QString insert_app = "insert into app values(?,?,?,?)";
  query.prepare(create_app);
  if (!query.exec()) {
    return false;
  }
  query.prepare(insert_app);
  QVariantList business_credit;
  QVariantList is_pass;
  QVariantList type;
  QVariantList created_date;
  list<JoinApplication*> totalapp = platform_->GetApps();
  for (list<JoinApplication*>::iterator find = totalapp.begin();
       find != totalapp.end();
       ++find) {
    business_credit.append(QString::fromStdString((*find)->GetBusinessBelong().GetCreditCode()));
    is_pass.append((*find)->GetFirstAccount()->IsActived());
    type.append(0);
    created_date.append((*find)->GetCreatedDate().toString());
  }
  query.addBindValue(business_credit);
  query.addBindValue(is_pass);
  query.addBindValue(type);
  query.addBindValue(created_date);

  if (!query.execBatch()) {
    return false;
  }

//******************hotel*�����ϴ�*********************************************

  query.exec("DELETE from hotel");
  QString create_hotel = "create table IF NOT EXISTS "
                           "hotel (credit_code varchar,"
                           "name varchar,"
                           "city varchar)";
  QString insert_hotel = "insert into hotel values(?,?,?)";
  query.prepare(create_hotel);
  if (!query.exec()) {
    return false;
  }
  query.prepare(insert_hotel);
  QVariantList credit_code;
  QVariantList name;
  QVariantList city;
  for (vector<Hotel*>::iterator find = platform_->GetHotelList().begin();
       find != platform_->GetHotelList().end();
       ++find) {
    credit_code.append(QString::fromStdString((*find)->GetCreditCode()));
    name.append(QString::fromStdString((*find)->GetName()));
    city.append(QString::fromStdString((*find)->GetCity()));
  }
  query.addBindValue(credit_code);
  query.addBindValue(name);
  query.addBindValue(city);
  if (!query.execBatch()) {
    return false;
  }

//**********************room*�����ϴ�******************************************

  query.exec("DELETE from room");
  QString create_room = "create table IF NOT EXISTS "
                           "room (credit_code varchar,"
                                 "room_number varchar,"
                                 "room_type varchar,"
                                 "price int,"
                                 "bed_type int)";
  QString insert_room = "insert into room values(?,?,?,?,?)";
  QVariantList credit;
  QVariantList room_number;
  QVariantList room_type;
  QVariantList price;
  QVariantList bed_type;
  query.prepare(create_room);
  if (!query.exec()) {
    return false;
  }
  query.prepare(insert_room);

  for (vector<Hotel*>::iterator find_hotel = platform_->GetHotelList().begin();
       find_hotel != platform_->GetHotelList().end();
       ++find_hotel) {
    for (vector<Room>::iterator find = (*find_hotel)->ManageRooms().begin();
         find != (*find_hotel)->ManageRooms().end();
         ++find) {
      credit.append(QString::fromStdString((*find_hotel)->GetCreditCode()));
      room_number.append(QString::fromStdString((*find).GetRoomNumber()));
      room_type.append(QString::fromStdString((*find).GetRoomTypeDefinedByHotel()));
      price.append(find->GetPricePerNight());
      bed_type.append(static_cast<int>(find->GetBedType()));
    }
  }
  query.addBindValue(credit);
  query.addBindValue(room_number);
  query.addBindValue(room_type);
  query.addBindValue(price);
  query.addBindValue(bed_type);

  if (!query.execBatch()) {
    return false;
  }
  return true;
}

// �رն�Ӧ���ݿ�
void BtripDatabase::CloseDatabase() {
  database_.close();
}
