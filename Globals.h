#ifndef GLOBALS_H
#define GLOBALS_H

#include "Product.h"

const int MAX_PRODUCTS = 100;

const int MAX_CART_ITEMS = 100;

const int MAX_ORDERS = 100;

extern Product g_products[MAX_PRODUCTS];

extern int g_productCount;

extern int g_next_order_id;

#endif


