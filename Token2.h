#pragma once
#include"Token.h"
class Token2:virtual public Token
{
public:
	void Draw()
	{
		setcolor(YELLOW);
		setfillstyle(1, YELLOW);
		line(C.Y + 30, C.X + 20, C.Y + 20, C.X + 10);
		line(C.Y + 10, C.X + 20, C.Y + 20, C.X + 10);
		line(C.Y + 20, C.X + 30, C.Y + 10, C.X + 20);
		line(C.Y + 30, C.X + 20, C.Y + 20, C.X + 30);
		floodfill(C.Y + 20, C.X + 20, YELLOW);
		/*line(C.Y + 30, C.X + 60, C.Y + 70, C.X + 60);
		line(C.Y + 70, C.X + 60, C.Y + 50, C.X + 30);
		line(C.Y + 50, C.X + 30, C.Y + 30, C.X + 60);*/
		/*floodfill(C.Y + 50, C.X + 50, YELLOW);
		floodfill(C.Y + 50,C.X+ 70, YELLOW);*/
	}
};

