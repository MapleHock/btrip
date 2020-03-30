//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：hotel.cpp
// 当前版本：1.0
// 摘要：本文件中实现Hotel类的成员函数。
// 作者：吴文绪
// 完成日期：2018.7.28
//****************************************************************************

#include "hotel.h"

// 构造函数，用传入数据对应初始化，将初始评论设为3
Hotel::Hotel(const string& name, const string& city, const string& area,
             string credit_code)
  : Business(credit_code),
    name_(name), city_(city), area_(area) {
  rooms_.clear();
  review_ = 3;
}

Hotel::~Hotel() {}

//**********************取值函数***********************************************
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

//******************设值函数**************************************************
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

// 返回房间向量容器的引用
// 以便于访问到任意一间房，作为抽象的管理方式
vector<Room>& Hotel::ManageRooms() {
  return rooms_;
}

// 增加房间，提供的一种管理接口
void Hotel::AddOneRoom(const Room& room_model) {
    rooms_.push_back(room_model);
}

// 返回房间向量容器的常引用
// 以便于访问到任意一间房，而不产生更改作为抽象的搜索准备方式
const vector<Room>& Hotel::PrepareSearch() const {
  return rooms_;
}

// 得到起价，提供的一种查询接口
// 用迭代器对rooms遍历得到最小价钱
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

// 得到在给定期限内可用的房间数，提供的一种查询接口
// 用迭代器对rooms遍历，配合上计数器得到可供使用的房间数并返回
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

// 得到在给定期限内可用的给定房型的房间数，提供的一种查询接口
// 用迭代器对rooms遍历，配合上计数器得到可供使用的房间数并返回
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

// 得到起价，提供的一种查询接口
// 用迭代器对rooms遍历得到符合条件的房间的最小价钱
// 若没有给定床型的房间返回-1作为异常值
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

// 得到起价，提供的一种查询接口
// 用迭代器对rooms遍历得到符合条件的房间的最小价钱
// 若没有给定房型的房间返回-1作为异常值
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
