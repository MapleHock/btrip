//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：btripdatabase.h
// 当前版本：1.0
// 摘要：本文件中实现对BtripDatabase的定义。本类主要用于封装程序运行中所需要的上传下载
//      数据的操作。
// 作者：吴文绪
// 完成日期：2018.7
//****************************************************************************

#ifndef BTRIPDATABASE_H
#define BTRIPDATABASE_H

#include <QSqlDatabase>
#include "platform.h"

// 类BtripDatabase将平台的实例和对应名称的数据库进行连接，实现数据库的上传下载
class BtripDatabase {
public:
// 构造函数将传入的平台指针和对应文件名的数据库绑定在一个实例中，以备实现上传下载
// 本函数不允许传入空指针。
  BtripDatabase(Platform* platform, const QString& database_name);
  ~BtripDatabase();

// 建立数据库连接，建立成功返回true
  bool CreateConnect();

// 将数据库数据上传到内存，全部数据上传成功返回true
  bool Upload();

// 将内存中存储的数据更新置数据库，全部数据上传成功返回true
  bool UpdataDatabase();
// 关闭对应数据库
  void CloseDatabase();
private:
  Platform* platform_;
  QString database_name_;
  QSqlDatabase database_;

};

#endif // BTRIPDATABASE_H
