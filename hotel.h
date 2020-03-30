//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�hotel.h
// ��ǰ�汾��1.0
// ժҪ�����ļ���ʵ��Hotel��Ķ��壬�ڼ̳�Business�Ļ����������˾Ƶ��������У�������
//      �������Ϣ
// ���ߣ�������
// ������ڣ�2018.7.28
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

// Hotel�౾�ļ���ʵ��Hotel��Ķ��壬�ڼ̳�Business�Ļ�����������˽�����ݳ�Ա�Ƶ�����
//���У�����,�������Ϣ������һ���ȡֵ��ֵ�����⣬�ṩ�˸��ຯ�����ڲ�ѯ���򷿼������
class Hotel : public Business {
public:
  Hotel(const string& name, const string& city, const string& area,
        string credit_code);
  ~Hotel();

//****ȡֵ����****************************************************************
  const string& GetName() const;
  const string& GetCity() const;
  const string& GetArea() const;
  HotelPolicies& GetHotelPolicies();
  Amenities& GetAmenities();
  unsigned int GetReview() const;
//***************************************************************************

//********��ֵ����***********************************************************
  void RefreshReview(unsigned int new_review);
  void ResetReview(unsigned int review);
  void ResetName(const string& new_name);
//***************************************************************************

// ����rooms�ķǳ��������ھƵ�Ĺ���
  vector<Room>& ManageRooms();

// Ϊ�Ƶ���ӷ���
  void AddOneRoom(const Room& room_model);

// ����rooms�ĳ�������������
  const vector<Room>& PrepareSearch() const;

// ������ʽ1���ո�����ס������ڷ��ط�������
  unsigned int RoomsAvailabel(const QDate& check_in_date, 
                              const QDate& check_out_date) const;

// ������ʽ2���ո�����ס������ںͷ������ͷ��ط�������
// ��room_number��������ʱ������ָ��Ĳ�����ֵΪ��һ�����������ķ����
  unsigned int RoomsAvailabel(const QDate& check_in_date, 
                              const QDate& check_out_date,
                              const string& room_type,
                              string* room_number = NULL) const;

// �õ����,������ʾ
  int GetStartingPrice() const;

// �õ��������͵����,������ʾ
  int GetStartingPrice(Room::BedType bed_type) const;

 // �õ��������͵����,������ʾ
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
