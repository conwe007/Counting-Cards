#ifndef __DECK_H
#define __DECK_H

#include "card.h"
#include <cstdlib>
#include <string>

class Deck
{
private:
    Card cards[NUM_CARDS];
    int index_deck;

public:
    Deck();

    Card draw();
    void shuffle();

    std::string toString();

};

#endif /* __DECK_H */
