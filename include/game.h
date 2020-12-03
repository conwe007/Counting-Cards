#ifndef __GAME_H
#define __GAME_H

#include "deck.h"
#include "hand.h"

class Game
{
private:
    Deck deck;
    Hand player;
    Hand dealer;

public:
    Game();

    void reset();
    void dealPlayer();
    void dealDealer();

    std::string toString();
};

#endif /* __GAME_H */
