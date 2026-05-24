#include "Menu.h"
#include "Admin.h"
#include "Customer.h"
#include "FileHandler.h"

#include<iostream>
#include<fstream>

using namespace std;

Admin current_admin;

Customer current_customer;

bool is_logged_in = false;

bool is_admin = false;

void admin_menu()
{
    int choice;

    do
    {
        cout << "\n===== ADMIN MENU =====\n";

        cout << "1. Add Product\n";

        cout << "2. Remove Product\n";

        cout << "3. View Products\n";

        cout << "0. Logout\n";

        cout << "Enter choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:

            current_admin.addproduct();

            break;

        case 2:

            current_admin.removeproduct();

            break;

        case 3:

            current_admin.view_all_products();

            break;

        case 0:

            cout << "Logged out successfully.\n";

            break;

        default:

            cout << "Invalid choice.\n";
        }

    } while (choice != 0);
}

void customer_menu()
{
    int choice;

    do
    {
        cout << "\n===== CUSTOMER MENU =====\n";

        cout << "1. View Products\n";

        cout << "2. Add To Cart\n";

        cout << "3. View Cart\n";

        cout << "4. Checkout\n";

        cout << "0. Logout\n";

        cout << "Enter choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:

            current_customer.view_products();

            break;

        case 2:

            current_customer.add_to_cart();

            break;

        case 3:

            current_customer.view_cart();

            break;

        case 4:

            current_customer.check_out();

            break;

        case 0:

            cout << "Logged out successfully.\n";

            break;

        default:

            cout << "Invalid choice.\n";
        }

    } while (choice != 0);
}

void mainMenu()
{
    int choice;

    do
    {
        cout << "\n=====  SHOPPING SYSTEM =====\n";

        cout << "1. Login As Admin\n";

        cout << "2. Login As Customer\n";

        cout << "3. Register Customer\n";

        cout << "0. Exit\n";

        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string password;

            cout << "Enter Admin Password: ";

            cin >> password;

            if (current_admin.adminLogin(password))
            {
                cout << "Admin Login Successful.\n";

                admin_menu();
            }
            else
            {
                cout << "Wrong Password.\n";
            }

            break;
        }

        case 2:
        {
            string email;
            string password;

            cout << "Enter Email: ";

            cin >> email;

            cout << "Enter Password: ";

            cin >> password;

            ifstream inFile("customers.txt");

            string stored_email;
            string stored_pass;
            string name;
            string address;

            bool found = false;

            if (inFile.is_open())
            {
                while (
                    inFile
                    >> stored_email
                    >> stored_pass
                    >> name
                    >> address
                )
                {
                    if (
                        stored_email == email
                        &&
                        stored_pass == password
                    )
                    {
                        found = true;

                        current_customer
                            .set_user_attr(
                                name,
                                email,
                                address
                            );

                        current_customer
                            .set_password(password);

                        cout << "Login Successful.\n";

                        customer_menu();

                        break;
                    }
                }

                inFile.close();
            }

            if (!found)
            {
                cout << "Invalid Email or Password.\n";
            }

            break;
        }

        case 3:

            register_customer();

            break;

        case 0:

            cout << "Thank You For Using System.\n";

            break;

        default:

            cout << "Invalid choice.\n";
        }

    } while (choice != 0);
}
