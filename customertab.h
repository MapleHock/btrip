//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称： custmoertab.h
// 当前版本：1.0
// 摘要：本文件中实现customer对应的用户界面类的定义，在qt的基础上添加了customer指针
//      用于绑定账户，显示信息
// 作者：吴文绪
// 完成日期：2018.8.1
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

// 价位文本框信号，用于和rangesilder同步
  void SendTextLowValue(int value);
  void SendTextHighValue(int value);
  void SendHighValueIsHighest(bool is_highest);
private slots:

// 用户界面修改日期时对对应的dateedit的最值进行限定
  void on_check_in_dateedit_userDateChanged(const QDate &date);

  void on_check_out_dateedit_userDateChanged(const QDate &date);

// 清除搜索信息
  void on_clear_all_button_clicked();

 //****************** 价位文本框槽，用于和rangesilder同步***********************
  void on_lowest_price_lineedit_cursorPositionChanged(int arg1, int arg2);

  void on_highest_price_lineedit_cursorPositionChanged(int arg1, int arg2);

  void SetLowLineEdit(int low_value);

  void SetHighLineEdit(int high_value);

//****************************************************************************

// 发送搜索需求，会对信息不足时在error_label提示错误
  void on_search_button_clicked();

// 从搜索结果界面返回索索界面
  void on_return_button_clicked();

// 双击搜索结果跳转到酒店详细信息
  void on_result_table_cellDoubleClicked(int row, int column);

// 价格排序选择按钮
  void on_price_filter_button_clicked();

// 评价排序选择按钮
  void on_review_push_button_clicked();

// 下单按钮，调用对应底层函数
  bool new_booking(QString room_type, int number);

// 支付按钮，调用对应底层函数
  void on_pay_button_clicked();

// 记录用户最后点击的订单的位置
  void on_booking_table_cellClicked(int row, int column);

// 评价按钮，调用对应底层函数
  void on_review_button_clicked();

private:
// 私有成员，用于将对应的订单显示
  void ShowBookingList(const vector<HotelBooking*>& copy);

// 私有成员，用于刷新订单显示
  void RefreshBooking();

// 私有成员用于显示搜索结果
  void ShowResult();

// 私有成员 输入bool返回"yes" "no"用于显示
  QString BoolToQstring(bool bool_);

// 私有成员，用于将不符合条件的结果涂色
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
