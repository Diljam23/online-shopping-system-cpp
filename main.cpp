#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <limits>

#include "Product.h"
#include "ShoppingCart.h"
#include "User.h"

using namespace std;

mutex inventoryMutex;

void displayProducts(const vector<Product>& products) {
  cout << "\n===== Available Products =====\n";
  for (const auto& product : products) {
      product.displayProduct();
  }
}
Product* findProduct(vector<Product>& products, int id) {
  for (auto& product : products) {
      if (product.getId() == id) {
          return &product;
      }
  }
  return nullptr;
}
void clearInput() {
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void processCheckout(User& user) {
  lock_guard<mutex>
  lock(inventoryMutex);
  for (auto& item : user.getCart().getItems()) {
      if (item.quantity > item.product->getStock()) {
          cout << "Checkout failed. Not enough stock for " << item.product->getName() <<".\n";
          return;
      }
  }
  for (auto& item : user.getCart().getItems()) {
      item.product->reduceStock(item.quantity);
  }

  void simulatedShopping(User& user, Product& Product, int quantity) {
{
  lock_guard<mutex>
  lock(inventoryMutex);
  cout << "\n" << user.getUserType()
       << " is shopping in a separate thread.\n";
}
user.getCart().addItem(&product, quantity);
processCheckout(user);
  }
int main(){
  vector<Product> products = {
        Product(1, "Laptop", "Portable computer for school or work", 899.99, 5),
        Product(2, "Wireless Mouse", "Bluetooth computer mouse", 24.99, 10),
        Product(3, "Keyboard", "USB mechanical keyboard", 49.99, 8),
        Product(4, "Headphones", "Noise-cancelling headphones", 79.99, 6)
  }
  RegularUser regular("Jamie Dilley", "jamie@email.com", "Fennimore, WI");
  PremiumUser premium("Sarah Smith", "sarah@email.com", "Wausau, WI");
  VIPUser vip("Mike Johnson", "mike@email.com", "Milwaukee, WI");

  int choice;
  do {
      cout << "\n===== Online Shopping System =====\n";
      cout << "1. View Products\n";
      cout << "2. Add Products\n";
      cout << "3. Remove Product from Cart\n";
      cout << "4. Update Cart Quantity\n";
      cout << "5. View Cart\n";
      cout << "6. Checkout\n";
      cout << "7. Update Product Information\n";
      cout << "8. Run Multithreading Demo\n";
      cout << "9. Exit\n";
      cout << "Enter your choice: ";
      cin >> choice;

      if (cin.fail()) {
          clearInput();
          cout << "Invalid input. Please enter a number.\n";
          continue;
      }
      if (choice == 1) {
          displayProducts(products);
      }
      else if (choice == 2) {
          int id;
          int quantity;

          displayProducts(products);
          cout << "Enter product ID: ";
          cin >> quantity;

          if (quantity <= 0) {
            cout << "Quantity must be greater than zero.\n";
            continue;
          }

          Product* product = finalProduct(products, id);
          if (product == nullptr) {
            cout << "Invalid product ID.\n";
          }
          else if (quantity > product->getStock()) {
          }
          else
          {
          regular.getCart().addItem(product, quantity);
          }
      }
      else if (choice == 3) {
          int id;

          cout << "Enter product ID to remove from cart: ";
          cin >> id;

          regular.getCart().removeItem(id);
      }
      else if (choice == 4) {
          int id;
          int quantity;

          cout << ""Enter product ID to update: ";
          cin >> id;

          cout << "Enter new quantity: ";
          cin >> quantity;

          regular.getCart().updateQuantity(id, quantity);
      }
      else if (choice == 5) {

      regular.getCart().displayCart();
      }
      else if (choice == 6) {
          string confirm;

          cout << "Would you like to complete your purchase? Type yes or no: ";
          cin >> confirm;

          if (confirm == "yes" || confirm == "Yes") {
            processCheckout(regular);
          }
          else {
                cout << "Checkout cancelled.\n";
          }
      }
      else if (choice == 7) {
            int id;
            string name;
            string description;
            double price;
            int stock;

            displayProducts(products);

            cout << "Enter product ID to update: ";
            cin >> id;

            Product* product = findProducts(products, id);
            if (product == nullptr) {

                cout << "Invalid product ID.\n";
                continue;
            }
            clearInput();

            cout << "Enter new product name: ";
            getline(cin, name);

            cout << "Enter new product description: ";
            getline(cin, description);

            cout << "Enter new price: ";
            cin >> price;

            cout << "Enter new stock: ";
            cin >> stock;

            if (price < 0 || stock < 0) {
                cout << "Price and stock cannot be negative.\n";
                continue;
            }
            else if (choice == 8) {
                  cout << "\nRunning multithreading demo...\n";

                  thread1 t1(simulatedShopping, ref(premium), ref(products[0]), 1);
                  thread2 t2(simulatedShopping, ref(vip), ref(products[1]), 2);
                  thread3 t3(simulatedShopping, ref(regular), ref(products[2]), 1);

                  t1.join();
                  t2.join();
                  t3.join();

                  cout << "\nMultithreading demo complete.\n";
            }
            else if (choice == 9) {
                  cout << "Exiting program. Goodbye!\n";
            }
            else {
                cout << "Invalid menu choice. Please try again.\n";
            }
      } while (choice != 9);
      return 0;
  }
            
        
               
        
