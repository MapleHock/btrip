#include "customertab.h"
#include "ui_customertab.h"
#include "rangeslider.h"
#include "detaildialog.h"

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

#include <QMessageBox>

extern Platform platform;

CustomerTab::CustomerTab(Customer* current_account, QWidget *parent) :
  current_account_(current_account),
  QTabWidget(parent),
  ui(new Ui::CustomerTab)
{
  ui->setupUi(this);
  viewing_hotel_index_ = -1;
  last_booking_row_ = -1;
// 初始化搜索界面
  is_price_text_low_to_high_ = true;
  is_review_text_high_to_low_ = true;
  ui->and_more_label->hide();
  ui->error_search_label->hide();
// 隔离信号以便完成dateedit初始化
  ui->check_in_dateedit->blockSignals(true);
  ui->check_out_dateedit->blockSignals(true);
  ui->check_in_dateedit->setMinimumDate(QDate::currentDate());
  ui->check_out_dateedit->setMinimumDate(QDate::currentDate());
  ui->check_in_dateedit->setDate(QDate::currentDate());
  ui->check_out_dateedit->setDate(QDate::currentDate());
  ui->check_out_dateedit->setEnabled(false);
  ui->check_in_dateedit->blockSignals(false);
  ui->check_out_dateedit->blockSignals(false);
  ui->check_out_dateedit->setEnabled(true);
// 初始化rangerslider
  ui->price_range_slider->SetRange(0, 1000);
  ui->lowest_price_lineedit->setValidator(new QIntValidator(0, 1000, this));
  ui->highest_price_lineedit->setValidator(new QIntValidator(0, 1000, this));
  connect(this, &CustomerTab::SendTextLowValue,
          ui->price_range_slider, &RangeSlider::setLowerValue);
  connect(this, &CustomerTab::SendTextHighValue,
          ui->price_range_slider, &RangeSlider::setUpperValue);
  connect(ui->price_range_slider, &RangeSlider::lowerValueChanged,
          this, &CustomerTab::SetLowLineEdit);
  connect(ui->price_range_slider, &RangeSlider::upperValueChanged,
          this, &CustomerTab::SetHighLineEdit);
  connect(this, &CustomerTab::SendHighValueIsHighest,
          ui->and_more_label, &QLabel::setVisible);
// 初始化结果界面
  QStringList header_labels;
  header_labels << tr("name") << tr("Starting at") << tr("review") << tr("features") << tr("index background");
  ui->result_table->setHorizontalHeaderLabels(header_labels);
  ui->result_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
  ui->result_table->setColumnHidden(4, true);
  ui->search_result_tab->setEnabled(false);
// 初始化订单界面，调用了私有成员函数RefreshBooking();
  ui->error_label_booking->hide();
  RefreshBooking();
}

CustomerTab::~CustomerTab()
{
  delete ui;
}

//********************* 用户界面修改日期时对对应的dateedit的最值进行限定*********
void CustomerTab::on_check_in_dateedit_userDateChanged(const QDate& date)
{
  ui->check_in_dateedit->blockSignals(true);
  ui->check_out_dateedit->blockSignals(true);
  QDate check_in_date(date);
  ui->check_out_dateedit->setMinimumDate(check_in_date.addDays(1));
  QDate check_out_date = ui->check_out_dateedit->date();
  ui->total_day_lcd->display(static_cast<int>(check_in_date.daysTo(check_out_date)));
  ui->check_in_dateedit->blockSignals(false);
  ui->check_out_dateedit->blockSignals(false);
}

void CustomerTab::on_check_out_dateedit_userDateChanged(const QDate &date)
{
  ui->check_in_dateedit->blockSignals(true);
  ui->check_out_dateedit->blockSignals(true);
  QDate check_in_date = ui->check_in_dateedit->date();
  QDate check_out_date(date);
  ui->total_day_lcd->display(static_cast<int>(check_in_date.daysTo(check_out_date)));
  ui->check_in_dateedit->blockSignals(false);
  ui->check_out_dateedit->blockSignals(false);
}

//****************************************************************************

// 清除搜索信息
void CustomerTab::on_clear_all_button_clicked()
{
  ui->error_search_label->hide();
  ui->check_in_dateedit->blockSignals(true);
  ui->check_out_dateedit->blockSignals(true);
  ui->check_in_dateedit->setMinimumDate(QDate::currentDate());
  ui->check_out_dateedit->setMinimumDate(QDate::currentDate());
  ui->check_in_dateedit->setDate(QDate::currentDate());
  ui->check_out_dateedit->setDate(QDate::currentDate());
  ui->check_out_dateedit->setEnabled(false);
  ui->check_in_dateedit->blockSignals(false);
  ui->check_out_dateedit->blockSignals(false);
  ui->check_out_dateedit->setEnabled(true);
  ui->city_lineedit->clear();
  ui->area_lineedit->clear();
  ui->bed_type_combobox->setCurrentIndex(-1);
  ui->total_day_lcd->display(0);
  ui->window_checkBox->setChecked(true);
  ui->bathroom_checkBox->setChecked(true);
  ui->add_bed_checkBox->setChecked(false);
  ui->lowest_price_lineedit->blockSignals(true);
  ui->highest_price_lineedit->blockSignals(true);
  ui->price_range_slider->blockSignals(true);
  ui->lowest_price_lineedit->clear();
  ui->highest_price_lineedit->clear();
  ui->price_range_slider->setLowerValue(ui->price_range_slider->GetMinimun());
  ui->price_range_slider->setUpperValue(ui->price_range_slider->GetMaximun());
  ui->and_more_label->hide();
  ui->lowest_price_lineedit->blockSignals(false);
  ui->highest_price_lineedit->blockSignals(false);
  ui->price_range_slider->blockSignals(false);
}

//****************** 价位文本框槽，用于和rangesilder同步***********************

void CustomerTab::on_lowest_price_lineedit_cursorPositionChanged(int arg1, int arg2)
{
  if(!ui->highest_price_lineedit->text().isEmpty() &&
      ui->lowest_price_lineedit->text().toInt() > ui->highest_price_lineedit->text().toInt()) {
        ui->lowest_price_lineedit->setText(
                    ui->lowest_price_lineedit->text().left(
                              ui->lowest_price_lineedit->text().size() - 1));
      }
  emit SendTextLowValue(ui->lowest_price_lineedit->text().toInt());
}

void CustomerTab::on_highest_price_lineedit_cursorPositionChanged(int arg1, int arg2)
{
  if (ui->lowest_price_lineedit->text().isEmpty() ||
      ui->lowest_price_lineedit->text().toInt() <= ui->highest_price_lineedit->text().toInt()) {
    emit SendTextHighValue(ui->highest_price_lineedit->text().toInt());
    emit SendHighValueIsHighest(ui->highest_price_lineedit->text().toInt()
                                  == ui->price_range_slider->GetMaximun());
  }
}

void CustomerTab::SetLowLineEdit(int low_value) {
  ui->lowest_price_lineedit->setText(QString::number(low_value));
}

void CustomerTab::SetHighLineEdit(int high_value) {
  ui->highest_price_lineedit->setText(QString::number(high_value));
}

//****************************************************************************

// 发送搜索需求，会对信息不足时在error_label提示错误
void CustomerTab::on_search_button_clicked()
{
  if (ui->city_lineedit->text().isEmpty() ||
      ui->check_out_dateedit->date() == QDate::currentDate()) {
      ui->error_search_label->setText(tr("please compelete the information"));
      ui->error_search_label->show();
      return;
  }

  string city = ui->city_lineedit->text().toStdString();

  const vector<Hotel*>& all_hotel
                      = current_account_->SearchAt(platform)->PrepareSearch();
// 第一次查询将符合城市的指针传入
  for (int i = 0; i < all_hotel.size(); i++) {
    if(all_hotel[i]->GetCity() == city) {
      target_hotel_.push_back(all_hotel[i]);
    }
  }

  ui->city_label->setText(tr("City: ") + ui->city_lineedit->text());
  ui->total_result_label->setText(tr("Total %1 result(s)").arg(target_hotel_.size()));
  ui->price_filter_button->setText(tr("price low to high"));
  is_price_text_low_to_high_ = true;
  ui->review_push_button->setText(tr("review high to low"));
  is_review_text_high_to_low_ = true;
  ShowResult();
  ui->search_result_tab->setEnabled(true);
  setCurrentWidget(ui->search_result_tab);
  ui->search_tab->setEnabled(false);
}

void CustomerTab::ShowResult() {
  if (target_hotel_.size() == 0) {
    return;
  }
// 顺序  name|starting price|review|features|(hide) index at vector

  for (int i = 0; i < target_hotel_.size(); i++) {
    int row_count = ui->result_table->rowCount();
    ui->result_table->insertRow(row_count);
    QTableWidgetItem* name = new QTableWidgetItem();
    name->setText(QString::fromStdString(target_hotel_[i]->GetName()));
    ui->result_table->setItem(row_count, 0, name);
    QTableWidgetItem* starting_price = new QTableWidgetItem();
    starting_price->setText(QString::number(target_hotel_[i]->GetStartingPrice()));
    ui->result_table->setItem(row_count, 1, starting_price);
    QTableWidgetItem* review = new QTableWidgetItem();
    review->setText(QString::number(target_hotel_[i]->GetReview()));
    ui->result_table->setItem(row_count, 2,review);
// TODO 把feature转化为可以显示的图标
    QTableWidgetItem* features = new QTableWidgetItem();
    features->setText("temp");
    ui->result_table->setItem(row_count, 3,features);
    QTableWidgetItem* index = new QTableWidgetItem();
    index->setText(QString::number(i));
    ui->result_table->setItem(row_count, 4, index);
// gray for those unavailable
    int count = target_hotel_[i]->
          RoomsAvailabel(ui->check_in_dateedit->date(),ui->check_out_dateedit->date());
    if (count == 0) {
      GrayRow(i, ui->result_table);
    }
  }
}

// 从搜索结果界面返回索索界面 将搜索界面初始化
void CustomerTab::on_return_button_clicked()
{
  for (; ui->result_table->rowCount() > 0; ui->result_table->removeRow(0)) {}
  target_hotel_.clear();
  ui->city_label->setText(tr("City: "));
  ui->total_result_label->setText(tr("Total  result(s)"));
  ui->review_push_button->setText(tr("review high to low"));
  ui->price_filter_button->setText(tr("price low to high"));
  on_clear_all_button_clicked();
  ui->search_tab->setEnabled(true);
  setCurrentWidget(ui->search_tab);
  ui->search_result_tab->setEnabled(false);
}

// 双击搜索结果跳转到酒店详细信息，通过记录的隐藏的index对target_hotels进行访问
void CustomerTab::on_result_table_cellDoubleClicked(int row, int column)
{
  if (column != 0) {
    return;
  }
  viewing_hotel_index_ = ui->result_table->item(row, 4)->text().toInt();
  detail_dialog_ =
    new DetailDialog(target_hotel_[ui->result_table->item(row, 4)->text().toInt()],
                     &ui->check_in_dateedit->date(),
                     &ui->check_out_dateedit->date(),
                     this);
  connect(detail_dialog_, &DetailDialog::OverBooking,
          this, &CustomerTab::new_booking);
  detail_dialog_->open();
  return;
}

// 排序筛选，调用qt库实现
void CustomerTab::on_price_filter_button_clicked()
{
  if (is_price_text_low_to_high_) {
    ui->result_table->sortItems(1,Qt::AscendingOrder);
    ui->price_filter_button->setText(tr("price high to low"));
    is_price_text_low_to_high_ = false;
  } else {
    ui->result_table->sortItems(1,Qt::DescendingOrder);
    ui->price_filter_button->setText(tr("price low to high"));
    is_price_text_low_to_high_ = true;
  }
}

void CustomerTab::on_review_push_button_clicked()
{
  if (is_review_text_high_to_low_) {
    ui->result_table->sortItems(2,Qt::DescendingOrder);
    ui->price_filter_button->setText(tr("review low to high"));
    is_review_text_high_to_low_ = false;
  } else {
    ui->result_table->sortItems(2,Qt::AscendingOrder);
    ui->price_filter_button->setText(tr("review high to low"));
    is_review_text_high_to_low_ = true;
  }
}

bool CustomerTab::new_booking(QString room_type, int number) {
// booking
  current_account_->BookRoom(QDate::currentDate(),
                             *(target_hotel_[viewing_hotel_index_]),
                             room_type.toStdString(), number,
                             platform,
                             ui->check_in_dateedit->date(),
                             ui->check_out_dateedit->date());
  (const_cast<HotelBooking*>(current_account_->ViewHotelUnpay().back()))->SetRoomType(room_type.toStdString());
// set ui
  ui->search_result_tab->setEnabled(false);
  ui->search_tab->setEnabled(true);
  on_clear_all_button_clicked();
  RefreshBooking();
  setCurrentWidget(ui->bookings_tab);
  return true;
}

// 私有成员，用于将对应的订单显示
void CustomerTab::ShowBookingList(const vector<HotelBooking*>& copy) {
  for(int i = 0; i < copy.size(); i++) {
    int row_count = ui->booking_table->rowCount();
    ui->booking_table->insertRow(row_count);
    QTableWidgetItem* hotel = new QTableWidgetItem();
    hotel->setText(QString::fromStdString(copy[i]->GetHotelName()));
    ui->booking_table->setItem(row_count, 0, hotel);
    QTableWidgetItem* check_in = new QTableWidgetItem();
    check_in->setText(copy[i]->GetCheckInDate().toString());
    ui->booking_table->setItem(row_count, 1, check_in);
    QTableWidgetItem* check_out = new QTableWidgetItem();
    check_out->setText(copy[i]->GetCheckOutDate().toString());
    ui->booking_table->setItem(row_count, 2, check_out);
    QTableWidgetItem* total_cost = new QTableWidgetItem();
    total_cost->setText(QString::number(copy[i]->GetUnitPrice()
                                    * copy[i]->GetAmount()));
    ui->booking_table->setItem(row_count, 3, total_cost);
    QTableWidgetItem* is_payed = new QTableWidgetItem();
    is_payed->setText(BoolToQstring(copy[i]->IsPayed()));
    ui->booking_table->setItem(row_count, 4, is_payed);
    QTableWidgetItem* created_date = new QTableWidgetItem();
    created_date->setText(copy[i]->GetCreatedDate().toString());
    ui->booking_table->setItem(row_count, 5, created_date);
    QTableWidgetItem* index = new QTableWidgetItem();
    index->setText(QString::number(i));
    ui->booking_table->setItem(row_count, 6, index);
  }
}

// 私有成员，用于刷新订单显示 调用了ShowBookingList作为实现
void CustomerTab::RefreshBooking() {
  for(; ui->booking_table->rowCount() > 0; ui->booking_table->removeRow(0)) {}
  QStringList headr_labels;
  headr_labels << tr("hotel") << tr("check in") << tr("check out")
               << tr("total cost") << tr("is payed") << tr("created date")
               << tr("index");
  ui->booking_table->setHorizontalHeaderLabels(headr_labels);
  ui->booking_table->setColumnHidden(6,true);
  ui->booking_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
  ShowBookingList(current_account_->ViewHotelUnpay());
  ui->booking_table->insertRow(ui->booking_table->rowCount());
  ShowBookingList(current_account_->ViewHotelUnreview());
}

// 私有成员 输入bool返回"yes" "no"用于显示
QString CustomerTab::BoolToQstring(bool bool_) {
  if (bool_) {
    return "yes";
  }
  else {
    return "no";
  }
}

// 支付，调用底层逻辑中对应函数完成，对返回的错误信息进行一定的显示
// TODO 此处的支付金额调到最大，实际情况中应该接入实际支付的api完成实现
void CustomerTab::on_pay_button_clicked()
{
  if (last_booking_row_ == -1 ||
      ui->booking_table->item(last_booking_row_, 4)->text().isEmpty()) {
    ui->error_label_booking->setText(tr("please choose a booking"));
    ui->error_label_booking->show();
    return;
  }

  if (ui->booking_table->item(last_booking_row_, 4)->text() == "yes") {
    ui->error_label_booking->setText(tr("the booking has been payed"));
    ui->error_label_booking->show();
    RefreshBooking();
    return;
  }
  int order = ui->booking_table->item(last_booking_row_, 6)->text().toInt();
  HotelBooking* the_booking = current_account_->PayHotel(order,65535);
  if (the_booking == NULL) {
    ui->error_label_booking->setText(tr("not enough"));
    ui->error_label_booking->show();
    RefreshBooking();
    return;
  }
  platform.GetAUncheckedBooking(the_booking);
  ui->error_label_booking->setText(tr("pay successfully"));
  ui->error_label_booking->show();
  RefreshBooking();
  return;
}

void CustomerTab::on_booking_table_cellClicked(int row, int column)
{
  last_booking_row_ = row;
}

void CustomerTab::GrayRow(int row, QTableWidget *table) {
  QBrush gray(Qt::HorPattern);
  // TODO fill table
  for (int i = 0; i < table->columnCount(); i++) {
    table->item(row, i)->setBackground(gray);
  }
}

// 评价，调用底层逻辑中对应函数完成，对返回的错误信息进行一定的显示

void CustomerTab::on_review_button_clicked()
{
  if (last_booking_row_ == -1 ||
      ui->booking_table->item(last_booking_row_, 4)->text().isEmpty()) {
    ui->error_label_booking->setText(tr("please choose a booking"));
    ui->error_label_booking->show();
    return;
  }
  int i = 0;
  for (; i + last_booking_row_ < ui->booking_table->rowCount(); i++) {
    if (ui->booking_table->item(last_booking_row_ + i, 4)->text().isEmpty()) {
      break;
    }
  }
  if (i + last_booking_row_ < ui->booking_table->rowCount()) {
    ui->error_label_booking->setText(tr("an unpayed one cann't be reviewed"));
    ui->error_label_booking->show();
    return;
  }
  i = ui->booking_table->item(last_booking_row_, 6)->text().toInt();
  HotelBooking* booking = current_account_->ReviewHotel(i, ui->review_spinbox->value());
  if (booking == NULL) {
    ui->error_label_booking->setText(tr("an unfinished one cann't be reviewed"));
    ui->error_label_booking->show();
    return;
  }
  platform.GetAReview(booking);
}





