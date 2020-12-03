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
    this->player += this->deck.draw();
}

void Game::dealDealer()
{
    this->dealer += this->deck.draw();
}

std::string Game::toString()
{
    std::string output = "";

    output += ("Player: " + this->player.toString() + "\n");
    output += ("Dealer: " + this->dealer.toString() + "\n");

    return output;
}