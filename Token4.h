#pragma once
#include"Token.h"
class Token4:public Token
{
public:
	
	void Draw()
	{
		setfillstyle(1, GREEN);
		bar(C.X +10, C.Y + 10, C.X + 20, C.Y + 30);
		bar(C.X + 15, C.Y + 15, C.X + 30, C.Y + 20);
	}
};

