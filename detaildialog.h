//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：detaildialog.h
// 当前版本：1.0
// 摘要：本文件中实现DetailDialog类，用于显示细节信息
// 作者：吴文绪
// 完成日期：2018.8.2
//****************************************************************************

#ifndef DETAILDIALOG_H
#define DETAILDIALOG_H

#include <QDialog>
#include <QDate>

#include "hotel.h"
#include "customer.h"

namespace Ui {
class DetailDialog;
}

// DetailDialog类，根据传入的酒店指针和住店日期，显示对应的房间情况
class DetailDialog : public QDialog {
  Q_OBJECT

public:
  explicit DetailDialog(Hotel* hotel,
                        QDate* check_in,
                        QDate* check_out,
                        QWidget *parent = 0);
  ~DetailDialog();

signals:

  void LastClickRowRoomCount(int num);

 // 发送最后决定预定的房间的类型数量
  void OverBooking(QString room_type, unsigned int number);

private slots:
  void on_rooms_list_cellClicked(int row, int column);

  void on_booking_clicked();

private:
  QString EnumBedTypeToString(Room::BedType bed_type);

  Customer* current_account_;
  Hotel* hotel_;
  QDate* check_in_;
  QDate* check_out_;
  int last_click_row;

  Ui::DetailDialog *ui;
};

#endif // DETAILDIALOG_H
