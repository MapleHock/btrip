//****************************************************************************
// Copyright [2018] <吴文绪>
// 文件名称：administratortab.h
// 当前版本：1.0
// 摘要：本文件中实现对Amenities类的成员函数定义。本类为对Hotel类的丰富描述
// 作者：吴文绪
// 完成日期：2018.7.28
//****************************************************************************

#include "amenities.h"

Amenities::Amenities(bool is_free_wifi /*=false*/,
                     bool is_airport_pickup /*=false*/,
                     bool is_free_parking /*=false*/,
                     bool is_front_24hours /*=false*/,
                     bool is_non_somking_floor /*=false*/,
                     bool is_luggage_storage /*=false*/,
                     bool is_wake_up /*=false*/,
                     bool is_cloth_service /*=false*/) 
  : is_free_wifi_(is_free_wifi),
    is_airport_pickup_(is_airport_pickup),
    is_free_parking_(is_free_parking),
    is_front_24hours_(is_front_24hours),
    is_non_somking_floor_(is_non_somking_floor),
    is_luggage_storage_(is_luggage_storage),
    is_wake_up_(is_wake_up),
    is_cloth_service_(is_cloth_service){}

Amenities::~Amenities() {}

//**************************取值函数*******************************************
bool Amenities::IsFreeWifi() const {
  return is_free_wifi_;
}

bool Amenities::IsAirportPickup() const {
  return is_airport_pickup_;
}

bool Amenities::IsFreeParking() const {
  return is_free_parking_;
}

bool Amenities::IsFront24Hours() const {
  return is_front_24hours_;
}

bool Amenities::IsNonSomkingFloor() const {
  return is_non_somking_floor_;
}

bool Amenities::IsLuggageStorage() const {
  return is_luggage_storage_;
}

bool Amenities::IsWakeUp() const {
  return is_wake_up_;
}

bool Amenities::IsClothService() const {
  return is_cloth_service_;
}
//****************************************************************************

//*************************设值函数********************************************
void Amenities::SetFreeWifi(bool new_is_free_wifi) {
  is_free_wifi_ = new_is_free_wifi;
}

void Amenities::SetAirportPickup(bool new_is_airport_pickup) {
  is_airport_pickup_ = new_is_airport_pickup;
}

void Amenities::SetFreeParking(bool new_is_free_parking) {
  is_free_parking_ = new_is_free_parking;
}

void Amenities::SetFront24Hours(bool new_is_front_24hours) {
  is_front_24hours_ = new_is_front_24hours;
}

void Amenities::SetNonSomkingFloor(bool new_is_non_somking_floor) {
  is_non_somking_floor_ = new_is_non_somking_floor;
}

void Amenities::SetLuggageStorage(bool new_is_luggage_storage) {
  is_luggage_storage_ = new_is_luggage_storage;
}

void Amenities::SetWakeUp(bool new_is_wake_up) {
  is_wake_up_ = new_is_wake_up;
}

void Amenities::SetClothService(bool new_is_cloth_service) {
  is_cloth_service_ = new_is_cloth_service;
}
