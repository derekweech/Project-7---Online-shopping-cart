#include <iostream>
#include "string"

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

using namespace std;

string GetUserString(const string & prompt);
double GetUserDouble(const string & prompt);
int GetUserInt(const string & prompt);
void PrintMenu();

int main() {

    string currCustomerName = GetUserString("Enter Customer's Name: ");
    string currCartDate = GetUserString("Enter Today's Date: ");

    //Enters user info through default constructor
    ShoppingCart userCart(currCustomerName, currCartDate);

    string userMenuChoice = "none";
    bool continueMenuLoop = true;
    while (continueMenuLoop) {
        userMenuChoice = GetUserString("Enter option: ");

        if (userMenuChoice == "add") {
            string itemName = GetUserString("Enter the item name: ");
            string itemDescription = GetUserString("Enter the item description: ");
            double itemPrice = GetUserDouble("Enter the item price: ");
            int itemQuantity = GetUserInt("Enter the item quantity: ");

            //Creates new item
            ItemToPurchase nextItem = ItemToPurchase(itemName, itemDescription, itemPrice, itemQuantity);
            userCart.AddItemToCart(nextItem);

            cout << endl;
        } else if (userMenuChoice == "remove") {
            string nameOfItemToRemove = GetUserString("Enter name of the item to remove: ");
            //removes item from cart
            userCart.RemoveItemFromCart(nameOfItemToRemove);

            cout << endl;
        } else if (userMenuChoice == "change") {
            string nameOfItemToChange = GetUserString("Enter the item name: ");
            int newItemQuantity = GetUserInt("Enter the new quantity: ");
            //changes item in cart
            userCart.UpdateQuantity(nameOfItemToChange, newItemQuantity);

            cout << endl;

        } else if (userMenuChoice == "descriptions") {
            //prints all descriptions
            userCart.PrintAllDesc();
        } else if (userMenuChoice == "cart") {
            //Prints price and quantity of cart
            userCart.PrintQuantityAndCost();

        } else if (userMenuChoice == "options") {
            //menu
            PrintMenu();
        } else if (userMenuChoice == "quit") {
            //closes program
            cout << "Goodbye." << endl;
            continueMenuLoop = false;
        } else {
            //menu
            PrintMenu();
        }
    }
    return 0;
}

string GetUserString(const string & prompt) {
    string userAnswer = "none";

    cout << prompt;
    getline(cin, userAnswer);
    cout << endl;
    return userAnswer;
}
double GetUserDouble(const string & prompt) {
    double userAnswer = 0.0;

    cout << prompt;
    cin >> userAnswer;
    cin.ignore();
    cout << endl;
    return userAnswer;
}
int GetUserInt(const string & prompt) {
    int userAnswer = 0;

    cout << prompt;
    cin >> userAnswer;
    cin.ignore();
    cout << endl;
    return userAnswer;
}
void PrintMenu(){
    cout << "MENU" << endl <<
         "add - Add item to cart" << endl <<
         "remove - Remove item from cart" << endl <<
         "change - Change item quantity" << endl <<
         "descriptions - Print the items' descriptions" << endl <<
         "cart - Print the shopping cart" << endl <<
         "options - Print the options menu" << endl <<
         "quit - Quit" << endl << endl;
}