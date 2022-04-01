#include "Platform.h"

platform::platform()
    :pos({0.0f,0.0f,0.0f}), obstacles(0), difficluty(0)
{
}

platform::platform(std::vector<float> pos, int obstacles, int difficluty)
    :pos(pos), obstacles(obstacles), difficluty(difficluty)
{
}

platform::~platform()
{
   //this->next.reset();
   
}

void platform::setPosition(float x, float y, float z)
{
    this->pos[0] = x;
    this->pos[1] = y;
    this->pos[2] = z;
}

std::vector<float> platform::getPos()
{
    return this->pos;
}

float platform::distance(std::vector<float>& position)
{
    return 0.0f;
}
