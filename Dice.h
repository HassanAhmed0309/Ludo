#pragma once
#include"graphics.h"
enum PLAYER { Black = 1,Blue = 2,Pink = 3,Yellow = 4,Magenta = 5,Grey = 6,White = 7,Red = 8 };

class Dice
{
	int* TurnNo;
public:
	int RollADice()
	{
		TurnNo = new int[3];
		int dr = rand() % 6;
		/*if (PLAYER == 1)
		{
			TurnNo = 
		}*/
	}
	void Draw(int DiceNo)
	{
		// center of graphics screen: 600,500
		int boxstart = 400, boxend = 500, boxcenter = (boxstart + boxend)/2;
		setfillstyle(1, WHITE);
		setcolor(WHITE);
		rectangle(boxstart + 550, boxstart , boxend + 550, boxend);
		floodfill(boxstart + 560, boxstart + 10, WHITE);
		if (DiceNo == 1)
		{
			setfillstyle(1, RED);
			setcolor(RED);
			circle(boxcenter + 550, boxcenter,10);
			floodfill(boxcenter + 550, boxcenter, RED);
		}
		else if (DiceNo == 2)
		{
			setfillstyle(1, RED);
			setcolor(RED);
			circle(boxcenter + 530, boxcenter, 10);
			floodfill(boxcenter + 530, boxcenter + 1, RED);
			circle(boxcenter + 570, boxcenter, 10);
			floodfill(boxcenter + 570, boxcenter + 1, RED);
		}
		else if (DiceNo == 3)
		{
			setfillstyle(1, RED);
			setcolor(RED);
			circle(boxcenter + 530, boxcenter + 10, 10);
			floodfill(boxcenter + 530, boxcenter + 11, RED);
			circle(boxcenter + 570, boxcenter + 10, 10);
			floodfill(boxcenter + 570, boxcenter + 11, RED);
			circle(boxcenter + 550, boxcenter - 20, 10);
			floodfill(boxcenter + 550, boxcenter - 19, RED);
		}
		else if (DiceNo == 4)
		{
			setfillstyle(1, RED);
			setcolor(RED);
			circle(boxcenter + 530, boxcenter + 15, 10);
			floodfill(boxcenter + 530, boxcenter + 16, RED);
			circle(boxcenter + 570, boxcenter + 15, 10);
			floodfill(boxcenter + 570, boxcenter + 16, RED);
			circle(boxcenter + 530, boxcenter -15, 10);
			floodfill(boxcenter + 530, boxcenter - 14, RED);
			circle(boxcenter + 570, boxcenter - 15, 10);
			floodfill(boxcenter + 570, boxcenter - 14, RED);
		}
		else if (DiceNo == 5)
		{
			setfillstyle(1, RED);
			setcolor(RED);
			circle(boxcenter + 530, boxcenter + 20, 10);
			floodfill(boxcenter + 530, boxcenter + 21, RED);
			circle(boxcenter + 570, boxcenter + 20, 10);
			floodfill(boxcenter + 570, boxcenter + 21, RED);
			circle(boxcenter + 550, boxcenter, 10);
			floodfill(boxcenter + 550, boxcenter, RED);
			circle(boxcenter + 530, boxcenter - 20, 10);
			floodfill(boxcenter + 530, boxcenter - 19, RED);
			circle(boxcenter + 570, boxcenter - 20, 10);
			floodfill(boxcenter + 570, boxcenter - 19, RED);
		}
		else if (DiceNo == 6)
		{
			setfillstyle(1, RED);
			setcolor(RED);
			circle(boxcenter + 520, boxcenter + 20 , 10);
			floodfill(boxcenter + 521, boxcenter + 21, RED);
			circle(boxcenter + 580, boxcenter + 20 , 10);
			floodfill(boxcenter + 581, boxcenter + 21, RED);
			circle(boxcenter + 550, boxcenter + 20, 10);
			floodfill(boxcenter + 550, boxcenter + 21, RED);
			circle(boxcenter + 520, boxcenter - 20, 10);
			floodfill(boxcenter + 521, boxcenter - 19, RED);
			circle(boxcenter + 580, boxcenter - 20, 10);
			floodfill(boxcenter + 581, boxcenter - 19, RED);
			circle(boxcenter + 550, boxcenter -20, 10);
			floodfill(boxcenter + 550, boxcenter - 19, RED);
		}

	}
};

