#pragma once
#include <math.h>

struct Vector2 {
	float x;
	float y;

	float length() {
		return sqrt(x * x + y * y);
	}
};

struct Vector3 {
	float x;
	float y;
	float z;

	float length() {
		return sqrt(x * x + y * y + z * z);
	}
};