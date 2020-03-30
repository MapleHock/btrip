//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：joinapplication.h
// 当前版本：1.0
// 摘要：本文件中实现抽象类JoinApplication的定义，在酒店管理中使用其中一种情况
// 作者：吴文绪
// 完成日期：2018.7。27
//****************************************************************************

#ifndef JOINAPPLICATION_H
#define JOINAPPLICATION_H
#include <qdatetime.h>
#include "abstractuser.h"
#include "business.h"
class Platform;

// JoinApplication类用于描述商家和平台之间的加盟申请等
// 其有公有枚举成员描述其申请类型
// 私有成员中持有商家和平台端的引用，绑定的账户指针和是否通过
// 程序仅适用了一种情况，但为其他业务预留了接口
class JoinApplication {
public:
  enum  Applicationtype { HOTEL, TRAIN, AIRLINE, USERDEFINE };

  JoinApplication(Business& business, Platform& platform,
                  const QDate& created_date, Applicationtype app_type);
  ~JoinApplication();

//**********************取值函数***********************************************
  Business& GetBusinessBelong();
  Platform& GetPlatformBelong();
  AbstractUser* GetFirstAccount();
  const QDate& GetCreatedDate() const;
  bool IsPass() const;
//****************************************************************************

//*********************设值函数************************************************
  void ResetFirstAccount(AbstractUser* new_account);
  void Passed();
protected:
private:
  Business& business_belong_;
  Platform& platform_belong_;
  AbstractUser* first_manager_account_;
  const QDate created_date_;
  bool is_pass_;
  Applicationtype application_type_;
};

#endif // !JOINAPPLICATION_H
