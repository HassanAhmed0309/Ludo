#pragma once
#include"Token.h"
#include"Graphics/graphics.h"
#include"Coordinates.h"
class Token1:public Token
{
public:
	void Draw()
	{
		setfillstyle(1, BLACK);
		bar(C.getx() + 10, C.gety() + 20, C.getx() + 30, C.gety() + 35);
	}
};

