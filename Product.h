#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

class Product {
private:
  int id;
  string name;
  string description;
  double price;
  int stock;

public:
  Product(int id, string name, string description, double price, int stock);
      int getId() const;
      string getName() const;
      string getDescription() const;
      double getPrice() const;
      int getStock() const;

      void updateProduct(string newName, string newDescription, double newPrice, int newStock);
      bool reduceStock(int quantity);
      void displayProduct() const;
};
#endif
