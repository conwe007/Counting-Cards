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

    int card_stats[NUM_VALUES];

public:
    /**
     * Default constructor, creates a standard deck of 52 cards and sets the position index pointer to 0
     */
    Deck();

    /**
     * Assigns values of deck to another Deck object
     * 
     * @return a reference to other Deck object
     */
    Deck& operator=(const Deck& deck);

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
     * Randomizes the order of cards in the deck after index_deck position
     */
    void shuffleRemaining();

    /**
     * Returns the number of cards of the given value left in the deck
     * 
     * @return the number of cards of the given value left in the deck
     */
    int getCardStats(int value);

    /**
     * Returns a string representation of the deck
     * 
     * @return a string representation of the deck
     */
    std::string toString();
};

#endif /* __DECK_H */
