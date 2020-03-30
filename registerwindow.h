//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�registerwindow.h
// ��ǰ�汾��1.0
// ժҪ�����ļ���ʵ��ע�ᴰ����Ķ���
// ���ߣ�������
// ������ڣ�2018.7
//****************************************************************************

#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QDialog>

namespace Ui {
class RegisterWindow;
}

// �̳�QDialog��д�ĵ������
class RegisterWindow : public QDialog {
  Q_OBJECT

public:
  explicit RegisterWindow(QWidget *parent = 0);
  ~RegisterWindow();

private slots:
// �����˳�ע�ᴰ��
  void on_cancel_button_clicked();

// ��ʾ�û�ע������
  void on_user_type_combobox_currentIndexChanged(int index);

// ע��
  void on_register_button_clicked();

// ��ת���Ƶ�����
  void on_apply_button_clicked();

private:
  Ui::RegisterWindow *ui;
};

#endif // REGISTERWINDOW_H
