//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：business.h
// 当前版本：1.0
// 摘要：本文件中实现对抽象类business的定义。该类作为B2C电商平台的抽象成员之一，拥有递
//      交申请，接受拒绝完成订单的能力。
// 作者：吴文绪
// 完成日期：2018.7.26
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

// Business类拥有私有数据成员credit_code作为主键。拥有不同情况的订单的指针队列/向量容器
// 以此模拟对订单的操作。其拥有静态公有成员递交申请，用于和平台端的通信。其他成员函数
// 用于对订单的接受、查看、接受、拒绝、完成等功能
class Business {
public:
 // 静态公有成员Apply返回一个完成的申请，用于和平台端的通信
  static JoinApplication* Apply(JoinApplication* application);
  Business(string credit_code);
  virtual ~Business();
  const string& GetCreditCode() const;

// 得到订单，用于接受平台端传出的审核后的订单的指针
// 订单错配时传出NULL作为错误信息
  AbstractBooking* ReceiveABooking(AbstractBooking* new_booking);

// 接受订单，接受位于bookings_recived_队首的订单，更新其状态至已接受
// 返回该订单指针
  AbstractBooking* AcceptABooking();

// 接受订单输入参数对应的订单，更新其状态至已接受，用于不经平台的订单的建立过程
// 返回该订单指针，
  AbstractBooking* AcceptABooking(AbstractBooking* booking);

// 取值函数，返回订单队列，用于查询对应订单的状态
  const deque<AbstractBooking*>& ViewBookingsReceived();
  const vector<AbstractBooking*>& ViewBookingsUnfinished();

// 接受订单，拒绝位于bookings_recived_队首的订单
// 返回该订单指针
// 队列为空返回NULL作为错误信息
  AbstractBooking* RejectABooking();

// 完成订单，完成输入位置的订单，更新其状态置已完成，
// 返回该订单指针
  AbstractBooking* FinishABooking(unsigned int booking_order_);

// 从队列bookings_will_back_将订单发送给平台
  AbstractBooking* SendBackABooking();

// 查看尚未接受/拒绝的订单，用于ui的订单显示
  AbstractBooking* ViewAnUncceptBooking();
protected:
private:
  const string credit_code_;
  deque<AbstractBooking*> bookings_recived_;
  vector<AbstractBooking*> bookings_unfinished_;
  deque<AbstractBooking*> bookings_will_back_;
};

#endif // !BUSINESS_H
