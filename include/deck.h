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
    Deck();

    Card deal();
    void shuffle();

    std::string toString();

};

#endif /* __DECK_H */
