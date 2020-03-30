//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：platform.cpp
// 当前版本：1.0
// 摘要：本文件中实现Platform类的成员函数的定义。该类为程序中数据传递的核心，也是整个流
// 程中中要的一环
// 作者：吴文绪
// 完成日期：2018.7.29
//****************************************************************************

#include "platform.h"

#include "abstractuser.h"
#include "customer.h"
#include "hotelmanager.h"
using std::string;

Platform::Platform() {}

Platform::~Platform() {}

// 根据用户类型注册并将其放入对应队列
// 由于定义先后问题，这里采用reinterper_cast，加入usertype进行鉴别
void Platform::UserRegister(AbstractUser* new_user, UserType user_type) {
  switch (user_type) {
  case Platform::CUSTOMER: {
    customer_list_.push_back(reinterpret_cast<Customer*>(new_user));
    break;
  }
  case Platform::PLATFORMADMINISTRATOR: {
    platformadministrator_list_.push_back(
                        reinterpret_cast<PlatformAdministrator*>(new_user));
    break;
  }
  case Platform::HOTELMANAGER: {
    hotelmanager_list_.push_back(reinterpret_cast<HotelManager*>(new_user));
    break;
  }
  default:
    break;
  }
}

//***********************取值函数**********************************************
vector<Customer*>& Platform::GetCustomerList() {
  return customer_list_;
}

vector<HotelManager*>& Platform::GetHotelManagerList() {
  return hotelmanager_list_;
}

vector<PlatformAdministrator*>& Platform::GetPlatformAdministratorList() {
  return platformadministrator_list_;
}

vector<Hotel*>& Platform::GetHotelList() {
  return hotel_list_;
}

const vector<Hotel*>& Platform::PrepareSearch() const {
  return hotel_list_;
}

//****************************************************************************

//******************订单申请的审阅**********************************************
// 将订单插入待审核队列，生成流水号，返回订单指针  
AbstractBooking* Platform::GetAUncheckedBooking(AbstractBooking* new_booking) {
  if (ViewLatestBooking() == NULL) {
    new_booking->SetSerialNumber(1);
  } else {
    new_booking->SetSerialNumber(ViewAnUncheckedBooking()->GetSerialNumber() + 1);
  }
  bookings_wait_to_check_.push_back(new_booking);
  return new_booking;
}

// 查看队首的未审核订单，返回订单指针
AbstractBooking* Platform::ViewAnUncheckedBooking() const {
  if (bookings_wait_to_check_.size() != 0) {
    return bookings_wait_to_check_.front();
  } else {
    return NULL;
  }
}

// 查看队尾的未审核订单，返回订单指针
AbstractBooking* Platform::ViewLatestBooking() const {
  if (bookings_wait_to_check_.size() != 0) {
    return bookings_wait_to_check_.back();
  } else {
    return NULL;
  }
}

// 将未审核队列的队首订单弹出，返回订单指针
AbstractBooking* Platform::HoldABooking() {
  AbstractBooking* booking_held = bookings_wait_to_check_.front();
  bookings_wait_to_check_.pop_front();
  return booking_held;
}

// 审核订单，被为按照输入设置抽成
// 重载形式分别针对对队首订单直接审核，对抽出的订单的审核，返回订单指针
// 当订单无法找到是返回空指针为异常值
AbstractBooking* Platform::CheckABooking(AbstractBooking* booking,
                                         unsigned int share_percent) {
  if (booking = NULL) {
    return NULL;
  }
  booking->BeChecked();
  booking->SetSharePercnet(share_percent);
  bookings_checked_.push_back(booking);
  return booking;
}

AbstractBooking* Platform::CheckABooking(unsigned int share_percent) {
  AbstractBooking* booking_checked = bookings_wait_to_check_.front();
  booking_checked->BeChecked();
  booking_checked->SetSharePercnet(share_percent);
  bookings_wait_to_check_.pop_front();
  bookings_checked_.push_back(booking_checked);
  return booking_checked;
}

// 拒绝订单，返回订单指针，
// 将订单流水号置0作为一场值，数据库连接时舍弃
AbstractBooking* Platform::RejectABooking(AbstractBooking* booking) {
  booking->SetSerialNumber(0);
  return booking;
}

// 得到商家反馈的订单，返回订单指针
// 可能返回空指针为作为异常值
// 在订单无法找到存根或者被商家拒绝时会返回空指针
AbstractBooking* Platform::GetABookingFromBusiness(AbstractBooking* new_booking) {
  list<AbstractBooking*>::iterator find_booking = bookings_checked_.begin();
  for (; find_booking != bookings_checked_.end(); ++find_booking) {
    if (*find_booking == new_booking) {
      break;
    }
  }
  if (find_booking == bookings_checked_.end()) {
    return NULL;
  }
  bookings_checked_.erase(find_booking);
  if (new_booking->IsAcceptedByBusiness() && new_booking->IsFinished()) {
    bookings_wait_to_review_.push_back(new_booking);
    return new_booking;
  } else {
    new_booking->SetSerialNumber(0);
    return NULL;
  }
}

// 得到用户反馈的订单，更新酒店评价，返回订单指针
AbstractBooking * Platform::GetAReview(AbstractBooking* booking) {
  HotelBooking* hotel_booking = dynamic_cast<HotelBooking*>(booking);
  if (hotel_booking != NULL) {
    int review = hotel_booking->GetRiew();
    string target_code =
      reinterpret_cast<const Hotel&>(hotel_booking->GetBusiness()).GetCreditCode();
    unsigned int i = 0;
    for (; i < hotel_list_.size(); i++) {
      if (hotel_list_[i]->GetCreditCode() == target_code) {
        break;
      }
    }
    hotel_list_[i]->RefreshReview(review);
  }
  return booking;
}

// 得到申请并将其加入待审核队列，返回申请指针
JoinApplication* Platform::GetAnApplication(JoinApplication* new_application) {
  apps_to_check_.push_back(new_application);
  return new_application;
}

// 查看队首的待审核申请，返回申请指针
// 无返回空指针作为异常值
JoinApplication* Platform::ViewAnUncheckApp() {
  if (apps_to_check_.size() != 0) {
    return apps_to_check_.front();
  } else {
    return NULL;
  }
}

// 将队首的待审核队列弹出，并将其返回
JoinApplication* Platform::HoldAnApp() {
  JoinApplication* app_held = apps_to_check_.front();
  apps_to_check_.pop_front();
  return app_held;
}

// 将被抽出/队首的申请审核
void Platform::CheckAnApp(JoinApplication* app) {
  apps_checked_.push_back(app);
  app->GetFirstAccount()->ActiveAccount();
  hotel_list_.push_back(reinterpret_cast<Hotel*>(&(app->GetBusinessBelong())));
}

void Platform::CheckAnApp() {
  JoinApplication* app_checked = apps_to_check_.front();
  app_checked->Passed();
  apps_to_check_.pop_front();
  apps_checked_.push_back(app_checked);
  app_checked->GetFirstAccount()->ActiveAccount();
  hotel_list_.push_back(reinterpret_cast<Hotel*>(&(app_checked->GetBusinessBelong())));
}

// 拒绝申请，返回申请指针
// 删除该指针指向的内容
JoinApplication* Platform::RejectAnApp(JoinApplication* app) {
  delete app;
  return app;
}

//***************************************************************************

//********************数据库连接时使用******************************************

// 得到订单总组，更新数据库用
// 用迭代器遍历三个booking表中综合并返回
list<AbstractBooking*> Platform::GetBookings() {
  list<AbstractBooking*> total;
  for (deque<AbstractBooking*>::iterator find = bookings_wait_to_check_.begin();
      find != bookings_wait_to_check_.end();
      ++ find) {
    total.push_back(*find);
  }
  for (list<AbstractBooking*>::iterator find = bookings_checked_.begin();
    find != bookings_checked_.end();
    ++find) {
    total.push_back(*find);
  }
  for (list<AbstractBooking*>::iterator find = bookings_wait_to_review_.begin();
    find != bookings_wait_to_review_.end();
    ++find) {
    total.push_back(*find);
  }
  return total;
}

// 得到申请总组,更新数据库用
// 用迭代器遍历两个application表中综合返回
list<JoinApplication*> Platform::GetApps() {
  list<JoinApplication*> total;
  for (deque<JoinApplication*>::iterator find = apps_to_check_.begin();
    find != apps_to_check_.end();
    ++find) {
    total.push_back(*find);
  }
  for (deque<JoinApplication*>::iterator find = apps_checked_.begin();
    find != apps_checked_.end();
    ++find) {
    total.push_back(*find);
  }
  return total;
}

// 根据数据库信息生成managerlist， 载入数据库数据用，全部成功返回true
bool Platform::InsertManager(const string& username, const string& password, const string& credit_code) {
  for (vector<Hotel*>::iterator find = hotel_list_.begin();
        find != hotel_list_.end(); ++find) {
       if ((*find)->GetCreditCode() == credit_code) {
       HotelManager* new_one = new HotelManager(username,
                                                password,
                                                **find);
       hotelmanager_list_.push_back(new_one);
       return true;
     }
  }
  return false;
}

// 根据数据库信息生成roomlist， 载入数据库数据用，全部成功返回true
bool Platform::InsertRoom(const string& credit_code, const string& room_number,
                         const string& room_type, int price, int bed_type) {
  for (vector<Hotel*>::iterator find = hotel_list_.begin();
        find != hotel_list_.end(); ++find) {
    if ((*find)->GetCreditCode() == credit_code) {
      int floor = QString::fromStdString((room_number.substr(0,1))).toInt();
      Room* new_one = new Room(room_type, room_number, 20, floor,
                            static_cast<Room::BedType>(bed_type), true, true, false,
                            price);
      (*find)->AddOneRoom(*new_one);
      return true;
    }
  }
  return false;
}

// 根据数据库信息生成bookinglist， 载入数据库数据用，全部成功返回true
// 程序通过各类迭代器进行数据更新，需要保证按照数据库主键到外键的调用顺序更新
// 参考btripdatabase
// 这是根据读取情况进行模拟操作将booking插入到队形的列表中
bool Platform::InsertBooking(int serial, const QDate& create_date, const QDate& check_in,
                const QDate& check_out, int unit_price, int share, bool is_payed,
                bool is_checked, bool is_accepted, bool is_finish,
                const string& customer_name, const string& hotel_code) {
  vector<Hotel*>::iterator find_hotel;
  for (find_hotel = hotel_list_.begin();
      find_hotel != hotel_list_.end(); ++find_hotel) {
    if ((*find_hotel)->GetCreditCode() == hotel_code) {
      break;
    }
  }
  if (find_hotel == hotel_list_.end()) {
    return false;
  }
  vector<Customer*>::iterator find_customer;
  for (find_customer = customer_list_.begin();
      find_customer != customer_list_.end(); ++find_customer) {
    if ((*find_customer)->GetUsername() == customer_name) {
      break;
    }
  }
  if (find_customer == customer_list_.end()) {
    return false;
  }
  int price_pernight = unit_price / check_in.daysTo(check_out);
  HotelBooking* new_one = new HotelBooking(create_date, price_pernight, 1, **find_customer,
                               *this, **find_hotel, check_in, check_out);
  string room_type;
  string room_number;
  vector<Room>::iterator find_room = (*find_hotel)->ManageRooms().begin();
  for (; find_room != (*find_hotel)->ManageRooms().end(); ++find_room) {
    int price_delta = abs(find_room->GetPricePerNight() - unit_price / check_in.daysTo(check_out));
    if (price_delta <= 10) {
      room_type = find_room->GetRoomTypeDefinedByHotel();
      break;
    }
  }
  new_one->SetRoomType(room_type);
  if (!is_payed) {

    (*find_customer)->BookRoom(create_date, **find_hotel, room_type, 1, *this,
                                check_in,check_out);
    return true;
  }
  new_one->BePayed(65535);
  new_one->SetSerialNumber(serial);
  if (!is_checked) {
    bookings_wait_to_check_.push_back(new_one);
    return true;
  }
  new_one->BeChecked();
  new_one->SetSharePercnet(share);
  bookings_checked_.push_back(new_one);
  if (!is_accepted) {
    (*find_hotel)->ReceiveABooking(new_one);
    return true;
  }
  new_one->BeAccepted();
  (*find_hotel)->RoomsAvailabel(check_in,check_out,room_type,&room_number);
  new_one->SetRoomNumber(room_number);
  int i = 0;
  for (; i < (*find_hotel)->ManageRooms().size(); i++) {
    if (room_number == (*find_hotel)->ManageRooms()[i].GetRoomNumber()) {
      break;
    }
  }
  (*find_hotel)->ManageRooms()[i].BeBooked(check_in,check_out);
  if (!is_finish) {
    (*find_hotel)->AcceptABooking(new_one);
    return true;
  }
  (*find_hotel)->AcceptABooking(new_one);
  (*find_hotel)->FinishABooking((*find_hotel)->ViewBookingsUnfinished().size() - 1);
  return true;
}

// 根据数据库信息生成applicationlist， 载入数据库数据用，全部成功返回true
bool Platform::InsertApplicatioin(const string& credit_code, bool is_pass, int type, const QDate& created_date) {
  vector<Hotel*>::iterator find_hotel;
  for (find_hotel = hotel_list_.begin();
      find_hotel != hotel_list_.end(); ++find_hotel) {
    if ((*find_hotel)->GetCreditCode() == credit_code) {
      break;
    }
  }
  if (find_hotel == hotel_list_.end()) {
    return false;
  }
  JoinApplication* new_one = new JoinApplication(**find_hotel, *this, created_date,
                                 static_cast<JoinApplication::Applicationtype>(type));
  if (is_pass) {
    apps_checked_.push_back(new_one);
  } else {
    apps_to_check_.push_back(new_one);
  }
  return true;
}






