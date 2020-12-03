#include "card.h"

Card::Card()
{
    this->suit = -1;
    this->value = -1;
}

Card::Card(int suit, int value)
{
    this->suit = suit;
    this->value = value;
}

int Card::getSuit()
{
    return this->suit;
}

int Card::getValue()
{
    return this->value;
}

void Card::setSuit(int suit)
{
    this->suit = suit;
}

void Card::setValue(int value)
{
    this->value = value;
}

Card& Card::operator=(const Card& other)
{
    this->suit = other.suit;
    this->value = other.value;

    return *this;
}


std::string Card::toString()
{
    std::string value = "";
    std::string suit = "";

    value += lut_value[this->value];
    suit += lut_suit[this->suit];

    return value + suit;
}