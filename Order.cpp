#include "Order.h"
#include "Globals.h"

#include<fstream>
#include<iomanip>

using namespace std;

extern int g_next_order_id;

Order::Order()
{
    order_id = g_next_order_id++;

    customer_name = "";

    total_price = 0;

    product_count = 0;

    for (int i = 0; i < MAX_CART_ITEMS; i++)
    {
        products_purchased[i] = -1;
        product_quantities[i] = 0;
    }
}

void Order::set_customer_name(string name)
{
    customer_name = name;
}

void Order::set_total_price(float total)
{
    total_price = total;
}

void Order::add_product(int product_id, int quantity)
{
    products_purchased[product_count] = product_id;

    product_quantities[product_count] = quantity;

    product_count++;
}

void Order::calculate_order_total()
{
    total_price = 0;

    for (int i = 0; i < product_count; i++)
    {
        int prod_id = products_purchased[i];

        int qty = product_quantities[i];

        for (int j = 0; j < g_productCount; j++)
        {
            if (g_products[j].get_id() == prod_id)
            {
                total_price +=
                    qty * g_products[j].get_price();

                break;
            }
        }
    }
}

void Order::display_order_details()
{
    cout << "\n======= ORDER RECEIPT =======\n";

    cout << "Order ID: "
         << order_id
         << "\n";

    cout << "Customer: "
         << customer_name
         << "\n";

    cout << "----------------------------\n";

    for (int i = 0; i < product_count; i++)
    {
        int prod_id = products_purchased[i];

        int qty = product_quantities[i];

        for (int j = 0; j < g_productCount; j++)
        {
            if (g_products[j].get_id() == prod_id)
            {
                cout << g_products[j].get_name()
                     << " x "
                     << qty
                     << "\n";

                cout << "Total: $"
                     << fixed
                     << setprecision(2)
                     << qty * g_products[j].get_price()
                     << "\n";

                cout << "----------------------------\n";

                break;
            }
        }
    }

    cout << "Final Total: $"
         << fixed
         << setprecision(2)
         << total_price
         << "\n";

    cout << "=============================\n";
}

void Order::save_to_file()
{
    ofstream outFile("orders.txt", ios::app);

    if (outFile.is_open())
    {
        outFile << order_id
                << " "
                << customer_name
                << " "
                << total_price;

        for (int i = 0; i < product_count; i++)
        {
            outFile << " "
                    << products_purchased[i]
                    << " "
                    << product_quantities[i];
        }

        outFile << endl;

        outFile.close();
    }
    else
    {
        cout << "Unable to save order.\n";
    }
}
