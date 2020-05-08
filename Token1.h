#pragma once
#include"Token.h"
class Token1:virtual public Token
{
public:
	void Draw()
	{
		//floodfill(T.C.getx() - 2, T.C.gety() - 2, 6);
		//setcolor(14);
		setfillstyle(1, YELLOW);
		bar(C.Y + 10, C.X + 10, C.Y + 30, C.X + 30);
	}
};

