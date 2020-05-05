#pragma once
class Coordinates
{
	int X;
	int Y;
public:
	Coordinates() :X(0), Y(0)
	{

	}
	Coordinates(int x, int y) :X(x), Y(y)
	{
	}
	void Setx(int x)
	{
		X = x;
	}
	void Sety(int y)
	{
		Y = y;
	}
	int getx()
	{
		return X;
	}
	int gety()
	{
		return Y;
	}
};

