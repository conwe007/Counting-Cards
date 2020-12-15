#include "main.h"

int main(int argc, char* argv[])
{
    srand(time(nullptr));

    Game g = Game();

    g.reset();

    g.dealDealer();
    g.dealDealer();
    std::cout << g.dealer.toString() << std::endl;

    g.simulateExpectedWeightDealer(100000);
    std::cout << g.dealerExpectedWeightsToString() << std::endl;
    
    
    return 0;
}
