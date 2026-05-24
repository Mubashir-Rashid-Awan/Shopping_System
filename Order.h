#ifndef ORDER_H
#define ORDER_H
#include "Globals.h"
#include<iostream>
using namespace std;


class Order
{
private:

    int order_id;

    string customer_name;

    float total_price;

    int products_purchased[MAX_CART_ITEMS];

    int product_quantities[MAX_CART_ITEMS];

    int product_count;

public:

    Order();

    void set_customer_name(string name);

    void set_total_price(float total);

    void add_product(int product_id, int quantity);

    void calculate_order_total();

    void display_order_details();

    void save_to_file();
};

#endif

