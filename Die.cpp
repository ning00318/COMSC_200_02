#include<iostream>
#include<cstdlib>
#include "Die.h"
using namespace std;

// Commemt1: Constructor receives an argument for how many sides
//           of the die and execute an initial roll of the die.
Die::Die(int numSides)
    : sides(numSides)
{
    roll();
}
// Comment 2: Member function receives an argument for how many sides
//            of the die and execute a roll of the die.
void Die::setSides(int numSides)
{
    sides = numSides;
    roll();
}
// Comment 3: Member function roll a dice, the die's value should
//            randomly chosen between 1 to sides number.
void Die::roll()
{
    value = rand() % sides + 1;
}
// Comment 4: Member function returns how many sides of the die.
int Die::getSides() const
{
    return sides;
}
// Comment 5: Member function returns the value of the die.
int Die::getValue()const
{
    return value;
}