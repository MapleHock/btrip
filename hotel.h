//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：hotel.h
// 当前版本：1.0
// 摘要：本文件中实现Hotel类的定义，在继承Business的基础上增加了酒店名，城市，地区，
//      房间等信息
// 作者：吴文绪
// 完成日期：2018.7.28
//****************************************************************************

#ifndef HOTEL_H
#define HOTEL_H
#include <vector>
#include "room.h"
#include "business.h"
#include "hotelpolicies.h"
#include "amenities.h"
using std::string;
using std::vector;

// Hotel类本文件中实现Hotel类的定义，在继承Business的基础上增加了私有数据成员酒店名，
//城市，地区,房间等信息。除了一般的取值设值函数外，提供了各类函数用于查询空域房间的数量
class Hotel : public Business {
public:
  Hotel(const string& name, const string& city, const string& area,
        string credit_code);
  ~Hotel();

//****取值函数****************************************************************
  const string& GetName() const;
  const string& GetCity() const;
  const string& GetArea() const;
  HotelPolicies& GetHotelPolicies();
  Amenities& GetAmenities();
  unsigned int GetReview() const;
//***************************************************************************

//********设值函数***********************************************************
  void RefreshReview(unsigned int new_review);
  void ResetReview(unsigned int review);
  void ResetName(const string& new_name);
//***************************************************************************

// 返回rooms的非常引用用于酒店的管理
  vector<Room>& ManageRooms();

// 为酒店添加房间
  void AddOneRoom(const Room& room_model);

// 返回rooms的常引用用于搜索
  const vector<Room>& PrepareSearch() const;

// 搜索方式1按照给定入住搬出日期返回房间数量
  unsigned int RoomsAvailabel(const QDate& check_in_date, 
                              const QDate& check_out_date) const;

// 搜索方式2按照给定入住搬出日期和房间类型返回房间数量
// 当room_number参数非零时给传入指针的参量赋值为第一个符合条件的房间号
  unsigned int RoomsAvailabel(const QDate& check_in_date, 
                              const QDate& check_out_date,
                              const string& room_type,
                              string* room_number = NULL) const;

// 得到起价,用于显示
  int GetStartingPrice() const;

// 得到给定床型的起价,用于显示
  int GetStartingPrice(Room::BedType bed_type) const;

 // 得到给定床型的起价,用于显示
  int GetPriceForAType(const string& room_type) const;
protected:
private:
  string name_;
  const string city_;
  const string area_;
  vector<Room> rooms_;
  HotelPolicies hotel_policies_;
  Amenities amenities_;
  float review_;
};

#endif // !HOTEL_H
