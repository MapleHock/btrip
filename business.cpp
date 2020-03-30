//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�business.cpp
// ��ǰ�汾��1.0
// ժҪ�����ļ���ʵ�ֶԳ�����business�ĳ�Ա��������Ҫͨ����stl���к����ĵ���ģ�ⶩ��
//      �ھƵ�˾���������
// ���ߣ�������
// ������ڣ�2018.7.26
//****************************************************************************

#include "business.h"

/*static*/ JoinApplication* Business::Apply(JoinApplication* application) {
  return application;
}

Business::Business(string credit_code) : credit_code_(credit_code) {}

/*virtual*/ Business::~Business() {}

const string& Business::GetCreditCode() const {
  return credit_code_;
}

// �õ����������ڽ���ƽ̨�˴�������˺�Ķ�����ָ��
// �������������䣬��������Ӧ���̼ҵ�credit_code������ƥ�䣬����NULLΪ������Ϣ
AbstractBooking* Business::ReceiveABooking(AbstractBooking* new_booking) {
  if (new_booking->GetBusiness().GetCreditCode() != credit_code_) {
    bookings_will_back_.push_back(new_booking);
    return NULL;
  } else {
    bookings_recived_.push_back(new_booking);
    return new_booking;
  }
}

// ���ܶ���������λ��bookings_recived_���׵Ķ�����������״̬���ѽ���
// ���ظö���ָ��
AbstractBooking* Business::AcceptABooking() {
  AbstractBooking* new_booking = bookings_recived_.front();
  new_booking->BeAccepted();
  bookings_recived_.pop_front();
  bookings_unfinished_.push_back(new_booking);
  return new_booking;
}

// ���ܶ������������Ӧ�Ķ�����������״̬���ѽ���
// ���ظö���ָ�롣
AbstractBooking* Business::AcceptABooking(AbstractBooking* booking) {
  bookings_unfinished_.push_back(booking);
  return booking;
}

// ȡֵ�����������յ��Ķ������У����ڲ�ѯ��Ӧ������״̬
const deque<AbstractBooking*>& Business::ViewBookingsReceived() {
  return bookings_recived_;
}

// ȡֵ����������δ��ɵĶ������У����ڲ�ѯ��Ӧ������״̬
const vector<AbstractBooking*>& Business::ViewBookingsUnfinished() {
  return bookings_unfinished_;
}

// �ܾ��������ܾ�λ��bookings_recived_���׵Ķ���
// ���ظö���ָ��
// ����Ϊ�շ���NULL��Ϊ������Ϣ
AbstractBooking * Business::RejectABooking() {
  if (bookings_recived_.size() == 0) {
    return NULL;
  } else {
    AbstractBooking* the_booking = bookings_recived_.front();
    bookings_recived_.pop_front();
    bookings_will_back_.push_back(the_booking);
    return the_booking;
  }
}

AbstractBooking* Business::FinishABooking(unsigned int booking_order_){
  AbstractBooking* new_booking = bookings_unfinished_[booking_order_];
  new_booking->BeFinished();
  bookings_unfinished_.erase(bookings_unfinished_.begin() + booking_order_);
  bookings_will_back_.push_back(new_booking);
  return new_booking;
}

// �Ӷ���bookings_will_back_�������׵Ķ���ָ�벢���䷵��
AbstractBooking* Business::SendBackABooking() {
  AbstractBooking* new_booking = bookings_will_back_.front();
  bookings_will_back_.pop_front();
  return new_booking;
}

// �鿴��δ����/�ܾ��Ķ����������ܵ��������׵�ֵ
AbstractBooking* Business::ViewAnUncceptBooking() {
  return bookings_recived_.front();
}
