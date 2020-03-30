//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：licnse.h
// 当前版本：1.0
// 摘要：本文件中实现了License类的成员函数的定义。后被JoinApplication增加功能取代
// 作者：吴文绪
// 完成日期：2018.7.27
//****************************************************************************

#include "license.h"

License::License(const string& registration_number, const string& company_name,
                 const string& legal_person_name, const QDate& registration_date,
                 const int validity_year)
  : registration_number_(registration_number), company_name_(company_name),
    legal_person_name_(legal_person_name), registration_date_(registration_date),
    expiry_date_(registration_date)
{
  expiry_date_.addYears(validity_year);
  is_actived_ = true;
}

License::~License() {}

//*********************************取值函数***********************************
const string& License::GetRegistrationNumber() const {
  return registration_number_;
}

const string& License::GetCompanyName() const {
  return company_name_;
}

const string& License::GetLegalPersonName() const {
  return legal_person_name_;
}

const QDate& License::GetRegistrationDate() const {
  return registration_date_;
}

const QDate& License::GetExpiryDate() const {
  return expiry_date_;
}

bool License::IsActived() const {
  return is_actived_;
}

//***************************************************************************

//延长License使用年限
bool License::ExtendValidity(int year) {
  if (IsActived()) {
    expiry_date_.addYears(year);
    return true;
  } else {
    return false;
  }
}

// 吊销License
void License::deactive() {
  is_actived_ = false;
}
