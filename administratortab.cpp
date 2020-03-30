//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�administratortab.cpp
// ��ǰ�汾��1.0
// ժҪ�����ļ���ʵ�ֶ�AdministratorTab���Ա�����Ķ��塣
// ���ߣ�������
// ������ڣ�2018.7.26
//****************************************************************************

#include "administratortab.h"
#include "ui_administratortab.h"

#include "abstractbooking.h"
#include "abstractuser.h"
#include "amenities.h"
#include "business.h"
#include "customer.h"
#include "hotel.h"
#include "hotelbooking.h"
#include "hotelmanager.h"
#include "hotelpolicies.h"
#include "joinapplication.h"
#include "license.h"
#include "platform.h"
#include "platformadministrator.h"
#include "room.h"

extern Platform platform;

// AdministratorTab��Ĺ��캯������qt�Ļ������������˻�Աָ�룬��������ui��ײ㡣
// ����ʱ�������˽�г�Ա������������Ͷ����������ˢ�¡�ͬʱ��ʼ����Ч���ָ��
// booking_count_ share_count_ app_count_
AdministratorTab::AdministratorTab(PlatformAdministrator* current_account,
  QWidget *parent)
  : current_account_(current_account),
  QTabWidget(parent),
  ui(new Ui::AdministratorTab) {
  ui->setupUi(this);
  app_displayed_ = NULL;
  is_app_holding_ = false;
  app_count_ = 0;
  RefreshApp();

  booking_displayed_ = NULL;
  is_booking_holding_ = false;
  booking_count_ = 0;
  share_count_ = 0;
  RefreshBooking();
}

AdministratorTab::~AdministratorTab() {
  delete ui;
}

// ˽�г�Ա����
// ˢ�����������档��Ҫ����PlatformAdministrator��������Ĳ鿴����������
// JoinApplication�ĸ�������ת��Ϊҳ�����ʾ����������Ҫ���õײ��߼��д�����ָ�������
// ����״̬�������޸Ķ�Ӧ��label���ݡ�ͬʱ������ʹ��dynamic_cast�������˵���ݽ���ת��
// �жϣ���֤�˿�����ά��Դ����Ļ����ϣ���������Hotel��������̼�����ʱ�������ô˴���
// ���п����޸ġ��ڹ���Ͱ������º��Ӧ�ر�����
void AdministratorTab::RefreshApp() {

// ����application��ǩҳ�ϵļ�Ч��ʾ�ռ��״̬��
  ui->error_application_label->hide();
  ui->app_num_label->setText(QString("%1").arg(app_count_));
  ui->app_treewidget->clear();
  app_displayed_ = platform.ViewAnUncheckApp();
  if (app_displayed_ == NULL) {
    ui->error_application_label->setText(tr("no applilcation to check"));
    ui->error_application_label->show();
    return;
  }

  Hotel* hotel_applying = dynamic_cast<Hotel*>(&(app_displayed_->GetBusinessBelong()));
  QTreeWidgetItem* created_date = new QTreeWidgetItem(ui->app_treewidget,
                                      QStringList(QString(tr("created date: ")
                              + app_displayed_->GetCreatedDate().toString())));
  if (hotel_applying != NULL) {
    QTreeWidgetItem* app_type = new QTreeWidgetItem(ui->app_treewidget,
      QStringList(QString(tr("app type: ") + tr("Hotel"))));
  }
  QTreeWidgetItem* credit_code = new QTreeWidgetItem(ui->app_treewidget,
                                 QStringList(QString(tr("credit code: ")
    + QString::fromStdString(app_displayed_->GetBusinessBelong().GetCreditCode()))));

// ��dynamic_cast���ָ������жϣ���ΪHotelApplication������������ݽ��и���
  if (hotel_applying != NULL) {
    QTreeWidgetItem* name = new QTreeWidgetItem(ui->app_treewidget,
      QStringList(QString(tr("name: ")
      + QString::fromStdString(hotel_applying->GetName()))));
    QTreeWidgetItem* city = new QTreeWidgetItem(ui->app_treewidget,
      QStringList(QString(tr("city: ")
      + QString::fromStdString(hotel_applying->GetCity()))));
    QTreeWidgetItem* area = new QTreeWidgetItem(ui->app_treewidget,
      QStringList(QString(tr("area: ")
      + QString::fromStdString(hotel_applying->GetArea()))));
    QTreeWidgetItem* rooms = new QTreeWidgetItem(ui->app_treewidget,
      QStringList(QString(tr("rooms"))));
    QTreeWidgetItem* policies = new QTreeWidgetItem(ui->app_treewidget,
      QStringList(QString(tr("policies"))));
    QTreeWidgetItem* amenities = new QTreeWidgetItem(ui->app_treewidget,
      QStringList(QString(tr("amenities"))));

// ���õ������Դ�����Ƶ�ķ�����б�������ʾ������Ϣ��������������
    vector<Room>::iterator visit_all_room = hotel_applying->ManageRooms().begin();
    for (;visit_all_room != hotel_applying->ManageRooms().end(); ++visit_all_room) {
      QTreeWidgetItem* room = new QTreeWidgetItem(rooms,
        QStringList(QString(
        QString::fromStdString(visit_all_room->GetRoomNumber()))));
      QTreeWidgetItem* self_type = new QTreeWidgetItem(room,
        QStringList(QString(tr("type defined by hotel: ")
        + QString::fromStdString(visit_all_room->GetRoomTypeDefinedByHotel()))));
      QTreeWidgetItem* size = new QTreeWidgetItem(room,
        QStringList(QString(tr("size: ")
        + QString::number(visit_all_room->GetSize()))));
      QTreeWidgetItem* bed_type = new QTreeWidgetItem(room,
        QStringList(QString(tr("bed type: ")
        + EnumBedTypeToString(visit_all_room->GetBedType()))));
      QTreeWidgetItem* is_window = new QTreeWidgetItem(room,
        QStringList(QString(tr("window: ")
        + BoolToString(visit_all_room->IsWithWindow()))));
      QTreeWidgetItem* is_bathroom = new QTreeWidgetItem(room,
        QStringList(QString(tr("bathroom: ")
        + BoolToString(visit_all_room->IsWithBathRoom()))));
      QTreeWidgetItem* is_add_bed = new QTreeWidgetItem(room,
        QStringList(QString(tr("able to add bed: ")
        + BoolToString(visit_all_room->IsAbleToAddBed()))));
    }

// �����Ƶ��������� 
    HotelPolicies* the_policies = &(hotel_applying->GetHotelPolicies());
    QTreeWidgetItem* is_free_breakfast = new QTreeWidgetItem(policies,
      QStringList(QString(tr("free break fast: ")
      + BoolToString(the_policies->IsFreeBreakfast()))));
    QTreeWidgetItem* is_pet_allowed = new QTreeWidgetItem(policies,
      QStringList(QString(tr("allow pet: ")
      + BoolToString(the_policies->IsPetAllowed()))));
    QTreeWidgetItem* check_in = new QTreeWidgetItem(policies,
      QStringList(QString(tr("check in time: ")
      + QString::number(the_policies->GetCheckInTime())
      + ":00")));
    QTreeWidgetItem* check_out = new QTreeWidgetItem(policies,
      QStringList(QString(tr("check out time: ")
      + QString::number(the_policies->GetCheckOutTime())
      + ":00")));
    QTreeWidgetItem* max_children = new QTreeWidgetItem(policies,
      QStringList(QString(tr("max child(ren) per adult: ")
      + QString::number(the_policies->GetMaxChildrenPerAdult()))));
    QTreeWidgetItem* other = new QTreeWidgetItem(policies,
      QStringList(QString(tr("other(html): ")
      + QString::fromStdString(the_policies->GetOthers()))));

    Amenities* the_amenities = &(hotel_applying->GetAmenities());
    QTreeWidgetItem* is_free_wifi = new QTreeWidgetItem(amenities,
      QStringList(QString(tr("free wifi: ")
      + BoolToString(the_amenities->IsFreeWifi()))));
    QTreeWidgetItem* is_pickup = new QTreeWidgetItem(amenities,
      QStringList(QString(tr("airport pickup: ")
      + BoolToString(the_amenities->IsAirportPickup()))));
    QTreeWidgetItem* is_free_park = new QTreeWidgetItem(amenities,
      QStringList(QString(tr("free parking: ")
      + BoolToString(the_amenities->IsFreeParking()))));
    QTreeWidgetItem* is_24_front = new QTreeWidgetItem(amenities,
      QStringList(QString(tr("24 hours front: ")
      + BoolToString(the_amenities->IsFront24Hours()))));
    QTreeWidgetItem* is_non_somking = new QTreeWidgetItem(amenities,
      QStringList(QString(tr("non smoking floor: ")
      + BoolToString(the_amenities->IsNonSomkingFloor()))));
    QTreeWidgetItem* is_storage = new QTreeWidgetItem(amenities,
      QStringList(QString(tr("luggage storage: ")
      + BoolToString(the_amenities->IsLuggageStorage()))));
    QTreeWidgetItem* is_wake_up = new QTreeWidgetItem(amenities,
      QStringList(QString(tr("wake up service: ")
      + BoolToString(the_amenities->IsWakeUp()))));
    QTreeWidgetItem* is_cloth_service = new QTreeWidgetItem(amenities,
      QStringList(QString(tr("cloth service: ")
      + BoolToString(the_amenities->IsClothService()))));
  }
// չ�����������������Ա�鿴
  ui->app_treewidget->expandAll();
}

// ��boolת��ΪQString���أ�����Ϊ��yes�� ��no�� ���ڽ����ϵ�������ʾ
QString AdministratorTab::BoolToString(bool bool_) {
  if (bool_) {
    return tr("yes");
  } else {
    return tr("no");
  }
}

// ��Room��ö����ת��ΪQString���أ�����Ϊ"single", "double","king size",
// "triple and more"�����ڽ����ϵ�������ʾ
QString AdministratorTab::EnumBedTypeToString(Room::BedType bed_type) {
  switch (bed_type) {
  case Room::SINGLE: return tr("single");
  case Room::DOUBLE: return tr("double");
  case Room::KINGSIZE: return tr("king size");
  case Room::TRIPLEANDMORE: return tr("triple and more");
  default: return tr("error");
  }
}

// hold_app_button����źŵĶ�Ӧ�ۺ���������PlatformAdministrator�Ķ�Ӧ�������й���.
// ͬʱͨ������ֵ���ж�����ʾ������Ϣ����ֹ�������
// hold_app_button�ڵ������Ϊ�ܾ���ť����Ӧ���þܾ�����ĺ���
void AdministratorTab::on_hold_app_button_clicked() {
  if (!is_app_holding_) {
    if (current_account_->HoldAnApp() == NULL) {
      ui->error_application_label->setText(tr("application don't exsist"));
      ui->error_application_label->show();
      return;
    }
    ui->hold_app_button->setText(tr("Reject"));
    is_app_holding_ = true;
    return;
  } else {
    current_account_->RejectAnApp(app_displayed_);
    ui->hold_app_button->setText(tr("Hold"));
    is_app_holding_ = false;
    app_count_++;
    RefreshApp();
  }
}

// check_app_button����źŵĶ�Ӧ�ۺ���������PlatformAdministrator�Ķ�Ӧ�������й���
// �ڱ���ģ��������ʱ������ڶ��ҵ��Ա������ͬʱ��ˣ�ʵ�ʲ��ᴥ�����ķ�֧
// ͬʱ��������������˻���Ч���Ա���ʾ
void AdministratorTab::on_check_app_button_clicked() {
  if (app_displayed_ == NULL) {
    RefreshApp();
    return;
  }
  if (is_app_holding_) {
    current_account_->CheckAnApp(app_displayed_);
    ui->hold_app_button->setText(tr("Hold"));
    is_app_holding_ = false;
  } else {
    if (!current_account_->CheckAnApp()) {
      ui->error_application_label->setText(tr("app has been checked by other"));
      ui->error_application_label->show();
      return;
    }
  }
  app_count_++;
  RefreshApp();
}

// application ��������
//*****************************************************************************
// booking ��������

// ˽�г�Ա����
// ˢ�¶���������档��Ҫ����PlatformAdministrator��������Ĳ鿴����������
// AbstractBooking�ĸ�������ת��Ϊҳ�����ʾ����������Ҫ���õײ��߼��д�����ָ�������
// ����״̬�������޸Ķ�Ӧ��label���ݡ�ͬʱ������ʹ��dynamic_cast�Զ��������ͽ���ת��
// �жϣ���֤�˿�����ά��Դ����Ļ����ϣ���������HotelBooking������Ķ���ʱ�������ô˴�
// ����п����޸ġ��ڹ���Ͱ������º��Ӧ�ر����á�
void AdministratorTab::RefreshBooking() {
  ui->error_booking_label->hide();
  ui->total_check_label->setText(tr("Total check %1 booking(s)").arg(booking_count_));
  ui->total_share_label->setText(tr("Total share: ")
                        + QString::number(share_count_, 'f', 2)
                        + tr(" money"));
  ui->booking_list->clear();
  booking_displayed_ = platform.ViewAnUncheckedBooking();
  if (booking_displayed_ == NULL) {
    ui->error_booking_label->setText(tr("no booking to check"));
    ui->error_booking_label->show();
    return;
  }

  QTreeWidgetItem* serial_number = new QTreeWidgetItem(ui->booking_list,
    QStringList(QString(tr("serial number: "))
    + QString::number(booking_displayed_->GetSerialNumber())));
  QTreeWidgetItem* created_date = new QTreeWidgetItem(ui->booking_list,
    QStringList(QString(tr("created date: ")
    + booking_displayed_->GetCreatedDate().toString())));
  QTreeWidgetItem* credit_code = new QTreeWidgetItem(ui->booking_list,
    QStringList(QString(tr("credit code: ")
    + QString::fromStdString(booking_displayed_->GetBusiness().GetCreditCode()))));
  HotelBooking* hotel_booking = dynamic_cast<HotelBooking*>(booking_displayed_);

//��dynamic_cast��ת������ж϶������ͣ���ʾHotelBooking��������Ϣ
  if (hotel_booking != NULL) {
    QTreeWidgetItem* hotel_name = new QTreeWidgetItem(ui->booking_list,
      QStringList(QString(tr("hotel name: ")
      + QString::fromStdString(hotel_booking->GetHotelName()))));
    QTreeWidgetItem* check_in = new QTreeWidgetItem(ui->booking_list,
      QStringList(QString(tr("check in date: ")
      + hotel_booking->GetCheckInDate().toString())));
    QTreeWidgetItem* check_out = new QTreeWidgetItem(ui->booking_list,
      QStringList(QString(tr("check out date: ")
      + hotel_booking->GetCheckOutDate().toString())));
    QTreeWidgetItem* total_price = new QTreeWidgetItem(ui->booking_list,
      QStringList(QString(tr("total price: ")
      + QString::number(hotel_booking->GetAmount()
      * hotel_booking->GetUnitPrice()))));

  }
}

// hold_booking_button����źŵĶ�Ӧ�ۺ���������PlatformAdministrator�Ķ�Ӧ��������
// ������ͬʱͨ������ֵ���ж�����ʾ������Ϣ����ֹ�������
// hold_booking_button�ڵ������Ϊ�ܾ���ť����Ӧ���þܾ�����ĺ���
void AdministratorTab::on_hold_booking_button_clicked() {
  if (!is_booking_holding_) {
    if (current_account_->HoldABooking() == NULL) {
      ui->error_booking_label->setText(tr("booking don't exsist"));
      ui->error_booking_label->show();
      return;
    }
    ui->hold_booking_button->setText(tr("Reject"));
    is_booking_holding_ = true;
    return;
  } else {
    current_account_->RejectAbooking(booking_displayed_);
    ui->hold_booking_button->setText(tr("Hold"));
    is_booking_holding_ = false;
    booking_count_++;
    RefreshBooking();
  }
}

// check_app_button����źŵĶ�Ӧ�ۺ���������PlatformAdministrator�Ķ�Ӧ�������й���
// �ڱ���ģ��������ʱ������ڶ��ҵ��Ա������ͬʱ��ˣ�ʵ�ʲ��ᴥ�� other ��֧
// ͬʱ��������������˻���Ч���Ա���ʾ
void AdministratorTab::on_check_button_clicked() {
  if (booking_displayed_ == NULL) {
    RefreshApp();
    return;
  }
  if (is_booking_holding_) {
    current_account_->CheckABooking(ui->share_spinbox->value(), booking_displayed_);
    ui->hold_booking_button->setText(tr("Hold"));
    is_booking_holding_ = false;
  } else {
    if (!current_account_->CheckABooking(ui->share_spinbox->value())) {
      ui->error_booking_label->setText(tr("booking has been checked by other"));
      ui->error_booking_label->show();
      return;
    }
    booking_count_++;
    share_count_ += static_cast<float>(booking_displayed_->GetSharePercent()) / 100
      * booking_displayed_->GetUnitPrice()
      * booking_displayed_->GetAmount();
    const Hotel* target_hotel_is_exsist =
      dynamic_cast<const Hotel*>(&(booking_displayed_->GetBusiness()));
    if (target_hotel_is_exsist != NULL) {
      Hotel* target_hotel = const_cast<Hotel*>(target_hotel_is_exsist);
      target_hotel->ReceiveABooking(booking_displayed_);
    }
    RefreshBooking();
  }
}
