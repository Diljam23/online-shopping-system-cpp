#ifndef USER_H
#define USER_H

#include <string>
#include "ShoppingCart.h"
using namespace std;

class User {
protected:
  string name;
  string email;
  string shippingAddress;
  ShoppingCart cart;

public:
  User(string name, string email, string shippingAddress);
  virtual double getDiscount() const;
  virtual string getUserType() const;

  ShoppingCart& getCart();
  void checkout();
};
class RegularUser : public User {
public:
  RegularUser(string name, string email, string shippingAddress);
  string getUserType() const override;
};
class PremiumUser : public User {
public:
  PremiumUser(string name, string email, string shippingAddress);
  double getDiscount() const override;
  string getUserType() const override;
};
class VIPUser : public User {
public:
  VIPUser(string name, string email, string shippingAddress);
  double getDiscount() const override;
  string getUserType() const override;
};

#endif
