#ifndef VENDING_MACHINE_H
#define VENDING_MACHINE_H
#include "stock.h"


class Vending_Machine : public Stock // inherit from class Stock.
{
    public:
        Vending_Machine(); // Empty constructor.
        virtual void insert_Money(); // Virtual function for insert the money.
        virtual void Choose_item (); // Virtual function for choose item.
        friend void return_change(Vending_Machine o); // Friend function for print the menu with changes and the rest.
        friend bool emptymachine (Vending_Machine o); // Friend function for check if the machine is empty.


    protected:
        double money;
        double arr[5] = {20,10,5,1,0.5}; // Array of coins which can put in machine and return for user.
        int    choose; // choose the item.
        int    quantity; // input the quantity.
        float  coins; // input the coins.
        int y = 0; // input for the choice of picking another item or returning his money.

};

#endif // VENDING_MACHINE_H
