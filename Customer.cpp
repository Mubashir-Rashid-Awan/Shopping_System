#include "Customer.h"
#include "Globals.h"
#include "Product.h"
#include "Order.h"
#include "FileHandler.h"

#include<iostream>
#include<iomanip>

using namespace std;

Customer::Customer()
{
    cart_count = 0;
    password = "";

    for (int i = 0; i < 100; i++)
    {
        shopping_cart[i] = -1;
        cart_quantity[i] = 0;
    }
}

void Customer::set_password(string pass)
{
    password = pass;
}

bool Customer::customerLogin(string pass)
{
    return (pass == password);
}

void Customer::view_products()
{
    if (g_productCount == 0)
    {
        cout << "No products available.\n";
        return;
    }

    cout << "\n===== AVAILABLE PRODUCTS =====\n";

    for (int i = 0; i < g_productCount; i++)
    {
        cout << "\nProduct #" << (i + 1) << ":\n";

        cout << "ID: "
             << g_products[i].get_id()
             << "\n";

        cout << "Name: "
             << g_products[i].get_name()
             << "\n";

        cout << "Price: $"
             << fixed
             << setprecision(2)
             << g_products[i].get_price()
             << "\n";

        cout << "Stock: "
             << g_products[i].get_stock()
             << "\n";

        cout << "----------------------------\n";
    }
}

void Customer::add_to_cart()
{
    int product_id;
    int quantity;

    bool found = false;

    view_products();

    cout << "Enter Product ID to add to cart: ";
    cin >> product_id;

    cout << "Enter quantity: ";
    cin >> quantity;

    for (int i = 0; i < g_productCount; i++)
    {
        if (g_products[i].get_id() == product_id)
        {
            found = true;

            if (g_products[i].get_stock() < quantity)
            {
                cout << "Not enough stock available.\n";
                return;
            }

            for (int j = 0; j < cart_count; j++)
            {
                if (shopping_cart[j] == product_id)
                {
                    cart_quantity[j] += quantity;

                    cout << "Cart updated successfully.\n";
                    return;
                }
            }

            shopping_cart[cart_count] = product_id;
            cart_quantity[cart_count] = quantity;

            cart_count++;

            cout << "Product added to cart successfully.\n";

            return;
        }
    }

    if (!found)
    {
        cout << "Product not found.\n";
    }
}

void Customer::view_cart()
{
    if (cart_count == 0)
    {
        cout << "Your cart is empty.\n";
        return;
    }

    float total = 0;

    cout << "\n===== SHOPPING CART =====\n";

    for (int i = 0; i < cart_count; i++)
    {
        int prod_id = shopping_cart[i];
        int qty = cart_quantity[i];

        for (int j = 0; j < g_productCount; j++)
        {
            if (g_products[j].get_id() == prod_id)
            {
                float item_total =
                    qty * g_products[j].get_price();

                cout << "\nItem #" << (i + 1) << "\n";

                cout << "Product: "
                     << g_products[j].get_name()
                     << "\n";

                cout << "Quantity: "
                     << qty
                     << "\n";

                cout << "Price: $"
                     << fixed
                     << setprecision(2)
                     << g_products[j].get_price()
                     << "\n";

                cout << "Total: $"
                     << fixed
                     << setprecision(2)
                     << item_total
                     << "\n";

                cout << "----------------------------\n";

                total += item_total;
            }
        }
    }

    cout << "Cart Total: $"
         << fixed
         << setprecision(2)
         << total
         << "\n";
}

void Customer::check_out()
{
    if (cart_count == 0)
    {
        cout << "Your cart is empty.\n";
        return;
    }

    char confirm;

    view_cart();

    cout << "Confirm Order (Y/N): ";
    cin >> confirm;

    if (toupper(confirm) != 'Y')
    {
        cout << "Checkout cancelled.\n";
        return;
    }

    float total = 0;

    Order new_order;

    new_order.set_customer_name(name);

    for (int i = 0; i < cart_count; i++)
    {
        int prod_id = shopping_cart[i];
        int qty = cart_quantity[i];

        for (int j = 0; j < g_productCount; j++)
        {
            if (g_products[j].get_id() == prod_id)
            {
                g_products[j].set_stock(
                    g_products[j].get_stock() - qty
                );

                total += qty *
                         g_products[j].get_price();

                new_order.add_product(prod_id, qty);

                break;
            }
        }
    }

    new_order.set_total_price(total);

    new_order.display_order_details();

    saveProductsToFile();

    new_order.save_to_file();

    cart_count = 0;

    for (int i = 0; i < 100; i++)
    {
        shopping_cart[i] = -1;
        cart_quantity[i] = 0;
    }

    cout << "Thank you for shopping with us!\n";
}

