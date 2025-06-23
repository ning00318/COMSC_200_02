#include<iostream>
#include<string>
#include<ctime>
#include "Die.h"
using namespace std;

void displayMessage();
bool rollOrNot();
void displayResult(int, int);

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    
    Die die1(6);
    Die die2(6);

    displayMessage();
    
    bool ifPlay = true;
    int computerPoints = 0;
    int playerPoints = 0;

    while (ifPlay)
    {
        if (rollOrNot())
        {
            die1.roll();
            die2.roll();
            computerPoints += die1.getValue() + die2.getValue();

            die1.roll();
            die2.roll();
            playerPoints += die1.getValue() + die2.getValue();
            cout << "\nYou have " << playerPoints << " points." << endl << endl;
        }
        else
        {
            ifPlay = false;
            cout << "\n--------------------------------" << endl;
        }
    }

    if (playerPoints > 0)
        displayResult(computerPoints, playerPoints);    
    cout << "\nGame Over\n\n";

    return 0;
}

void displayMessage()
{
    cout << "Let's play a game of 21!" << endl << endl;
    cout << "--------------------------------" << endl;
}

bool rollOrNot()
{
    char yesOrNo;

    cout << "Would you like to roll the dice?" << endl;
    cout << "Enter Y for yes or N for no: ";
    cin >> yesOrNo;

    if (yesOrNo == 'Y' || yesOrNo == 'y')
        return true;
    else if (yesOrNo == 'N' || yesOrNo == 'n')
        return false;
    else
    {
        cout << "\nPlease enter the valid character" << endl;
        return rollOrNot();
    }
}

void displayResult(int pointsOfComputer, int pointsOfPlayer)
{
    cout << "The computer had " << pointsOfComputer << " points." << endl;
    cout << "You had " << pointsOfPlayer << " points." << endl << endl;

    if (pointsOfPlayer > pointsOfComputer && pointsOfPlayer <= 21 || pointsOfPlayer <= 21 && pointsOfComputer > 21)
        cout << "Congratulations! You won!";
    else if (pointsOfPlayer == pointsOfComputer && pointsOfPlayer <= 21)
        cout << "Tie! No one wins.";
    else
        cout << "Better luck next time.";
    cout << "\n\n--------------------------------\n";
}