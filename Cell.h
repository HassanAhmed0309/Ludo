#pragma once
#include"Coordinates.h"
#include"Graphics/graphics.h"
#include"Token.h"
#include"Controls.h"

class Cell:public Controls
{
		int grad=0;
		int dim=40;
	public:
		int diceNo;
		bool stop;
		int stopColor= GREEN;
		Cell() :stop(0), Controls(0, 0),diceNo(-1){}
		void DrawCell()
		{
			//int color,bcolor = RED;
			//if (!stop) color = WHITE;
			//else color = stopColor;
			//setcolor(bcolor);
			//rectangle(C.getx(), C.gety(), C.getx() + dim, C.gety() + dim);
			//setfillstyle(SOLID_FILL, color);
			//floodfill(C.getx() + 3, C.gety() + 3,bcolor);
			int points[10] = { C.getx(),C.gety(),C.getx() + dim,C.gety() + grad,C.getx() + dim, C.gety() + dim + grad,C.getx(), C.gety() + dim, C.getx(),C.gety() };
			int color, bcolor = RED;
			if (!stop) color = WHITE;
			else color = stopColor;
			setcolor(bcolor);
			drawpoly(5, points);
			setfillstyle(SOLID_FILL, color);
			floodfill(C.getx() + 3, C.gety() + 3, bcolor);
		}
		Coordinates GetCoordinates() {
			return C;
		}
		void DrawUnit(Token * token)
		{
			if (token) {
				token->SetCoordinates(C);
				token->Draw();
			}
		}
		void UnDrawCell() {

			int color = 0, bcolor = 0;
			setcolor(bcolor);
			rectangle(C.getx(), C.gety(), C.getx() + 40, C.gety() + 40);
			setfillstyle(SOLID_FILL, color);
			floodfill(C.getx() + 3, C.gety() + 3, bcolor);
		}
		void SetCoordinates(int x, int y)
		{
			C.Setx(x);
			C.Sety(y);
		}
		void DrawDiamond() {
			int points[10] = {C.getx(),C.gety(),C.getx()+dim,C.gety()+grad,C.getx()+dim, C.gety()+dim+grad,C.getx(), C.gety()+dim, C.getx(),C.gety()};
			int color, bcolor = RED;
			if (!stop) color = WHITE;
			else color = stopColor;
			setcolor(bcolor);
			drawpoly(5, points);
			setfillstyle(SOLID_FILL, color);
			floodfill(C.getx() + 3, C.gety() + 3, bcolor);
		}
		void SetGrad(int g) {
			grad = g;
		}
		void SetDim(int d) {
			dim = d;
		}
};

