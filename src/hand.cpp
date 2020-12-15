#include "hand.h"

Hand::Hand()
{
    num_soft_aces = 0;
    num_hard_aces = 0;
    state = STATE_START;
}

int Hand::getWeight()
{
    int total = 0;

    for(int index_hand = 0; index_hand < this->cards.size(); index_hand++)
    {
        total += this->cards[index_hand].getWeight();
    }

    return total;
}

int Hand::getNumAces()
{
    return num_soft_aces + num_hard_aces;
}

int Hand::getNumSoftAces()
{
    return num_soft_aces;
}

int Hand::getState()
{
    return state;
}

void Hand::setState(int state)
{
    this->state = state;
}

void Hand::hardenOneAce()
{
    for(int index_hand = 0; index_hand < this->cards.size(); index_hand++)
    {
        if(lut_value[this->cards[index_hand].getValue()] == 'A' && this->cards[index_hand].isSoftAce())
        {
            this->cards[index_hand].toggleAceValue();
            num_soft_aces--;
            num_hard_aces++;
            return;
        }
    }
}

Hand& Hand::operator+=(const Card& card)
{
    this->cards.push_back(card);

    if(lut_value[card.getValue()] == 'A')
    {
        if(card.isSoftAce())
        {
            num_soft_aces++;
        }
        else
        {
            num_hard_aces++;
        }
    }

    return *this;
}

void Hand::clear()
{
    this->cards.clear();
    this->num_soft_aces = 0;
    this->num_hard_aces = 0;
    this->state = STATE_START;
}

bool Hand::isBusted()
{
    bool is_busted = true;

    if(this->getWeight() <= 21)
    {
        is_busted = false;
    }

    return is_busted;
}

bool Hand::isBlackjack()
{
    bool is_blackjack = false;

    if(this->getWeight() == 21)
    {
        is_blackjack = true;
    }

    return is_blackjack;
}

int Hand::chooseMoveDealer()
{
    int move = MOVE_STAY;

    switch(this->state)
    {
        case STATE_START:
        {
            int dealer_weight = this->getWeight();

            if(dealer_weight < 17)
            {
                move = MOVE_HIT;
                this->state = STATE_HIT;
            }
            else
            {
                move = MOVE_STAY;
                this->state = STATE_STAY;
            }
            break;
        }
        
        case STATE_STAY:
        {
            move = MOVE_STAY;
            this->state = STATE_STAY;
            break;
        }
        
        case STATE_HIT:
        {
            int dealer_weight = this->getWeight();

            if(dealer_weight < 17)
            {
                move = MOVE_HIT;
                this->state = STATE_HIT;
            }
            else if(dealer_weight >= 17 && dealer_weight <= 21)
            {
                move = MOVE_STAY;
                this->state = STATE_STAY;
            }
            else
            {
                int dealer_num_soft_aces = this->num_soft_aces;

                if(dealer_num_soft_aces == 0)
                {
                    move = MOVE_STAY;
                    this->state = STATE_BUST;
                }
                else
                {
                    this->hardenOneAce();
                    this->state = STATE_HARDEN_ACE;
                    move = this->chooseMoveDealer();
                }
            }
            break;
        }
        
        case STATE_HARDEN_ACE:
        {
            int dealer_weight = this->getWeight();

            if(dealer_weight < 17)
            {
                move = MOVE_HIT;
                this->state = STATE_HIT;
            }
            else if(dealer_weight >= 17 && dealer_weight <= 21)
            {
                move = MOVE_STAY;
                this->state = STATE_STAY;
            }
            else
            {
                move = MOVE_STAY;
                this->state = STATE_BUST;
            }
            break;
        }
        
        case STATE_BUST:
        {
            move = MOVE_STAY;
            this->state = STATE_BUST;
            break;
        }
        
        default:
        {
            move = MOVE_ERROR;
            this->state = STATE_ERROR;
            break;
        }
    }

    return move;
}

int Hand::chooseMovePlayer()
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

std::string Hand::toString()
{
    std::string output = "";

    for(int index_hand = 0; index_hand < this->cards.size(); index_hand++)
    {
        output += this->cards[index_hand].toString();
        output += " ";
    }

    return output;
}