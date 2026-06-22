#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <vector>
#include "product.h"
using namespace std;

class CartItem {
public:
  Product* product;
  int quantity;

  CartItem(Product* product, int quantity);
};

class ShoppingCart {
private:
  vector<CartItem> items;

public:
  void addItem(Product* product, int quantity);
  void removeItem(int productId);
  void updateQuantity(int productId, int quantity);
  void displayCart() const;
  double calculateTotal() const;
  bool isEmpty() const;
  vector<CartItem>& getItems();
};

#endif
