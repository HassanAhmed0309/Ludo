#pragma once
#include"Token.h"
class Token7:virtual public Token
{
public:
	void Draw()
	{
		setcolor(LIGHTGRAY);
		setfillstyle(1, LIGHTGREEN);
		arc(C.X + 20, C.Y + 25, 0, 180, 10);
		line(C.X + 6,C.Y + 20,C.X + 34,C.Y + 20);
		floodfill(C.X+ 20,C.Y + 19, LIGHTGRAY);
	}
};

