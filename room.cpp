//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：room.cpp
// 当前版本：1.0
// 摘要：本文件中实现Room类的成员函数的实现
// 作者：吴文绪
// 完成日期：2018.7.27
//****************************************************************************

#include "room.h"

#include <sstream>
using std::stringstream;

Room::Room(string room_type_defined_by_hotel, string room_number, 
           unsigned int size, int floor_number, BedType bed_type, 
           bool is_with_window, bool is_with_bathroom, bool is_able_to_add_bed,
           unsigned int price_pernight)
  : room_type_defined_by_hotel_(room_type_defined_by_hotel),
    room_number_(room_number), size_(size), floor_number_(floor_number),
    bed_type_(bed_type), is_with_window_(is_with_window),
    is_with_bathroom_(is_with_bathroom),
    is_able_to_add_bed_(is_able_to_add_bed), 
    price_pernight_(price_pernight) {}

Room::Room(string room_type_defined_by_hotel, unsigned int size, 
           int floor_number, BedType bed_type, bool is_with_window,
           bool is_with_bathroom, bool is_able_to_add_bed, 
           unsigned int price_pernight)
  : room_type_defined_by_hotel_(room_type_defined_by_hotel),
    size_(size), floor_number_(floor_number),
    bed_type_(bed_type), is_with_window_(is_with_window),
    is_with_bathroom_(is_with_bathroom),
    is_able_to_add_bed_(is_able_to_add_bed),
    price_pernight_(price_pernight) {
  stringstream auto_room_number;
  auto_room_number << floor_number_;
  room_number_ =  auto_room_number.str();
}

bool Room::operator== (const string& room_number_read) {
  return room_number_ == room_number_read;
}

Room::~Room() {}

//**************************取值函数*******************************************
const string& Room::GetRoomTypeDefinedByHotel() const {
  return room_type_defined_by_hotel_;
}

const string& Room::GetRoomNumber() const {
  return room_number_;
}

unsigned int Room::GetSize() const {
  return size_;
}

int Room::GetFloorNumber() const {
  return floor_number_;
}

Room::BedType Room::GetBedType() const {
  return bed_type_;
}

bool Room::IsWithWindow() const {
  return is_with_window_;
}

bool Room::IsWithBathRoom() const {
  return is_with_bathroom_;
}

bool Room::IsAbleToAddBed() const {
  return is_able_to_add_bed_;
}

unsigned int Room::GetPricePerNight() const {
  return price_pernight_;
}

const list<QDate>& Room::GetBookingDates() const {
  return booking_dates_;
}
//****************************************************************************

//********************************设值函数*************************************
void Room::ResetRoomNumber(const string& new_room_number) {
  room_number_ = new_room_number;
}

void Room::ResetPricePernight(unsigned int new_price_pernight) {
  price_pernight_ = new_price_pernight;
}

// 试图在输入的两个日期内提交申请，如果预约成功返回true
// 用迭代器在已有预约的日期中遍历，如果所有的日期都在这个时间段之外，则预约成功
// 把这些日期添加进去
bool Room::BeBooked(const QDate& check_in_date, const QDate& check_out_date) {
  list<QDate>::iterator find_date = booking_dates_.begin();
  for (; find_date != booking_dates_.end(); ++find_date) {
    if (*find_date >= check_in_date && *find_date < check_out_date) {
      return false;
    }
  }
  for (int i = 0; check_in_date.addDays(i) < check_out_date; i++) {
    booking_dates_.push_back(check_in_date.addDays(i));
  }
  return true;
}

// 取消输入日期的预约，成功返回true
// 用迭代器在已有预约的日期中遍历，如果存在这个日期则将他删除返回true
bool Room::CancelABookingDate(const QDate& date) {
  list<QDate>::iterator find_date = booking_dates_.begin();
  for (; find_date != booking_dates_.end(); ++find_date) {
    if (*find_date == date) {
      booking_dates_.erase(find_date);
      return true;
    }
  }
  return false;
}
