//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�room.h
// ��ǰ�汾��1.0
// ժҪ�����ļ���ʵ��Room��Ķ���
// ���ߣ�������
// ������ڣ�2018.7.27
//****************************************************************************

#ifndef ROOM_H
#define ROOM_H
#include <string>
#include <qdatetime.h>
#include <list>
using std::string;
using std::list;

// Room�����˽�����ݳ�Ա���ͣ�����ţ���С��¥�㣬��Ԥ����ʱ�����������
// ����Ҫ�����б�Ԥ��ȡ��Ԥ���������۸��
// ��Ҫ�ڲ�ѯ��Ԥ�������б�����
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
//**************************ȡֵ����*******************************************
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

//********************************��ֵ����*************************************
  void ResetRoomNumber(const string& new_room_number);
  void ResetPricePernight(unsigned int new_price_pernight);
//****************************************************************************  
// ��ͼ������������������ύ���룬���ԤԼ�ɹ�����true
  bool BeBooked(const QDate& check_in_date, const QDate& check_out_date);

// ȡ���������ڵ�ԤԼ���ɹ�����true
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
