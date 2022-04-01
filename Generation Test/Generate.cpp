#include "Generate.h"
#include <iostream>
generation::generation(int seed, int elements)
	:seed(seed), elements(elements)
{
	this->startPlat = new platform({ 0.0f, 0.0f, 0.0f }, 0,0);
}

generation::~generation()
{
	this->startPlat = nullptr;
	for (int i = 0; i < anchors.size(); i++) {
		delete anchors.at(i);
	}
	anchors.clear();
}

bool generation::start(int selectedDiff)
{
	srand(this->seed);
	float xPos = 0;
	int xofMin = 5;
	float yPos = 0;
	int stepMax = 10*selectedDiff;
	platform* current = startPlat;
	platform* newPlat;
	for (int i = 0; i < this->elements; i++) {
		xPos +=  xofMin + (std::rand() % (stepMax - xofMin +1));
		yPos += rand() % stepMax;
		newPlat = new platform({ xPos, yPos, 0.0f }, 0, 1);
		current->next = newPlat;
		this->anchors.push_back(current);
		current = newPlat;
	}
	this->anchors.push_back(newPlat);
	return true;
}

std::vector<platform*> generation::getPlatforms()
{
	return this->anchors;
}

