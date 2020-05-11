#include"Dice.h"
#include"Cell.h"
#include"Player1.h"
#include"Player2.h"
#include"Player3.h"
#include"Player4.h"
#include<vector>
#include<iostream>
class Token;
#pragma once
class Ludo_4Player
{
	int CellSquareDim = 40,NoOfPlayers=4;
	Player* Players[4];
	Cell* PlayZone;
	Cell** SafeZone;
	Dice dice;
	std::vector<Token*> SavedTokens;
	int Turn;
	void SetPlayZoneCoordinates(int x[],int y[]);
	void DrawSafeZone(int, int, int, int, Cell*);
	void SetLudo();
	void InitPlayersTokens();
	void MoveSelectedPlayerPiece(int);
	void PlayAllMoves();
	void TurnChange();
	void JustMove(int);
	void MoveToKill(int);
	void MoveInSafe(int);
	int AddDiceInTokenLocation(int,int);
	void RedrawSavedTokens(int);
	void RemoveFromSavedTokens(Token *);
	void AddSavedTokens(Token*);
	void PlayerWin(int);
public:
	void StartGame();
	Ludo_4Player(int);
	~Ludo_4Player();
};

