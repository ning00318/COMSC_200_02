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
    // Comment 6: Use the current time to seed the random number generator.
    srand(static_cast<unsigned int>(time(0)));
    
    // Comment 7: Setting the number of sides for the dice.
    Die die1(6);
    Die die2(6);

    displayMessage();   // Comment 8: Display a welcome message.
    
    bool ifPlay = true;
    int computerPoints = 0;
    int playerPoints = 0;

    while (ifPlay)
    {   
        // Comment 9: Ask the player whether or not they want to play.
        if (rollOrNot())
        {
            // Comment 11: Computer first roll two dice, add up the points,
            //             and then accumulate its previous points of rolls.
            die1.roll();
            die2.roll();
            computerPoints += die1.getValue() + die2.getValue();

            // Comment 12: Player then roll the same two dice, add up the points,
            //             and then accumulate the player's previous points of rolls.
            die1.roll();
            die2.roll();
            playerPoints += die1.getValue() + die2.getValue();

            // Comment 13: Display to the player how many points they accumulate
            //             while hiding the points the computer has.
            cout << "\nYou have " << playerPoints << " points." << endl << endl;
        }
        else
        {
            ifPlay = false;
            cout << "\n--------------------------------" << endl;
        }
    }

    // Comment 14: When the player chose not to roll and had at least one roll, display the final results.
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
        // Comment 10: If the player enter an invalid character, the hint shows,
        //             and then the rollOrNot message display again.
        cout << "\nPlease enter the valid character" << endl; 
        return rollOrNot();
    }
}

void displayResult(int pointsOfComputer, int pointsOfPlayer)
{
    cout << "The computer had " << pointsOfComputer << " points." << endl;
    cout << "You had " << pointsOfPlayer << " points." << endl << endl;

    /*
    Comment 15: When the player's point is greater than the computer's and the points
                are less than or equal to 21, or when the computer's point exceeds 21
                while the player's is less than or equal to 21, the player wins.
    */
    if (pointsOfPlayer > pointsOfComputer && pointsOfPlayer <= 21 || pointsOfPlayer <= 21 && pointsOfComputer > 21)
        cout << "Congratulations! You won!";
    // Comment 16: When the player's point is the same as the computer's
    //             while both points are less than or equal to 21, no one wins.
    else if (pointsOfPlayer == pointsOfComputer && pointsOfPlayer <= 21)
        cout << "Tie! No one wins.";
    else
        cout << "Better luck next time.";
    cout << "\n\n--------------------------------\n";
}