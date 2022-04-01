#pragma once
#include "Platform.h"
#include <random>

class generation {
private:
	int seed;
	int elements;
	std::shared_ptr<platform> startPlat;
	std::vector<std::shared_ptr<platform>> anchors;
public:
	generation(int seed, int elements);
	~generation();
	bool start(int selectedDiff);
	std::vector<std::shared_ptr<platform>> getPlatforms();
};