//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�hotelapplicationstep.h
// ��ǰ�汾��1.0
// ժҪ�����ļ���ʵ����HotelApplicationStep����Ϊ�Ƶ�ݽ������򵼽���
// ���ߣ�������
// ������ڣ�2018.7.28
//****************************************************************************

#ifndef HOTELAPPLICATIONSTEP_H
#define HOTELAPPLICATIONSTEP_H

#include <QWizard>

#include "room.h"

namespace Ui {
class HotelApplicationStep;
}

// HotelApplicationStep�࣬�̳�QWizrad����ɷ���
class HotelApplicationStep : public QWizard {
  Q_OBJECT

public:
  enum Page {
    WElCOME, NOTICE, HOTELINFO, ROOM, FINISH
  };

  explicit HotelApplicationStep(QWidget *parent = 0);
  ~HotelApplicationStep();

private slots:

// ��ҳʱ���ڼ�������Ϣ�Ƿ���ɵĺ���
  void on_HotelApplicationStep_currentIdChanged(int id);

// ����Ƿ��ǰ���fninsh�˳�
  void on_HotelApplicationStep_finished(int result);

// ���ӷ���
  void on_add_button_clicked();

//ɾ������
  void on_delete_button_clicked();

// ���뵽������ͬ�������
  void on_copy_button_clicked();

// �˳���������ͬ�������
  void on_copy_cancel_button_clicked();

// ������ͬ����
  void on_copy_done_button_clicked();

private:
// ��շ�����Ϣ��д��,��add�����
  void ClearRoomInfoLeft();

// ֵת������
  QString BoolToQstring(bool bool_);
  bool QstringToBool(const QString& qstring);
  Room::BedType QStringToBedType(const QString& qstring);

  Ui::HotelApplicationStep *ui;
};

#endif // HOTELAPPLICATIONSTEP_H
