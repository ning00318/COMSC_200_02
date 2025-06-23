#include<iostream>
#include<string>
#include<ctime>
#include "Die.h"
using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    
    Die die1(6);
    Die die2(6);

    cout << "Let's play a game of 21!" << endl << endl;
    cout << "--------------------------------" << endl;
    
    bool ifPlay = true;
    char yesOrNo;
    int sumComputerPoints = 0;
    int sumPlayerPoints = 0;

    while (ifPlay)
    {
        cout << "Would you like to roll the dice?" << endl;
        cout << "Enter Y for yes or N for no: ";
        cin >> yesOrNo;

        if (yesOrNo == 'Y' || yesOrNo == 'y')
        {
            die1.roll();
            die2.roll();
            sumComputerPoints += die1.getValue() + die2.getValue();

            die1.roll();
            die2.roll();
            sumPlayerPoints += die1.getValue() + die2.getValue();
            cout << "\nYou have " << sumPlayerPoints << " points." << endl << endl;
        }
        else if (yesOrNo == 'N' || yesOrNo == 'n')
        {
            ifPlay = false;
            cout << "\n--------------------------------" << endl;
        }
        else
            cout << "\nPlease enter the valid character" << endl;
    }
    if (sumPlayerPoints > 0)
    {
        cout << "The computer had " << sumComputerPoints << " points." << endl;
        cout << "You had " << sumPlayerPoints << " points." << endl << endl;

        if (sumPlayerPoints > sumComputerPoints && sumPlayerPoints <= 21 || sumPlayerPoints <= 21 && sumComputerPoints > 21)
            cout << "Congratulations! You won!";
        else if (sumPlayerPoints == sumComputerPoints && sumPlayerPoints <= 21)
            cout << "It's a tie! No one wins.";
        else
            cout << "Better luck next time.";
        
            cout << "\n\n--------------------------------\n";
    }
    
    cout << "\nGame Over\n\nPress any key to continue . . .\n\n";

    return 0;
}