#include <iostream>
#include "Generate.h"
int main()
{
    std::cout << "Platform generation test\n";

    generation levelGen(20, 10);
    levelGen.start(1);
    std::vector<platform*> platforms = levelGen.getPlatforms();

    for (int i = 0; i < platforms.size(); i++) {
        std::cout << i << " platform.\nXPos: " << platforms[i]->getPos().at(0) << " YPos: " << platforms[i]->getPos().at(1) << "\n";
    }

    return 0;
}