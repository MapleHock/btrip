//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：patformadministrator.h
// 当前版本：1.0
// 摘要：本文件中实现业务员PlatformAdministrator类的定义。
// 作者：吴文绪
// 完成日期：2018.7.28
//****************************************************************************

#ifndef PLATFORMADMINISTRATOR_H
#define PLATFORMADMINISTRATOR_H
#include "abstractuser.h"
#include "platform.h"

// PlatformAdministrator类继承于AbstractUser类并增加了所处平台的持有引用
// 通过持有引用利用平台对应的函数完成查看审理订单和报告的职能
class PlatformAdministrator : public AbstractUser {
public:
  PlatformAdministrator(const string& username, const string& password,
                        Platform& platform_belong);
  ~PlatformAdministrator();

// 按照输入抽成检查队首订单，检查成功返回true
  bool CheckABooking(unsigned int share_percent);

// 拿出队首的订单 失败返回空指针
// 本机模拟多机操作不会产生
  AbstractBooking* HoldABooking();

// 按照输入抽成检查输入订单，返回订单指针
  AbstractBooking* CheckABooking(unsigned int share_percent,
                                AbstractBooking* booking);

// 拒绝输入订单
  bool RejectAbooking(AbstractBooking* booking);

// 检查队首申请，成功返回真
  bool CheckAnApp();

// 拿出队首申请，返回其指针
  JoinApplication* HoldAnApp();

// 检查输入申请，返回其指针
  JoinApplication* CheckAnApp(JoinApplication* app);

// 拒绝输入申请，成功返回true
  bool RejectAnApp(JoinApplication* app);
protected:
private:
  Platform& platform_belong_;
};

#endif // !PLATFORMADMINISTRATOR_H
