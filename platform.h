//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�platform.h
// ��ǰ�汾��1.0
// ժҪ�����ļ���ʵ��Platform��Ķ��塣����Ϊ���������ݴ��ݵĺ��ģ�Ҳ��������������Ҫ��
// һ��
// ���ߣ�������
// ������ڣ�2018.7.29
//****************************************************************************

#ifndef PLATFORM_H
#define PLATFORM_H
#include <deque>

#include "joinapplication.h"
#include "abstractuser.h"
using std::deque;
using std::list;

class AbstractBooking;
class Customer;
class HotelManager;
class PlatformAdministrator;
class Hotel;

// Platform����������û���ָ�����JoinApplication��ָ���AbstractBooking��ָ��
// ����ͨ��JoinApplicationӵ����Hotel*��ָ����У����Ծݴ˷��ʵ����������е�����
// �乫�г�Ա����Ϊ��Ϊ�������֣��õ��������С��������Ͷ��������ݿ�����ʱʹ�ú���
class Platform {
public:
// ����ö�ٳ�Ա������ĳЩ�޷�ʹ��dynamic_cast����½��пɿ���ǿ������ת��
  enum UserType{CUSTOMER, PLATFORMADMINISTRATOR, HOTELMANAGER};
  Platform();
  ~Platform();
// �����û�����ע�Ტ��������Ӧ����
  void UserRegister(AbstractUser* new_user, UserType user_type);

//***********************ȡֵ����**********************************************
  vector<Customer*>& GetCustomerList();
  vector<HotelManager*>& GetHotelManagerList();
  vector<PlatformAdministrator*>& GetPlatformAdministratorList();
  vector<Hotel*>& GetHotelList();
  const vector<Hotel*>& PrepareSearch() const;
//****************************************************************************

//******************�������������**********************************************
// �������������˶��У�������ˮ�ţ����ض���ָ��  
  AbstractBooking* GetAUncheckedBooking(AbstractBooking* new_booking);

// �鿴���׵�δ��˶��������ض���ָ��
  AbstractBooking* ViewAnUncheckedBooking() const;

// �鿴��β��δ��˶��������ض���ָ��
  AbstractBooking* ViewLatestBooking() const;

// ��δ��˶��еĶ��׶������������ض���ָ��
  AbstractBooking* HoldABooking();

// ��˶�������Ϊ�����������ó��
// ������ʽ�ֱ���ԶԶ��׶���ֱ����ˣ��Գ���Ķ�������ˣ����ض���ָ��
// ��һ��������ʽ�᷵�ؿ�ָ����Ϊ�쳣ֵ
  AbstractBooking* CheckABooking(AbstractBooking* booking ,
                                 unsigned int share_percent);
  AbstractBooking* CheckABooking(unsigned int share_percent);

// �ܾ����������ض���ָ�룬
// ��������ˮ����0��Ϊһ��ֵ�����ݿ�����ʱ����
  AbstractBooking* RejectABooking(AbstractBooking* booking);

// �õ��̼ҷ����Ķ��������ض���ָ��
// ���ܷ��ؿ�ָ��Ϊ��Ϊ�쳣ֵ
// �ڶ����޷��ҵ�������߱��̼Ҿܾ�ʱ�᷵�ؿ�ָ��
  AbstractBooking* GetABookingFromBusiness(AbstractBooking* new_booking);

// �õ��û������Ķ��������¾Ƶ����ۣ����ض���ָ��
  AbstractBooking* GetAReview(AbstractBooking* booking);

// �õ����벢����������˶��У���������ָ��
  JoinApplication* GetAnApplication(JoinApplication* new_application);

// �鿴���׵Ĵ�������룬��������ָ��
// �޷��ؿ�ָ����Ϊ�쳣ֵ
  JoinApplication* ViewAnUncheckApp();

// �����׵Ĵ���˶��е����������䷵��
  JoinApplication* HoldAnApp();

// �������/���׵��������
  void CheckAnApp(JoinApplication* app);
  void CheckAnApp();

// �ܾ����룬��������ָ��
// ɾ����ָ��ָ�������
  JoinApplication* RejectAnApp(JoinApplication* app);
//***************************************************************************

//********************���ݿ�����ʱʹ��******************************************

// �õ������飬�������ݿ���
  list<AbstractBooking*> GetBookings();

// �õ�������,�������ݿ���
  list<JoinApplication*> GetApps();

// �������ݿ���Ϣ����managerlist�� �������ݿ������ã�ȫ���ɹ�����true
  bool InsertManager(const string& username, const string& password, const string& credit_code);

// �������ݿ���Ϣ����roomlist�� �������ݿ������ã�ȫ���ɹ�����true
  bool InsertRoom(const string& credit_code, const string& room_number, const string& room_type,
                 int price, int bed_type);

// �������ݿ���Ϣ����bookinglist�� �������ݿ������ã�ȫ���ɹ�����true
  bool InsertBooking(int serial, const QDate& create_date, const QDate& check_in, const QDate& check_out,
                     int unit_price, int share, bool is_payed, bool is_checked,
                     bool is_accepted, bool is_finish, const string& customer_name,
                     const string& hotel_code);

// �������ݿ���Ϣ����applicationlist�� �������ݿ������ã�ȫ���ɹ�����true
  bool InsertApplicatioin(const string& credit_code, bool is_pass, int type, const QDate& created_date);
protected:
private:
  vector<Customer*> customer_list_;
  vector<HotelManager*> hotelmanager_list_;
  vector<PlatformAdministrator*> platformadministrator_list_;
  deque<AbstractBooking*> bookings_wait_to_check_;
  list<AbstractBooking*> bookings_checked_;
  list<AbstractBooking*> bookings_wait_to_review_;
  deque<JoinApplication*> apps_to_check_;
  deque<JoinApplication*> apps_checked_;
  vector<Hotel*> hotel_list_;
};

#endif  // PLATFORM_H
