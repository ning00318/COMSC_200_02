#include<iostream>
#include<cstdlib>
#include "Die.h"
using namespace std;

Die::Die(int numSides)
    : sides(numSides)
{
    roll();
}
void Die::setSides(int numSides)
{
    sides = numSides;
    roll();
}
void Die::roll()
{
    value = rand() % sides + 1;
}
int Die::getSides() const
{
    return sides;
}
int Die::getValue()const
{
    return value;
}