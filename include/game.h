#ifndef __GAME_H
#define __GAME_H

#include "deck.h"
#include "hand.h"

#define STAY 0
#define HIT 1

#define PLAYER 0
#define DEALER 1

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
    int chooseMovePlayer();
    int chooseMoveDealer();
    int bestMovePlayer();

    std::string toString();
};

#endif /* __GAME_H */
