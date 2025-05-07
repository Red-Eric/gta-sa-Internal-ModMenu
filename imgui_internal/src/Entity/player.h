#pragma once
#include "../Memory/mem.h"
#include "../Global/global.h"

struct Positon
{
	float* X;
	float* Y;
	float* Z;
};

class Player {
public:
	float* HealthAddr;
	Positon pos;

	Player();
};