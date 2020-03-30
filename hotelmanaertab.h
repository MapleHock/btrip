//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：hotelmanaertab.h
// 当前版本：1.0
// 摘要：本文件中实现hotelmanaertab类，为业务员HotelMnanger的主要界面
//      有管理订单和管理酒店的功能
// 作者：吴文绪
// 完成日期：2018.7.31
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

// 构造函数，除了qt风格的的父对象指针之外，还需要绑定业务员指针以此同步操作
  explicit HotelManaerTab(HotelManager* current_account, QWidget *parent = 0);
  ~HotelManaerTab();

private slots:

// 搜索房间
  void on_search_button_clicked();

// 实现删除字符串时取消搜索
  void on_room_type_lineedit_textChanged(const QString &arg1);

// 接受订单
  void on_accept_button_clicked();

// 拒绝订单
  void on_reject_button_clicked();

 // 双击查询房间预约状态
  void on_room_table_cellDoubleClicked(int row, int column);

// 记录将要操作的订单位置
  void on_unfinish_table_cellClicked(int row, int column);

// 完成订单
  void on_finish_button_clicked();

private:
// 界面刷新与显示函数
  void RefreshBooking();
  void ShowBookingList(const deque<HotelBooking*>& copy, QTableWidget* table);
  void ShowBookingList(const vector<HotelBooking*>& copy, QTableWidget *table);
  void RefreshRoom();

  Ui::HotelManaerTab *ui;
  HotelManager* current_account_;
  int last_unfinished_row_;
};

#endif // HOTELMANAERTAB_H
