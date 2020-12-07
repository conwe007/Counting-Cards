#ifndef __CARD_H
#define __CARD_H

#include <string>

#define NUM_SUITS 4
#define NUM_VALUES 13

#define ACE_OFFSET 10

const char lut_suit[NUM_SUITS] = {'c', 'd', 's', 'h'};
const char lut_value[NUM_VALUES] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
const int lut_weight[NUM_VALUES] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

class Card
{
private:
    int suit;
    int value;
    bool is_soft_ace; // true if ace weight is 11, false if ace weight is 1
    bool is_face_down; // true if the card should not be displayed, false otherwise

public:
    /**
     * Default constructor, initializes the card to error values
     */
    Card();

    /**
     * Constructor, initializes the card to defined values
     */
    Card(int suit, int value);

    /**
     * Returns an integer indicating the cards suit
     * 
     * @return an integer between 0 and 3, inclusive
     */
    int getSuit() const;

    /**
     * Returns an integer indicating the cards value
     * 
     * @return an integer between 0 and 12, inclusive
     */
    int getValue() const;

    /**
     * Returns an integer indicating the cards weight (its value when determining hand weight)
     * 
     * @return an integer between 1 and 11, inclusive
     */
    int getWeight() const;

    /**
     * Sets a card's suit
     * 
     * @param suit the suit to set as the card's
     */
    void setSuit(int suit);

    /**
     * Sets a card's value
     * 
     * @param value the value to set as the card's
     */
    void setValue(int value);

    /**
     * Returns a boolean indicating whether the card's weight is 1 or 11, if it is an ace
     * 
     * @returns true if the card is a soft ace (weight = 11), false if the card is a hard ace (weight = 1)
     */
    bool isSoftAce() const;

    /**
     * If the card is a soft ace then make it a hard ace, and vice versa
     */
    void toggleAceValue();

    /**
     * Returns a boolean indicating whether the card is face up or face down (displayed or not displayed)
     * 
     * @return true if the card is face down (not displayed), false if the card is face up (displayed)
     */
    bool isFaceDown();

    /**
     * If the card is face down then flip it face up, and vice versa
     */
    void flipOver();

    /**
     * Sets the class members of the card equal to those of another card
     * 
     * @param other the other card to pull class member values from
     * @return a reference to the card whose class members were set
     */
    Card& operator=(const Card& other);

    /**
     * Returns a string representation of the card
     * 
     * @return a string representation of the card
     */
    std::string toString();
};

#endif /* __CARD_H */
