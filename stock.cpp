
#include "stock.h"
#include <iostream>
#include <iomanip>

using namespace std;

Stock::Stock() // empty constructor.
{
    //ctor
}

ostream& operator<< (ostream& out , Stock a) //function to print the menu.
{
    cout << setw(14) << "Item "
         << setw(8)  << "Cost "
         << setw(16) << "Amount\n";
    cout << "---------------------------------------\n";

    for (int i = 0 ; i < 10 ; i++)
    {
        out << setw (11) << a.Item[i];
        out << setw (8)  << a.price[i]  << " LE";
        out << setw (11) << a.Amount[i] << endl;
    }
    cout << "----------------------------------------\n";
}
