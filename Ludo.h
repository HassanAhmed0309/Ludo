#pragma once

#include "Player.h"
#include "Token.h"
#include "Dice.h"

class Ludo:public Player
{
protected:
	char** Grid;
	Player* Players;
	//Player Players[MaxPlayers];
	int NoOfPlayers, Turn, MaxNoSteps, WC;

public:

	Ludo() {};
	void InitBoard()
	{

	}

	Ludo(int NOP)
	{
		Players = new Player[NOP];
		Grid = nullptr;
	}

	void UpdateBoard(Token *T)
	{

	}

	void ChangeTurn()
	{

	}

	void DisplayPlayerMsg()
	{

	}

	void UpdatePlayerList(int Turn)
	{

	}

	void DisplayResult()
	{

	}

	void DisplayBoard()
	{

	}

	bool isWin()
	{
		return true;
	}

	void StartGame()
	{

	}

	void init()
	{
		//cin number of players
		// will initialize the Player*;
	}
	void Play()
	{
		do
		{
			DICE.RollaDice();
			while (Players[Turn].RollDice(DICE.DiceNo))
			{
				DICE.DisplayValues();
				//Players[Turn].ChoosingTokken();
				int Di = Players[Turn].SelectDiceNo(DICE.DiceNo);
				Sleep(1000);
				//move;
				DICE.DiceNo=DICE.RemoveDiceNo(DICE.DiceNo,Di);
				cleardevice();
			}
		} while (true);
		/*init();
		StartGame();
		DisplayBoard();
		DisplayPlayerMsg();
		Players[Turn].DICE.RollaDice();
		Players[Turn].ChoosingTokken();
		Players[Turn].PlayingSelectedToken(tokenSelected);
		UpdateBoard(tokenSelected);
		Players[Turn].DrawToken();
		if (isWin())
		{
			UpdatePlayerList(Turn);
			WC++;
		}
		ChangeTurn();
		while (WC < NoOfPlayers - 1)
		{
			DisplayResult();
		}
		*/
	}
};

