//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�licnse.h
// ��ǰ�汾��1.0
// ժҪ�����ļ���ʵ����License��Ķ��塣��JoinApplication���ӹ���ȡ��
// ���ߣ�������
// ������ڣ�2018.7.27
//****************************************************************************

#ifndef LICENSE_H
#define LICENSE_H
#include <qdatetime.h>
#include <string>
using std::string;

// License����˽�����ݳ�Ա��ע��š���˾������������ע�����ڡ���Ч�ڡ��Ƿ񼤻�
class License {
public:
  License(const string& registration_number, const string& company_name,
          const string& legal_person_name, const QDate& registration_date,
          const int validity_year);
  ~License();
//*********************************ȡֵ����***********************************
  const string& GetRegistrationNumber() const;
  const string& GetCompanyName() const;
  const string& GetLegalPersonName() const;
  const QDate& GetRegistrationDate() const;
  const QDate& GetExpiryDate() const;
  bool IsActived() const;
//***************************************************************************

//�ӳ�Licenseʹ������
  bool ExtendValidity(int year);
// ����License
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
