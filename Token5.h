#pragma once
#include"Token.h"
class Token5 :public Token
{
public:
	void Draw()
	{
		setcolor(CYAN);
		line(C.X + 30, C.Y + 20, C.X + 20, C.Y + 10);
		line(C.X + 10, C.Y + 20, C.X + 20, C.Y + 10);
		line(C.X + 30, C.Y + 20, C.X + 10, C.Y + 20);
		setfillstyle(SOLID_FILL, CYAN);
		floodfill(C.X + 20, C.Y + 15, CYAN);
	}
};

