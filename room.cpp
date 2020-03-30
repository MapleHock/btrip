//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�room.cpp
// ��ǰ�汾��1.0
// ժҪ�����ļ���ʵ��Room��ĳ�Ա������ʵ��
// ���ߣ�������
// ������ڣ�2018.7.27
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

//**************************ȡֵ����*******************************************
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

//********************************��ֵ����*************************************
void Room::ResetRoomNumber(const string& new_room_number) {
  room_number_ = new_room_number;
}

void Room::ResetPricePernight(unsigned int new_price_pernight) {
  price_pernight_ = new_price_pernight;
}

// ��ͼ������������������ύ���룬���ԤԼ�ɹ�����true
// �õ�����������ԤԼ�������б�����������е����ڶ������ʱ���֮�⣬��ԤԼ�ɹ�
// ����Щ������ӽ�ȥ
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

// ȡ���������ڵ�ԤԼ���ɹ�����true
// �õ�����������ԤԼ�������б�����������������������ɾ������true
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
