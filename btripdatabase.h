//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�btripdatabase.h
// ��ǰ�汾��1.0
// ժҪ�����ļ���ʵ�ֶ�BtripDatabase�Ķ��塣������Ҫ���ڷ�װ��������������Ҫ���ϴ�����
//      ���ݵĲ�����
// ���ߣ�������
// ������ڣ�2018.7
//****************************************************************************

#ifndef BTRIPDATABASE_H
#define BTRIPDATABASE_H

#include <QSqlDatabase>
#include "platform.h"

// ��BtripDatabase��ƽ̨��ʵ���Ͷ�Ӧ���Ƶ����ݿ�������ӣ�ʵ�����ݿ���ϴ�����
class BtripDatabase {
public:
// ���캯���������ƽָ̨��Ͷ�Ӧ�ļ��������ݿ����һ��ʵ���У��Ա�ʵ���ϴ�����
// ���������������ָ�롣
  BtripDatabase(Platform* platform, const QString& database_name);
  ~BtripDatabase();

// �������ݿ����ӣ������ɹ�����true
  bool CreateConnect();

// �����ݿ������ϴ����ڴ棬ȫ�������ϴ��ɹ�����true
  bool Upload();

// ���ڴ��д洢�����ݸ��������ݿ⣬ȫ�������ϴ��ɹ�����true
  bool UpdataDatabase();
// �رն�Ӧ���ݿ�
  void CloseDatabase();
private:
  Platform* platform_;
  QString database_name_;
  QSqlDatabase database_;

};

#endif // BTRIPDATABASE_H
