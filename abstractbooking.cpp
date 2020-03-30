//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：abstractbooking.cpp
// 当前版本：1.0
// 摘要：本文件主要实定义了对应头文件中Abstracting类的成员函数。
// 作者：吴文绪
// 完成日期：2018.7.26
//****************************************************************************

#include "abstractbooking.h"

// AbstractBooking类的构造函数，输入创建日期、单价、数量、顾客平台商家三位的常引用。
// 这些用于初始化其对应的数据成员。并且将被支付、检查、接受、完成的状态置false。流水号在，
// 支付之前由于不与平台产生联系，置为0。本函数不会将任何参数释放
AbstractBooking::AbstractBooking(const QDate& created_date, 
                                 unsigned int unit_price,
                                 unsigned int amount,
                                 const Customer& customer,
                                 const Platform& platform,
                                 const Business& business)
  : created_date_(created_date),
    unit_price_(unit_price),
    amount_(amount),
    is_payed_(false),
    is_fininshed_(false),
    is_checked_by_platform_(false), 
    is_accepted_by_business_(false),
    customer_(customer),
    platform_(platform),
    business_(business) {
  serial_number_ = 0;
  share_percent_ = 0;
}

/*virtual*/ AbstractBooking::~AbstractBooking() {}

//*******AbstractBooking类数据成员的取值函数,缺少对平台引用的取值函数*************
unsigned long int AbstractBooking::GetSerialNumber() const {
  return serial_number_;
}

const QDate& AbstractBooking::GetCreatedDate() const {
  return created_date_;
}


unsigned int AbstractBooking::GetUnitPrice() const {
  return unit_price_;
}

unsigned int AbstractBooking::GetAmount() const {
  return amount_;
}

unsigned int AbstractBooking::GetSharePercent() const {
  return share_percent_;
}

bool AbstractBooking::IsCheckedByPlatform() const {
  return is_checked_by_platform_;
}

bool AbstractBooking::IsPayed() const {
  return is_payed_;
}

bool AbstractBooking::IsAcceptedByBusiness() const {
  return is_accepted_by_business_;
}

bool AbstractBooking::IsFinished() const {
  return is_fininshed_;
}

const Customer& AbstractBooking::GetCustomer() const {
  return customer_;
}

const Business& AbstractBooking::GetBusiness() const {
  return business_;
}

//****************************************************************************

// 设值函数
// 设置流水号，供订单传递至平台端时由平台端调用。
void AbstractBooking::SetSerialNumber(unsigned long int serial_number) {
  serial_number_ = serial_number;
}

// 设置抽成，供平台端的业务员（也即PlatformAdministrator类调用）
void AbstractBooking::SetSharePercnet(unsigned int share_percent) {
  share_percent_ = share_percent;
}

// 订单支付，输入金额，返回订单的支付情况。由公有枚举型PaySituation定义依次为已经支付，
// 金额不足，支付成功三种信息。
AbstractBooking::PaySituation AbstractBooking::BePayed(unsigned int money) {
  if (IsPayed()) {
    return HAVEPAYED;
  }
  if (money < unit_price_ * amount_) {
    return NOTENOUGH;
  } else {
    is_payed_ = true;
    return SUCCESS;
  }
}

// 将订单被检查的状态设置为是，供平台端业务员调用。
void AbstractBooking::BeChecked() {
  is_checked_by_platform_ = true;
}

// 讲订单被接受的状态设置为是，供商家端业务员调用
void AbstractBooking::BeFinished() {
  is_fininshed_ = true;
}

// 讲订单被接受的状态设置为是，供商家端业务员调用
void AbstractBooking::BeAccepted() {
  is_accepted_by_business_ = true;
}
