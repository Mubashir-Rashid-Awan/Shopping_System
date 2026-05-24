#ifndef PRODUCT_H
#define PRODUCT_H

#include<iostream>
#include<iomanip>
using namespace std;

class Product
{
private:
    int id;
    string name;
    string category;
    float price;
    int stock;

public:
    Product();

    Product(int i, string n, string c, float p, int s);

    int get_id();
    string get_name();
    float get_price();
    int get_stock();

    void set_stock(int s);

    void display_product();
};

#endif