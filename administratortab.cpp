//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：administratortab.cpp
// 当前版本：1.0
// 摘要：本文件中实现对AdministratorTab类成员函数的定义。
// 作者：吴文绪
// 完成日期：2018.7.26
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

// AdministratorTab类的构造函数，在qt的基础上增加了账户员指针，用于连接ui与底层。
// 构造时亦调用了私有成员函数，对申请和订单界面进行刷新。同时初始化绩效审核指标
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

// 私有成员函数
// 刷新申请管理界面。主要调用PlatformAdministrator对于申请的查看函数。并将
// JoinApplication的各个数据转化为页面的显示。函数中主要运用底层逻辑中传出空指针表述的
// 特殊状态，来对修改对应的label内容。同时函数中使用dynamic_cast对申请人的身份进行转化
// 判断，保证了可以在维持源代码的基础上，若有增加Hotel类以外的商家申请时，能重用此代码
// 进行快速修改。在构造和按键按下后对应地被调用
void AdministratorTab::RefreshApp() {

// 更新application标签页上的绩效显示空间的状态；
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

// 对dynamic_cast后的指针进行判断，若为HotelApplication则对其特有数据进行更新
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

// 利用迭代器对待申请酒店的房间进行遍历，显示房间信息，建立房间子树
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

// 建立酒店政策子树 
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
// 展开所有树，方便管理员查看
  ui->app_treewidget->expandAll();
}

// 将bool转化为QString返回，返回为“yes” “no“ 用于界面上的数据显示
QString AdministratorTab::BoolToString(bool bool_) {
  if (bool_) {
    return tr("yes");
  } else {
    return tr("no");
  }
}

// 将Room类枚举型转化为QString返回，返回为"single", "double","king size",
// "triple and more"。用于界面上的数据显示
QString AdministratorTab::EnumBedTypeToString(Room::BedType bed_type) {
  switch (bed_type) {
  case Room::SINGLE: return tr("single");
  case Room::DOUBLE: return tr("double");
  case Room::KINGSIZE: return tr("king size");
  case Room::TRIPLEANDMORE: return tr("triple and more");
  default: return tr("error");
  }
}

// hold_app_button点击信号的对应槽函数，调用PlatformAdministrator的对应函数进行工作.
// 同时通过返回值的判定，显示错误信息，防止误操作。
// hold_app_button在点击后会变为拒绝按钮，对应调用拒绝申请的函数
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

// check_app_button点击信号的对应槽函数，调用PlatformAdministrator的对应函数进行工作
// 在本机模拟多机操作时不会存在多个业务员对申请同时审核，实际不会触发最后的分支
// 同时将工作结果记入账户绩效，以备显示
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

// application 操作部分
//*****************************************************************************
// booking 操作部分

// 私有成员函数
// 刷新订单管理界面。主要调用PlatformAdministrator对于申请的查看函数。并将
// AbstractBooking的各个数据转化为页面的显示。函数中主要运用底层逻辑中传出空指针表述的
// 特殊状态，来对修改对应的label内容。同时函数中使用dynamic_cast对订单的类型进行转化
// 判断，保证了可以在维持源代码的基础上，若有增加HotelBooking类以外的订单时，能重用此代
// 码进行快速修改。在构造和按键按下后对应地被调用。
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

//用dynamic_cast的转换结果判断订单类型，显示HotelBooking的特有信息
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

// hold_booking_button点击信号的对应槽函数，调用PlatformAdministrator的对应函数进行
// 工作。同时通过返回值的判定，显示错误信息，防止误操作。
// hold_booking_button在点击后会变为拒绝按钮，对应调用拒绝申请的函数
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

// check_app_button点击信号的对应槽函数，调用PlatformAdministrator的对应函数进行工作
// 在本机模拟多机操作时不会存在多个业务员对申请同时审核，实际不会触发 other 分支
// 同时将工作结果记入账户绩效，以备显示
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
