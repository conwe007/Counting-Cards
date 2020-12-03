#include "hand.h"

Hand::Hand()
{
    
}

int Hand::getValue()
{
    int total = 0;

    for(int index_hand = 0; index_hand < this->cards.size(); index_hand++)
    {
        total += (this->cards[index_hand].getValue() + 1);
    }

    return total;
}

Hand& Hand::operator+=(const Card& card)
{
    this->cards.push_back(card);

    return *this;
}

void Hand::clear()
{
    this->cards.clear();
}

bool Hand::isBusted()
{
    bool is_busted = true;

    if(this->getValue() <= 21)
    {
        is_busted = false;
    }

    return is_busted;
}

bool Hand::isBlackjack()
{
    bool is_blackjack = false;

    if(this->getValue() == 21)
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