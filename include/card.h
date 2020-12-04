#ifndef __CARD_H
#define __CARD_H

#include <string>

#define NUM_SUITS 4
#define NUM_VALUES 13

#define ACE_OFFSET 10

const char lut_suit[NUM_SUITS] = {'c', 'd', 's', 'h'};
const char lut_value[NUM_VALUES] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
const int lut_weight[NUM_VALUES] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

class Card
{
private:
    int suit;
    int value;
    bool is_high_ace;
    bool is_face_down;

public:
    Card();
    Card(int suit, int value);

    int getSuit() const;
    int getValue() const;
    int getWeight() const;

    void setSuit(int suit);
    void setValue(int value);

    bool isHighAce();
    void toggleAceValue();

    bool isFaceDown();
    void flipOver();

    Card& operator=(const Card& other);

    std::string toString();
};

#endif /* __CARD_H */
