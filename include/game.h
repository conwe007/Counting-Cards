#ifndef __GAME_H
#define __GAME_H

#include "deck.h"
#include "hand.h"

#define MOVE_ERROR -1
#define MOVE_STAY 0
#define MOVE_HIT 1
#define MOVE_SPLIT 2
#define MOVE_DOUBLE_DOWN 3

#define NUM_MOVES 4

#define PLAYER 0
#define DEALER 1

#define WEIGHT_DEALER_BUST 0

#define NUM_WEIGHTS 22

class Game
{
public:
    Deck deck;
    Hand player;
    Hand dealer;

    double player_expected_values[NUM_MOVES]; // table of expected values for each of the player's moves
    double dealer_expected_weights[NUM_WEIGHTS]; // table of odds that the dealer will end up with each possible weight

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
     * Fills dealer_expected_weights array with the dealer's odds of ending in each possible weight
     */
    void calculateExpectedWeightDealer();

    /**
     * Simulates specified number of trials to determine dealer's expected weight experimentally and returns the most likely weight
     * 
     * @return the weight the dealer is most likely to end up with
     */
    int simulateExpectedWeightDealer(int num_trials);

    /**
     * Fills player_expected_values array with the player's expected value for each move
     */
    void calculateExpectedValuePlayer();

    /**
     * Returns the player's expected value if they make the specified move
     * 
     * @return the player's expected value if they make the specified move
     */
    double getExpectedValuePlayer(int move);

    /**
     * Returns a string representation of the current game state
     * 
     * @return a string representation of the current game state
     */
    std::string toString();

    /**
     * Returns a string representation of dealer_expected_weights array
     * 
     * @return a string representation of dealer_expected_weights array
     */
    std::string dealerExpectedWeightsToString();
};

#endif /* __GAME_H */
