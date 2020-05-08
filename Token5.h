#pragma once
#include"Token.h"
class Token5 :virtual public Token
{
public:
	void Draw()
	{
		setcolor(YELLOW);
		line(C.Y + 30, C.X + 20, C.Y + 20, C.X + 10);
		line(C.Y + 10, C.X + 20, C.Y + 20, C.X + 10);
		line(C.Y + 30, C.X + 20, C.Y + 10, C.X + 20);
		setfillstyle(SOLID_FILL, YELLOW);
		floodfill(C.Y + 20, C.X + 15, YELLOW);
	}
};

