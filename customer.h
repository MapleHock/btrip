//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：customer.h
// 当前版本：1.1
// 摘要：在1.0版本对ustomer类的定义基础上，增加了搜索评价功能
// 作者：吴文绪
// 完成日期：2018.7.29
// 版本：1.0
// 摘要：本文件中实现Customer类的初步定义
// 作者：吴文绪
// 完成日期：2018.7.27
//****************************************************************************

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <vector>
#include "abstractuser.h"
#include "hotelbooking.h"
#include "hotel.h"
using std::vector;

class Platform;

// Customer类的定义，其继承于抽象类AbstractUser，除了拥有自己的用户名和密码以外，
// 添加了公有成员函数用于房间预订，支付，对订单状态的查看
// 对酒店搜索和对酒店的评价
class Customer : public AbstractUser {
public:

// 构造函数，创建一个对应用户名和密码的用户
  Customer(const string& username, const string& password);
  ~Customer();

 // 向对应的平台发出申请，返回该平台指针
  Platform* SearchAt(Platform& platform) const;

// 查看订单，返回对应订单vector容器的常引用
  const vector<HotelBooking*>& ViewHotelUnpay() const;
  const vector<HotelBooking*>& ViewHotelUnreview() const;

// 预订酒店，按照给定的酒店，房间类型，出入时间，在给定的平台进行酒店预订
// 成功返回true
// 该函数会创建需要由调用者释放的空间
  bool BookRoom(const QDate& booking_date,
                const Hotel& hotel,const string& room_type, unsigned int count,
                const Platform& platform,
                const QDate& check_in_date,const QDate& check_out_date);

// 支付在hotel_bookings_unpay_对应位置的订单，如果支付成功，返回对应的订单指针
// 失败返回NULL
  HotelBooking* PayHotel(unsigned int booking_order, unsigned int money);

// 评价在hotel_bookings_unpay_对应位置的订单，如果评价成功，返回对应的订单指针
// 失败返回NULL
  HotelBooking* ReviewHotel(unsigned int booking_order, unsigned int review);
protected:
private:
  vector<HotelBooking*> hotel_bookings_unpay_;
  vector<HotelBooking*> hotel_bookings_unreview_;
};


#endif // !CUSTOMER_H



