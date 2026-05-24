
#include "FileHandler.h"
#include "Globals.h"
#include "Product.h"

#include<iostream>
#include<fstream>

using namespace std;

void saveProductsToFile()
{
    ofstream outFile("products.txt");

    if (outFile.is_open())
    {
        for (int i = 0; i < g_productCount; i++)
        {
            outFile
                << g_products[i].get_id() << " "
                << g_products[i].get_name() << " "
                << g_products[i].get_price() << " "
                << g_products[i].get_stock()
                << endl;
        }

        outFile.close();
    }
    else
    {
        cout << "Unable to save products.\n";
    }
}

void loadProductsFromFile()
{
    ifstream inFile("products.txt");

    g_productCount = 0;

    if (inFile.is_open())
    {
        int id;
        int stock;

        string name;
        string category;

        float price;

        while (
            inFile
            >> id
            >> name
            >> price
            >> stock
        )
        {
            g_products[g_productCount] =
                Product(
                    id,
                    name,
                    category,
                    price,
                    stock
                );

            g_productCount++;
        }

        inFile.close();

        cout << "Products loaded successfully.\n";
    }
    else
    {
        cout << "No product file found.\n";
    }
}

void load_next_order_id()
{
    ifstream inFile("orders.txt");

    int id;
    int max_id = 0;

    string line;

    if (inFile.is_open())
    {
        while (inFile >> id)
        {
            inFile.ignore(1000, '\n');

            if (id > max_id)
            {
                max_id = id;
            }
        }

        inFile.close();
    }

    g_next_order_id = max_id + 1;
}

void register_customer()
{
    string name;
    string email;
    string address;
    string password;

    cin.ignore();

    cout << "Enter Your Name: ";
    getline(cin, name);

    cout << "Enter Your Email: ";
    getline(cin, email);

    ifstream checkFile("customers.txt");

    string stored_email;

    bool email_exists = false;

    if (checkFile.is_open())
    {
        while (checkFile >> stored_email)
        {
            checkFile.ignore(1000, '\n');

            if (stored_email == email)
            {
                email_exists = true;
                break;
            }
        }

        checkFile.close();
    }

    if (email_exists)
    {
        cout << "Email already exists.\n";
        return;
    }

    cout << "Enter Your Address: ";
    getline(cin, address);

    cout << "Create Password: ";
    getline(cin, password);

    ofstream outFile(
        "customers.txt",
        ios::app
    );

    if (outFile.is_open())
    {
        outFile
            << email << " "
            << password << " "
            << name << " "
            << address
            << endl;

        outFile.close();

        cout << "Registration successful!\n";
    }
    else
    {
        cout << "Unable to register.\n";
    }
}

