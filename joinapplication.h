//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�joinapplication.h
// ��ǰ�汾��1.0
// ժҪ�����ļ���ʵ�ֳ�����JoinApplication�Ķ��壬�ھƵ������ʹ������һ�����
// ���ߣ�������
// ������ڣ�2018.7��27
//****************************************************************************

#ifndef JOINAPPLICATION_H
#define JOINAPPLICATION_H
#include <qdatetime.h>
#include "abstractuser.h"
#include "business.h"
class Platform;

// JoinApplication�����������̼Һ�ƽ̨֮��ļ��������
// ���й���ö�ٳ�Ա��������������
// ˽�г�Ա�г����̼Һ�ƽ̨�˵����ã��󶨵��˻�ָ����Ƿ�ͨ��
// �����������һ���������Ϊ����ҵ��Ԥ���˽ӿ�
class JoinApplication {
public:
  enum  Applicationtype { HOTEL, TRAIN, AIRLINE, USERDEFINE };

  JoinApplication(Business& business, Platform& platform,
                  const QDate& created_date, Applicationtype app_type);
  ~JoinApplication();

//**********************ȡֵ����***********************************************
  Business& GetBusinessBelong();
  Platform& GetPlatformBelong();
  AbstractUser* GetFirstAccount();
  const QDate& GetCreatedDate() const;
  bool IsPass() const;
//****************************************************************************

//*********************��ֵ����************************************************
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
