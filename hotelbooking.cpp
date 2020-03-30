//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�hotelbooking.cpp
// ��ǰ�汾��1.0
// ժҪ�����ļ���ʵ��HotelBooking��ĳ�Ա����
// ���ߣ�������
// ������ڣ�2018.7.28
//****************************************************************************

#include "hotelbooking.h"
#include "hotel.h"

// ���캯�������մ�����Ϣ���충����
// ���л���AbstractBooking�е����ݳ�Ա���� unit_price����ʼ��Ϊÿ������*��ʱ��
// amountΪ�����ķ�����
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

//****************ȡֵ����*****************************************************
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

//***************��ֵ����*****************************************************

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
