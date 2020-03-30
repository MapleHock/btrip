//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�customer.h
// ��ǰ�汾��1.1
// ժҪ����1.0�汾��ustomer��Ķ�������ϣ��������������۹���
// ���ߣ�������
// ������ڣ�2018.7.29
// �汾��1.0
// ժҪ�����ļ���ʵ��Customer��ĳ�������
// ���ߣ�������
// ������ڣ�2018.7.27
//****************************************************************************

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <vector>
#include "abstractuser.h"
#include "hotelbooking.h"
#include "hotel.h"
using std::vector;

class Platform;

// Customer��Ķ��壬��̳��ڳ�����AbstractUser������ӵ���Լ����û������������⣬
// ����˹��г�Ա�������ڷ���Ԥ����֧�����Զ���״̬�Ĳ鿴
// �ԾƵ������ͶԾƵ������
class Customer : public AbstractUser {
public:

// ���캯��������һ����Ӧ�û�����������û�
  Customer(const string& username, const string& password);
  ~Customer();

 // ���Ӧ��ƽ̨�������룬���ظ�ƽָ̨��
  Platform* SearchAt(Platform& platform) const;

// �鿴���������ض�Ӧ����vector�����ĳ�����
  const vector<HotelBooking*>& ViewHotelUnpay() const;
  const vector<HotelBooking*>& ViewHotelUnreview() const;

// Ԥ���Ƶ꣬���ո����ľƵ꣬�������ͣ�����ʱ�䣬�ڸ�����ƽ̨���оƵ�Ԥ��
// �ɹ�����true
// �ú����ᴴ����Ҫ�ɵ������ͷŵĿռ�
  bool BookRoom(const QDate& booking_date,
                const Hotel& hotel,const string& room_type, unsigned int count,
                const Platform& platform,
                const QDate& check_in_date,const QDate& check_out_date);

// ֧����hotel_bookings_unpay_��Ӧλ�õĶ��������֧���ɹ������ض�Ӧ�Ķ���ָ��
// ʧ�ܷ���NULL
  HotelBooking* PayHotel(unsigned int booking_order, unsigned int money);

// ������hotel_bookings_unpay_��Ӧλ�õĶ�����������۳ɹ������ض�Ӧ�Ķ���ָ��
// ʧ�ܷ���NULL
  HotelBooking* ReviewHotel(unsigned int booking_order, unsigned int review);
protected:
private:
  vector<HotelBooking*> hotel_bookings_unpay_;
  vector<HotelBooking*> hotel_bookings_unreview_;
};


#endif // !CUSTOMER_H



