//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：abstractuser.cpp
// 当前版本：1.0
// 摘要：本文件中实现对AbstractUser类的成员函数的定义
// 作者：吴文绪
// 完成日期：2018.7.26
//****************************************************************************

#include "abstractuser.h"

// AbstractUser类的构造函数。有两个重载。无参数的类型生成一个用户名密码为空的冻结账户，
// 会在载入数据库时被视为无效数据注销。另一个根据输入的用户名密码生成一个激活的账户
AbstractUser::AbstractUser() : is_actived_(false) {}

AbstractUser::AbstractUser(const string& username, const string& password)
  : username_(username), password_(password), is_actived_(true) {}

/*virtual*/ AbstractUser::~AbstractUser() {}

//***********AbstractUser类的取值函数******************************************
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

// 检测输入密码是否和账户密码一致，一致返回true。用于登录。
bool AbstractUser::CheckPassword(const string& password_written) const {
  return password_written == password_;
}

// 重置密码，第一个参数为检测原始密码，第二为新密码。若原始密码和账户密码相同，将账户密码，
// 置为新密码，返回真
bool AbstractUser::ResetPassword(const string& old_password,
                                 const string& new_password) {
  if (CheckPassword(old_password)) {
    password_ = new_password;
    return true;
  } else {
    return false;
  }
}

// 激活冻结账户，将is_actived_设为false或true
void AbstractUser::BlockAccount() {
  is_actived_ = false;
}

void AbstractUser::ActiveAccount() {
  is_actived_ = true;
}
