//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：patformadministrator.cpp
// 当前版本：1.0
// 摘要：本文件中实现业务员PlatformAdministrator类的成员函数定义。
// 作者：吴文绪
// 完成日期：2018.7.28
//****************************************************************************

#include "platformadministrator.h"

PlatformAdministrator::PlatformAdministrator(const string& username, 
                                             const string& password,
                                             Platform& platform_belong) 
  : AbstractUser(username, password),
    platform_belong_(platform_belong) {}

PlatformAdministrator::~PlatformAdministrator() {}

// 按照输入抽成检查队首订单，检查成功返回true
bool PlatformAdministrator::CheckABooking(unsigned int share_percent) {
  if (platform_belong_.ViewAnUncheckedBooking()->IsCheckedByPlatform()) {
    return false;
  } else {
    platform_belong_.CheckABooking(share_percent);
    return true;
  }
}

// 拿出队首的订单 失败返回空指针
// 本机模拟多机操作不会产生
AbstractBooking* PlatformAdministrator::HoldABooking() {
  if (platform_belong_.ViewAnUncheckedBooking()->IsCheckedByPlatform()) {
    return NULL;
  } else {
    return platform_belong_.HoldABooking();
  }
}

// 按照输入抽成检查输入订单，返回订单指针
AbstractBooking* PlatformAdministrator::CheckABooking
                                          (unsigned int share_percent,
                                         AbstractBooking* booking) {
  if (booking == NULL) {
    return NULL;
  } else {
    return platform_belong_.CheckABooking(booking, share_percent);
  }
}

// 拒绝输入订单
bool PlatformAdministrator::RejectAbooking(AbstractBooking* booking) {
  platform_belong_.RejectABooking(booking);
  return true;
}

// 检查队首申请，成功返回真
JoinApplication* PlatformAdministrator::HoldAnApp() {
  if (platform_belong_.ViewAnUncheckApp() == NULL) {
    return NULL;
  }
  if (platform_belong_.ViewAnUncheckApp()->IsPass()) {
    return NULL;
  } else {
    return platform_belong_.HoldAnApp();
  }
}

// 拿出队首申请，返回其指针
JoinApplication* PlatformAdministrator::CheckAnApp(JoinApplication* app) {
  if (app == NULL) {
    return NULL;
  } else {
    platform_belong_.CheckAnApp(app);
    return app;
  }
}

// 检查输入申请，返回其指针
bool PlatformAdministrator::CheckAnApp() {
  if (platform_belong_.ViewAnUncheckApp()->IsPass()) {
    return false;
  } else {
    platform_belong_.CheckAnApp();
    return true;
  }
}

// 拒绝输入申请，成功返回true
bool PlatformAdministrator::RejectAnApp(JoinApplication* app) {
  platform_belong_.RejectAnApp(app);
  return true;
}
