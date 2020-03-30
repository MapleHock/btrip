#include "hotelapplicationstep.h"
#include "ui_hotelapplicationstep.h"

#include <QMessageBox>

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

// 构造函数，设定表头，隐藏错误label，设定只能输入文字
HotelApplicationStep::HotelApplicationStep(QWidget *parent) :
  QWizard(parent),
  ui(new Ui::HotelApplicationStep) {
  ui->setupUi(this);
  ui->error_label_info->hide();
  // set for room page
  ui->error_label_room->hide();
  QStringList header_labels;
  header_labels << tr("room number") << tr("price") << tr("bed type")
    << tr("room type") << tr("floor") << tr("size")
    << tr("window") << tr("bathroom") << tr("add bed");
  ui->rooms_list->setHorizontalHeaderLabels(header_labels);
  ui->rooms_list->setSelectionBehavior(QAbstractItemView::SelectRows);
  //ui->rooms_list->resizeColumnsToContents();
  ui->price_lineedit->setValidator(new QIntValidator(0, 65535, this));
  ui->copy_min_num_lineedit->setValidator(new QIntValidator(0, 65535, this));
  ui->copy_min_num_lineedit->setValidator(new QIntValidator(0, 65535, this));
  ui->copy_floor_lineedit->setValidator(new QIntValidator(0, 65535, this));
}

HotelApplicationStep::~HotelApplicationStep() {
  delete ui;
}

// 翻页时用于检测必填信息是否完成的函数，若未完成调用back()并显示错误label
void HotelApplicationStep::on_HotelApplicationStep_currentIdChanged(int id) {
  Page current_page = Page(id);
  switch (current_page) {
  case HOTELINFO: {
    if (ui->reject_radio->isChecked()) {
      back();
    }
    break;
  }
  case ROOM: {
    if (ui->name_lineedit->text().isEmpty() ||
      ui->city_lineedit->text().isEmpty() ||
      ui->area_lineedit->text().isEmpty() ||
      ui->credit_lineedit->text().isEmpty()) {
      ui->error_label_info->setText(tr("please compelete the information"));
      ui->error_label_info->show();
      back();
    }
    break;
  }
  case FINISH: {
    if (ui->rooms_list->rowCount() == 0) {
      ui->error_label_room->setText(tr("please compelete the information"));
      ui->error_label_room->show();
      back();
    } else {
      ui->username_label->setText(ui->name_lineedit->text());
    }
    break;
  }
  default:
    break;
  }

}

// 检测是否是按下fninsh退出
// 若为1按照所填信息提交申请到平台
void HotelApplicationStep::on_HotelApplicationStep_finished(int result) {
  // 0 for cancel 1 for finish
  if (result == 1) {
    Hotel* new_hotel = new Hotel(ui->name_lineedit->text().toStdString(),
      ui->city_lineedit->text().toStdString(),
      ui->area_lineedit->text().toStdString(),
      ui->credit_lineedit->text().toStdString());
    JoinApplication* new_application = new JoinApplication(
      *new_hotel,
      platform,
      QDate::currentDate(),
      JoinApplication::HOTEL);
    platform.GetAnApplication(Business::Apply(new_application));
    HotelManager* new_manager = new HotelManager(
      new_application->GetFirstAccount()->GetUsername(),
      new_application->GetFirstAccount()->GetPassword(),
      *new_hotel);
    new_application->ResetFirstAccount(new_manager);
    new_manager->BlockAccount();
    platform.GetHotelManagerList().push_back(new_manager);
    // set Hotel Policies
    new_hotel->GetHotelPolicies().SetCheckIntime(ui->check_in_timeedit->time().hour());
    new_hotel->GetHotelPolicies().SetCheckOutTime(ui->check_out_timeedit->time().hour());
    new_hotel->GetHotelPolicies().SetIsFreeBreakfast(ui->is_free_breakfast_checkbox->isChecked());
    new_hotel->GetHotelPolicies().SetIsPetAllowed(ui->is_pet_allow_checkbox->isChecked());
    new_hotel->GetHotelPolicies().SetMaxChildrenPerAdult(ui->children_adult_spinbox->value());
    new_hotel->GetHotelPolicies().SetOthers(ui->others_textedit->toHtml().toStdString());

    // set Amenities
    new_hotel->GetAmenities().SetAirportPickup(ui->airport_checkbox->isChecked());
    new_hotel->GetAmenities().SetClothService(ui->cloth_service_checkbox->isChecked());
    new_hotel->GetAmenities().SetFreeParking(ui->parking_checkbox->isChecked());
    new_hotel->GetAmenities().SetFreeWifi(ui->wifi_checkbox->isChecked());
    new_hotel->GetAmenities().SetFront24Hours(ui->front24_checkbox->isChecked());
    new_hotel->GetAmenities().SetLuggageStorage(ui->luggage_storage_checkbox->isChecked());
    new_hotel->GetAmenities().SetNonSomkingFloor(ui->nonsomking_checkbox->isChecked());
    new_hotel->GetAmenities().SetWakeUp(ui->wakeup_checkbox->isChecked());

    // order:room number|price|bed type|room type|floor|size|window|bathroom|add bed
    for (int i = 0; i < ui->rooms_list->rowCount(); i++) {
      Room new_room(ui->rooms_list->item(i, 3)->text().toStdString(),
        ui->rooms_list->item(i, 0)->text().toStdString(),
        ui->rooms_list->item(i, 5)->text().toInt(),
        ui->rooms_list->item(i, 4)->text().toInt(),
        QStringToBedType(ui->rooms_list->item(i, 2)->text()),
        QstringToBool(ui->rooms_list->item(i, 6)->text()),
        QstringToBool(ui->rooms_list->item(i, 7)->text()),
        QstringToBool(ui->rooms_list->item(i, 8)->text()),
        ui->rooms_list->item(i, 1)->text().toInt());
      new_hotel->AddOneRoom(new_room);
    }
  }
}

// 将房间信息移动到表
void HotelApplicationStep::on_add_button_clicked() {
  if (ui->floor_spinbox->value() == 0 ||
    ui->price_lineedit->text().isEmpty() ||
    ui->room_number_lineedit->text().isEmpty() ||
    ui->self_define_type_lineedit->text().isEmpty() ||
    ui->size_spinox->value() == 0 ||
    ui->bed_type_combobox->currentIndex() == -1) {
    ui->error_label_room->setText(tr("please compelete the information"));
    ui->error_label_room->show();
    return;
  }
  // order:room number|price|bed type|room type|floor|size|window|bathroom|add bed
  int row_count = ui->rooms_list->rowCount();
  ui->rooms_list->insertRow(row_count);
  QTableWidgetItem* room_number = new QTableWidgetItem();
  room_number->setText(ui->room_number_lineedit->text());
  ui->rooms_list->setItem(row_count, 0, room_number);
  QTableWidgetItem* price = new QTableWidgetItem();
  price->setText(ui->price_lineedit->text());
  ui->rooms_list->setItem(row_count, 1, price);
  QString bed_type_qstring;
  switch (ui->bed_type_combobox->currentIndex()) {
  case 0: bed_type_qstring = "single"; break;
  case 1: bed_type_qstring = "double"; break;
  case 2: bed_type_qstring = "king size"; break;
  case 3: bed_type_qstring = "triple and more";break;
  default: bed_type_qstring = "\0";break;
  }
  QTableWidgetItem* bed_type = new QTableWidgetItem(bed_type_qstring);
  ui->rooms_list->setItem(row_count, 2, bed_type);
  QTableWidgetItem* room_type = new QTableWidgetItem();
  room_type->setText(ui->self_define_type_lineedit->text());
  ui->rooms_list->setItem(row_count, 3, room_type);
  QString floor_qstring(QString::number(ui->floor_spinbox->value()));
  QTableWidgetItem* floor = new QTableWidgetItem(floor_qstring);
  ui->rooms_list->setItem(row_count, 4, floor);
  QString size_qstring(QString::number(ui->size_spinox->value()));
  QTableWidgetItem* size = new QTableWidgetItem(size_qstring);
  ui->rooms_list->setItem(row_count, 5, size);
  QTableWidgetItem* window = new QTableWidgetItem(
    BoolToQstring(ui->window_checkbox->isChecked()));
  ui->rooms_list->setItem(row_count, 6, window);
  QTableWidgetItem* bathroom = new QTableWidgetItem(
    BoolToQstring(ui->bathroom_checkbox->isChecked()));
  ui->rooms_list->setItem(row_count, 7, bathroom);
  QTableWidgetItem* add_bed = new QTableWidgetItem(
    BoolToQstring(ui->add_bed_checkbox->isChecked()));
  ui->rooms_list->setItem(row_count, 8, add_bed);
  ClearRoomInfoLeft();
  ui->copy_row_spinbox->setMaximum(row_count + 1);
  ui->copy_row_spinbox->setValue(row_count + 1);
}

// 清除房间信息填写栏
void HotelApplicationStep::ClearRoomInfoLeft() {
  ui->floor_spinbox->setValue(0);
  ui->price_lineedit->clear();
  ui->room_number_lineedit->clear();
  ui->self_define_type_lineedit->clear();
  ui->size_spinox->setValue(0);
  ui->bed_type_combobox->setCurrentIndex(-1);
}

// 删除对应序列房间
void HotelApplicationStep::on_delete_button_clicked() {
  int row_count = ui->rooms_list->currentRow();
  if (row_count != -1) {
    ui->rooms_list->removeRow(row_count);
  }
}

// 跳转到拷贝界面
void HotelApplicationStep::on_copy_button_clicked() {
  if (ui->stackedWidget->currentIndex() == 1) {
    ui->error_label_room->setText(tr("already in copy mode"));
    ui->error_label_room->show();
    return;
  }
  if (ui->stackedWidget->currentIndex() == 0) {
    ui->stackedWidget->setCurrentIndex(1);
  }
}

void HotelApplicationStep::on_copy_cancel_button_clicked() {
  ui->copy_max_num_lineedit->clear();
  ui->copy_min_num_lineedit->clear();
  ui->copy_floor_lineedit->clear();
  ui->stackedWidget->setCurrentIndex(0);
}

// 执行房间拷贝
void HotelApplicationStep::on_copy_done_button_clicked() {
  if (ui->copy_max_num_lineedit->text().isEmpty() ||
    ui->copy_min_num_lineedit->text().isEmpty()) {
    ui->error_label_room->setText(tr("please compelete the information"));
    ui->error_label_room->show();
    return;
  }
  int current_row = ui->copy_row_spinbox->value() - 1;
  bool is_pure_room_number = false;
  ui->rooms_list->item(current_row, 4)->text().toInt(&is_pure_room_number);
  if (!is_pure_room_number) {
    ui->error_label_room->setText(tr("only support pure number"));
    ui->error_label_room->show();
    return;
  }
  int floor_num;
  if (ui->copy_floor_lineedit->text().isEmpty()) {
    floor_num = ui->rooms_list->item(current_row, 4)->text().toInt();
  } else {
    floor_num = ui->copy_floor_lineedit->text().toInt();
  }
  for (int i = ui->copy_min_num_lineedit->text().toInt();
    i <= ui->copy_max_num_lineedit->text().toInt();
    i++) {
    int row_count = ui->rooms_list->rowCount();
    ui->rooms_list->insertRow(row_count);
    QTableWidgetItem* room_number = new QTableWidgetItem();
    room_number->setText(QString::number(i));
    ui->rooms_list->setItem(row_count, 0, room_number);
    QTableWidgetItem* price = new QTableWidgetItem(
      *(ui->rooms_list->item(current_row, 1)));
    ui->rooms_list->setItem(row_count, 1, price);
    QTableWidgetItem* bed_type = new QTableWidgetItem(
      *(ui->rooms_list->item(current_row, 2)));
    ui->rooms_list->setItem(row_count, 2, bed_type);
    QTableWidgetItem* room_type = new QTableWidgetItem(
      *(ui->rooms_list->item(current_row, 3)));
    ui->rooms_list->setItem(row_count, 3, room_type);
    QString floor_qstring(QString::number(floor_num));
    QTableWidgetItem* floor = new QTableWidgetItem(floor_qstring);
    ui->rooms_list->setItem(row_count, 4, floor);
    QTableWidgetItem* size = new QTableWidgetItem(
      *(ui->rooms_list->item(current_row, 5)));
    ui->rooms_list->setItem(row_count, 5, size);
    QTableWidgetItem* window = new QTableWidgetItem(
      *(ui->rooms_list->item(current_row, 6)));
    ui->rooms_list->setItem(row_count, 6, window);
    QTableWidgetItem* bathroom = new QTableWidgetItem(
      *(ui->rooms_list->item(current_row, 7)));
    ui->rooms_list->setItem(row_count, 7, bathroom);
    QTableWidgetItem* add_bed = new QTableWidgetItem(
      *(ui->rooms_list->item(current_row, 8)));
    ui->rooms_list->setItem(row_count, 8, add_bed);
    ui->copy_row_spinbox->setMaximum(row_count + 1);
    ui->copy_row_spinbox->setValue(row_count + 1);
  }
}

//***********值转换函数********************************************************
QString HotelApplicationStep::BoolToQstring(bool bool_) {
  if (bool_) {
    return "yes";
  } else {
    return "no";
  }
}

bool HotelApplicationStep::QstringToBool(const QString& qstring) {
  return qstring == "yes";
}

Room::BedType HotelApplicationStep::QStringToBedType(const QString& qstring) {
  if (qstring == "single") {
    return Room::SINGLE;
  }
  if (qstring == "double") {
    return Room::DOUBLE;
  }
  if (qstring == "king size") {
    return Room::KINGSIZE;
  }
  if (qstring == "triple and more") {
    return Room::TRIPLEANDMORE;
  }
  return Room::SINGLE;
}
//***************************************************************************
