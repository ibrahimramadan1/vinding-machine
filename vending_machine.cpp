#include "vending_machine.h"
#include <iostream>
#include <iomanip>

using namespace std;

Vending_Machine::Vending_Machine() // empty constructor to set money.
{
    money = 0;
}
void Vending_Machine::insert_Money() // for insert the money.
{
backtomoney: // the program will return here according goto function.
    while (true)
    {
        cout << "Enter your money puts coins (1/2 LE, or 1 LE) and/or bills +(5, 10 or 20 LE) and enter 0 if you don't:";
        cin  >> coins;
        if (coins == 0.5 || coins == 1 || coins == 5 || coins == 10 || coins == 20) // condition for check if the coins valid
        {
            money += coins; // money = money + coins
        }
        else if (coins == 0)  // if coins equal 0 so the user is enough to put coins.
        {
            break;
        }
        else // condition for check if the coins invalid
        {
            cout<<"Invalid currency \nput again\n";
            goto backtomoney;
        }

    }
}
void Vending_Machine::Choose_item() // function for choose item.
{
    Vending_Machine ob;
    ob.money = money;
    int b; // input if user want another item.
    while (true)
    {
backtochoose: // the program will return here according goto function.
        cout << "Enter your choose:";
        while (true)
        {
            cin >> choose;
            if (choose <= 9 && choose >= 0)
            {
                break;
            }
            else
            {
                cout << "Invalid choose..please enter the correct choose\n";
                goto backtochoose;
            }

        }
backtoquantity: // the program will return here according goto function.
        cout << "Enter amount:";
        cin  >> quantity;
        if (Amount[choose] == 0)
                //If the required item is not available,the machine will display a message informing him that the
                //item is not available and gives him the choice of picking another item or returning his money.
        {
            cout << "Item is not available.\nIf you wanna picking another item enter 1 or enter 0 to return your money: ";
            cin  >> y;
            if (y == 1)
            {
                goto backtochoose;
            }
            else
            {
                break;
            }

        }
        if (quantity > Amount[choose] || quantity < 0) // condition for check if the quantity is not available.
        {
            cout << "Not enough quantity \nPut quantity again\n";
            goto backtoquantity;
        }
        Amount[choose] -= quantity; // Amount of item subtract quantity from user.
        money          -= quantity * price[choose]; // Consumption of user money.
        if (money < 0) // condition if the money is smaller than zero and return the amount   /****/.
        {
            cout << "Not enough money put quantity again\n";
            Amount[choose] += quantity;
            money          += quantity * price[choose];
            goto backtoquantity;
        }
        if (money == 0) // if the money is zero will break.
        {
            break;
        }
        // if the user want another item the program will continue.
        cout << "If you want another item enter 1 else enter 0..";
        cin  >> b;
        if (b == 1)
        {
            continue;
        }
        else
            break;
    }
}

void return_change(Vending_Machine o)
// Return the rest of money as coins (1/2 LE, or 1 LE) and/or bills +(5, 10 or 20 LE),
// and print the menu with changes
{
    cout << "---------------------------------------\n";
    cout << o << endl;
    cout << "Your money " << o.money << " LE" << endl;
    while (o.money != 0)
    {
        if (o.money >= 20)
        {
            cout << "20 LE\n";
            o.money -= 20;
            continue;
        }
        if (o.money >= 10)
        {
            cout << "10 LE\n";
            o.money -= 10;
            continue;
        }
        if (o.money >= 5)
        {
            cout << "5 LE\n";
            o.money -= 5;
            continue;
        }
        if (o.money >= 1)
        {
            cout << "1 LE\n";
            o.money -= 20;
            continue;
        }
        if (o.money >= 0.5)
        {
            cout << "0.5 LE\n";
            o.money -= 0.5;
            continue;
        }


    }
}

bool emptymachine(Vending_Machine o)  //function for check if the machine is empty.
{
    for (int i = 0; i < 10; i++)
    {
        if (o.Amount[i] != 0)
            return 0;
    }
    return 1;
}
