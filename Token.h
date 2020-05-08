#pragma once
#include"Coordinates.h"
//#include"Dice.h"
class Token
{
public:
	char Status;
	char color;
	int initialLocation;
	int NoofStepsTaken;
	int TokenLocationOnBoard;
	Coordinates C;
	Token():Status(0),C(0,0)
	{
	}
	Token(int X,int Y):C(X,Y)
	{
	}
	virtual void Draw() = 0;
	void SetCoordinates(Coordinates C1)
	{
		C.X = C1.X;
		C.Y = C1.Y;
	}
	~Token()
	{
	}
};

