//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：administratortab.h
// 当前版本：1.0
// 摘要：本文件中实现对Amenities类的定义。本类为对Hotel类的丰富描述
// 作者：吴文绪
// 完成日期：2018.7.28
//****************************************************************************

// TODO用偏特化模板对布尔型进行更高效的存储

#ifndef AMENITIES_H
#define AMENITIES_H

// Amenities类对Hotel类的丰富描述
class Amenities {
public:
  Amenities(bool is_free_wifi = false,
            bool is_airport_pickup = false,
            bool is_free_parking = false,
            bool is_front_24hours = false,
            bool is_non_somking_floor = false,
            bool is_luggage_storage = false,
            bool is_wake_up = false,
            bool is_cloth_service = false);
  ~Amenities();
//**************************取值函数*******************************************
  bool IsFreeWifi() const;
  bool IsAirportPickup() const;
  bool IsFreeParking() const;
  bool IsFront24Hours() const;
  bool IsNonSomkingFloor() const;
  bool IsLuggageStorage() const;
  bool IsWakeUp() const;
  bool IsClothService() const;
//****************************************************************************

//*************************设值函数********************************************
  void SetFreeWifi(bool new_is_free_wifi);
  void SetAirportPickup(bool new_is_airport_pickup);
  void SetFreeParking(bool new_is_free_parking);
  void SetFront24Hours(bool new_is_front_24hours);
  void SetNonSomkingFloor(bool new_is_non_somking_floor);
  void SetLuggageStorage(bool new_is_luggage_storage);
  void SetWakeUp(bool new_is_wake_up);
  void SetClothService(bool new_is_cloth_service);
 //****************************************************************************
protected:
private:
  bool is_free_wifi_;
  bool is_airport_pickup_;
  bool is_free_parking_;
  bool is_front_24hours_;
  bool is_non_somking_floor_;
  bool is_luggage_storage_;
  bool is_wake_up_;
  bool is_cloth_service_;
};

#endif // !AMENITIES_H
