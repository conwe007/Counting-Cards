#include "card.h"

Card::Card()
{
    this->suit = -1;
    this->value = -1;
    this->is_soft_ace = true;
    this->is_face_down = false;
}

Card::Card(int suit, int value)
{
    this->suit = suit;
    this->value = value;
    this->is_soft_ace = true;
    this->is_face_down = false;
}

int Card::getSuit() const
{
    return this->suit;
}

int Card::getValue() const
{
    return this->value;
}

int Card::getWeight() const
{
    int weight = 0;

    if(lut_value[this->value] == 'A')
    {
        if(this->is_soft_ace)
        {
            weight = lut_weight[this->value] + ACE_OFFSET;
        }
        else
        {
            weight = lut_weight[this->value];
        }
    }
    else
    {
        weight = lut_weight[this->value];
    }

    return weight;
}

void Card::setSuit(int suit)
{
    this->suit = suit;
}

void Card::setValue(int value)
{
    this->value = value;
}

bool Card::isSoftAce() const
{
    return this->is_soft_ace;
}

void Card::toggleAceValue()
{
    this->is_soft_ace = !this->is_soft_ace;
}

bool Card::isFaceDown()
{
    return this->is_face_down;
}

void Card::flipOver()
{
    this->is_face_down = !this->is_face_down;
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

    if(this->is_face_down)
    {
        value += "X";
        value += "x";
    }
    else
    {
        value += lut_value[this->value];
        suit += lut_suit[this->suit];
    }
    
    return value + suit;
}