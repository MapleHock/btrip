//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：
// 当前版本：1.0
// 摘要：本文件中实现酒店端业务员HotelManager类的定义，通过对酒店的持有引用
//      选择性的访问酒店成员函数完成订单和房间管理
// 作者：吴文绪
// 完成日期：2018.7.27
//****************************************************************************

#include "hotelmanager.h"

// 构造函数输入用户名密码和对应酒店的引用，完成绑定
HotelManager::HotelManager(const string& username, const string& password,
                           Hotel& hotel_belong)
  : AbstractUser(username, password), hotel_belong_(hotel_belong) {}

HotelManager::~HotelManager() {}

// 取值函数返回酒店引用
Hotel& HotelManager::GetHotelBelong() {
  return hotel_belong_;
}

// 通过持有引用调用酒店的拒绝函数
// 当酒店拒绝失败是返回空指针
// 当酒店拒绝的不是HotelBooking时返回空指针
HotelBooking * HotelManager::RejectABooking() {
  return dynamic_cast<HotelBooking*>(hotel_belong_.RejectABooking());
}

// 通过持有引用调用酒店的完成订单函数，成功返回true
// 注意访问可能越界
bool HotelManager::FinishABooking(unsigned int booking_order) {
  
  if (hotel_belong_.FinishABooking(booking_order) != NULL) {
    return true;
  } else {
    return false;
  }
}

//************************房间管理*********************************************
// 通过持有引用调用酒店的Manage函数和迭代器对房间遍历完成对房间的定价成功返回true
bool HotelManager::ResetRoomPrice(unsigned int new_price,
                                  const string& room_number) {
  bool is_changed = false;
  vector<Room>::iterator room_address = hotel_belong_.ManageRooms().begin();
  while (room_address != hotel_belong_.ManageRooms().end()) {
    if (room_address->GetRoomNumber() == room_number) {
      room_address->ResetPricePernight(new_price);
      is_changed = true;
      break;
    }
    ++room_address;
  }
  return is_changed;
}
bool HotelManager::ResetPriceSameType(unsigned int new_price,
                                     const string& room_type_defined_by_hotel) {
  bool is_changed = false;
  vector<Room>::iterator room_address = hotel_belong_.ManageRooms().begin();
  while (room_address != hotel_belong_.ManageRooms().end()) {
    if (room_address->GetRoomTypeDefinedByHotel() == room_type_defined_by_hotel) {
      room_address->ResetPricePernight(new_price);
      is_changed = true;
      continue;
    }
    ++room_address;
  }
  return is_changed;
}

bool HotelManager::ResetPriceThisAndSimilar(unsigned int new_price,
                                            const string& room_number) {
  bool is_changed = false;
  string this_type_defined_by_hotel;
  vector<Room>::iterator room_address = hotel_belong_.ManageRooms().begin();
  while (room_address != hotel_belong_.ManageRooms().end()) {
    if (room_address->GetRoomNumber() == room_number) {
      room_address->ResetPricePernight(new_price);
      is_changed = true;
      this_type_defined_by_hotel = room_address->GetRoomTypeDefinedByHotel();
      break;
    }
    ++room_address;
  }
  if (is_changed) {
    room_address = hotel_belong_.ManageRooms().begin();
    while (room_address != hotel_belong_.ManageRooms().end()) {
      if (room_address->GetRoomTypeDefinedByHotel() == this_type_defined_by_hotel) {
        room_address->ResetPricePernight(new_price);
        continue;
      }
      ++room_address;
    }
  }
  return is_changed;
}

//****************************************************************************

// 查看订单，用于ui界面的显示
const deque<AbstractBooking*>& HotelManager::ViewBookingsReceived() {
  return hotel_belong_.ViewBookingsReceived();
}

// 查看订单，用于ui界面的显示
const vector<AbstractBooking*>& HotelManager::ViewBookingsUnfinished() {
  return hotel_belong_.ViewBookingsUnfinished();
}

// 酒店管理员为酒店队首的订单安排房间，成功返回true
bool HotelManager::AcceptABooking(const string& room_number) {
  HotelBooking* new_booking = 
            dynamic_cast<HotelBooking*>(hotel_belong_.ViewAnUncceptBooking());
  if (new_booking == NULL || new_booking->IsAcceptedByBusiness()) {
    return false;
  } else {
    Room* target_room = NULL;
    for (unsigned int i = 0; i < hotel_belong_.ManageRooms().size(); i++) {
      if (room_number == hotel_belong_.ManageRooms()[i].GetRoomNumber()) {
        target_room = &(hotel_belong_.ManageRooms()[i]);
        break;
      }
    }
    if (target_room == NULL) {
      return false;
    }
    target_room->BeBooked(new_booking->GetCheckInDate(), 
                          new_booking->GetCheckOutDate());
    new_booking->SetRoomNumber(room_number);
    hotel_belong_.AcceptABooking();
    return true;
  }
}
