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

    for(int value = 0; value < NUM_VALUES; value++)
    {
        this->card_stats[value] = NUM_SUITS;
    }
}

Deck& Deck::operator=(const Deck& deck)
{
    for(int index_deck = 0; index_deck < NUM_CARDS; index_deck++)
    {
        this->cards[index_deck] = deck.cards[index_deck];
    }

    this->index_deck = deck.index_deck;
    this->num_cards_left = deck.num_cards_left;

    for(int value = 0; value < NUM_VALUES; value++)
    {
        this->card_stats[value] = deck.card_stats[value];
    }

    return *this;
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
        this->num_cards_left--;
        this->card_stats[dealt_card.getValue()]--;
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

    this->index_deck = 0;
    this->num_cards_left = NUM_CARDS;
}

void Deck::shuffleRemaining()
{
    for(int index_old = this->index_deck; index_old < NUM_CARDS; index_old++)
    {
        int index_new = (rand() % (NUM_CARDS - index_old)) + index_old;

        Card temp = this->cards[index_old];
        this->cards[index_old] = this->cards[index_new];
        this->cards[index_new] = temp;
    }
}

int Deck:: getCardStats(int value)
{
    int card_stats_value = -1;

    if(value >= 0 && value < NUM_VALUES)
    {
        card_stats_value = this->card_stats[value];
    }

    return card_stats_value;
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