#ifndef __CARD_H
#define __CARD_H

#include <string>

#define NUM_SUITS 4
#define NUM_VALUES 13
#define NUM_CARDS 52

const char lut_suit[NUM_SUITS] = {'c', 'd', 's', 'h'};
const char lut_value[NUM_VALUES] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};

class Card
{
private:
    int suit;
    int value;

public:
    Card();
    Card(int suit, int value);

    int getSuit();
    int getValue();

    void setSuit(int suit);
    void setValue(int value);

    Card& operator=(const Card& other);

    std::string toString();
};

#endif /* __CARD_H */
