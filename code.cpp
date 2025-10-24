#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // for table formatting
#include <algorithm>  // <-- Add this

using namespace std;

struct Product {
    int id;
    string name;
    double price;
    string manufacturer;
    string expiryDate;
    int quantity;
};

struct Customer {
    int id;
    string name;
    string contact;
};

struct Supplier {
    int id;
    string name;
    string contact;
    string address;
};

// Global vectors
vector<Product> inventory;
vector<Customer> customers;
vector<Supplier> suppliers;

// Utility function for line separators
void printLine() {
    cout << string(80, '-') << endl;
}

// ---------- PRODUCT SECTION ----------

bool productExists(int id) {
    for (auto &p : inventory) if (p.id == id) return true;
    return false;
}

void addOrUpdateProduct() {
    int productId;
    cout << "\nEnter Product ID: ";
    cin >> productId;

    for (auto &product : inventory) {
        if (product.id == productId) {
            int choice;
            cout << "\nProduct already exists.\n";
            cout << "1. Update Quantity\n2. Update Full Details\nEnter choice: ";
            cin >> choice;

            if (choice == 1) {
                int addQty;
                cout << "Enter additional quantity: ";
                cin >> addQty;
                product.quantity += addQty;
                cout << "Quantity updated successfully.\n";
            } else if (choice == 2) {
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, product.name);
                cout << "Enter new price: ";
                cin >> product.price;
                cout << "Enter new manufacturer: ";
                cin.ignore();
                getline(cin, product.manufacturer);
                cout << "Enter new expiry date (dd-mm-yyyy): ";
                getline(cin, product.expiryDate);
                cout << "Enter new quantity: ";
                cin >> product.quantity;
                cout << "Product details updated successfully.\n";
            }
            return;
        }
    }

    // Add new product
    Product newProduct;
    newProduct.id = productId;
    cout << "Enter Product Name: ";
    cin.ignore();
    getline(cin, newProduct.name);
    cout << "Enter Price: ";
    cin >> newProduct.price;
    cout << "Enter Manufacturer: ";
    cin.ignore();
    getline(cin, newProduct.manufacturer);
    cout << "Enter Expiry Date (dd-mm-yyyy): ";
    getline(cin, newProduct.expiryDate);
    cout << "Enter Quantity: ";
    cin >> newProduct.quantity;

    inventory.push_back(newProduct);
    cout << "✅ Product added successfully.\n";
}

void displayProducts() {
    if (inventory.empty()) {
        cout << "\nNo products available.\n";
        return;
    }

    printLine();
    cout << left << setw(6) << "ID" << setw(20) << "Name" << setw(10)
         << "Price" << setw(20) << "Manufacturer" << setw(15)
         << "Expiry Date" << setw(10) << "Qty" << endl;
    printLine();

    for (const auto &p : inventory) {
        cout << left << setw(6) << p.id << setw(20) << p.name
             << setw(10) << p.price << setw(20) << p.manufacturer
             << setw(15) << p.expiryDate << setw(10) << p.quantity << endl;
    }
    printLine();
}

void searchProduct() {
    int id;
    cout << "\nEnter Product ID to search: ";
    cin >> id;
    for (auto &p : inventory) {
        if (p.id == id) {
            cout << "\n--- Product Found ---\n";
            cout << "ID: " << p.id << "\nName: " << p.name
                 << "\nPrice: " << p.price << "\nManufacturer: " << p.manufacturer
                 << "\nExpiry: " << p.expiryDate << "\nQuantity: " << p.quantity << endl;
            return;
        }
    }
    cout << "Product not found.\n";
}

void deleteProduct() {
    int id;
    cout << "\nEnter Product ID to delete: ";
    cin >> id;
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->id == id) {
            inventory.erase(it);
            cout << "Product deleted successfully.\n";
            return;
        }
    }
    cout << "Product not found.\n";
}

// ---------- CUSTOMER SECTION ----------

void addCustomer() {
    Customer c;
    cout << "\nEnter Customer ID: ";
    cin >> c.id;

    if (any_of(customers.begin(), customers.end(), [&](Customer &cust){ return cust.id == c.id; })) {
        cout << "Customer with this ID already exists!\n";
        return;
    }

    cout << "Enter Customer Name: ";
    cin.ignore();
    getline(cin, c.name);
    cout << "Enter Contact: ";
    getline(cin, c.contact);

    customers.push_back(c);
    cout << "✅ Customer added successfully.\n";
}

void displayCustomers() {
    if (customers.empty()) {
        cout << "\nNo customers found.\n";
        return;
    }

    printLine();
    cout << left << setw(6) << "ID" << setw(25) << "Name" << setw(20) << "Contact" << endl;
    printLine();

    for (const auto &c : customers)
        cout << left << setw(6) << c.id << setw(25) << c.name << setw(20) << c.contact << endl;

    printLine();
}

void deleteCustomer() {
    int id;
    cout << "\nEnter Customer ID to delete: ";
    cin >> id;
    for (auto it = customers.begin(); it != customers.end(); ++it) {
        if (it->id == id) {
            customers.erase(it);
            cout << "Customer deleted successfully.\n";
            return;
        }
    }
    cout << "Customer not found.\n";
}

// ---------- SUPPLIER SECTION ----------

void addSupplier() {
    Supplier s;
    cout << "\nEnter Supplier ID: ";
    cin >> s.id;

    if (any_of(suppliers.begin(), suppliers.end(), [&](Supplier &sup){ return sup.id == s.id; })) {
        cout << "Supplier with this ID already exists!\n";
        return;
    }

    cout << "Enter Supplier Name: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter Contact: ";
    getline(cin, s.contact);
    cout << "Enter Address: ";
    getline(cin, s.address);

    suppliers.push_back(s);
    cout << "✅ Supplier added successfully.\n";
}

void displaySuppliers() {
    if (suppliers.empty()) {
        cout << "\nNo suppliers available.\n";
        return;
    }

    printLine();
    cout << left << setw(6) << "ID" << setw(20) << "Name"
         << setw(20) << "Contact" << setw(25) << "Address" << endl;
    printLine();

    for (const auto &s : suppliers)
        cout << left << setw(6) << s.id << setw(20) << s.name
             << setw(20) << s.contact << setw(25) << s.address << endl;
    printLine();
}

void deleteSupplier() {
    int id;
    cout << "\nEnter Supplier ID to delete: ";
    cin >> id;
    for (auto it = suppliers.begin(); it != suppliers.end(); ++it) {
        if (it->id == id) {
            suppliers.erase(it);
            cout << "Supplier deleted successfully.\n";
            return;
        }
    }
    cout << "Supplier not found.\n";
}

// ---------- MAIN MENU ----------

int main() {
    int choice;
    while (true) {
        printLine();
        cout << "\n💄 COSMETIC SHOP MANAGEMENT SYSTEM 💄\n";
        printLine();
        cout << "1. Add or Update Product\n";
        cout << "2. Display Products\n";
        cout << "3. Search Product\n";
        cout << "4. Delete Product\n";
        cout << "5. Add Customer\n";
        cout << "6. Display Customers\n";
        cout << "7. Delete Customer\n";
        cout << "8. Add Supplier\n";
        cout << "9. Display Suppliers\n";
        cout << "10. Delete Supplier\n";
        cout << "11. Exit\n";
        printLine();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addOrUpdateProduct(); break;
            case 2: displayProducts(); break;
            case 3: searchProduct(); break;
            case 4: deleteProduct(); break;
            case 5: addCustomer(); break;
            case 6: displayCustomers(); break;
            case 7: deleteCustomer(); break;
            case 8: addSupplier(); break;
            case 9: displaySuppliers(); break;
            case 10: deleteSupplier(); break;
            case 11: cout << "👋 Exiting system. Goodbye!\n"; return 0;
            default: cout << "❌ Invalid choice. Please try again.\n";
        }
    }
}
