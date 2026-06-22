#include "User.h"
#include <iostream>
using namespace std;

User::User(string name, string email, string shippingAddress) {
  this->name = name;
  this->email = email;
  this->shippingAddress = shippingAddress;
}
double User::getDiscount() const {
  return 0.0;
}
string User::getUserType() const {
  return "Regular User";
}
ShoppingCart& User::getCart() {
  return cart;
}
void User::Checkout() {
  if (cart.isEmpty()) {
      cout << "Checkout failed. Cart is empty.\n";
      return;
  }
  double total = cart.calculateTotal();
  double discount = total * getDiscount();
  double finalTotal = total - discount;

  cout << "\n===== Order Summary =====\n";
  cout << "Customer: " << name << endl;
  cout << "Email: " << email << endl;
  cout << "User Type: " << getUserType() << endl;
  cout << "Shipping Address: " << shippingAddress << endl;

  cart.displayCart();

  cout << "Discount: $" << discount << endl;
  cout << "Final Total: $" << finalTotal << endl;
  cout << "Payment Status: Approved\n";
  cout << "Order completed successfully.\n";
}
RegularUser::RegularUser(string name, string email, string shippingAddress)
  : User(name, email, shippingAddress){
  }
  string RegularUser::getUserType() const {
    return "Regular User";
  }
  PremiumUser::PremiumUser(string name, string email, string shippingAddress)
  : User(name, email, shippingAddress){
  }
  double PremiumUser::getDiscount() const {
    return 0.10;
  }
  string PremiumUser::getUserType() const {
    return "Premium User";
  }
  VIPUser::VIPUser(string name, string email, string shippingAddress)
  : User(name, email, shippingAddress){
  }
  double VIPUser::getDiscount() const {
    return 0.20;
  }
  string VIPUser::getUserType() const {
    return "VIP User";
  }
