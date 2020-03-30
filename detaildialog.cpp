//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：detaildialog.h
// 当前版本：1.0
// 摘要：本文件中实现DetailDialog类的成员函数，用于显示细节信息
// 作者：吴文绪
// 完成日期：2018.8.2
//****************************************************************************

#include "detaildialog.h"
#include "ui_detaildialog.h"



DetailDialog::DetailDialog(Hotel* hotel,
  QDate* check_in,
  QDate* check_out,
  QWidget *parent) :
  hotel_(hotel),
  check_in_(check_in),
  check_out_(check_out),
  QDialog(parent),
  ui(new Ui::DetailDialog) {
  last_click_row = -1;
  ui->setupUi(this);
  ui->error_label->hide();
  ui->name_label->setText(QString::fromStdString(hotel_->GetName()));
  connect(this, &DetailDialog::LastClickRowRoomCount,
    ui->number_spin_box, &QSpinBox::setMaximum);
  vector<const Room*> room_models;
  for (unsigned int i = 0; i < hotel_->PrepareSearch().size(); i++) {
    bool is_new = true;
    unsigned int j = 0;
    for (; j < room_models.size(); j++) {
      if (room_models[j]->GetRoomTypeDefinedByHotel()
        == hotel_->PrepareSearch()[i].GetRoomTypeDefinedByHotel()) {
        is_new = false;
        break;
      }
    }
    if (is_new) {
      room_models.push_back(&(hotel_->PrepareSearch()[i]));
    }
  }
  QStringList header_labels;
  header_labels << tr("name") << tr("bed type") << tr("price") << tr("count");
  ui->rooms_list->setHorizontalHeaderLabels(header_labels);
  for (unsigned int i = 0; i < room_models.size(); i++) {
    int row_count = ui->rooms_list->rowCount();
    ui->rooms_list->insertRow(row_count);
    QTableWidgetItem* room_type = new QTableWidgetItem();
    room_type->setText(QString::fromStdString(room_models[i]->GetRoomTypeDefinedByHotel()));
    ui->rooms_list->setItem(row_count, 0, room_type);
    QTableWidgetItem* bed_type = new QTableWidgetItem();
    bed_type->setText(EnumBedTypeToString(room_models[i]->GetBedType()));
    ui->rooms_list->setItem(row_count, 1, bed_type);
    QTableWidgetItem* price = new QTableWidgetItem();
    price->setText(QString::number(room_models[i]->GetPricePerNight()));
    ui->rooms_list->setItem(row_count, 2, price);
    QTableWidgetItem* count = new QTableWidgetItem();
    count->setText(QString::number(hotel->RoomsAvailabel(*check_in, *check_out,
      room_models[i]->GetRoomTypeDefinedByHotel())));
    ui->rooms_list->setItem(row_count, 3, count);
  }
}

DetailDialog::~DetailDialog() {
  delete ui;
}

QString DetailDialog::EnumBedTypeToString(Room::BedType bed_type) {
  switch (bed_type) {
  case Room::SINGLE: return tr("singal");
  case Room::DOUBLE: return tr("double");
  case Room::KINGSIZE: return tr("king size");
  case Room::TRIPLEANDMORE: return tr("triple and more");
  default: return tr("error");
  }
}

void DetailDialog::on_rooms_list_cellClicked(int row, int column) {
  last_click_row = row;
  emit LastClickRowRoomCount(ui->rooms_list->item(row, 3)->text().toInt());
}

void DetailDialog::on_booking_clicked() {
  if (last_click_row == -1) {
    ui->error_label->setText(tr("please choose a room first"));
    ui->error_label->show();
    return;
  }
  if (ui->rooms_list->item(last_click_row, 3)->text().toInt() == 0) {
    ui->error_label->setText(tr("sorry not availabel"));
    ui->error_label->show();
    return;
  }

  emit OverBooking(ui->rooms_list->item(last_click_row, 0)->text(),
    ui->number_spin_box->value());
  close();
}
