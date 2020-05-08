#pragma once
#include"Token.h"
class Token6:virtual public Token
{
public:
	void Draw()
	{
		setcolor(YELLOW);
		setfillstyle(1, YELLOW);
		int points[12];
		//5, 20, 15, 10, 35, 15, 35, 25, 15, 30, 5, 20
		points[0] = C.Y + 5;
		points[1] = C.X + 20;
		points[2] = C.Y + 15;
		points[3] = C.X + 10;
		points[4] = C.Y + 35;
		points[5] = C.X + 15;
		points[6] = C.Y + 35;
		points[7] = C.X + 25;
		points[8] = C.Y + 15;
		points[9] = C.X + 30;
		points[10] = C.Y + 5;
		points[11] = C.X + 20;
		drawpoly(6, points);
		fillpoly(6, points);
	}
};