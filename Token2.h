#pragma once
#include"Token.h"
class Token2:public Token
{
public:
	
	void Draw()
	{
		setcolor(BLUE);
		setfillstyle(1, BLUE);
		line(C.X + 30, C.Y + 20, C.X + 20, C.Y + 10);
		line(C.X + 10, C.Y + 20, C.X + 20, C.Y + 10);
		line(C.X + 20, C.Y + 30, C.X + 10, C.Y + 20);
		line(C.X + 30, C.Y + 20, C.X + 20, C.Y + 30);
		floodfill(C.X + 20, C.Y + 20, BLUE);
		/*line(C.Y + 30, C.Y + 60, C.Y + 70, C.X + 60);
		line(C.Y + 70, C.X + 60, C.Y + 50, C.X + 30);
		line(C.Y + 50, C.X + 30, C.Y + 30, C.X + 60);*/
		/*floodfill(C.Y + 50, C.X + 50, YELLOW);
		floodfill(C.Y + 50,C.X+ 70, YELLOW);*/
	}
};

