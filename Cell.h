#pragma once
#include"Coordinates.h"
#include"Graphics/graphics.h"
class Cell:public Coordinates
{
		bool stop;
		Coordinates C;
		int grad = 30;
		//Token* token;
	public:
		Cell() :stop(0), Coordinates(0, 0)
		{

		}
		void DrawCell()
		{
			setcolor(14);
			rectangle(C.getx(), C.gety(), C.getx() + 40, C.gety() + 40);
		}
		void DrawUnit()
		{
			setfillstyle(1, 7);
			bar(C.getx(), C.gety(), C.getx() + 40, C.gety() + 40);
		}
		void SetCoordinates(int x, int y)
		{
			C.Setx(x);
			C.Sety(y);
		}
		void DrawDiamond() {
			int dim = 35;
			int points[10] = {C.getx(),C.gety(),C.getx()+dim,C.gety()+grad,C.getx()+dim, C.gety()+dim+grad,C.getx(), C.gety()+dim, C.getx(),C.gety()};
			setcolor(14);
			drawpoly(5, points);
		}
		void SetGrad(int g) {
			grad = g;
		}
};

