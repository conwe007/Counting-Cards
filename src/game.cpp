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

    switch(this->dealer.getState())
    {
        case STATE_START:
            if(this->dealer.getWeight() < 17)
            {
                move = MOVE_HIT;
                this->dealer.setState(STATE_HIT);
            }
            else
            {
                move = MOVE_STAY;
                this->dealer.setState(STATE_STAY);
            }
            break;
        
        case STATE_STAY:
            move = MOVE_STAY;
            this->dealer.setState(STATE_STAY);
            break;
        
        case STATE_HIT:
            if(this->dealer.getWeight() < 17)
            {
                move = MOVE_HIT;
                this->dealer.setState(STATE_HIT);
            }
            else if(this->dealer.getWeight() >= 17 && this->dealer.getWeight() <= 21)
            {
                move = MOVE_STAY;
                this->dealer.setState(STATE_STAY);
            }
            else
            {
                if(this->dealer.getNumSoftAces() == 0)
                {
                    move = MOVE_STAY;
                    this->dealer.setState(STATE_BUST);
                }
                else
                {
                    this->dealer.hardenOneAce();
                    this->dealer.setState(STATE_HARDEN_ACE);
                    move = this->chooseMoveDealer();
                }
            }
            break;
        
        case STATE_HARDEN_ACE:
            if(this->dealer.getWeight() < 17)
            {
                move = MOVE_HIT;
                this->dealer.setState(STATE_HIT);
            }
            else if(this->dealer.getWeight() >= 17 && this->dealer.getWeight() <= 21)
            {
                move = MOVE_STAY;
                this->dealer.setState(STATE_STAY);
            }
            else
            {
                move = MOVE_STAY;
                this->dealer.setState(STATE_BUST);
            }
            break;
        
        case STATE_BUST:
            move = MOVE_STAY;
            this->dealer.setState(STATE_BUST);
            break;
        
        default:
            move = MOVE_ERROR;
            this->dealer.setState(STATE_ERROR);
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