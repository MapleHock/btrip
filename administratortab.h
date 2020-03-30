//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�administratortab.h
// ��ǰ�汾��1.0
// ժҪ�����ļ���ʵ�ֶ�AdministratorTab��Ķ��塣
//      AdministratorTab����ҵ��ԱPlatformAdministrator����Ӧ����Ҫ�������档��Ӧ��
//      ҵ�������Ҫʵ���˹�������Ͷ�����������
// ���ߣ�������
// ������ڣ�2018.7.26
//****************************************************************************

#ifndef ADMINISTRATORTAB_H
#define ADMINISTRATORTAB_H

#include <QTabWidget>

#include "platformadministrator.h"
#include "room.h"

namespace Ui {
class AdministratorTab;
}

// AdministratorTab��Ķ��塣��qt designerҳ������ƵĿؼ��Ͷ�Ӧ��ҵ��Ա��ɡ�
// ��Ҫ����ui����ɾƵ�����Ͷ����Ĺ���
class AdministratorTab : public QTabWidget {
  Q_OBJECT

public:
// AdministratorTab��Ĺ��캯������qt�Ļ������������˻�Աָ�룬��������ui��ײ�
  explicit AdministratorTab(PlatformAdministrator* current_account,
    QWidget *parent = 0);
  ~AdministratorTab();

private slots:

// PlatformAdministrator�������ʵ�������г��
  void on_hold_app_button_clicked();

 // PlatformAdministrator������������
  void on_check_app_button_clicked();

 // PlatformAdministrator�������ʵĶ������г��
  void on_hold_booking_button_clicked();

 // PlatformAdministrator�� ���� ������
  void on_check_button_clicked();

private:
  
// ����/����ˢ�£������ڳ�ʼ������������һ��������/�����������ں�õ���һ����������Ϣ
  void RefreshApp();
  void RefreshBooking();

// ����ת������������ת������/�����ж�Ӧ���������ͷ�����ʾ
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
