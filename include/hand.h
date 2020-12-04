#ifndef __HAND_H
#define __HAND_H

#include "card.h"
#include <cstdlib>
#include <string>
#include <vector>

class Hand
{
private:
    std::vector<Card> cards;
    int num_aces;

public:
    Hand();

    int getWeight();
    int getNumAces();
    void lowerOneAce();
    Hand& operator+=(const Card& card);
    void clear();
    bool isBusted();
    bool isBlackjack();

    std::string toString();
};

#endif /* __HAND_H */
