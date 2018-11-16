// Program: Problem 0 – Vending Machine Simulator
// Purpose: separate class in files
// Author:  Ibrahim Ramadan 20170002
//          Ahmed Elsayed   20170011
// Date:    16 November  2018
// Version: 2.0

#include <iostream>
#include <iomanip>
#include "stock.h"
#include "vending_machine.h"

using namespace std;

int main()
{
    int close; // To close the program or continue.
    Stock a; //object a from class stock
    Vending_Machine b; //object b from class stock
    cout << a << endl;; // print the menu of vending machine.

    while (true)
    {
        cout << "If you wanna to close enter 0:";
        cin  >> close;
        if(close == 0)
        {
            break;
        }
        b.insert_Money(); // A buyer puts coins (1/2 LE, or 1 LE) and/or bills +(5, 10 or 20 LE).
        b.Choose_item();  // A buyer will choose which it want.
        return_change(b); // print the menu of vending machine with changes and the rest.
        if (emptymachine(b)) // Check if the machine empty if the machine is empty the program will stop.
            break;
    }
    return 0;

    // End of program.
}
