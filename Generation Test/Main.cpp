#include <iostream>
#include "Generate.h"
int main()
{
    std::cout << "Platform generation test\n";

    generation levelGen((int)time(0), 10);
    levelGen.start(1);
    std::vector<std::shared_ptr<platform>> platforms = levelGen.getPlatforms();

    for (int i = 0; i < platforms.size(); i++) {
        std::cout << i << " platform.\nXPos: " << platforms[i].get()->getPos().at(0) << " YPos: " << platforms[i].get()->getPos().at(1) << "\n";
    }


    for (int i = 0; i < platforms.size(); i++) {
        platforms[i].reset();
    }
    platforms.clear();
    return 0;
}