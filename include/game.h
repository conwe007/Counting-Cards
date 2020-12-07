#ifndef __GAME_H
#define __GAME_H

#include "deck.h"
#include "hand.h"

#define MOVE_STAY 0
#define MOVE_HIT 1
#define MOVE_SPLIT 2
#define MOVE_DOUBLE_DOWN 3

#define PLAYER 0
#define DEALER 1

class Game
{
private:
    Deck deck;
    Hand player;
    Hand dealer;

public:
    /**
     * Default constructor, creates new objects for deck, player, and dealer
     */
    Game();

    /**
     * Reshuffles the deck and clears player and dealer hands
     */
    void reset();

    /**
     * Removes the top card of the deck and adds it to the player hand
     */
    void dealPlayer();

    /**
     * Removes the top card of the deck and adds it to the dealer hand
     */
    void dealDealer();

    /**
     * Takes input from the player and returns an integer indicating a move
     * 
     * @return MOVE_STAY, MOVE_HIT, MOVE_SPLIT, or MOVE_DOUBLE_DOWN
     */
    int chooseMovePlayer();

    /**
     * Follows the rules of blackjack to determine a move for the dealer and returns an integer indicating a move
     * 
     * @return MOVE_STAY or MOVE_HIT
     */
    int chooseMoveDealer();

    /**
     * Analyzes current game state and determines the best move for the player and returns an integer indicating the best move
     * 
     * @return MOVE_STAY, MOVE_HIT, MOVE_SPLIT, or MOVE_DOUBLE_DOWN
     */
    int bestMovePlayer();

    /**
     * Returns a string representation of the current game state
     * 
     * @return a string representation of the current game state
     */
    std::string toString();
};

#endif /* __GAME_H */
