#pragma once
#include"Token.h"
class Token4:virtual public Token
{
public:
	void Draw()
	{
		setfillstyle(1, YELLOW);
		bar(C.Y +15, C.X + 15, C.Y + 25, C.X + 35);
		bar(C.Y + 20, C.X + 15, C.Y + 35, C.X + 25);
	}
};

