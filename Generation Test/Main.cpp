#include <iostream>
#include "Generate.h"
int main()
{
    int seed = time(0);
    std::cout << "Platform generation test\n Input seed: ";
    std::cin >> seed;
    player* pl = new player();
    generation levelGen(seed, 20);
    levelGen.assignPlayer(pl);
    levelGen.start(1);
    std::vector<platform*> platforms = levelGen.getPlatforms();

    for (int i = 0; i < platforms.size(); i++) {
        std::cout << i << " platform.\nXPos: " << platforms[i]->getPos().at(0) << " YPos: " << platforms[i]->getPos().at(1) << " ZPos: " << platforms[i]->getPos().at(2) << "\n";
    }

    delete pl;
    return 0;
}