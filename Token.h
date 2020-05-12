#pragma once
#include<stack>
#include <iostream>
#include"Coordinates.h"
#include"Controls.h"
#include"Graphics/graphics.h"
class Token:public Controls
{

public:
	Coordinates HomeLoc;
	char Status;
	int BelongsToPlayer;
	int FinalLocation;
	int TokenLocationNearWin =0 ;
	int TokenLocationOnBoard;
	int TokenPossibleDiceMoves[10];
	int TPDMsize;
	Token() :Status('H'), TPDMsize(0),BelongsToPlayer(0)
	{
	}
	Token(int X,int Y)
	{
	}
	void SetFinalLocation(int i) {
		FinalLocation = i;
	};
	virtual void Draw() = 0;
	void SetCoordinates(Coordinates C1)
	{
		C.X = C1.X;
		C.Y = C1.Y;
	}
	void SetHomeLocation(Coordinates Hc) {
		HomeLoc = Hc;
	}
	void Can_DiceNoPlayed(int diceNo) {
		if (Status == 'H') 
		{
			if (diceNo == 6) 
			{
				TokenPossibleDiceMoves[TPDMsize] = diceNo;
				TPDMsize++;
				return;
			}
			else 
			{
				return;
			}
		}
		if (Status == 'C') 
		{
			if (diceNo <= 5 - TokenLocationNearWin) 
			{
				TokenPossibleDiceMoves[TPDMsize] = diceNo;
				TPDMsize++;
				return;
			}
			else
			{
				return;
			}
		}
		TokenPossibleDiceMoves[TPDMsize] = diceNo;
		TPDMsize++;
	};
	void RemoveDiceMove(int diceNo) {
		for (int i = 0; i < TPDMsize; i++) {
			if (TokenPossibleDiceMoves[i] == diceNo) {
				TokenPossibleDiceMoves[i] = -1;
			}
		}
	}
	~Token()
	{
	}
};

