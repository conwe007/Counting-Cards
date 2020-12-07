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
    int num_soft_aces; // number of aces with a weight of 11
    int num_hard_aces; // number of aces with a weight of 1

public:
    /**
     * Default constructor, initializes ace counters to 0
     */
    Hand();

    /**
     * Returns the weight of the hand
     * 
     * @return the calculated weight of the hand
     */
    int getWeight();

    /**
     * Returns the number of aces in the hand
     * 
     * @return the number of aces in the hand
     */
    int getNumAces();

    /**
     * If at least one soft ace is present in the hand, harden one ace
     */
    void hardenOneAce();

    /**
     * Adds one card to the hand
     * 
     * @return a reference to the hand
     */
    Hand& operator+=(const Card& card);

    /**
     * Removes all cards from the hand and resets ace counters
     */
    void clear();

    /**
     * Returns a boolean indicating whether the hard weight of the hand is greater than 21
     * 
     * @return true if hard weight is > 21, false otherwise
     */
    bool isBusted();

    /**
     * Returns a boolean indicating whether the current weight of the hand is exactly 21
     * 
     * @return true if weight = 21, false otherwise
     */
    bool isBlackjack();

    /**
     * Returns a string representation of the hand
     * 
     * @return a string representation of the hand
     */
    std::string toString();
};

#endif /* __HAND_H */
