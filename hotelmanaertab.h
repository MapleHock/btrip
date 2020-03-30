//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�hotelmanaertab.h
// ��ǰ�汾��1.0
// ժҪ�����ļ���ʵ��hotelmanaertab�࣬Ϊҵ��ԱHotelMnanger����Ҫ����
//      �й������͹���Ƶ�Ĺ���
// ���ߣ�������
// ������ڣ�2018.7.31
//****************************************************************************

#ifndef HOTELMANAERTAB_H
#define HOTELMANAERTAB_H

#include <QTabWidget>
#include <QTableWidget>

#include "hotelmanager.h"


namespace Ui {
class HotelManaerTab;
}

class HotelManaerTab : public QTabWidget {
  Q_OBJECT

public:

// ���캯��������qt���ĵĸ�����ָ��֮�⣬����Ҫ��ҵ��Աָ���Դ�ͬ������
  explicit HotelManaerTab(HotelManager* current_account, QWidget *parent = 0);
  ~HotelManaerTab();

private slots:

// ��������
  void on_search_button_clicked();

// ʵ��ɾ���ַ���ʱȡ������
  void on_room_type_lineedit_textChanged(const QString &arg1);

// ���ܶ���
  void on_accept_button_clicked();

// �ܾ�����
  void on_reject_button_clicked();

 // ˫����ѯ����ԤԼ״̬
  void on_room_table_cellDoubleClicked(int row, int column);

// ��¼��Ҫ�����Ķ���λ��
  void on_unfinish_table_cellClicked(int row, int column);

// ��ɶ���
  void on_finish_button_clicked();

private:
// ����ˢ������ʾ����
  void RefreshBooking();
  void ShowBookingList(const deque<HotelBooking*>& copy, QTableWidget* table);
  void ShowBookingList(const vector<HotelBooking*>& copy, QTableWidget *table);
  void RefreshRoom();

  Ui::HotelManaerTab *ui;
  HotelManager* current_account_;
  int last_unfinished_row_;
};

#endif // HOTELMANAERTAB_H
