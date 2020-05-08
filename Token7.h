#pragma once
#include"Token.h"
class Token7:virtual public Token
{
public:
	void Draw()
	{
		setcolor(YELLOW);
		setfillstyle(1, YELLOW);
		arc(C.Y + 20, C.X + 20, 0, 180, 15);
		line(C.Y + 6,C.X + 20,C.Y + 34,C.X + 20);
		floodfill(C.Y+ 20,C.X + 19, YELLOW);
	}
};

