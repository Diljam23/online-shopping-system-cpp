# online-shopping-system-cpp

The Multi-Threaded Online Shopping System is a C++ console application that simulate a simple online shopping experience. The purpose of this project is to demonstrate object-oriented programming, inheritance, encapsulation, polymorphism, input validation, inventory management, and multithreading. The application allows users to browse products, add items to a shopping cart, update cart quantities, remove products, and complete a simulated checkout process.

This project was designed around a real-world e-commerce system because online shopping applications are familiar and practical. Most online stores need to track products, manage inventory, support customer accounts, calculate totals, and process orders. This made the project a good choice for demonstrating the programming concepts learned throughout the course.

The application includes a Product class that stores product details such as Product ID, name, description, price, and stock quantity. Product information is kept private and accessed through public methods, which demonstrates encapsulation. The Product class also includes functions to update product information, reduce stock after a purchase, and display product details.

The ShoppingCart class manages the products a user adds to their cart. It stores products and quantities, calculates the total cost, displays the cart, removes products, and updates product quantities. This keeps cart-related functionality separate from product and user information, making the program more organized and easier to maintain.

The User class stores customer information such as name, email, shipping address, and shopping cart. The program also includes three different user types: RegularUser, PremiumUser, and VIPUser. These classes demonstrate inheritance from the User class. They also demonstrate inheritance because they reuse common features from the User class. They also demonstrate polymorphism because each user type can have a different discount. Regular users receive no discount, Premium users receive a 10% discount, and VIP users receive a 20% discount.

A checkout system is included to simulate payment processing. When the user checks out, the program asks for confirmation, checks whether the cart is empty, validates that enough inventory is available, update product stock, calculates the discount, and prints an order summary. The order summary includes the customer name, email, user type, shipping address, cart contents, discount, final total, and payment status.

Multithreading is one of the most important parts of this project. The program includes a demo where multiple users shop at the same time. This simulates a real-world online store where many customers may be interacting with the system at once. A mutex lock is used to protect shared inventory data. This prevents race conditions and helps make sure product stock is updated safely when multiple users are shopping concurrently.

Error handling and validation were also added to improve the reliability of the application. The program checks for invalid menu choices, non-number input, negative quantities, insufficient stock, invalid product IDs, and empty shopping carts. These checks help prevent the application from crashing and make the program easier for users to interact with.

## Files in this Project

### main.cpp
This file contains the main menu, product list, user objects, checkout processing, input validation, and multithreading demo.

### Product.h
This header file declares the Product class and its attributes and methods.

### Product.cpp
This file implements the Product class functions, including displaying products, updating product details, and reducing stock.

### ShoppingCart.h
This header file declares the CartItem and ShoppingCart classes.

### ShoppingCart.cpp
This file impelments shopping cart functions such as adding products, removing products, updating quantities, displaying cart contents, and calculating totals.

### User.h
This header file decalres the User base class and the RegularUser, PremiumUser, and VIPUser derived classes.

### User.cpp
This file implements the user classes, discount behavior, user type behavior, aand checkout summary.

### Design Decisions
I chose to separate the program into multiple files because this makes the application more organized and professional. Instead of placing all of the code into one large file, each class has its own header and implementation file. This makes the project easier to read, test, update, and explain.

I also chose to use inheritance for the user types because regular, premium and VIP users share many of the same features. They all have names, emails, shipping addresses, and shopping carts. However they have different discount privileges. Using inheritance allowed me to reuse common code while still giving each user type its own behavior.

A mutex was included because product inventory is a shared resource. In the multithreading demo, several users can shop at the same time. Without a mutex, two users could try to update the same product stock at the same moment, which could cause incorrect inventory values. The mutex helps keep the data accurate and demonstrates safe concurrent programming.

Overall, this project creates a complete C++ shopping application that meets the assignment requirements while showing important programming concepts in a realistic way.
