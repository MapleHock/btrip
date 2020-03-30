//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：abstractuser.h
// 当前版本：1.0
// 摘要：本文件中实现对AbstractUser类的定义。AbstractUser类是各个类型用户的基类
// 作者：吴文绪
// 完成日期：2018.7.26
//****************************************************************************

#ifndef ABSTRACTUSER_H
#define ABSTRACTUSER_H
#include <string>
using std::string;

// AbstractUser类，拥有私有数据成员用户名、密码、是否被激活。其公有成员函数除取值函数外，
// 还包括激活和冻结账户。本类作为抽象类主要用于被继承以实现不同类型的用户
class AbstractUser {
public:

// AbstractUser类的构造函数。有两个重载。无参数的类型生成一个用户名密码为空的冻结账户，
// 会在载入数据库时被视为无效数据注销。另一个根据输入的用户名密码生成一个激活的账户
  AbstractUser();
  AbstractUser(const string& username, const string& password);
  virtual ~AbstractUser();

//*************** 取值函数*****************************************************
  const string& GetUsername() const;
  const string& GetPassword() const;
  bool IsActived() const;
//****************************************************************************

// 检测输入密码是否和账户密码一致，一致返回true。用于登录。
  bool CheckPassword(const string& password_written) const;

// 重置密码，第一个参数为检测原始密码，第二为新密码。若原始密码和账户密码相同，将账户密码，
// 置为新密码，返回真
  bool ResetPassword(const string& old_password, const string& new_password);

// 激活冻结账户，将is_actived_设为false或true
  void BlockAccount();
  void ActiveAccount();
protected:
private:
  const string username_;
  string password_;
  bool is_actived_;
};

#endif // !ABSTRACTUSER_H
