#pragma once
#include"Token.h"
class Token6:public Token
{
public:
	void Draw()
	{
		setcolor(LIGHTGRAY);
		setfillstyle(1, LIGHTGRAY);
		int points[12];
		//5, 20, 15, 10, 35, 15, 35, 25, 15, 30, 5, 20
		points[0] = C.X + 5;
		points[1] = C.Y + 20;
		points[2] = C.X + 15;
		points[3] = C.Y + 10;
		points[4] = C.X + 35;
		points[5] = C.Y + 15;
		points[6] = C.X + 35;
		points[7] = C.Y + 25;
		points[8] = C.X + 15;
		points[9] = C.Y + 30;
		points[10] = C.X + 5;
		points[11] = C.Y + 20;
		drawpoly(6, points);
		fillpoly(6, points);
	}
};