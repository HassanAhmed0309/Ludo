#pragma once
#include <vector>
#include <iostream>
#include<Windows.h>
#include<time.h>
using namespace std;
#include"Controls.h"
#include"Graphics/graphics.h"
#include"Cell.h"
class Dice:public Controls
{
	int sum = 0, trans=0;

public:
	vector<int> DiceNo;
	Dice() :Controls(300, 300) {};
	void Reset()
	{
		DiceNo.clear();
	}
	bool IsSixGained() 
	{
		for (int i = 0; i < DiceNo.size(); i++) 
		{
			if (DiceNo[i] == 6) 
			{
				return true;
			}
		}
		return false;
	}
	
	void TakeInput(int& rpos, int& cpos)
	{
		while (!ismouseclick(WM_LBUTTONDOWN))
		{

		}
		getmouseclick(WM_LBUTTONDOWN, rpos, cpos);
		return;
	}

	//int SelectDiceNo()
	//{
	//	int Di;
	//	cout << "Select Dice No";
	//	bool found = false;
	//	int rpos, cpos;
	//	TakeInput(rpos, cpos);
	//	for (int i = 0; i < ForDiceSelectionSize; i++) {
	//		if (ForDiceSelection[i].MouseClick(rpos, cpos)) {
	//			return ForDiceSelection[i].diceNo;
	//		}
	//	}	
	//	return -1;
	//}
	bool RollaDice()//bool 
	{
		srand(time(0));
		int D = 0;
		D = rand() % 6 + 1;
		Sleep(1000);
		sum += D;
		DiceNo.push_back(D);
			//Count++;// size
		if (sum == 18)
		{
			sum = 0;
			return true;
		}
		if(D == 6)
		{
			return true;
		}
		sum = 0;
		return false;
	}
	void RemoveDiceNo(int Di)
	{
		vector<int>::reverse_iterator itr1;
		for (itr1 = DiceNo.rbegin(); itr1 < DiceNo.rend(); itr1++)
		{
			if (*itr1 == Di)
			{
				DiceNo.erase((itr1 + 1).base());
				break;
			}	
		}
	}
	void DisplayDice(Coordinates C,int dice)const
	{
		switch (dice)
		{
		case 1:
			moveto(C.X + 10, C.Y + 10);
			outtext("1"); break;
		case 2:
			moveto(C.X + 10, C.Y + 10);
			outtext("2"); break;
		case 3:
			moveto(C.X + 10, C.Y + 10);
			outtext("3"); break;
		case 4:
			moveto(C.X + 10, C.Y + 10);
			outtext("4"); break;
		case 5:
			moveto(C.X + 10, C.Y + 10);
			outtext("5"); break;
		case 6:
			moveto(C.X + 10, C.Y + 10);
			outtext("6"); break;
		case -1:
			moveto(C.X + 10, C.Y + 10);
			outtext("  "); break;

		default:
			break;
		}
	}
	//void DisplayValues()
	//{
	//	moveto(5, 5);
	//	vector<int>::iterator it;
	//	for (it = DiceNo.begin(); it < DiceNo.end(); it++)
	//	{
	//		DisplayDice(*it);
	//		outtext(" ");
	//	}
	//}
};

