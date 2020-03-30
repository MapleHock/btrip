//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�patformadministrator.cpp
// ��ǰ�汾��1.0
// ժҪ�����ļ���ʵ��ҵ��ԱPlatformAdministrator��ĳ�Ա�������塣
// ���ߣ�������
// ������ڣ�2018.7.28
//****************************************************************************

#include "platformadministrator.h"

PlatformAdministrator::PlatformAdministrator(const string& username, 
                                             const string& password,
                                             Platform& platform_belong) 
  : AbstractUser(username, password),
    platform_belong_(platform_belong) {}

PlatformAdministrator::~PlatformAdministrator() {}

// ���������ɼ����׶��������ɹ�����true
bool PlatformAdministrator::CheckABooking(unsigned int share_percent) {
  if (platform_belong_.ViewAnUncheckedBooking()->IsCheckedByPlatform()) {
    return false;
  } else {
    platform_belong_.CheckABooking(share_percent);
    return true;
  }
}

// �ó����׵Ķ��� ʧ�ܷ��ؿ�ָ��
// ����ģ���������������
AbstractBooking* PlatformAdministrator::HoldABooking() {
  if (platform_belong_.ViewAnUncheckedBooking()->IsCheckedByPlatform()) {
    return NULL;
  } else {
    return platform_belong_.HoldABooking();
  }
}

// ���������ɼ�����붩�������ض���ָ��
AbstractBooking* PlatformAdministrator::CheckABooking
                                          (unsigned int share_percent,
                                         AbstractBooking* booking) {
  if (booking == NULL) {
    return NULL;
  } else {
    return platform_belong_.CheckABooking(booking, share_percent);
  }
}

// �ܾ����붩��
bool PlatformAdministrator::RejectAbooking(AbstractBooking* booking) {
  platform_belong_.RejectABooking(booking);
  return true;
}

// ���������룬�ɹ�������
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

// �ó��������룬������ָ��
JoinApplication* PlatformAdministrator::CheckAnApp(JoinApplication* app) {
  if (app == NULL) {
    return NULL;
  } else {
    platform_belong_.CheckAnApp(app);
    return app;
  }
}

// ����������룬������ָ��
bool PlatformAdministrator::CheckAnApp() {
  if (platform_belong_.ViewAnUncheckApp()->IsPass()) {
    return false;
  } else {
    platform_belong_.CheckAnApp();
    return true;
  }
}

// �ܾ��������룬�ɹ�����true
bool PlatformAdministrator::RejectAnApp(JoinApplication* app) {
  platform_belong_.RejectAnApp(app);
  return true;
}
