//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�patformadministrator.h
// ��ǰ�汾��1.0
// ժҪ�����ļ���ʵ��ҵ��ԱPlatformAdministrator��Ķ��塣
// ���ߣ�������
// ������ڣ�2018.7.28
//****************************************************************************

#ifndef PLATFORMADMINISTRATOR_H
#define PLATFORMADMINISTRATOR_H
#include "abstractuser.h"
#include "platform.h"

// PlatformAdministrator��̳���AbstractUser�ಢ����������ƽ̨�ĳ�������
// ͨ��������������ƽ̨��Ӧ�ĺ�����ɲ鿴�������ͱ����ְ��
class PlatformAdministrator : public AbstractUser {
public:
  PlatformAdministrator(const string& username, const string& password,
                        Platform& platform_belong);
  ~PlatformAdministrator();

// ���������ɼ����׶��������ɹ�����true
  bool CheckABooking(unsigned int share_percent);

// �ó����׵Ķ��� ʧ�ܷ��ؿ�ָ��
// ����ģ���������������
  AbstractBooking* HoldABooking();

// ���������ɼ�����붩�������ض���ָ��
  AbstractBooking* CheckABooking(unsigned int share_percent,
                                AbstractBooking* booking);

// �ܾ����붩��
  bool RejectAbooking(AbstractBooking* booking);

// ���������룬�ɹ�������
  bool CheckAnApp();

// �ó��������룬������ָ��
  JoinApplication* HoldAnApp();

// ����������룬������ָ��
  JoinApplication* CheckAnApp(JoinApplication* app);

// �ܾ��������룬�ɹ�����true
  bool RejectAnApp(JoinApplication* app);
protected:
private:
  Platform& platform_belong_;
};

#endif // !PLATFORMADMINISTRATOR_H
