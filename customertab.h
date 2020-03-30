//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ� custmoertab.h
// ��ǰ�汾��1.0
// ժҪ�����ļ���ʵ��customer��Ӧ���û�������Ķ��壬��qt�Ļ����������customerָ��
//      ���ڰ��˻�����ʾ��Ϣ
// ���ߣ�������
// ������ڣ�2018.8.1
//****************************************************************************
#ifndef CUSTOMERTAB_H
#define CUSTOMERTAB_H

#include <QTabWidget>
#include <QTableWidget>

#include "customer.h"
#include "detaildialog.h"


namespace Ui {
class CustomerTab;
}

class CustomerTab : public QTabWidget {
  Q_OBJECT

public:
  explicit CustomerTab(Customer* current_account,
    QWidget *parent = 0);
  ~CustomerTab();

signals:

// ��λ�ı����źţ����ں�rangesilderͬ��
  void SendTextLowValue(int value);
  void SendTextHighValue(int value);
  void SendHighValueIsHighest(bool is_highest);
private slots:

// �û������޸�����ʱ�Զ�Ӧ��dateedit����ֵ�����޶�
  void on_check_in_dateedit_userDateChanged(const QDate &date);

  void on_check_out_dateedit_userDateChanged(const QDate &date);

// ���������Ϣ
  void on_clear_all_button_clicked();

 //****************** ��λ�ı���ۣ����ں�rangesilderͬ��***********************
  void on_lowest_price_lineedit_cursorPositionChanged(int arg1, int arg2);

  void on_highest_price_lineedit_cursorPositionChanged(int arg1, int arg2);

  void SetLowLineEdit(int low_value);

  void SetHighLineEdit(int high_value);

//****************************************************************************

// �����������󣬻����Ϣ����ʱ��error_label��ʾ����
  void on_search_button_clicked();

// ������������淵����������
  void on_return_button_clicked();

// ˫�����������ת���Ƶ���ϸ��Ϣ
  void on_result_table_cellDoubleClicked(int row, int column);

// �۸�����ѡ��ť
  void on_price_filter_button_clicked();

// ��������ѡ��ť
  void on_review_push_button_clicked();

// �µ���ť�����ö�Ӧ�ײ㺯��
  bool new_booking(QString room_type, int number);

// ֧����ť�����ö�Ӧ�ײ㺯��
  void on_pay_button_clicked();

// ��¼�û�������Ķ�����λ��
  void on_booking_table_cellClicked(int row, int column);

// ���۰�ť�����ö�Ӧ�ײ㺯��
  void on_review_button_clicked();

private:
// ˽�г�Ա�����ڽ���Ӧ�Ķ�����ʾ
  void ShowBookingList(const vector<HotelBooking*>& copy);

// ˽�г�Ա������ˢ�¶�����ʾ
  void RefreshBooking();

// ˽�г�Ա������ʾ�������
  void ShowResult();

// ˽�г�Ա ����bool����"yes" "no"������ʾ
  QString BoolToQstring(bool bool_);

// ˽�г�Ա�����ڽ������������Ľ��Ϳɫ
  void GrayRow(int row, QTableWidget* table);

  Customer* current_account_;
  vector<Hotel*> target_hotel_;
  Ui::CustomerTab *ui;
  DetailDialog* detail_dialog_;
  int viewing_hotel_index_;
  int last_booking_row_;
  bool is_price_text_low_to_high_;
  bool is_review_text_high_to_low_;
};

#endif // CUSTOMERTAB_H
