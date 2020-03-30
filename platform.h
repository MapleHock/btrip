//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：platform.h
// 当前版本：1.0
// 摘要：本文件中实现Platform类的定义。该类为程序中数据传递的核心，也是整个流程中中要的
// 一环
// 作者：吴文绪
// 完成日期：2018.7.29
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

// Platform类持有三种用户的指针队列JoinApplication的指针和AbstractBooking的指针
// 并且通过JoinApplication拥有了Hotel*的指针队列，可以据此访问到程序重所有的数据
// 其公有成员函数为分为三个部分，得到各个队列、检查申请和订单、数据库连接时使用函数
class Platform {
public:
// 公有枚举成员，用于某些无法使用dynamic_cast情况下进行可靠的强制类型转换
  enum UserType{CUSTOMER, PLATFORMADMINISTRATOR, HOTELMANAGER};
  Platform();
  ~Platform();
// 根据用户类型注册并将其放入对应队列
  void UserRegister(AbstractUser* new_user, UserType user_type);

//***********************取值函数**********************************************
  vector<Customer*>& GetCustomerList();
  vector<HotelManager*>& GetHotelManagerList();
  vector<PlatformAdministrator*>& GetPlatformAdministratorList();
  vector<Hotel*>& GetHotelList();
  const vector<Hotel*>& PrepareSearch() const;
//****************************************************************************

//******************订单申请的审阅**********************************************
// 将订单插入待审核队列，生成流水号，返回订单指针  
  AbstractBooking* GetAUncheckedBooking(AbstractBooking* new_booking);

// 查看队首的未审核订单，返回订单指针
  AbstractBooking* ViewAnUncheckedBooking() const;

// 查看队尾的未审核订单，返回订单指针
  AbstractBooking* ViewLatestBooking() const;

// 将未审核队列的队首订单弹出，返回订单指针
  AbstractBooking* HoldABooking();

// 审核订单，被为按照输入设置抽成
// 重载形式分别针对对队首订单直接审核，对抽出的订单的审核，返回订单指针
// 第一种重载形式会返回空指针作为异常值
  AbstractBooking* CheckABooking(AbstractBooking* booking ,
                                 unsigned int share_percent);
  AbstractBooking* CheckABooking(unsigned int share_percent);

// 拒绝订单，返回订单指针，
// 将订单流水号置0作为一场值，数据库连接时舍弃
  AbstractBooking* RejectABooking(AbstractBooking* booking);

// 得到商家反馈的订单，返回订单指针
// 可能返回空指针为作为异常值
// 在订单无法找到存根或者被商家拒绝时会返回空指针
  AbstractBooking* GetABookingFromBusiness(AbstractBooking* new_booking);

// 得到用户反馈的订单，更新酒店评价，返回订单指针
  AbstractBooking* GetAReview(AbstractBooking* booking);

// 得到申请并将其加入待审核队列，返回申请指针
  JoinApplication* GetAnApplication(JoinApplication* new_application);

// 查看队首的待审核申请，返回申请指针
// 无返回空指针作为异常值
  JoinApplication* ViewAnUncheckApp();

// 将队首的待审核队列弹出，并将其返回
  JoinApplication* HoldAnApp();

// 将被抽出/队首的申请审核
  void CheckAnApp(JoinApplication* app);
  void CheckAnApp();

// 拒绝申请，返回申请指针
// 删除该指针指向的内容
  JoinApplication* RejectAnApp(JoinApplication* app);
//***************************************************************************

//********************数据库连接时使用******************************************

// 得到订单组，更新数据库用
  list<AbstractBooking*> GetBookings();

// 得到申请组,更新数据库用
  list<JoinApplication*> GetApps();

// 根据数据库信息生成managerlist， 载入数据库数据用，全部成功返回true
  bool InsertManager(const string& username, const string& password, const string& credit_code);

// 根据数据库信息生成roomlist， 载入数据库数据用，全部成功返回true
  bool InsertRoom(const string& credit_code, const string& room_number, const string& room_type,
                 int price, int bed_type);

// 根据数据库信息生成bookinglist， 载入数据库数据用，全部成功返回true
  bool InsertBooking(int serial, const QDate& create_date, const QDate& check_in, const QDate& check_out,
                     int unit_price, int share, bool is_payed, bool is_checked,
                     bool is_accepted, bool is_finish, const string& customer_name,
                     const string& hotel_code);

// 根据数据库信息生成applicationlist， 载入数据库数据用，全部成功返回true
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
