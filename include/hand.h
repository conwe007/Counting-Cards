#ifndef __HAND_H
#define __HAND_H

#include "card.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#define MOVE_ERROR -1
#define MOVE_STAY 0
#define MOVE_HIT 1
#define MOVE_SPLIT 2
#define MOVE_DOUBLE_DOWN 3

#define STATE_ERROR -1
#define STATE_START 0
#define STATE_STAY 1
#define STATE_HIT 2
#define STATE_HARDEN_ACE 3
#define STATE_BUST 4

class Hand
{
private:
    std::vector<Card> cards;
    int num_soft_aces; // number of aces with a weight of 11
    int num_hard_aces; // number of aces with a weight of 1
    int state; // used to determine next move

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
     * Returns the number of soft aces in the hand
     * 
     * @return the number of soft aces in the hand
     */
    int getNumSoftAces();

    /**
     * Returns hand's state
     * 
     * @return hand's state
     */
    int getState();

    /**
     * Sets the hand's state
     * 
     * @param state the state to set to
     */
    void setState(int state);

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
     * Follows the rules of blackjack to determine a move for the dealer and returns an integer indicating a move
     * 
     * @return MOVE_STAY or MOVE_HIT
     */
    int chooseMoveDealer();

    /**
     * Takes input from the player and returns an integer indicating a move
     * 
     * @return MOVE_STAY, MOVE_HIT, MOVE_SPLIT, or MOVE_DOUBLE_DOWN
     */
    int chooseMovePlayer();

    /**
     * Returns a string representation of the hand
     * 
     * @return a string representation of the hand
     */
    std::string toString();
};

#endif /* __HAND_H */
