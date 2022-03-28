#include <iostream>
#include <iomanip>
#include <utility>

#include "ItemToPurchase.h"

//default constructor
ItemToPurchase::ItemToPurchase(std::string currItemName, std::string currItemDescription, double currItemPrice, int currItemQuantity) {
    itemName = std::move(currItemName);
    itemDescription = std::move(currItemDescription);
    itemPrice = currItemPrice;
    itemQuantity = currItemQuantity;
}
//Returns given item name
std::string ItemToPurchase::GetName() {
    return itemName;
}
//Enters user desired quantity per item
void ItemToPurchase::SetQuantity(int currQuantity) {
    itemQuantity = currQuantity;
}
//Returns total quantity
int ItemToPurchase::GetQuantity() const {
    return itemQuantity;
}
//Enters price of item
double ItemToPurchase::GetPrice() const {
    return itemPrice;
}
//Prints cost of item name, quantity of item, and price of item
std::string ItemToPurchase::PrintCost() {
    //formats output for complicated string
    std::ostringstream myString;

    myString << itemName <<
    " " << itemQuantity <<
    " @ $" << std::fixed << std::setprecision(2) << itemPrice <<
    " = $" << itemQuantity * itemPrice <<
    std::endl;

    return myString.str();
}
//Prints description of item
std::string ItemToPurchase::PrintDesc() {
    return itemName + ": " + itemDescription;
}

