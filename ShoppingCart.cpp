#include <iostream>
#include <iomanip>
#include <utility>

#include "ShoppingCart.h"
//default constructor
ShoppingCart::ShoppingCart(std::string currCustomerName, std::string currCartDate) {
    customerName = std::move(currCustomerName);
    cartDate = std::move(currCartDate);
}
//Adds a single item to the user's cart
void ShoppingCart::AddItemToCart(ItemToPurchase nextItem) {
    for (auto & ListOfItem : itemsInCart) {
        if (nextItem.GetName() == ListOfItem.GetName()) {
            std::cout <<
            "Item is already found in the cart. It will not be added." <<
            std::endl;
            return;
        }
    }
    itemsInCart.push_back(nextItem);
}
//Removes a single item from the cart
void ShoppingCart::RemoveItemFromCart(const std::string& ItemRemoval) {
    for (int i = 0; i < itemsInCart.size(); i++) {
        if (ItemRemoval == itemsInCart.at(i).GetName()) {
            itemsInCart.erase(itemsInCart.begin() + i);
            return;
        }
    }
    std::cout <<
    "Item not found in cart. It will not be removed." <<
    std::endl;
}
//Change an item from the cart
void ShoppingCart::UpdateQuantity(std::string ItemUpdate, int nextQuantity) {
    for (int i = 0; i < itemsInCart.size(); i++) {
        if (itemsInCart.at(i).GetName() == ItemUpdate) {
            itemsInCart.at(i).SetQuantity(nextQuantity);
            return;
        }
    }
    std::cout <<
    "Item not found in cart. It will not be modified." <<
    std::endl;
}
//Tells you how many items are in the cart
int ShoppingCart::TotalItemsInCart() {
    int totalItems = 0;
    for (auto & ListOfItem : itemsInCart) {
        totalItems += ListOfItem.GetQuantity();
    }
    return totalItems;
}
//Tell you the total cost of all items in cart
double ShoppingCart::TotalCostOfItems() {
    double totalCost = 0;

    for (auto & ListOfItem : itemsInCart) {
        totalCost += ListOfItem.GetQuantity() * ListOfItem.GetPrice();
    }
    return totalCost;
}
//Prints all descriptions of each item in cart
void ShoppingCart::PrintAllDesc() {
    std::cout <<
    customerName << "'s Shopping Cart - " << cartDate <<
    std::endl;

    if (!itemsInCart.empty()) {
        std::cout <<
        "Item Descriptions" <<
        std::endl;
        for (auto & ListOfItem : itemsInCart) {
            std::cout << ListOfItem.PrintDesc();
            std::cout << std::endl;

        }
    } else {
        std::cout <<
        "Shopping cart is empty." <<
        std::endl;
    }
    std::cout <<
    std::endl;
}
//Prints total cost and quantity of items of current cart
void ShoppingCart::PrintQuantityAndCost() {
    std::cout << customerName <<
    "'s Shopping Cart - " << cartDate <<
    std::endl;

    if (!itemsInCart.empty()) {
        std::cout <<
        "Number of Items: " << TotalItemsInCart() <<
        std::endl << std::endl;
        for (auto & ListOfItem : itemsInCart) {
            std::cout << ListOfItem.PrintCost();
            std::cout << std::endl;
        }
        std::cout << std::endl <<
        "Total: $" << std::fixed << std::setprecision(2) << TotalCostOfItems() <<
        std::endl << std::endl;
    } else {
        std::cout <<
        "Shopping cart is empty." <<
        std::endl;
    }
}