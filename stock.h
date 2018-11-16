#ifndef STOCK_H
#define STOCK_H
#include <string>

using namespace std;

class Stock
{
    public:
        Stock(); // empty constructor
        friend ostream& operator<< (ostream& out,Stock a); // virtual function to print the menu.

    protected:
        string Item  [10] = {"Cheetos","Doritos","Chips","Cola can","Pepsi can","Chocolate","Snickers","Twix","Ulker","Waver"}; // array of string to print the item.
        int    Amount[10] = {10,10,10,10,10,10,10,10,10,10}; // array of integer to print the amount.
        double price [10] = {4,5,7.5,4,4,6.5,8.5,7,2.5,10}; // array of double to print the price.

};

#endif // STOCK_H
