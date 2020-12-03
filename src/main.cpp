#include "main.h"

int main(int argc, char* argv[])
{
    srand(time(nullptr));
    // Card c(1, 5);

    // std::cout << c.toString() << std::endl;

    // Deck d = Deck();
    // d.shuffle();

    // Hand h = Hand();

    // for(int i = 0; i < 10; i++)
    // {
    //     h += d.draw();
    //     std::cout << h.isBusted() << " " << h.getValue() << " " << h.toString() << std::endl;
    // }

    Game g = Game();

    g.reset();
    g.dealPlayer();
    g.dealDealer();
    std::cout << g.toString() << std::endl;

    return 0;
}
