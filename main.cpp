//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：main.cpp
// 当前版本：1.0
// 摘要：本文件实现了对数据库的连接和展开对话窗口轮询的功能
// 作者：吴文绪
// 完成日期：2018.8.2
//****************************************************************************

#include "mainwindow.h"

#include <QApplication>

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

#include "btripdatabase.h"


Platform platform;


int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  BtripDatabase btrip_database(&platform, "btrip.db");
  btrip_database.CreateConnect();
  bool t1 = btrip_database.Upload();
  MainWindow w;
  w.show();
  return a.exec();
}
