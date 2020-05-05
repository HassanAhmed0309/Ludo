#include"Player.h"
#include"Cell.h"
#pragma once
class Ludo_4Player
{
	int CellSquareDim = 40,NoOfPlayers=4;
	Player Players[4];
	Cell* PlayZone;
	Cell** SafeZone;
	void SetPlayZoneCoordinates(int x[],int y[]);
	void DrawSafeZone(int, int, int, int, Cell*);
	void SetLudo();
public:
	void StartGame();
	Ludo_4Player(int);
	~Ludo_4Player();
};

