#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

#include <string>

#include "ItemToPurchase.h"

class ItemToPurchase {
public:
    ItemToPurchase(std::string currItemName = "none", std::string currItemDescription = "none", double currItemPrice = 0.0, int currItemQuantity = 0);

    std::string GetName();
    void SetQuantity(int currQuantity);
    double GetPrice() const;
    int GetQuantity() const;

    std::string PrintCost();
    std::string PrintDesc();

private:
    std::string itemName;
    std::string itemDescription;
    double itemPrice;
    int itemQuantity;

};
#endif