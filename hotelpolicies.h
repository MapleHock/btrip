//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：hotelpolicies.h
// 当前版本：1.0
// 摘要：本文件中实现HotelPolicies类，为丰富酒店的特征而设置
// 作者：吴文绪
// 完成日期：2018.7.31
//****************************************************************************

#ifndef HOTELPOLICIES_H
#define HOTELPOLICIES_H
#include <string>
using std::string;

// HotelPolicies类，作为对酒店的丰富描述
// 显示酒店的各方面的信息
class HotelPolicies {
public:
  HotelPolicies(unsigned int check_in_time = 0, unsigned int check_out_time = 0,
                unsigned int max_children_per_adult = 0,
                bool is_pet_allowed = false,
                bool is_free_breakfast = false,
                const string& others = "\0");
  ~HotelPolicies();
//*****************取值函数****************************************************
  unsigned int GetCheckInTime() const;
  unsigned int GetCheckOutTime() const;
  unsigned int GetMaxChildrenPerAdult() const;
  bool IsPetAllowed() const;
  bool IsFreeBreakfast() const;
  const string& GetOthers() const;
//****************************************************************************

//*****************设值函数****************************************************
  void SetCheckIntime(unsigned int new_check_in_time);
  void SetCheckOutTime(unsigned int new_check_out_time);
  void SetMaxChildrenPerAdult(unsigned int new_max_children_per_adult_);
  void SetIsPetAllowed(bool new_is_pet_allowed);
  void SetIsFreeBreakfast(bool new_is_free_breakfast);
  void SetOthers(const string& new_others);
protected:
private:
  unsigned int check_in_time_;
  unsigned int check_out_time_;
  unsigned int max_children_per_adult_;
  bool is_pet_allowed_;
  bool is_free_breakfast_;
  string others_;
};

#endif // !HOTELPOLICIES_H
