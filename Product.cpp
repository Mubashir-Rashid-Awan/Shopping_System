#include "Product.h"

Product::Product()
{
    id = 0;
    name = "";
    category = "";
    price = 0;
    stock = 0;
}

Product::Product(int i, string n, string c, float p, int s)
{
    id = i;
    name = n;
    category = c;
    price = p;
    stock = s;
}

int Product::get_id()
{
    return id;
}

string Product::get_name()
{
    return name;
}

float Product::get_price()
{
    return price;
}

int Product::get_stock()
{
    return stock;
}

void Product::set_stock(int s)
{
    stock = s;
}

void Product::display_product()
{
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Category: " << category << endl;
    cout << "Price: $" << fixed << setprecision(2) << price << endl;
    cout << "Stock: " << stock << endl;
}