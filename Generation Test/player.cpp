#include "player.h"

player::player()
	:pos({0.0f, 0.0f, 0.0f}), jumpvel(20.0f), speed(5.0f), gravity(9.8f), launchangle(45.0f)
{
}

void player::moveto(const std::vector<float>& pos)
{
	for (int i = 0; i < this->pos.size(); i++) {
		this->pos[i] = pos[i];
	}
}
float player::getJumpDistance()
{
	float vel = sqrtf(powf(this->speed, 2.0) + powf(this->jumpvel, 2.0f));
	float t = (vel * sin(this->launchangle) + sqrtf(powf(vel * sinf(this->launchangle), 2.0f) + 2 * this->gravity * this->pos[2])) / this->gravity;

	return this->speed * t;
}

float player::getJumpDistance(float height)
{
	float vel = sqrtf(powf(this->speed, 2.0) + powf(this->jumpvel, 2.0f));
	float t = (vel * sin(this->launchangle) + sqrtf(powf(vel * sinf(this->launchangle), 2.0f) + 2 * this->gravity * (this->pos[2]-height))) / this->gravity;

	return this->speed * t;
}

float player::jumpHeight()
{
	float vel = sqrtf(powf(this->speed, 2.0) + powf(this->jumpvel, 2.0f));
	return this->pos[2] + (powf(vel, 2.0f) * powf(sin(this->launchangle),2.0f) / (2 * this->gravity));
}

bool player::isJumpPossible(std::vector<float> position)
{
	float jumpheight = jumpHeight();
	float heightDif = jumpheight - position.at(2);
	float jumpDist = getJumpDistance(position.at(2));
	float distanceDif = jumpDist - this->distance(position);
	/*if (heightDif <= 0) {
		plat->move(0, 0, heightDif);
	}
	if (distanceDif <= 0)
	{
		plat->move();
	}*/
	if (heightDif <= 0) {
		return false;
	}
	if (distanceDif <= 0) {
		return false;
	}
	return true;
}

float player::distance(std::vector<float>& position)
{
	return sqrtf(pow(this->pos[0] - position[0], 2.0) + pow(this->pos[1] - position[1], 2.0) + pow(this->pos[2] - position[2], 2.0));
}
