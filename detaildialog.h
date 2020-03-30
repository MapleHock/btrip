//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�detaildialog.h
// ��ǰ�汾��1.0
// ժҪ�����ļ���ʵ��DetailDialog�࣬������ʾϸ����Ϣ
// ���ߣ�������
// ������ڣ�2018.8.2
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

// DetailDialog�࣬���ݴ���ľƵ�ָ���ס�����ڣ���ʾ��Ӧ�ķ������
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

 // ����������Ԥ���ķ������������
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
