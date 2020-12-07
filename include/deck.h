#ifndef __DECK_H
#define __DECK_H

#include "card.h"
#include <cstdlib>
#include <string>

#define NUM_CARDS 52

class Deck
{
private:
    Card cards[NUM_CARDS];
    int index_deck;
    int num_cards_left;

public:
    /**
     * Default constructor, creates a standard deck of 52 cards and sets the position index pointer to 0
     */
    Deck();

    /**
     * Returns the top card of the deck and increments the position index
     * 
     * @return the top card of the deck
     */
    Card deal();

    /**
     * Randomizes the order of cards in the deck and returns the position index to 0
     */
    void shuffle();

    /**
     * Returns a string representation of the deck
     * 
     * @return a string representation of the deck
     */
    std::string toString();

};

#endif /* __DECK_H */
