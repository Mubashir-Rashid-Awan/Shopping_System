#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"

class Customer : public User
{
private:
    int shopping_cart[100];
    int cart_quantity[100];
    int cart_count;

    string password;

public:
    Customer();

    void set_password(string pass);

    bool customerLogin(string pass);

    void view_products();

    void add_to_cart();

    void view_cart();

    void check_out();
};

#endif