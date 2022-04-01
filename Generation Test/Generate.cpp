#include "Generate.h"
#include <iostream>
generation::generation(int seed, int elements)
	:seed(seed), elements(elements)
{
	this->startPlat.reset(new platform({ 0.0f, 0.0f, 0.0f }, 0,0));
}

generation::~generation()
{
	/*this->startPlat.reset();
	for (int i = 0; i < anchors.size(); i++) {
		std::cout << anchors.at(i).use_count() << "\n";
		//anchors.at(i).get()->~platform();
		anchors.at(i).get()->next.reset();
		anchors.at(i).reset();
		int h = 4;
	}*/
	anchors.clear();
}

bool generation::start(int selectedDiff)
{
	srand(this->seed);
	float xPos = 0;
	int xofMin = 5;
	float yPos = 0;
	int stepMax = 10*selectedDiff;
	std::shared_ptr<platform> current = startPlat;
	std::shared_ptr<platform> newPlat;
	for (int i = 0; i < this->elements; i++) {
		xPos +=  xofMin + (std::rand() % (stepMax - xofMin +1));
		yPos += rand() % stepMax;
		newPlat.reset(new platform({ xPos, yPos, 0.0f }, 0, 1));
		current.get()->next = newPlat;
		this->anchors.push_back(current);
		current = newPlat;
	}
	this->anchors.push_back(newPlat);
	return true;
}

std::vector<std::shared_ptr<platform>> generation::getPlatforms()
{
	return this->anchors;
}

