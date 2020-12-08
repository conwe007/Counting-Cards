#include "main.h"

int main(int argc, char* argv[])
{
    srand(time(nullptr));

    // Hand h = Hand();
    // h += Card(0, 0);
    // h += Card(1, 0);
    // h += Card(2, 0);
    // h += Card(3, 0);

    // std::cout << h.toString() << h.getWeight() << std::endl;

    // h.hardenOneAce();

    // std::cout << h.toString() << h.getWeight() << std::endl;

    // h.hardenOneAce();

    // std::cout << h.toString() << h.getWeight() << std::endl;

    // h.hardenOneAce();

    // std::cout << h.toString() << h.getWeight() << std::endl;

    // h.hardenOneAce();

    // std::cout << h.toString() << h.getWeight() << std::endl;

    // h.hardenOneAce();
    // std::cout << h.toString() << h.getWeight() << std::endl;

    // h.hardenOneAce();

    Game g = Game();

    g.reset();
    // g.dealDealer();
    // g.dealDealer();
    // std::cout << g.dealer.getWeight() << " " << g.dealer.toString() << std::endl;

    // while(g.dealer.getState() != STATE_STAY && g.dealer.getState() != STATE_BUST)
    // {
    //     switch(g.chooseMoveDealer())
    //     {
    //         case MOVE_STAY:
    //             std::cout << "dealer stays" << std::endl;
    //             break;
            
    //         case MOVE_HIT:
    //             g.dealDealer();
    //             std::cout << "dealer hits" << std::endl;
    //             std::cout << g.dealer.getWeight() << " " << g.dealer.toString() << std::endl;
    //     }
    // }

    // std::cout << g.dealer.getWeight() << " " << g.dealer.getState() << std::endl;

    Card ace1 = Card(0, 0);
    Card ace2 = Card(1, 0);
    Card five = Card(0, 4);
    Card seven = Card(0, 6);

    g.dealer += ace1;
    g.dealer += five;
    std::cout << g.dealer.getWeight() << " " << g.dealer.toString() << std::endl;
    std::cout << "move: " << g.chooseMoveDealer() << std::endl;
    g.dealer += seven;
    std::cout << g.dealer.getWeight() << " " << g.dealer.toString() << std::endl;
    std::cout << "move: " << g.chooseMoveDealer() << std::endl;
    g.dealer += ace2;
    std::cout << g.dealer.getWeight() << " " << g.dealer.toString() << std::endl;
    std::cout << "move: " << g.chooseMoveDealer() << std::endl;
    
    return 0;
}
