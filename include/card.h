#ifndef __CARD_H
#define __CARD_H

#include <string>

const char lut_suit[4] = {'c', 'd', 's', 'h'};
const char lut_value[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};

class Card
{
private:
    int suit;
    int value;

public:
    int getSuit();
    int getValue();

    void setSuit(int suit);
    void setValue(int value);

    string toString();
};

#endif /* __CARD_H */
