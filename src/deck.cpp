#include "deck.h"

Deck::Deck()
{
    for(int suit = 0; suit < NUM_SUITS; suit++)
    {
        for(int value = 0; value < NUM_VALUES; value++)
        {
            this->cards[suit * NUM_VALUES + value] = Card(suit, value);
        }
    }

    this->index_deck = 0;
    this->num_cards_left = NUM_CARDS;
}

Card Deck::deal()
{
    Card dealt_card;

    if(num_cards_left == 0)
    {
        dealt_card = Card();
    }
    else
    {
        dealt_card = this->cards[index_deck++];
        num_cards_left--;
    }
    
    return dealt_card;
}

void Deck::shuffle()
{
    for(int index_old = 0; index_old < NUM_CARDS; index_old++)
    {
        int index_new = (rand() % (NUM_CARDS - index_old)) + index_old;

        Card temp = this->cards[index_old];
        this->cards[index_old] = this->cards[index_new];
        this->cards[index_new] = temp;
    }

    index_deck = 0;
}

std::string Deck::toString()
{
    std::string output = "";

    for(int suit = 0; suit < NUM_SUITS; suit++)
    {
        for(int value = 0; value < NUM_VALUES; value++)
        {
            output += this->cards[suit * NUM_VALUES + value].toString();
            output += " ";
        }

        output += "\n";
    }

    return output;
}