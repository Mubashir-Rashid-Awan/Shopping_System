#include "Menu.h"
#include "FileHandler.h"

int main()
{
    loadProductsFromFile();
    load_next_order_id();

    mainMenu();

    return 0;
}