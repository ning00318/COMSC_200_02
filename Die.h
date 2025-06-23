#ifndef DIE_H
#define DIE_H

class Die
{
public:
    Die(int);
    void setSides(int);
    int roll();
    int getSides() const;
    int getValue()const;
private:
    int sides;
    int value;
};

#endif