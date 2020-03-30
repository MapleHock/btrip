//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：administratortab.h
// 当前版本：1.0
// 摘要：本文件中实现对AdministratorTab类的定义。
//      AdministratorTab类是业务员PlatformAdministrator所对应的主要操作界面。对应其
//      业务操作主要实现了管理申请和订单两个功能
// 作者：吴文绪
// 完成日期：2018.7.26
//****************************************************************************

#ifndef ADMINISTRATORTAB_H
#define ADMINISTRATORTAB_H

#include <QTabWidget>

#include "platformadministrator.h"
#include "room.h"

namespace Ui {
class AdministratorTab;
}

// AdministratorTab类的定义。由qt designer页面所设计的控件和对应的业务员组成。
// 主要能在ui上完成酒店申请和订单的管理
class AdministratorTab : public QTabWidget {
  Q_OBJECT

public:
// AdministratorTab类的构造函数，在qt的基础上增加了账户员指针，用于连接ui与底层
  explicit AdministratorTab(PlatformAdministrator* current_account,
    QWidget *parent = 0);
  ~AdministratorTab();

private slots:

// PlatformAdministrator对有疑问的申请进行抽出
  void on_hold_app_button_clicked();

 // PlatformAdministrator对申请完成审核
  void on_check_app_button_clicked();

 // PlatformAdministrator对有疑问的订单进行抽出
  void on_hold_booking_button_clicked();

 // PlatformAdministrator对 订单 完成审核
  void on_check_button_clicked();

private:
  
// 订单/申请刷新，用于在初始化界面或者完成一个订单的/申请的审核周期后得到下一个订单的信息
  void RefreshApp();
  void RefreshBooking();

// 数据转化函数，用于转化订单/申请中对应的数据类型方便显示
  QString BoolToString(bool bool_);
  QString EnumBedTypeToString(Room::BedType bed_type);

  Ui::AdministratorTab *ui;
  PlatformAdministrator* current_account_;
  JoinApplication* app_displayed_;
  bool is_app_holding_;
  unsigned int app_count_;

  AbstractBooking* booking_displayed_;
  bool is_booking_holding_;
  unsigned int booking_count_;
  double share_count_;
};

#endif // ADMINISTRATORTAB_H
