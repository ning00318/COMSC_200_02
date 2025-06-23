#include<iostream>
#include<string>
#include "Die.h"
using namespace std;

int main()
{
    cout << "Let's play a game of 21!" << endl << endl;
    cout << "--------------------------------" << endl;
    
    bool ifPlay = true;
    char yesOrNo;
    while (ifPlay)
    {
        cout << "Would you like to roll the dice?" << endl;
        cout << "Enter Y for yes or N for no: ";
        cin >> yesOrNo;

        if (yesOrNo == 'Y' || yesOrNo == 'y')
        {
            Die die1(6);
            Die die2(6);
            cout << "\n\nYou have " << die1.getValue() + die2.getValue() << " points." << endl << endl;
        }
        else if (yesOrNo == 'N' || yesOrNo == 'n')
        {
            ifPlay = false;
        }
        else
            cout << "Please enter the valid charracter";
    }
    

}