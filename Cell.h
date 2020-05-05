#pragma once
#include"Coordinates.h"
#include"graphics.h"
class Cell:public Coordinates
{
		bool stop;
		Coordinates C;
		//Token* token;
	public:
		Cell() :stop(0), Coordinates(0, 0)
		{

		}
		void DrawCell()
		{
			setcolor(14);
			rectangle(C.getx(), C.gety(), C.getx() + 60, C.gety() + 60);
		}
		void DrawUnit()
		{
			setfillstyle(1, 7);
			bar(C.getx(), C.gety(), C.getx() + 60, C.gety() + 60);
		}
		void SetCoordinates(int x, int y)
		{
			C.Setx(x);
			C.Sety(y);
		}
};

