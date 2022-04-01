#pragma once
#include <vector>
#include <math.h>
class player {
private:
	float jumpvel;
	float speed;
	float launchangle;
	float gravity;
	std::vector<float> pos;
public:
	player();
	void moveto(const std::vector<float>& pos );
	float getJumpDistance();
	float getJumpDistance(float height);
	float jumpHeight();
	bool isJumpPossible(std::vector<float> position);
	float distance(std::vector<float>& position);
};