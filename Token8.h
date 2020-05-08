#pragma once
#include"Token.h"
class Token8 :virtual public Token
{
public:
	void Draw()
	{
		setcolor(YELLOW);
		setfillstyle(1, YELLOW);
		sector(C.Y + 20,C.X + 20,0, 90,15,15);
	}
};

