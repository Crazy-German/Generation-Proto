#include "Platform.h"

platform::platform()
    :pos({0.0f,0.0f,0.0f}), obstacles(0), difficluty(0), next(nullptr)
{
}

platform::platform(std::vector<float> pos, int obstacles, int difficluty)
    :pos(pos), obstacles(obstacles), difficluty(difficluty), next(nullptr)
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

void platform::move(float xOfset, float yOfset, float zOfset)
{
    this->pos[0] += xOfset;
    this->pos[1] += yOfset;
    this->pos[2] += zOfset;
}

std::vector<float> platform::getPos()
{
    return this->pos;
}

float platform::distance(std::vector<float>& position)
{
    return sqrtf(pow(this->pos[0] - position[0], 2.0) + pow(this->pos[1] - position[1], 2.0) + pow(this->pos[2] - position[2],2.0));
}
