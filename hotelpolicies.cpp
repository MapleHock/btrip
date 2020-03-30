//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�hotelpolicies.cpp
// ��ǰ�汾��1.0
// ժҪ�����ļ���ʵ��HotelPolicies��ĳ�Ա������Ϊ�ḻ�Ƶ������������
// ���ߣ�������
// ������ڣ�2018.7.31
//****************************************************************************

#include "hotelpolicies.h"

HotelPolicies::HotelPolicies(unsigned int check_in_time /*=0*/, 
                             unsigned int check_out_time /*=0*/,
                             unsigned int max_children_per_adult /*=0*/,
                             bool is_pet_allowed /*=false*/,
                             bool is_free_breakfast /*=false*/,
                             const string& others /*="\0"*/)
  :check_in_time_(check_in_time),
   check_out_time_(check_out_time),
   max_children_per_adult_(max_children_per_adult),
   is_pet_allowed_(is_pet_allowed),
   is_free_breakfast_(is_free_breakfast),
   others_(others) {}

HotelPolicies::~HotelPolicies() {}

//*****************ȡֵ����****************************************************

unsigned int HotelPolicies::GetCheckInTime() const {
  return check_in_time_;
}

unsigned int HotelPolicies::GetCheckOutTime() const {
  return check_out_time_;
}

unsigned int HotelPolicies::GetMaxChildrenPerAdult() const {
  return max_children_per_adult_;
}

bool HotelPolicies::IsPetAllowed() const {
  return is_pet_allowed_;
}

bool HotelPolicies::IsFreeBreakfast() const {
  return is_free_breakfast_;
}

const string& HotelPolicies::GetOthers() const {
  return others_;
}

//****************************************************************************

//*****************��ֵ����****************************************************

void HotelPolicies::SetCheckIntime(unsigned int new_check_in_time) {
  check_in_time_ = new_check_in_time;
}

void HotelPolicies::SetCheckOutTime(unsigned int new_check_out_time) {
  check_out_time_ = new_check_out_time;
}

void HotelPolicies::SetMaxChildrenPerAdult(unsigned int new_max_children_per_adult_) {
  max_children_per_adult_ = new_max_children_per_adult_;
}

void HotelPolicies::SetIsPetAllowed(bool new_is_pet_allowed) {
  is_pet_allowed_ = new_is_pet_allowed;
}

void HotelPolicies::SetIsFreeBreakfast(bool new_is_free_breakfast) {
  is_free_breakfast_ = new_is_free_breakfast;
}

void HotelPolicies::SetOthers(const string& new_others) {
  others_ = new_others;
}
