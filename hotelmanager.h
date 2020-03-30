//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�
// ��ǰ�汾��1.0
// ժҪ�����ļ���ʵ�־Ƶ��ҵ��ԱHotelManager��Ķ��壬ͨ���ԾƵ�ĳ�������
//      ѡ���Եķ��ʾƵ��Ա������ɶ����ͷ������
// ���ߣ�������
// ������ڣ�2018.7.27
//****************************************************************************

#ifndef HOTELMANAGER_H__
#define HOTELMANAGER_H__
#include "abstractuser.h"
#include "hotel.h"
#include "hotelbooking.h"
using std::string;

// HotelManager�࣬�̳���AbstractUser�࣬������hotel_belong_�ĳ���ָ�룬
// �Դ˵õ�����ӿڣ�Ҳ�õ��˵���Hotel�����س�Ա�������оƵ����
class HotelManager : public AbstractUser {
public:

// ���캯�������û�������Ͷ�Ӧ�Ƶ�����ã���ɰ�
  HotelManager(const string& username, const string& password, 
               Hotel& hotel_belong);
  ~HotelManager();
// ȡֵ�������ؾƵ�����
  Hotel& GetHotelBelong();

// ͨ���������õ��þƵ�ľܾ�����
// ���Ƶ�ܾ�ʧ���Ƿ��ؿ�ָ��
// ���Ƶ�ܾ��Ĳ���HotelBookingʱ���ؿ�ָ��
  HotelBooking* RejectABooking();

// ͨ���������õ��þƵ����ɶ����������ɹ�����true
  bool FinishABooking(unsigned int booking_order);

// ͨ���������õ��þƵ��Manage������ɶԷ���Ķ��۳ɹ�����true
  bool ResetRoomPrice(unsigned int new_price, const string& room_number);
  bool ResetPriceSameType(unsigned int new_price,
                          const string& room_type_defined_by_hotel);
  bool ResetPriceThisAndSimilar(unsigned int new_price, 
                                const string& room_number);

// �Ƶ����ԱΪ�Ƶ���׵Ķ������ŷ��䣬�ɹ�����true
  bool AcceptABooking(const string& room_number);
// �鿴����������ui�������ʾ
  const deque<AbstractBooking*>& ViewBookingsReceived();
  const vector<AbstractBooking*>& ViewBookingsUnfinished();

protected:
private:
  Hotel& hotel_belong_;
};

#endif // !HOTELMANAGER_H__
