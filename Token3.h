#pragma once
#include"Token.h"
class Token3:public Token
{
public:
	void Draw()
	{
		setcolor(YELLOW);
		setfillstyle(1, YELLOW);
		circle(C.X + 10, C.Y + 10, 5);
		floodfill(C.X + 11, C.Y + 11, YELLOW);
	}
};

