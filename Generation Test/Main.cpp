#include <iostream>
#include <fstream>
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

    std::ofstream out("graph.dot");
    out << "digraph {\n" ;
    int scale = 10; 
    int abs_X = 0;
    int abs_Y = 0;
    for (int i = 0; i < platforms.size(); i++) {
        std::cout << i << " platform.\nXPos: " << platforms[i]->getPos().x << " YPos: " << platforms[i]->getPos().y << " ZPos: " << platforms[i]->getPos().z << "\n";
        //abs_X += platforms[i]->getPos().at(0) ;
        //abs_Y += platforms[i]->getPos().at(1) ;

        abs_X = platforms[i]->getPos().y;
        abs_Y = platforms[i]->getPos().x;

        out << "Platform_"<< i <<" [\n";
        out << "label = P_"<< i << "\n";
        //out << "pos = \""<< platforms[i]->getPos().at(0) * scale <<"," << platforms[i]->getPos().at(1) * scale <<"!\"\n";
        //out << "pos = \""<< abs_X + scale <<"," << abs_Y + scale <<"!\"\n";
        out << "pos = \""<< abs_X * scale <<"," << abs_Y * scale <<"!\"\n";
        out << "]\n";
        if (i != 0) {
            out << "Platform_" << i-1 << " -> " << "Platform_" << i << "\n";
        }
    }
    out << "}\n";

    out.close();

    delete pl;
    return 0;
}