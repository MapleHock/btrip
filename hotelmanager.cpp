//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�
// ��ǰ�汾��1.0
// ժҪ�����ļ���ʵ�־Ƶ��ҵ��ԱHotelManager��Ķ��壬ͨ���ԾƵ�ĳ�������
//      ѡ���Եķ��ʾƵ��Ա������ɶ����ͷ������
// ���ߣ�������
// ������ڣ�2018.7.27
//****************************************************************************

#include "hotelmanager.h"

// ���캯�������û�������Ͷ�Ӧ�Ƶ�����ã���ɰ�
HotelManager::HotelManager(const string& username, const string& password,
                           Hotel& hotel_belong)
  : AbstractUser(username, password), hotel_belong_(hotel_belong) {}

HotelManager::~HotelManager() {}

// ȡֵ�������ؾƵ�����
Hotel& HotelManager::GetHotelBelong() {
  return hotel_belong_;
}

// ͨ���������õ��þƵ�ľܾ�����
// ���Ƶ�ܾ�ʧ���Ƿ��ؿ�ָ��
// ���Ƶ�ܾ��Ĳ���HotelBookingʱ���ؿ�ָ��
HotelBooking * HotelManager::RejectABooking() {
  return dynamic_cast<HotelBooking*>(hotel_belong_.RejectABooking());
}

// ͨ���������õ��þƵ����ɶ����������ɹ�����true
// ע����ʿ���Խ��
bool HotelManager::FinishABooking(unsigned int booking_order) {
  
  if (hotel_belong_.FinishABooking(booking_order) != NULL) {
    return true;
  } else {
    return false;
  }
}

//************************�������*********************************************
// ͨ���������õ��þƵ��Manage�����͵������Է��������ɶԷ���Ķ��۳ɹ�����true
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

// �鿴����������ui�������ʾ
const deque<AbstractBooking*>& HotelManager::ViewBookingsReceived() {
  return hotel_belong_.ViewBookingsReceived();
}

// �鿴����������ui�������ʾ
const vector<AbstractBooking*>& HotelManager::ViewBookingsUnfinished() {
  return hotel_belong_.ViewBookingsUnfinished();
}

// �Ƶ����ԱΪ�Ƶ���׵Ķ������ŷ��䣬�ɹ�����true
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
