//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�abstractbooking.cpp
// ��ǰ�汾��1.0
// ժҪ�����ļ���Ҫʵ�����˶�Ӧͷ�ļ���Abstracting��ĳ�Ա������
// ���ߣ�������
// ������ڣ�2018.7.26
//****************************************************************************

#include "abstractbooking.h"

// AbstractBooking��Ĺ��캯�������봴�����ڡ����ۡ��������˿�ƽ̨�̼���λ�ĳ����á�
// ��Щ���ڳ�ʼ�����Ӧ�����ݳ�Ա�����ҽ���֧������顢���ܡ���ɵ�״̬��false����ˮ���ڣ�
// ֧��֮ǰ���ڲ���ƽ̨������ϵ����Ϊ0�����������Ὣ�κβ����ͷ�
AbstractBooking::AbstractBooking(const QDate& created_date, 
                                 unsigned int unit_price,
                                 unsigned int amount,
                                 const Customer& customer,
                                 const Platform& platform,
                                 const Business& business)
  : created_date_(created_date),
    unit_price_(unit_price),
    amount_(amount),
    is_payed_(false),
    is_fininshed_(false),
    is_checked_by_platform_(false), 
    is_accepted_by_business_(false),
    customer_(customer),
    platform_(platform),
    business_(business) {
  serial_number_ = 0;
  share_percent_ = 0;
}

/*virtual*/ AbstractBooking::~AbstractBooking() {}

//*******AbstractBooking�����ݳ�Ա��ȡֵ����,ȱ�ٶ�ƽ̨���õ�ȡֵ����*************
unsigned long int AbstractBooking::GetSerialNumber() const {
  return serial_number_;
}

const QDate& AbstractBooking::GetCreatedDate() const {
  return created_date_;
}


unsigned int AbstractBooking::GetUnitPrice() const {
  return unit_price_;
}

unsigned int AbstractBooking::GetAmount() const {
  return amount_;
}

unsigned int AbstractBooking::GetSharePercent() const {
  return share_percent_;
}

bool AbstractBooking::IsCheckedByPlatform() const {
  return is_checked_by_platform_;
}

bool AbstractBooking::IsPayed() const {
  return is_payed_;
}

bool AbstractBooking::IsAcceptedByBusiness() const {
  return is_accepted_by_business_;
}

bool AbstractBooking::IsFinished() const {
  return is_fininshed_;
}

const Customer& AbstractBooking::GetCustomer() const {
  return customer_;
}

const Business& AbstractBooking::GetBusiness() const {
  return business_;
}

//****************************************************************************

// ��ֵ����
// ������ˮ�ţ�������������ƽ̨��ʱ��ƽ̨�˵��á�
void AbstractBooking::SetSerialNumber(unsigned long int serial_number) {
  serial_number_ = serial_number;
}

// ���ó�ɣ���ƽ̨�˵�ҵ��Ա��Ҳ��PlatformAdministrator����ã�
void AbstractBooking::SetSharePercnet(unsigned int share_percent) {
  share_percent_ = share_percent;
}

// ����֧������������ض�����֧��������ɹ���ö����PaySituation��������Ϊ�Ѿ�֧����
// ���㣬֧���ɹ�������Ϣ��
AbstractBooking::PaySituation AbstractBooking::BePayed(unsigned int money) {
  if (IsPayed()) {
    return HAVEPAYED;
  }
  if (money < unit_price_ * amount_) {
    return NOTENOUGH;
  } else {
    is_payed_ = true;
    return SUCCESS;
  }
}

// ������������״̬����Ϊ�ǣ���ƽ̨��ҵ��Ա���á�
void AbstractBooking::BeChecked() {
  is_checked_by_platform_ = true;
}

// �����������ܵ�״̬����Ϊ�ǣ����̼Ҷ�ҵ��Ա����
void AbstractBooking::BeFinished() {
  is_fininshed_ = true;
}

// �����������ܵ�״̬����Ϊ�ǣ����̼Ҷ�ҵ��Ա����
void AbstractBooking::BeAccepted() {
  is_accepted_by_business_ = true;
}
