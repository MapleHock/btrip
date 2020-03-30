//****************************************************************************
// Copyright [2018] <������>
// �ļ����ƣ�administratortab.h
// ��ǰ�汾��1.0
// ժҪ�����ļ���ʵ�ֶ�Amenities��Ķ��塣����Ϊ��Hotel��ķḻ����
// ���ߣ�������
// ������ڣ�2018.7.28
//****************************************************************************

// TODO��ƫ�ػ�ģ��Բ����ͽ��и���Ч�Ĵ洢

#ifndef AMENITIES_H
#define AMENITIES_H

// Amenities���Hotel��ķḻ����
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
//**************************ȡֵ����*******************************************
  bool IsFreeWifi() const;
  bool IsAirportPickup() const;
  bool IsFreeParking() const;
  bool IsFront24Hours() const;
  bool IsNonSomkingFloor() const;
  bool IsLuggageStorage() const;
  bool IsWakeUp() const;
  bool IsClothService() const;
//****************************************************************************

//*************************��ֵ����********************************************
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
