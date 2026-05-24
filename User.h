#ifndef USER_H
#define USER_H

#include<iostream>
using namespace std;

class User
{
protected:
    string name;
    string email;
    string address;

public:
    void set_user_attr(string n, string e, string a);

    string get_user_name();
    string get_user_email();
    string get_user_address();

    void display_details();
};

#endif