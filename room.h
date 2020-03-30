//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：room.h
// 当前版本：1.0
// 摘要：本文件中实现Room类的定义
// 作者：吴文绪
// 完成日期：2018.7.27
//****************************************************************************

#ifndef ROOM_H
#define ROOM_H
#include <string>
#include <qdatetime.h>
#include <list>
using std::string;
using std::list;

// Room类包含私有数据成员类型，房间号，大小，楼层，被预定的时间和其他特征
// 其主要功能有被预定取消预定，调整价格等
// 主要在查询和预定操作中被调用
class Room {
public:
  enum BedType { SINGLE, DOUBLE, KINGSIZE, TRIPLEANDMORE };

  Room(string room_type_defined_by_hotel, string room_number, unsigned int size,
       int floor_number, BedType bed_type, bool is_with_window, 
       bool is_with_bathroom, bool is_able_to_add_bed,
       unsigned int price_pernight);
  Room(string room_type_defined_by_hotel, unsigned int size, int floor_number,
       BedType bed_type, bool is_with_window, bool is_with_bathroom,
       bool is_able_to_add_bed, unsigned int price_pernight);
  bool operator== (const string& room_number_read);
  ~Room();
//**************************取值函数*******************************************
  const string& GetRoomTypeDefinedByHotel() const;
  const string& GetRoomNumber() const;
  unsigned int GetSize() const;
  int GetFloorNumber() const;
  BedType GetBedType() const;
  bool IsWithWindow() const;
  bool IsWithBathRoom() const;
  bool IsAbleToAddBed() const;
  unsigned int GetPricePerNight() const;
  const list<QDate>& GetBookingDates() const;
//****************************************************************************

//********************************设值函数*************************************
  void ResetRoomNumber(const string& new_room_number);
  void ResetPricePernight(unsigned int new_price_pernight);
//****************************************************************************  
// 试图在输入的两个日期内提交申请，如果预约成功返回true
  bool BeBooked(const QDate& check_in_date, const QDate& check_out_date);

// 取消输入日期的预约，成功返回true
  bool CancelABookingDate(const QDate& date);
protected:
private:
  string room_type_defined_by_hotel_;
  string room_number_;
  unsigned int size_;
  int floor_number_;
  BedType bed_type_;
  bool is_with_window_;
  bool is_with_bathroom_;
  bool is_able_to_add_bed_;
  unsigned int price_pernight_;
  list<QDate> booking_dates_;
};



#endif // !ROOM_H
