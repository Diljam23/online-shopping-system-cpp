#include "Product.h"
#include <iostream>
using namespace std;

Product::Product(int id, string name, string description, double price, int stock) {
    this->id = id;
    this->name = name;
    this->description = description;
    this->price = price;
    this->stock = stock;
}
int Product::getId() const {
  return id;
}
string Product::getname() const {
  return name;
}
string Product::getDescription() const {
  return description;
}
double Product::getPrice() const {
  return price;
}
int Product::getStock() const {
  return stock;
}

void Product::updateProduct(string newName, string newDescription, double newPrice, int newStock) {
  name = newName;
  description = newDescription;
  price = newPrice;
  stock = newStock;
}

bool Product::reduceStock(int quantity) {
  if (quantity <= stock) {
      stock -= quantity;
      return true;
  }
  return false;
}

void Product::displayProduct() const {
  cout << "ID: " << id
       << " | Name: " << name
       << " | Description: " << description
       << " | Price: " << price
       << " | Stock: " << stock << endl;
}
