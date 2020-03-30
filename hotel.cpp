//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�hotel.cpp
// ��ǰ�汾��1.0
// ժҪ�����ļ���ʵ��Hotel��ĳ�Ա������
// ���ߣ�������
// ������ڣ�2018.7.28
//****************************************************************************

#include "hotel.h"

// ���캯�����ô������ݶ�Ӧ��ʼ��������ʼ������Ϊ3
Hotel::Hotel(const string& name, const string& city, const string& area,
             string credit_code)
  : Business(credit_code),
    name_(name), city_(city), area_(area) {
  rooms_.clear();
  review_ = 3;
}

Hotel::~Hotel() {}

//**********************ȡֵ����***********************************************
const string& Hotel::GetName() const {
  return name_;
}

const string& Hotel::GetCity() const {
  return city_;
}

const string& Hotel::GetArea() const {
  return area_;
}

HotelPolicies& Hotel::GetHotelPolicies() {
  return hotel_policies_;
}

Amenities& Hotel::GetAmenities(){
  return amenities_;
}

unsigned int Hotel::GetReview() const {
  return review_;
}
//**************************************************************************

//******************��ֵ����**************************************************
void Hotel::RefreshReview(unsigned int new_review) {
  review_ += new_review;
  review_ /= 2;
}

void Hotel::ResetReview(unsigned int review) {
  review_ = review;
}

void Hotel::ResetName(const string& new_name) {
  name_ = new_name;
}

//**************************************************************************

// ���ط�����������������
// �Ա��ڷ��ʵ�����һ�䷿����Ϊ����Ĺ���ʽ
vector<Room>& Hotel::ManageRooms() {
  return rooms_;
}

// ���ӷ��䣬�ṩ��һ�ֹ���ӿ�
void Hotel::AddOneRoom(const Room& room_model) {
    rooms_.push_back(room_model);
}

// ���ط������������ĳ�����
// �Ա��ڷ��ʵ�����һ�䷿����������������Ϊ���������׼����ʽ
const vector<Room>& Hotel::PrepareSearch() const {
  return rooms_;
}

// �õ���ۣ��ṩ��һ�ֲ�ѯ�ӿ�
// �õ�������rooms�����õ���С��Ǯ
int Hotel::GetStartingPrice() const {
  if (rooms_.size() == 0) {
    return -1;
  } else {
    unsigned int min_price = rooms_[0].GetPricePerNight();
    for (unsigned int i = 1; i < rooms_.size(); i++) {
      if (min_price > rooms_[i].GetPricePerNight()) {
        min_price = rooms_[i].GetPricePerNight();
      }
    }
    return min_price;
  }
}

// �õ��ڸ��������ڿ��õķ��������ṩ��һ�ֲ�ѯ�ӿ�
// �õ�������rooms����������ϼ������õ��ɹ�ʹ�õķ�����������
unsigned int Hotel::RoomsAvailabel(const QDate& check_in_date, 
                                   const QDate& check_out_date) const {
  unsigned int count = 0;
  for (unsigned int i = 0; i < PrepareSearch().size(); i++) {
    bool is_conflict = false;
    for (list<QDate>::const_iterator find_date = 
            PrepareSearch()[i].GetBookingDates().begin();
         find_date != PrepareSearch()[i].GetBookingDates().end();
         ++find_date) {
      if (*find_date >= check_in_date && *find_date < check_out_date) {
        is_conflict = true;
        break;
      }
    }
    if (!is_conflict) {
      count++;
    }
  }
  return count;
}

// �õ��ڸ��������ڿ��õĸ������͵ķ��������ṩ��һ�ֲ�ѯ�ӿ�
// �õ�������rooms����������ϼ������õ��ɹ�ʹ�õķ�����������
unsigned int Hotel::RoomsAvailabel(const QDate& check_in_date,
  const QDate& check_out_date,
  const string& room_type,
  string* room_number /*=NULL*/) const {
  unsigned int count = 0;
  for (unsigned int i = 0; i < PrepareSearch().size(); i++) {
    if (rooms_[i].GetRoomTypeDefinedByHotel() != room_type) {
      continue;
    }
    bool is_conflict = false;
    for (list<QDate>::const_iterator find_date =
      PrepareSearch()[i].GetBookingDates().begin();
      find_date != PrepareSearch()[i].GetBookingDates().end();
      ++find_date) {
      if (*find_date >= check_in_date && *find_date < check_out_date) {
        is_conflict = true;
        break;
      }
    }
    if (!is_conflict) {
      count++;
    }
    if (room_number != NULL && count == 1) {
      *room_number = rooms_[i].GetRoomNumber();
    }
  }
  return count;
}

// �õ���ۣ��ṩ��һ�ֲ�ѯ�ӿ�
// �õ�������rooms�����õ����������ķ������С��Ǯ
// ��û�и������͵ķ��䷵��-1��Ϊ�쳣ֵ
int Hotel::GetStartingPrice(Room::BedType bed_type) const {
  if (rooms_.size() == 0) {
    return -1;
  } else {
    unsigned int i = 0;
    for (; i < rooms_.size(); i++) {
      if (rooms_[i].GetBedType() == bed_type) {
        break;
      }
    }
    unsigned int min_price;
    if (i < rooms_.size()) {
      min_price = rooms_[i].GetPricePerNight();
    } else {
      return -1;
    }
    for (; i < rooms_.size(); i++) {
      if (rooms_[i].GetBedType() == bed_type &&
        min_price > rooms_[i].GetPricePerNight()) {
        min_price = rooms_[i].GetPricePerNight();
      }
    }
    return min_price;
  }
}

// �õ���ۣ��ṩ��һ�ֲ�ѯ�ӿ�
// �õ�������rooms�����õ����������ķ������С��Ǯ
// ��û�и������͵ķ��䷵��-1��Ϊ�쳣ֵ
int Hotel::GetPriceForAType(const string& room_type) const {
  unsigned int i = 0;
  for (; i < rooms_.size(); i++) {
    if (rooms_[i].GetRoomTypeDefinedByHotel() == room_type) {
      break;
    }
  }
  if (i < rooms_.size()) {
    return rooms_[i].GetPricePerNight();
  } else {
    return -1;
  }
}
