#pragma once
#include"Token.h"
class Token8 :virtual public Token
{
public:
	void Draw()
	{
		setcolor(BLUE);
		setfillstyle(1, BLUE);
		sector(C.X + 10,C.Y + 20,0, 90,10,10);
	}
};

