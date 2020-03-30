//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：licnse.h
// 当前版本：1.0
// 摘要：本文件中实现了License类的定义。后被JoinApplication增加功能取代
// 作者：吴文绪
// 完成日期：2018.7.27
//****************************************************************************

#ifndef LICENSE_H
#define LICENSE_H
#include <qdatetime.h>
#include <string>
using std::string;

// License类有私有数据成员，注册号、公司名、法人名、注册日期、有效期、是否激活
class License {
public:
  License(const string& registration_number, const string& company_name,
          const string& legal_person_name, const QDate& registration_date,
          const int validity_year);
  ~License();
//*********************************取值函数***********************************
  const string& GetRegistrationNumber() const;
  const string& GetCompanyName() const;
  const string& GetLegalPersonName() const;
  const QDate& GetRegistrationDate() const;
  const QDate& GetExpiryDate() const;
  bool IsActived() const;
//***************************************************************************

//延长License使用年限
  bool ExtendValidity(int year);
// 吊销License
  void deactive();
protected:
private:
  const string registration_number_;
  string company_name_;
  string legal_person_name_;
  const QDate registration_date_;
  QDate expiry_date_;
  bool is_actived_;
};


#endif // !LICENSE_H
