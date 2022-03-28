#ifndef UNTITLED1_SHOPPINGCART_H
#define UNTITLED1_SHOPPINGCART_H

#include <vector>
#include <string>

#include "ShoppingCart.h"
#include "ItemToPurchase.h"

class ShoppingCart {
public:
    ShoppingCart(std::string currCustomerName = "none", std::string currCartDate = "January 1, 1970");

    void AddItemToCart(ItemToPurchase nextItem);
    void RemoveItemFromCart(const std::string& ItemRemoval);
    void UpdateQuantity(std::string ItemUpdate, int nextQuantity);

    int TotalItemsInCart();
    double TotalCostOfItems();

    void PrintAllDesc();
    void PrintQuantityAndCost();

private:
    std::string customerName;
    std::string cartDate;

    std::vector <ItemToPurchase> itemsInCart;
};

#endif