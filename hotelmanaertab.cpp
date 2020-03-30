//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：hotelmanaertab.cpp
// 当前版本：1.0
// 摘要：本文件中实现hotelmanaertab类，为业务员HotelMnanger的成员函数
// 作者：吴文绪
// 完成日期：2018.7.31
//****************************************************************************

#include "hotelmanaertab.h"
#include "ui_hotelmanaertab.h"

#include "platform.h"
extern Platform platform;

HotelManaerTab::HotelManaerTab(HotelManager* current_account, QWidget *parent) :
  current_account_(current_account),
  QTabWidget(parent),
  ui(new Ui::HotelManaerTab) {
  ui->setupUi(this);
  ui->error_booking_label->hide();
  last_unfinished_row_ = -1;
// 刷新订单页和房间管理页
  RefreshBooking();
  RefreshRoom();
}

HotelManaerTab::~HotelManaerTab() {
  delete ui;
}

// 刷新订单页面
void HotelManaerTab::RefreshBooking() {
  for (; ui->receive_table->rowCount() > 0; ui->receive_table->removeRow(0)) {
  }
  for (; ui->unfinish_table->rowCount() > 0; ui->unfinish_table->removeRow(0)) {
  }
// 设置表头
  QStringList heard_labels;
  heard_labels << tr("room type") << tr("check in") << tr("check out")
    << tr("amount") << tr("share percent") << tr("index");
  ui->receive_table->setHorizontalHeaderLabels(heard_labels);
  ui->unfinish_table->setHorizontalHeaderLabels(heard_labels);
  ui->receive_table->setColumnHidden(5, true);
  ui->unfinish_table->setColumnHidden(5, true);
// 读取数据
  deque<HotelBooking*> show_booking_received;
  for (int i = 0; i < current_account_->ViewBookingsReceived().size(); i++) {
    HotelBooking* temp_address = reinterpret_cast<HotelBooking*>((current_account_->ViewBookingsReceived())[i]);
    show_booking_received.push_back(temp_address);
  }
  ShowBookingList(show_booking_received, ui->receive_table);
  vector<HotelBooking*> show_booking_unfinished;
  for (int i = 0; i < current_account_->ViewBookingsUnfinished().size(); i++) {
    HotelBooking* temp_address = reinterpret_cast<HotelBooking*>((current_account_->ViewBookingsUnfinished())[i]);
    show_booking_unfinished.push_back(temp_address);
  }
  ShowBookingList(show_booking_unfinished, ui->unfinish_table);
}

// 根据所给订单表，将数据刷新到给定表中有2个重载，分别针对 deque 和 vector
void HotelManaerTab::ShowBookingList(const deque<HotelBooking*>& copy,
  QTableWidget* table) {
  for (int i = 0; i < copy.size(); i++) {
    int row_count = table->rowCount();
    table->insertRow(row_count);
    QTableWidgetItem* room_type = new QTableWidgetItem();
    room_type->setText(QString::fromStdString(copy[i]->GetRoomType()));
    table->setItem(row_count, 0, room_type);
    QTableWidgetItem* check_in = new QTableWidgetItem();
    check_in->setText(copy[i]->GetCheckInDate().toString());
    table->setItem(row_count, 1, check_in);
    QTableWidgetItem* check_out = new QTableWidgetItem();
    check_out->setText(copy[i]->GetCheckOutDate().toString());
    table->setItem(row_count, 2, check_out);
    QTableWidgetItem* amount = new QTableWidgetItem();
    amount->setText(QString::number(copy[i]->GetAmount()));
    table->setItem(row_count, 3, amount);
    QTableWidgetItem* share_percent = new QTableWidgetItem();
    share_percent->setText(QString::number(copy[i]->GetSharePercent()) + "%");
    table->setItem(row_count, 4, share_percent);
    QTableWidgetItem* index = new QTableWidgetItem();
    index->setText(QString::number(i));
    table->setItem(row_count, 5, index);
  }
}

void HotelManaerTab::ShowBookingList(const vector<HotelBooking*>& copy,
  QTableWidget *table) {
  for (int i = 0; i < copy.size(); i++) {
    int row_count = table->rowCount();
    table->insertRow(row_count);
    QTableWidgetItem* room_type = new QTableWidgetItem();
    room_type->setText(QString::fromStdString(copy[i]->GetRoomType()));
    table->setItem(row_count, 0, room_type);
    QTableWidgetItem* check_in = new QTableWidgetItem();
    check_in->setText(copy[i]->GetCheckInDate().toString());
    table->setItem(row_count, 1, check_in);
    QTableWidgetItem* check_out = new QTableWidgetItem();
    check_out->setText(copy[i]->GetCheckOutDate().toString());
    table->setItem(row_count, 2, check_out);
    QTableWidgetItem* amount = new QTableWidgetItem();
    amount->setText(QString::number(copy[i]->GetAmount()));
    table->setItem(row_count, 3, amount);
    QTableWidgetItem* share_percent = new QTableWidgetItem();
    share_percent->setText(QString::number(copy[i]->GetSharePercent()) + "%");
    table->setItem(row_count, 4, share_percent);
    QTableWidgetItem* index = new QTableWidgetItem();
    index->setText(QString::number(i));
    table->setItem(row_count, 5, index);
  }
}

void HotelManaerTab::RefreshRoom() {
  vector<Room>& show_room = current_account_->GetHotelBelong().ManageRooms();
  for (; ui->room_table->rowCount() > 0; ui->room_table->removeRow(0)) {
  }
  // 设置表头
  QStringList heard_labels;
  heard_labels << tr("room number") << tr("room type") << tr("price") << tr("index");
  ui->room_table->setHorizontalHeaderLabels(heard_labels);
  ui->room_table->setColumnHidden(3, true);

  // 读取房间数据
  for (int i = 0; i < show_room.size(); i++) {
    int row_count = ui->room_table->rowCount();
    ui->room_table->insertRow(row_count);
    QTableWidgetItem* room_number = new QTableWidgetItem();
    room_number->setText(QString::fromStdString(show_room[i].GetRoomNumber()));
    ui->room_table->setItem(row_count, 0, room_number);
    QTableWidgetItem* room_type = new QTableWidgetItem();
    room_type->setText(QString::fromStdString(show_room[i].GetRoomTypeDefinedByHotel()));
    ui->room_table->setItem(row_count, 1, room_type);
    QTableWidgetItem* price = new QTableWidgetItem();
    price->setText(QString::number(show_room[i].GetPricePerNight()));
    ui->room_table->setItem(row_count, 2, price);
    QTableWidgetItem* index = new QTableWidgetItem();
    index->setText(QString::number(i));
    ui->room_table->setItem(row_count, 3, index);
  }
}

// 搜索房间，在ui层上实现，根据所给的信息在QTableWidgetItem中筛选
void HotelManaerTab::on_search_button_clicked() {
  if (ui->room_type_lineedit->text().isEmpty()) {
    return;
  }

  for (int i = 0; i < ui->room_table->rowCount(); i++) {
    if (ui->room_table->item(i, 1)->text() != ui->room_type_lineedit->text()) {
      ui->room_table->setRowHidden(i, true);
    }
  }
}

// 检测搜索栏是否为空，以此取消搜索
void HotelManaerTab::on_room_type_lineedit_textChanged(const QString &arg1) {
  if (arg1.isEmpty()) {
    for (int i = 0; i < ui->room_table->rowCount(); i++) {
      ui->room_table->setRowHidden(i, false);
    }
  }
}

// 接受订单，调用业务员的对应底层函数进行显示和接受，并将错误信息提示到label
// 在本机模拟多机操作的情况下，不会触发 已经被检查分支
void HotelManaerTab::on_accept_button_clicked() {
  string room_number;
  const HotelBooking* booking_now =
    dynamic_cast<HotelBooking*>(current_account_->ViewBookingsReceived()[0]);
  if (current_account_->GetHotelBelong().RoomsAvailabel(
    booking_now->GetCheckInDate(),
    booking_now->GetCheckOutDate(),
    booking_now->GetRoomType(),
    &room_number) != 0) {
    current_account_->AcceptABooking(room_number);
    ui->error_booking_label->hide();
    RefreshBooking();
  } else {
    ui->error_booking_label->setText(tr("booking has been checked"));
    ui->error_booking_label->show();
    RefreshBooking();
  }

}

// 拒绝订单，调用业务员的对应底层函数进行，并将错误信息提示到label
void HotelManaerTab::on_reject_button_clicked() {
  if (current_account_->RejectABooking() == NULL) {
    ui->error_booking_label->setText(tr("error booking"));
    ui->error_booking_label->show();
  }
  RefreshBooking();
}

// 双击查看房间预约状况根据
// 根据列表中绑定的房间序列index实现对房间的寻找
// 用迭代器遍历room的bookingdate完成楚竹查找
void HotelManaerTab::on_room_table_cellDoubleClicked(int row, int column) {
  unsigned i = ui->room_table->item(row, 3)->text().toInt();
  Room& the_room = current_account_->GetHotelBelong().ManageRooms()[i];
  for (; ui->booking_date_list->rowCount() > 0; ui->booking_date_list->removeRow(0)) {
  }
  for (list<QDate>::const_iterator show_date = the_room.GetBookingDates().begin();
    show_date != the_room.GetBookingDates().end();
    ++show_date) {
    int row_count = ui->booking_date_list->rowCount();
    ui->booking_date_list->insertRow(row_count);
    QTableWidgetItem* date = new QTableWidgetItem();
    date->setText(show_date->toString());
    ui->booking_date_list->setItem(row_count, 0, date);
  }
}

// 记录将要操作的订单在ui的位置
void HotelManaerTab::on_unfinish_table_cellClicked(int row, int column) {
  last_unfinished_row_ = row;
}

// 完成订单，调用对应的底层函数
void HotelManaerTab::on_finish_button_clicked() {
  if (last_unfinished_row_ == -1) {
    ui->error_booking_label->setText(tr("please choose an unfinish booking"));
    ui->error_booking_label->show();
    return;
  }
  // TODO remember cancel this to code
  int index = ui->unfinish_table->item(last_unfinished_row_, 5)->text().toInt();
  current_account_->FinishABooking(index);
  platform.GetABookingFromBusiness(current_account_->GetHotelBelong().SendBackABooking());
  RefreshBooking();
}
