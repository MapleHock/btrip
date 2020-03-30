//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�licnse.h
// ��ǰ�汾��1.0
// ժҪ�����ļ���ʵ����License��ĳ�Ա�����Ķ��塣��JoinApplication���ӹ���ȡ��
// ���ߣ�������
// ������ڣ�2018.7.27
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

//*********************************ȡֵ����***********************************
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

//�ӳ�Licenseʹ������
bool License::ExtendValidity(int year) {
  if (IsActived()) {
    expiry_date_.addYears(year);
    return true;
  } else {
    return false;
  }
}

// ����License
void License::deactive() {
  is_actived_ = false;
}
