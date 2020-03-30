//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：business.cpp
// 当前版本：1.0
// 摘要：本文件中实现对抽象类business的成员函数。主要通过对stl库中函数的调用模拟订单
//      在酒店端经历的流程
// 作者：吴文绪
// 完成日期：2018.7.26
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

// 得到订单，用于接受平台端传出的审核后的订单的指针
// 若产生订单错配，即订单对应的商家的credit_code和自身不匹配，传出NULL为错误信息
AbstractBooking* Business::ReceiveABooking(AbstractBooking* new_booking) {
  if (new_booking->GetBusiness().GetCreditCode() != credit_code_) {
    bookings_will_back_.push_back(new_booking);
    return NULL;
  } else {
    bookings_recived_.push_back(new_booking);
    return new_booking;
  }
}

// 接受订单，接受位于bookings_recived_队首的订单，更新其状态至已接受
// 返回该订单指针
AbstractBooking* Business::AcceptABooking() {
  AbstractBooking* new_booking = bookings_recived_.front();
  new_booking->BeAccepted();
  bookings_recived_.pop_front();
  bookings_unfinished_.push_back(new_booking);
  return new_booking;
}

// 接受订单输入参数对应的订单，更新其状态至已接受
// 返回该订单指针。
AbstractBooking* Business::AcceptABooking(AbstractBooking* booking) {
  bookings_unfinished_.push_back(booking);
  return booking;
}

// 取值函数，返回收到的订单队列，用于查询对应订单的状态
const deque<AbstractBooking*>& Business::ViewBookingsReceived() {
  return bookings_recived_;
}

// 取值函数，返回未完成的订单队列，用于查询对应订单的状态
const vector<AbstractBooking*>& Business::ViewBookingsUnfinished() {
  return bookings_unfinished_;
}

// 拒绝订单，拒绝位于bookings_recived_队首的订单
// 返回该订单指针
// 队列为空返回NULL作为错误信息
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

// 从队列bookings_will_back_弹出队首的订单指针并将其返回
AbstractBooking* Business::SendBackABooking() {
  AbstractBooking* new_booking = bookings_will_back_.front();
  bookings_will_back_.pop_front();
  return new_booking;
}

// 查看尚未接受/拒绝的订单，返回受到订单队首的值
AbstractBooking* Business::ViewAnUncceptBooking() {
  return bookings_recived_.front();
}
