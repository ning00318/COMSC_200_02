#ifndef DIE_H
#define DIE_H

class Die
{
public:
    Die(int);
    void setSides(int);
    void roll();
    int getSides() const;
    int getValue()const;
private:
    int sides;  // Number of sides on the die
    int value;  // The die's value
};

#endif