//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�customer.cpp
// ��ǰ�汾��1.1
// ժҪ����1.0�汾��ustomer��Ķ�������ϣ��������������۹���
// ���ߣ�������
// ������ڣ�2018.7.29
// �汾��1.0
// ժҪ�����ļ���ʵ��Customer��ĳ�Ա����
// ���ߣ�������
// ������ڣ�2018.7.27
//****************************************************************************


#include "customer.h"
#include "hotel.h"

// ���캯��������һ����Ӧ�û�����������û�
Customer::Customer(const string& username, const string& password)
  : AbstractUser(username, password) {}

Customer::~Customer() {}

// ���Ӧ��ƽ̨�������룬���ظ�ƽָ̨��
Platform* Customer::SearchAt(Platform& platform) const {
  return &platform;
}

// �鿴���������ض�Ӧ����vector�����ĳ�����
const vector<HotelBooking*>& Customer::ViewHotelUnpay() const {
  return hotel_bookings_unpay_;
}

// �鿴���������ض�Ӧ����vector�����ĳ�����
const vector<HotelBooking*>& Customer::ViewHotelUnreview() const {
  return hotel_bookings_unreview_;
}

// Ԥ���Ƶ꣬���ո����ľƵ꣬�������ͣ�����ʱ�䣬�ڸ�����ƽ̨���оƵ�Ԥ��
// �ɹ�����true
// �ú����ᴴ����Ҫ�ɵ������ͷŵĿռ�
bool Customer::BookRoom(const QDate& booking_date,
                const Hotel& hotel,const string& room_type, unsigned int count,
                const Platform& platform,
                const QDate& check_in_date,const QDate& check_out_date) {
  if (hotel.GetPriceForAType(room_type) == -1) {
    return false;
  }
  HotelBooking* new_booking = new HotelBooking(booking_date,
                                hotel.GetPriceForAType(room_type), count,
                                *this,
                                platform,
                                hotel,
                                check_in_date, check_out_date);
  new_booking->SetRoomType(room_type);
  hotel_bookings_unpay_.push_back(new_booking);
  return true;
}

// ֧����hotel_bookings_unpay_��Ӧλ�õĶ��������֧���ɹ������ض�Ӧ�Ķ���ָ��
// ʧ�ܷ���NULL�����ڴ�����Ϣ��ʾ
HotelBooking* Customer::PayHotel(unsigned int booking_order, unsigned int money) {
  vector<HotelBooking*>::iterator booking_address = 
                                              hotel_bookings_unpay_.begin()
                                            + booking_order;
  if ((*booking_address)->BePayed(money) == AbstractBooking::SUCCESS) {
    hotel_bookings_unreview_.push_back(*booking_address);
    hotel_bookings_unpay_.erase(booking_address);
    return hotel_bookings_unreview_.back();
  } else {
    return NULL;
  }
}

// ������hotel_bookings_unpay_��Ӧλ�õĶ�����������۳ɹ������ض�Ӧ�Ķ���ָ��
// ʧ�ܷ���NULL�����ڴ�����Ϣ��ʾ
HotelBooking* Customer::ReviewHotel(unsigned int booking_order,
                                    unsigned int review) {
  vector<HotelBooking*>::iterator booking_address =  
                                              hotel_bookings_unreview_.begin()
                                            + booking_order;
  if ((*booking_address)->GetRiew() < 0 && (*booking_address)->IsFinished()) {
    HotelBooking* the_booking = *booking_address;
    the_booking->SetRiew(review);
    hotel_bookings_unreview_.erase(booking_address);
    return the_booking;
  } else {
    return NULL;
  }
}
