#include<iostream>
#include<cstdlib>
#include<ctime>
#include "Die.h"
using namespace std;

Die::Die(int numSides)
    : sides(numSides)
{
    value = roll();
}
void Die::setSides(int numSides)
{
    sides = numSides;
    value = roll();
}
int Die::roll()
{
    srand(static_cast<unsigned int>(time(0)));
    value = rand() % sides + 1;
    return value;
}
int Die::getSides() const
{
    return sides;
}
int Die::getValue()const
{
    return value;
}