//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：hotelapplicationstep.h
// 当前版本：1.0
// 摘要：本文件中实现了HotelApplicationStep，作为酒店递交申请向导界面
// 作者：吴文绪
// 完成日期：2018.7.28
//****************************************************************************

#ifndef HOTELAPPLICATIONSTEP_H
#define HOTELAPPLICATIONSTEP_H

#include <QWizard>

#include "room.h"

namespace Ui {
class HotelApplicationStep;
}

// HotelApplicationStep类，继承QWizrad类完成分析
class HotelApplicationStep : public QWizard {
  Q_OBJECT

public:
  enum Page {
    WElCOME, NOTICE, HOTELINFO, ROOM, FINISH
  };

  explicit HotelApplicationStep(QWidget *parent = 0);
  ~HotelApplicationStep();

private slots:

// 翻页时用于检测必填信息是否完成的函数
  void on_HotelApplicationStep_currentIdChanged(int id);

// 检测是否是按下fninsh退出
  void on_HotelApplicationStep_finished(int result);

// 增加房间
  void on_add_button_clicked();

//删除房间
  void on_delete_button_clicked();

// 进入到拷贝相同房间界面
  void on_copy_button_clicked();

// 退出到拷贝相同房间界面
  void on_copy_cancel_button_clicked();

// 拷贝相同房间
  void on_copy_done_button_clicked();

private:
// 清空房间信息填写窗,由add后调用
  void ClearRoomInfoLeft();

// 值转换函数
  QString BoolToQstring(bool bool_);
  bool QstringToBool(const QString& qstring);
  Room::BedType QStringToBedType(const QString& qstring);

  Ui::HotelApplicationStep *ui;
};

#endif // HOTELAPPLICATIONSTEP_H
