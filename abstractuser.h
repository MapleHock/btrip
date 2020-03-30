//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�abstractuser.h
// ��ǰ�汾��1.0
// ժҪ�����ļ���ʵ�ֶ�AbstractUser��Ķ��塣AbstractUser���Ǹ��������û��Ļ���
// ���ߣ�������
// ������ڣ�2018.7.26
//****************************************************************************

#ifndef ABSTRACTUSER_H
#define ABSTRACTUSER_H
#include <string>
using std::string;

// AbstractUser�࣬ӵ��˽�����ݳ�Ա�û��������롢�Ƿ񱻼���乫�г�Ա������ȡֵ�����⣬
// ����������Ͷ����˻���������Ϊ��������Ҫ���ڱ��̳���ʵ�ֲ�ͬ���͵��û�
class AbstractUser {
public:

// AbstractUser��Ĺ��캯�������������ء��޲�������������һ���û�������Ϊ�յĶ����˻���
// �����������ݿ�ʱ����Ϊ��Ч����ע������һ������������û�����������һ��������˻�
  AbstractUser();
  AbstractUser(const string& username, const string& password);
  virtual ~AbstractUser();

//*************** ȡֵ����*****************************************************
  const string& GetUsername() const;
  const string& GetPassword() const;
  bool IsActived() const;
//****************************************************************************

// ������������Ƿ���˻�����һ�£�һ�·���true�����ڵ�¼��
  bool CheckPassword(const string& password_written) const;

// �������룬��һ������Ϊ���ԭʼ���룬�ڶ�Ϊ�����롣��ԭʼ������˻�������ͬ�����˻����룬
// ��Ϊ�����룬������
  bool ResetPassword(const string& old_password, const string& new_password);

// ������˻�����is_actived_��Ϊfalse��true
  void BlockAccount();
  void ActiveAccount();
protected:
private:
  const string username_;
  string password_;
  bool is_actived_;
};

#endif // !ABSTRACTUSER_H
