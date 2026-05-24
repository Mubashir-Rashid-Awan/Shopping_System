#include "Admin.h"
#include "Globals.h"
#include "FileHandler.h"

Admin::Admin()
{
    password = "admin123";
}

bool Admin::adminLogin(string pass)
{
    return (pass == password);
}

void Admin::addproduct() {
    if (g_productCount >= MAX_PRODUCTS) {
        cout << "Product list is full. Cannot add more products.\n";
        return;
    }
    int id;
    string name, category;
    float price;
    int stock;
    cout << "Enter Product ID: ";
    cin >> id;
    for (int i = 0; i < g_productCount; i++) {
        if (g_products[i].get_id() == id) {
            cout << "Product with this ID already exists.\n";
            return;
        }
    }
    cin.ignore();
    cout << "Enter Product Name: ";
    getline(cin, name);
    cout << "Enter Product Category: ";
    getline(cin, category);
    cout << "Enter Product Price: $";
    cin >> price;
    cout << "Enter Product Stock: ";
    cin >> stock;
    g_products[g_productCount] = Product(id, name, category, price, stock);
    g_productCount++;
    cout << "Product added successfully!\n";
    saveProductsToFile();
}

void Admin::removeproduct() {
    int id;
    bool found = false;
    cout << "Enter Product ID to remove: ";
    cin >> id;
    for (int i = 0; i < g_productCount; i++) {
        if (g_products[i].get_id() == id) {
            found = true;
            for (int j = i; j < g_productCount - 1; j++) {
                g_products[j] = g_products[j + 1];
            }
            g_productCount--;
            cout << "Product removed successfully!\n";
            break;
        }
    }
    if (!found) {
        cout << "Product with ID " << id << " not found.\n";
    }
    saveProductsToFile();
}
void Admin::view_all_products() {
    if (g_productCount == 0) {
        cout << "No products available.\n";
        return;
    }
    cout << "\n===== PRODUCT INVENTORY =====\n";
    for (int i = 0; i < g_productCount; i++) {
        cout << "\nProduct #" << (i + 1) << ":\n";
        g_products[i].display_product();
        cout << "----------------------------\n";
    }
}