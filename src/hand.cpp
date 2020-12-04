#include "hand.h"

Hand::Hand()
{
    num_aces = 0;
}

int Hand::getWeight()
{
    int total = 0;

    for(int index_hand = 0; index_hand < this->cards.size(); index_hand++)
    {
        total += (this->cards[index_hand].getWeight());
    }

    return total;
}

int Hand::getNumAces()
{
    return num_aces;
}

void Hand::lowerOneAce()
{
    for(int index_hand = 0; index_hand < this->cards.size(); index_hand++)
    {
        if(lut_value[this->cards[index_hand].getValue()] == 'A' && this->cards[index_hand].isHighAce())
        {
            this->cards[index_hand].toggleAceValue();
            return;
        }
    }
}

Hand& Hand::operator+=(const Card& card)
{
    this->cards.push_back(card);

    if(lut_value[card.getValue()] == 'A')
    {
        num_aces++;
    }

    return *this;
}

void Hand::clear()
{
    this->cards.clear();
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