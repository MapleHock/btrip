//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：customer.cpp
// 当前版本：1.1
// 摘要：在1.0版本对ustomer类的定义基础上，增加了搜索评价功能
// 作者：吴文绪
// 完成日期：2018.7.29
// 版本：1.0
// 摘要：本文件中实现Customer类的成员函数
// 作者：吴文绪
// 完成日期：2018.7.27
//****************************************************************************


#include "customer.h"
#include "hotel.h"

// 构造函数，创建一个对应用户名和密码的用户
Customer::Customer(const string& username, const string& password)
  : AbstractUser(username, password) {}

Customer::~Customer() {}

// 向对应的平台发出申请，返回该平台指针
Platform* Customer::SearchAt(Platform& platform) const {
  return &platform;
}

// 查看订单，返回对应订单vector容器的常引用
const vector<HotelBooking*>& Customer::ViewHotelUnpay() const {
  return hotel_bookings_unpay_;
}

// 查看订单，返回对应订单vector容器的常引用
const vector<HotelBooking*>& Customer::ViewHotelUnreview() const {
  return hotel_bookings_unreview_;
}

// 预订酒店，按照给定的酒店，房间类型，出入时间，在给定的平台进行酒店预订
// 成功返回true
// 该函数会创建需要由调用者释放的空间
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

// 支付在hotel_bookings_unpay_对应位置的订单，如果支付成功，返回对应的订单指针
// 失败返回NULL，用于错误信息显示
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

// 评价在hotel_bookings_unpay_对应位置的订单，如果评价成功，返回对应的订单指针
// 失败返回NULL，用于错误信息显示
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
