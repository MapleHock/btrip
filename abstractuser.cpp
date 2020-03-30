//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�abstractuser.cpp
// ��ǰ�汾��1.0
// ժҪ�����ļ���ʵ�ֶ�AbstractUser��ĳ�Ա�����Ķ���
// ���ߣ�������
// ������ڣ�2018.7.26
//****************************************************************************

#include "abstractuser.h"

// AbstractUser��Ĺ��캯�������������ء��޲�������������һ���û�������Ϊ�յĶ����˻���
// �����������ݿ�ʱ����Ϊ��Ч����ע������һ������������û�����������һ��������˻�
AbstractUser::AbstractUser() : is_actived_(false) {}

AbstractUser::AbstractUser(const string& username, const string& password)
  : username_(username), password_(password), is_actived_(true) {}

/*virtual*/ AbstractUser::~AbstractUser() {}

//***********AbstractUser���ȡֵ����******************************************
const string& AbstractUser::GetUsername() const {
  return username_;
}

const string& AbstractUser::GetPassword() const {
  return password_;
}

bool AbstractUser::IsActived() const {
  return is_actived_;
}

//***************************************************************************

// ������������Ƿ���˻�����һ�£�һ�·���true�����ڵ�¼��
bool AbstractUser::CheckPassword(const string& password_written) const {
  return password_written == password_;
}

// �������룬��һ������Ϊ���ԭʼ���룬�ڶ�Ϊ�����롣��ԭʼ������˻�������ͬ�����˻����룬
// ��Ϊ�����룬������
bool AbstractUser::ResetPassword(const string& old_password,
                                 const string& new_password) {
  if (CheckPassword(old_password)) {
    password_ = new_password;
    return true;
  } else {
    return false;
  }
}

// ������˻�����is_actived_��Ϊfalse��true
void AbstractUser::BlockAccount() {
  is_actived_ = false;
}

void AbstractUser::ActiveAccount() {
  is_actived_ = true;
}
