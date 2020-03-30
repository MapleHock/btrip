//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�business.h
// ��ǰ�汾��1.0
// ժҪ�����ļ���ʵ�ֶԳ�����business�Ķ��塣������ΪB2C����ƽ̨�ĳ����Ա֮һ��ӵ�е�
//      �����룬���ܾܾ���ɶ�����������
// ���ߣ�������
// ������ڣ�2018.7.26
//****************************************************************************

#ifndef BUSINESS_H
#define BUSINESS_H
#include <vector>
#include <deque>
#include "abstractbooking.h"

class JoinApplication;
using std::vector;
using std::deque;
using std::string;

// Business��ӵ��˽�����ݳ�Աcredit_code��Ϊ������ӵ�в�ͬ����Ķ�����ָ�����/��������
// �Դ�ģ��Զ����Ĳ�������ӵ�о�̬���г�Ա�ݽ����룬���ں�ƽ̨�˵�ͨ�š�������Ա����
// ���ڶԶ����Ľ��ܡ��鿴�����ܡ��ܾ�����ɵȹ���
class Business {
public:
 // ��̬���г�ԱApply����һ����ɵ����룬���ں�ƽ̨�˵�ͨ��
  static JoinApplication* Apply(JoinApplication* application);
  Business(string credit_code);
  virtual ~Business();
  const string& GetCreditCode() const;

// �õ����������ڽ���ƽ̨�˴�������˺�Ķ�����ָ��
// ��������ʱ����NULL��Ϊ������Ϣ
  AbstractBooking* ReceiveABooking(AbstractBooking* new_booking);

// ���ܶ���������λ��bookings_recived_���׵Ķ�����������״̬���ѽ���
// ���ظö���ָ��
  AbstractBooking* AcceptABooking();

// ���ܶ������������Ӧ�Ķ�����������״̬���ѽ��ܣ����ڲ���ƽ̨�Ķ����Ľ�������
// ���ظö���ָ�룬
  AbstractBooking* AcceptABooking(AbstractBooking* booking);

// ȡֵ���������ض������У����ڲ�ѯ��Ӧ������״̬
  const deque<AbstractBooking*>& ViewBookingsReceived();
  const vector<AbstractBooking*>& ViewBookingsUnfinished();

// ���ܶ������ܾ�λ��bookings_recived_���׵Ķ���
// ���ظö���ָ��
// ����Ϊ�շ���NULL��Ϊ������Ϣ
  AbstractBooking* RejectABooking();

// ��ɶ������������λ�õĶ�����������״̬������ɣ�
// ���ظö���ָ��
  AbstractBooking* FinishABooking(unsigned int booking_order_);

// �Ӷ���bookings_will_back_���������͸�ƽ̨
  AbstractBooking* SendBackABooking();

// �鿴��δ����/�ܾ��Ķ���������ui�Ķ�����ʾ
  AbstractBooking* ViewAnUncceptBooking();
protected:
private:
  const string credit_code_;
  deque<AbstractBooking*> bookings_recived_;
  vector<AbstractBooking*> bookings_unfinished_;
  deque<AbstractBooking*> bookings_will_back_;
};

#endif // !BUSINESS_H
