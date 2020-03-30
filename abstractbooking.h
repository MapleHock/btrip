// TODO find a way to obey standard and solve include each other

#ifndef ABSTRACTBOOKING_H
#define ABSTRACTBOOKING_H
#include <qdatetime.h>
//#include "customer.h"
//#include "platform.h"
//#include "business.h"
class Customer;
class Platform;
class Business;

// TODO make an undo system
class AbstractBooking {
public:
  enum PaySituation { HAVEPAYED, NOTENOUGH, SUCCESS };

  AbstractBooking(const QDate& created_date, 
                  unsigned int unit_price,
                  unsigned int amount,
                  const Customer& customer,
                  const Platform& platform,
                  const Business& business);
  virtual ~AbstractBooking();
  unsigned long int GetSerialNumber() const;
  const QDate& GetCreatedDate() const;
  unsigned int GetUnitPrice() const;
  unsigned int GetAmount() const;
  unsigned int GetSharePercent() const;
  bool IsCheckedByPlatform() const;
  bool IsPayed() const;
  bool IsAcceptedByBusiness() const;
  bool IsFinished() const;
  
  void SetSerialNumber(unsigned long int serial_number);
  void SetSharePercnet(unsigned int share_percent);
  void BeChecked();
  PaySituation BePayed(unsigned int money);
  void BeAccepted();
  void BeFinished();
  const Customer& GetCustomer() const;
  const Business& GetBusiness() const;
protected:
private:
  unsigned long int serial_number_;
  const QDate created_date_;
  unsigned int unit_price_;
  unsigned int amount_;
  unsigned int share_percent_;
  bool is_checked_by_platform_;
  bool is_payed_;
  bool is_accepted_by_business_;
  bool is_fininshed_;
  const Customer& customer_;
  const Platform& platform_;
  const Business& business_;
};

#endif // !BOOKING_H
