# cosmetic-shop-management-system-enhanced
💄 Cosmetic Shop Management System (C++)

A simple console-based management system built using C++ that helps manage products, customers, and suppliers of a cosmetic shop.
It allows adding, updating, viewing, searching, and deleting records — all from a clean, menu-driven interface.

🧾 Project Overview

This project simulates a basic Cosmetic Shop Management System that allows users to:

Manage Products (Add, Update, Search, Display, Delete)

Manage Customers (Add, Display, Delete)

Manage Suppliers (Add, Display, Delete)

Display all records in well-formatted tables

Prevent duplicate IDs and handle data updates gracefully

All operations are performed in-memory (no database required).

🛠️ Features
Feature	Description
Add / Update Product	Add a new product or update details & quantity of existing ones
Search Product	Find products by ID instantly
Delete Product	Remove a product from the inventory
Customer Management	Add, view, and delete customer details
Supplier Management	Add, view, and delete supplier information
Formatted Output	Displays all tables neatly using iomanip
Validation	Prevents duplicate IDs for all records
Menu-driven Interface	Easy to navigate and operate
🧩 Technologies Used

Language: C++

Concepts: Structures, Vectors, Loops, Conditionals, Functions, STL Algorithms

Headers Used:

<iostream> for input/output

<vector> for dynamic storage

<string> for string handling

<iomanip> for formatted tables

<algorithm> for STL utilities like any_of

⚙️ How to Run

Clone the repository:

git clone https://github.com/<your-username>/cosmetic-shop-management-system.git


Open the project folder:

cd cosmetic-shop-management-system


Compile the code:

g++ -o shop main.cpp


Run the program:

./shop

🧮 Menu Options
1. Add or Update Product
2. Display Products
3. Search Product
4. Delete Product
5. Add Customer
6. Display Customers
7. Delete Customer
8. Add Supplier
9. Display Suppliers
10. Delete Supplier
11. Exit

📸 Sample Output
------------------------------------------------------------
💄 COSMETIC SHOP MANAGEMENT SYSTEM 💄
------------------------------------------------------------
1. Add or Update Product
2. Display Products
3. Search Product
4. Delete Product
5. Add Customer
6. Display Customers
7. Delete Customer
8. Add Supplier
9. Display Suppliers
10. Delete Supplier
11. Exit
------------------------------------------------------------
Enter your choice: 1

Enter Product ID: 101
Enter Product Name: Lip Gloss
Enter Price: 199.99
Enter Manufacturer: Maybelline
Enter Expiry Date (dd-mm-yyyy): 12-08-2026
Enter Quantity: 20
✅ Product added successfully.

🚀 Future Enhancements

💾 File Handling – Save and load data from files

🧑‍💻 User Authentication – Admin & staff login system

📦 Billing System – Generate receipts for purchases

🧮 Stock Alerts – Notify when quantity is low

🧠 Database Integration – Use MySQL or SQLite for persistence
