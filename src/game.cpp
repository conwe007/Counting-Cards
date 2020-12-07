#include "game.h"

Game::Game()
{
    this->deck = Deck();
    this->player = Hand();
    this->dealer = Hand();
}

void Game::reset()
{
    this->deck.shuffle();
    this->player.clear();
    this->dealer.clear();
}

void Game::dealPlayer()
{
    this->player += this->deck.deal();
}

void Game::dealDealer()
{
    this->dealer += this->deck.deal();
}

int Game::chooseMovePlayer()
{
    int move = MOVE_STAY;



    return move;
}

int Game::chooseMoveDealer()
{
    int move = MOVE_STAY;

    switch(this->dealer.getNumAces())
    {
        case 0:
            if(this->dealer.getWeight() < 17)
            {
                
            }
            break;
        
        case 1:

            break;
        
        case 2:

            break;
        
        case 3:

            break;
        
        case 4:

            break;
        
        default:
            break;
    }

    return move;
}

int Game::bestMovePlayer()
{
    int move = MOVE_STAY;



    return move;
}

std::string Game::toString()
{
    std::string output = "";

    output += ("Player: " + this->player.toString() + "\n");
    output += ("Dealer: " + this->dealer.toString());

    return output;
}