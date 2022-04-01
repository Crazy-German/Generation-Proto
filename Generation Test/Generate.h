#pragma once
#include "Platform.h"
#include <random>

class generation {
private:
	int seed;
	int elements;
	platform* startPlat;
	std::vector<platform*> anchors;
public:
	generation(int seed, int elements);
	~generation();
	bool start(int selectedDiff);
	std::vector<platform*> getPlatforms();
};