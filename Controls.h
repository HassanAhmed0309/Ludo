#pragma once
#include"Coordinates.h"
class Controls
{
protected:
	Coordinates C;
	int dim = 40;
public:
	Controls() :C(0, 0) {};
	Controls(int x, int y) :C(y, x) {};
	bool MouseClick(int, int);
};

