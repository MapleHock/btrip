//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：hotelbooking.h
// 当前版本：1.0
// 摘要：本文件中实现HotelBooking类的定义，在继承ABstractBooking的基础上实现酒店订单
//      的扩展
// 作者：吴文绪
// 完成日期：2018.7.28
//****************************************************************************

#ifndef HOTELBOOKING_H
#define HOTELBOOKING_H
#include <string>
#include <qdatetime.h>
#include "abstractbooking.h"
using std::string;

class Hotel;

// HotelBooking类，在在继承ABstractBooking的基础上进行了酒店订单的个性化拓展。
// 了酒店名，房间类型，入住迁出日期，房间号，评价。
// 在订单创建时房间号为空，评论为-1。在酒店接单后会分配房间号，在客户评论后生成评价
class HotelBooking : public AbstractBooking {
public:
// 构造函数，按照传入信息构造订单，
// 其中基类AbstractBooking中的数据成员单价 unit_price被初始化为每晚消费*总时长
// amount为订购的房间数
  HotelBooking(const QDate& created_date,
               unsigned int price_pernight_perroom,
               unsigned int amount, 
               const Customer& customer,
               const Platform& platform,
               const Hotel& Hotel,
               const QDate& check_in_date,
               const QDate& check_out_date);
  ~HotelBooking();
//****************取值函数*****************************************************
  const string& GetHotelName() const;
  const string& GetRoomType() const;
  const QDate& GetCheckInDate() const;
  const QDate& GetCheckOutDate() const;
  unsigned int GetPricePerNightPerRoom() const;
  int GetRiew() const;
//****************************************************************************

//***************设值函数*****************************************************
  void SetRoomType(const string& room_type);
  void SetRoomNumber(const string& room_number);
  void SetRiew(int review);
protected:
private:
  string hotel_name_;
  string room_type_;
  QDate check_in_date_;
  QDate check_out_date_;
  string room_number_;
// 评价为0-5星 -1 为未评价
  int review_;
};

#endif // !HOTELBOOKING_H
