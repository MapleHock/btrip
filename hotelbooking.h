//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�hotelbooking.h
// ��ǰ�汾��1.0
// ժҪ�����ļ���ʵ��HotelBooking��Ķ��壬�ڼ̳�ABstractBooking�Ļ�����ʵ�־Ƶ궩��
//      ����չ
// ���ߣ�������
// ������ڣ�2018.7.28
//****************************************************************************

#ifndef HOTELBOOKING_H
#define HOTELBOOKING_H
#include <string>
#include <qdatetime.h>
#include "abstractbooking.h"
using std::string;

class Hotel;

// HotelBooking�࣬���ڼ̳�ABstractBooking�Ļ����Ͻ����˾Ƶ궩���ĸ��Ի���չ��
// �˾Ƶ������������ͣ���סǨ�����ڣ�����ţ����ۡ�
// �ڶ�������ʱ�����Ϊ�գ�����Ϊ-1���ھƵ�ӵ������䷿��ţ��ڿͻ����ۺ���������
class HotelBooking : public AbstractBooking {
public:
// ���캯�������մ�����Ϣ���충����
// ���л���AbstractBooking�е����ݳ�Ա���� unit_price����ʼ��Ϊÿ������*��ʱ��
// amountΪ�����ķ�����
  HotelBooking(const QDate& created_date,
               unsigned int price_pernight_perroom,
               unsigned int amount, 
               const Customer& customer,
               const Platform& platform,
               const Hotel& Hotel,
               const QDate& check_in_date,
               const QDate& check_out_date);
  ~HotelBooking();
//****************ȡֵ����*****************************************************
  const string& GetHotelName() const;
  const string& GetRoomType() const;
  const QDate& GetCheckInDate() const;
  const QDate& GetCheckOutDate() const;
  unsigned int GetPricePerNightPerRoom() const;
  int GetRiew() const;
//****************************************************************************

//***************��ֵ����*****************************************************
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
// ����Ϊ0-5�� -1 Ϊδ����
  int review_;
};

#endif // !HOTELBOOKING_H
