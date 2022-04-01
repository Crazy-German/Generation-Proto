#include <vector>
#include <math.h>
#include <memory>

class platform {
private:
	std::vector<float> pos;
	int obstacles;
	int difficluty;
public:
	platform();
	platform(std::vector<float> pos, int obstacles, int difficluty);
	~platform();
	void setPosition(float x, float y, float z);
	std::vector<float> getPos();
	float distance(std::vector<float> &position);
	std::shared_ptr<platform> next;
};