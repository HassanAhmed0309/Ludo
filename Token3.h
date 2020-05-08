#pragma once
#include"Token.h"
class Token3:virtual public Token
{
public:
	void Draw()
	{
		setcolor(YELLOW);
		setfillstyle(1, YELLOW);
		circle(C.Y + 20, C.X + 20, 10);
		floodfill(C.Y + 19, C.X + 19,YELLOW);
	}
};

