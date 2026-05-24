#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"

class Admin : public User
{
private:
    string password;

public:
    Admin();

    bool adminLogin(string pass);

    void addproduct();
    void removeproduct();
    void view_all_products();
};

#endif