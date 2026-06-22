#include "ShoppingCart.h"
#include <iostream>
using namespace std;

CartItem::CartItem(Product* product, int quantity) {
  this->product = product;
  this->quantity = quantity;
}
void ShoppingCart::addItem(Product* product, int quantity) {
  for (auto& item : items) {
      if (item.product->getId() == product->getId()) {
          item.quantity += quantity;
          cout << "Quantity updated in cart.\n";
          return;
      }
  }
  items.push_back(CartItem(product, quantity));
  cout << "Product added to cart.\n";
}
void ShoppingCart::removeItem(int productId) {
  for (auto it = items.begin(); it != items.end(); ++it) {
      if (it->product->getId() == productId) {
          items.erase(it);
          cout << "Product removed from cart.\n";
          return;
      }
  }
  cout << "Product was not found in cart.\n";
}
void ShoppingCart::updateQuantity(int productId, int quantity) {
  if (quantity <= 0) {
      removeItem(productId);
      return;
  }
  for (auto& item : items) {
      if (item.product->getId() == productId) {
          item.quantity = quantity;
          cout << "Cart quantity updated.\n";
          return;
      }
  }
  cout << "Product was not found in cart.\n";
}
void ShoppingCart::displayCart() const {
  if (items.empty()) {
      cout << "Your shopping cart is empty.\n"
        return;
  }
  cout << "\n===== Shopping Cart =====\n";

  for (const auto& item : items) {
      cout << item.product->getName()
           << " | Quantity: " << items.quantity
           << " | Subtotal: $" << item.product->getPrice() * item.quantity
           <<endl;
  }
  cout << "Cart Total: $" << calculateTotal() << endl;
}

double ShoppingCart::calculateTotal()
const {
  double total = 0;

  for (const auto& item : items) {
      total += item.product->getPrice() * item.quantity;
  }
  return total;
}

bool ShoppingCart::isEmpty() const {
  return items.empty();
}

vector<CartItem>& ShoppingCart::getItems()
{
  return items;
}

