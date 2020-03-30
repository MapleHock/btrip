//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�platform.cpp
// ��ǰ�汾��1.0
// ժҪ�����ļ���ʵ��Platform��ĳ�Ա�����Ķ��塣����Ϊ���������ݴ��ݵĺ��ģ�Ҳ��������
// ������Ҫ��һ��
// ���ߣ�������
// ������ڣ�2018.7.29
//****************************************************************************

#include "platform.h"

#include "abstractuser.h"
#include "customer.h"
#include "hotelmanager.h"
using std::string;

Platform::Platform() {}

Platform::~Platform() {}

// �����û�����ע�Ტ��������Ӧ����
// ���ڶ����Ⱥ����⣬�������reinterper_cast������usertype���м���
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

//***********************ȡֵ����**********************************************
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

//******************�������������**********************************************
// �������������˶��У�������ˮ�ţ����ض���ָ��  
AbstractBooking* Platform::GetAUncheckedBooking(AbstractBooking* new_booking) {
  if (ViewLatestBooking() == NULL) {
    new_booking->SetSerialNumber(1);
  } else {
    new_booking->SetSerialNumber(ViewAnUncheckedBooking()->GetSerialNumber() + 1);
  }
  bookings_wait_to_check_.push_back(new_booking);
  return new_booking;
}

// �鿴���׵�δ��˶��������ض���ָ��
AbstractBooking* Platform::ViewAnUncheckedBooking() const {
  if (bookings_wait_to_check_.size() != 0) {
    return bookings_wait_to_check_.front();
  } else {
    return NULL;
  }
}

// �鿴��β��δ��˶��������ض���ָ��
AbstractBooking* Platform::ViewLatestBooking() const {
  if (bookings_wait_to_check_.size() != 0) {
    return bookings_wait_to_check_.back();
  } else {
    return NULL;
  }
}

// ��δ��˶��еĶ��׶������������ض���ָ��
AbstractBooking* Platform::HoldABooking() {
  AbstractBooking* booking_held = bookings_wait_to_check_.front();
  bookings_wait_to_check_.pop_front();
  return booking_held;
}

// ��˶�������Ϊ�����������ó��
// ������ʽ�ֱ���ԶԶ��׶���ֱ����ˣ��Գ���Ķ�������ˣ����ض���ָ��
// �������޷��ҵ��Ƿ��ؿ�ָ��Ϊ�쳣ֵ
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

// �ܾ����������ض���ָ�룬
// ��������ˮ����0��Ϊһ��ֵ�����ݿ�����ʱ����
AbstractBooking* Platform::RejectABooking(AbstractBooking* booking) {
  booking->SetSerialNumber(0);
  return booking;
}

// �õ��̼ҷ����Ķ��������ض���ָ��
// ���ܷ��ؿ�ָ��Ϊ��Ϊ�쳣ֵ
// �ڶ����޷��ҵ�������߱��̼Ҿܾ�ʱ�᷵�ؿ�ָ��
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

// �õ��û������Ķ��������¾Ƶ����ۣ����ض���ָ��
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

// �õ����벢����������˶��У���������ָ��
JoinApplication* Platform::GetAnApplication(JoinApplication* new_application) {
  apps_to_check_.push_back(new_application);
  return new_application;
}

// �鿴���׵Ĵ�������룬��������ָ��
// �޷��ؿ�ָ����Ϊ�쳣ֵ
JoinApplication* Platform::ViewAnUncheckApp() {
  if (apps_to_check_.size() != 0) {
    return apps_to_check_.front();
  } else {
    return NULL;
  }
}

// �����׵Ĵ���˶��е����������䷵��
JoinApplication* Platform::HoldAnApp() {
  JoinApplication* app_held = apps_to_check_.front();
  apps_to_check_.pop_front();
  return app_held;
}

// �������/���׵��������
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

// �ܾ����룬��������ָ��
// ɾ����ָ��ָ�������
JoinApplication* Platform::RejectAnApp(JoinApplication* app) {
  delete app;
  return app;
}

//***************************************************************************

//********************���ݿ�����ʱʹ��******************************************

// �õ��������飬�������ݿ���
// �õ�������������booking�����ۺϲ�����
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

// �õ���������,�������ݿ���
// �õ�������������application�����ۺϷ���
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

// �������ݿ���Ϣ����managerlist�� �������ݿ������ã�ȫ���ɹ�����true
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

// �������ݿ���Ϣ����roomlist�� �������ݿ������ã�ȫ���ɹ�����true
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

// �������ݿ���Ϣ����bookinglist�� �������ݿ������ã�ȫ���ɹ�����true
// ����ͨ������������������ݸ��£���Ҫ��֤�������ݿ�����������ĵ���˳�����
// �ο�btripdatabase
// ���Ǹ��ݶ�ȡ�������ģ�������booking���뵽���ε��б���
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

// �������ݿ���Ϣ����applicationlist�� �������ݿ������ã�ȫ���ɹ�����true
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






