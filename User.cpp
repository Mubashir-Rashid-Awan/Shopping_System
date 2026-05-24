#include "User.h"

void User::set_user_attr(string n, string e, string a)
{
    name = n;
    email = e;
    address = a;
}

string User::get_user_name()
{
    return name;
}

string User::get_user_email()
{
    return email;
}

string User::get_user_address()
{
    return address;
}

void User::display_details()
{
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Address: " << address << endl;
}