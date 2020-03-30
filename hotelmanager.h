//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：
// 当前版本：1.0
// 摘要：本文件中实现酒店端业务员HotelManager类的定义，通过对酒店的持有引用
//      选择性的访问酒店成员函数完成订单和房间管理
// 作者：吴文绪
// 完成日期：2018.7.27
//****************************************************************************

#ifndef HOTELMANAGER_H__
#define HOTELMANAGER_H__
#include "abstractuser.h"
#include "hotel.h"
#include "hotelbooking.h"
using std::string;

// HotelManager类，继承于AbstractUser类，加上了hotel_belong_的持有指针，
// 以此得到登入接口，也得到了调用Hotel类的相关成员函数进行酒店管理
class HotelManager : public AbstractUser {
public:

// 构造函数输入用户名密码和对应酒店的引用，完成绑定
  HotelManager(const string& username, const string& password, 
               Hotel& hotel_belong);
  ~HotelManager();
// 取值函数返回酒店引用
  Hotel& GetHotelBelong();

// 通过持有引用调用酒店的拒绝函数
// 当酒店拒绝失败是返回空指针
// 当酒店拒绝的不是HotelBooking时返回空指针
  HotelBooking* RejectABooking();

// 通过持有引用调用酒店的完成订单函数，成功返回true
  bool FinishABooking(unsigned int booking_order);

// 通过持有引用调用酒店的Manage函数完成对房间的定价成功返回true
  bool ResetRoomPrice(unsigned int new_price, const string& room_number);
  bool ResetPriceSameType(unsigned int new_price,
                          const string& room_type_defined_by_hotel);
  bool ResetPriceThisAndSimilar(unsigned int new_price, 
                                const string& room_number);

// 酒店管理员为酒店队首的订单安排房间，成功返回true
  bool AcceptABooking(const string& room_number);
// 查看订单，用于ui界面的显示
  const deque<AbstractBooking*>& ViewBookingsReceived();
  const vector<AbstractBooking*>& ViewBookingsUnfinished();

protected:
private:
  Hotel& hotel_belong_;
};

#endif // !HOTELMANAGER_H__
