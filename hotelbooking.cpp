//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：hotelbooking.cpp
// 当前版本：1.0
// 摘要：本文件中实现HotelBooking类的成员函数
// 作者：吴文绪
// 完成日期：2018.7.28
//****************************************************************************

#include "hotelbooking.h"
#include "hotel.h"

// 构造函数，按照传入信息构造订单，
// 其中基类AbstractBooking中的数据成员单价 unit_price被初始化为每晚消费*总时长
// amount为订购的房间数
HotelBooking::HotelBooking(const QDate& created_date,
                           unsigned int price_pernight_perroom,
                           unsigned int amount,
                           const Customer& customer,
                           const Platform& platform,
                           const Hotel& hotel,
                           const QDate& check_in_date,
                           const QDate& check_out_date)
  : AbstractBooking(created_date,
    price_pernight_perroom * check_in_date.daysTo(check_out_date),
    amount, customer, platform, hotel),
  check_in_date_(check_in_date), check_out_date_(check_out_date), review_(-1) {
  hotel_name_ = hotel.GetName();
}

HotelBooking::~HotelBooking() {}

//****************取值函数*****************************************************
const string& HotelBooking::GetHotelName() const {
  return hotel_name_;
}

const string& HotelBooking::GetRoomType() const {
  return room_type_;
}

const QDate& HotelBooking::GetCheckInDate() const {
  return check_in_date_;
}

const QDate& HotelBooking::GetCheckOutDate() const {
  return check_out_date_;
}

unsigned int HotelBooking::GetPricePerNightPerRoom() const {
  return GetUnitPrice() / check_in_date_.daysTo(check_out_date_);
}

int HotelBooking::GetRiew() const {
  return review_;
}

//****************************************************************************

//***************设值函数*****************************************************

void HotelBooking::SetRoomType(const string& room_type) {
  room_type_ = room_type;
}

void HotelBooking::SetRoomNumber(const string& room_number) {
  room_number_ = room_number;
}

void HotelBooking::SetRiew(int review) {
  review_ = review;
}
//*****************************************************************************
