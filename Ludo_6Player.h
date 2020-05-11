#include"Dice.h"
#include"Cell.h"
#include"Player1.h"
#include"Player2.h"
#include"Player3.h"
#include"Player4.h"
#include"Player5.h"
#include"Player6.h"

#include<vector>
#include<iostream>
class Token;
#pragma once
class Ludo_6Player
{
	int CellSquareDim = 40, NoOfPlayers = 6;
	Player* Players[6];
	Cell* PlayZone;
	Cell** SafeZone;
	Dice dice;
	std::vector<Token*> SavedTokens;
	int Turn;
	void SetPlayZoneCoordinates(int x[], int y[]);
	void SetLudo();
	void InitPlayersTokens();
	void MoveSelectedPlayerPiece(int);
	void PlayAllMoves();
	void TurnChange();
	void JustMove(int);
	void MoveToKill(int);
	void MoveInSafe(int);
	int AddDiceInTokenLocation(int, int);
	void RedrawSavedTokens(int);
	void RemoveFromSavedTokens(Token*);
	void AddSavedTokens(Token*);
	void PlayerWin(int);
	void DrawPlayZone(int[],int[]);
	void DrawSafeZones(int[], int[]);
public:
	void StartGame();
	Ludo_6Player(int);
	~Ludo_6Player();
};

