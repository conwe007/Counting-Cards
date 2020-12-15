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
    int move = MOVE_ERROR;
    std::string move_str = "";

    std::cout << "Choose move ('stay'/'st', 'hit'/'h', 'split'/sp', 'double-down'/'dd'): ";
    std::cin >> move_str;

    if(move_str == "hit" || move_str == "h")
    {
        move = MOVE_HIT;
    }
    else if(move_str == "stay" || move_str == "st")
    {
        move = MOVE_STAY;
    }
    else if(move_str == "split" || move_str == "sp")
    {
        move = MOVE_SPLIT;
    }
    else if(move_str == "double-down" || move_str == "dd")
    {
        move = MOVE_DOUBLE_DOWN;
    }
    else
    {
        move = MOVE_ERROR;
    }
    

    return move;
}

int Game::chooseMoveDealer()
{
    int move = MOVE_STAY;

    switch(this->dealer.getState())
    {
        case STATE_START:
        {
            int dealer_weight = this->dealer.getWeight();

            if(dealer_weight < 17)
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
        }
        
        case STATE_STAY:
        {
            move = MOVE_STAY;
            this->dealer.setState(STATE_STAY);
            break;
        }
        
        case STATE_HIT:
        {
            int dealer_weight = this->dealer.getWeight();

            if(dealer_weight < 17)
            {
                move = MOVE_HIT;
                this->dealer.setState(STATE_HIT);
            }
            else if(dealer_weight >= 17 && dealer_weight <= 21)
            {
                move = MOVE_STAY;
                this->dealer.setState(STATE_STAY);
            }
            else
            {
                int dealer_num_soft_aces = this->dealer.getNumSoftAces();

                if(dealer_num_soft_aces == 0)
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
        }
        
        case STATE_HARDEN_ACE:
        {
            int dealer_weight = this->dealer.getWeight();

            if(dealer_weight < 17)
            {
                move = MOVE_HIT;
                this->dealer.setState(STATE_HIT);
            }
            else if(dealer_weight >= 17 && dealer_weight <= 21)
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
        }
        
        case STATE_BUST:
        {
            move = MOVE_STAY;
            this->dealer.setState(STATE_BUST);
            break;
        }
        
        default:
        {
            move = MOVE_ERROR;
            this->dealer.setState(STATE_ERROR);
            break;
        }
    }

    return move;
}

int Game::bestMovePlayer()
{
    int move = MOVE_STAY;



    return move;
}

void Game::calculateExpectedWeightDealer()
{
    int dealer_weight = this->dealer.getWeight();

    if(dealer_weight >= 17)
    {
        for(int index_dealer_expected_weight = 0; index_dealer_expected_weight < NUM_WEIGHTS; index_dealer_expected_weight++)
        {
            if(dealer_weight == index_dealer_expected_weight)
            {
                this->dealer_expected_weights[index_dealer_expected_weight] = 1.0;
            }
            else
            {
                this->dealer_expected_weights[index_dealer_expected_weight] = 0.0;
            }
        }
    }
    else
    {
        
    }
    
}

int Game::simulateExpectedWeightDealer(int num_trials)
{
    for(int index_dealer_expected_weights = 0; index_dealer_expected_weights < NUM_WEIGHTS; index_dealer_expected_weights++)
    {
        dealer_expected_weights[index_dealer_expected_weights] = 0.0;
    }

    for(int trial = 0; trial < num_trials; trial++)
    {
        Deck deck_simulation = this->deck;
        Hand dealer_simulation = this->dealer;

        deck_simulation.shuffleRemaining();

        int move_dealer = MOVE_ERROR;

        while(move_dealer != MOVE_STAY)
        {
            move_dealer = dealer_simulation.chooseMoveDealer();

            if(move_dealer == MOVE_HIT)
            {
                dealer_simulation += deck_simulation.deal();
            }
        }

        int dealer_simulation_weight = dealer_simulation.getWeight();

        if(dealer_simulation_weight > 21)
        {
            dealer_expected_weights[WEIGHT_DEALER_BUST]++;
        }
        else
        {
            dealer_expected_weights[dealer_simulation_weight]++;
        }       
    }

    double most_likely_weight = 0.0;
    int index_most_likely_weight = -1;

    for(int index_dealer_expected_weights = 0; index_dealer_expected_weights < NUM_WEIGHTS; index_dealer_expected_weights++)
    {
        dealer_expected_weights[index_dealer_expected_weights] /= num_trials;

        if(dealer_expected_weights[index_dealer_expected_weights] > most_likely_weight)
        {
            most_likely_weight = dealer_expected_weights[index_dealer_expected_weights];
            index_most_likely_weight = index_dealer_expected_weights;
        }
    }

    return index_most_likely_weight;
}

void Game::calculateExpectedValuePlayer()
{
    
}

double Game::getExpectedValuePlayer(int move)
{
    double expected_value = -1.0;

    if(move >= 0 && move < NUM_MOVES)
    {
        expected_value = this->player_expected_values[move];
    }

    return expected_value;
}

std::string Game::toString()
{
    std::string output = "";

    output += ("Player: " + this->player.toString() + "\n");
    output += ("Dealer: " + this->dealer.toString());

    return output;
}

std::string Game::dealerExpectedWeightsToString()
{
    std::string output = "";

    output += (std::to_string(dealer_expected_weights[WEIGHT_DEALER_BUST]) + " ");

    for(int index_dealer_expected_weights = 17; index_dealer_expected_weights < NUM_WEIGHTS; index_dealer_expected_weights++)
    {
        output += (std::to_string(dealer_expected_weights[index_dealer_expected_weights]) + " ");
    }

    return output;
}
