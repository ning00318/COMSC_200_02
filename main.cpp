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
    int sumComputerPoints = 0;
    int sumPlayerPoints = 0;
    while (ifPlay)
    {
        cout << "Would you like to roll the dice?" << endl;
        cout << "Enter Y for yes or N for no: ";
        cin >> yesOrNo;

        if (yesOrNo == 'Y' || yesOrNo == 'y')
        {
            Die die1(6);
            Die die2(6);
            sumComputerPoints += die1.getValue();
            sumPlayerPoints += die2.getValue();
            cout << "\nYou have " << sumPlayerPoints << " points." << endl << endl;
        }
        else if (yesOrNo == 'N' || yesOrNo == 'n')
        {
            ifPlay = false;
            cout << "\n--------------------------------" << endl;
        }
        else
            cout << "Please enter the valid character";
    }
    cout << "The computer had " << sumComputerPoints << " points." << endl;
    cout << "You had " << sumPlayerPoints << " points." << endl << endl;

    if (sumPlayerPoints > sumComputerPoints)
        cout << "Congratulations! You won!";
    else if (sumPlayerPoints == sumComputerPoints)
        cout << "Tie! No one loses or wins!";
    else
        cout << "Better luck next time.";
    
    cout << "\n\n--------------------------------\n\n";
    cout << "Game Over\n\nPress any key to continue . . .\n\n";
}