#include "main.h"

int main(int argc, char* argv[])
{
    srand(time(nullptr));

    Hand h = Hand();
    h += Card(0, 0);
    h += Card(1, 0);
    h += Card(2, 0);
    h += Card(3, 0);

    std::cout << h.toString() << h.getWeight() << std::endl;

    h.lowerOneAce();

    std::cout << h.toString() << h.getWeight() << std::endl;

    h.lowerOneAce();

    std::cout << h.toString() << h.getWeight() << std::endl;

    h.lowerOneAce();

    std::cout << h.toString() << h.getWeight() << std::endl;

    h.lowerOneAce();

    std::cout << h.toString() << h.getWeight() << std::endl;

    h.lowerOneAce();
    std::cout << h.toString() << h.getWeight() << std::endl;

    h.lowerOneAce();

    // Game g = Game();

    // g.reset();
    // g.dealPlayer();
    // g.dealDealer();
    // std::cout << g.toString() << std::endl;

    return 0;
}
