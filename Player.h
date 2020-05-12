#pragma once
#include"Token.h"
#include "Dice.h"
#include"Cell.h"
#include<vector>
#include<iostream>
class Player
{
protected:
	// char** GridPointer;
// number of token
	//GrowA<int> DiceNo;    // growable array is template
	int FinalLocation= 0;
	int InitalLocation= 0;
	int ForDiceSelectionSize = 0;
	Cell ForDiceSelection[6];
public:
	std::vector<Token*> TokenArray;
	Token* tokenSelected;
	Player() {
		tokenSelected = nullptr;
	};
	void SetFinalLocation(int FL) {
		FinalLocation = FL;
		InitalLocation = FL + 2;
	};
	virtual void SetTokens(Coordinates C) = 0;
	void TokenKilled(Token * killed) {
		Cell Home;
		killed->SetCoordinates(killed->HomeLoc);
		Home.SetCoordinates(killed->HomeLoc.X,killed->HomeLoc.Y);
		Home.DrawCell();
		Home.DrawUnit(killed);
	}
	void PlayingSelectedToken(){}
	void TakeInput(int& rpos, int& cpos)
	{
		while (!ismouseclick(WM_LBUTTONDOWN))
		{

		}
		getmouseclick(WM_LBUTTONDOWN, rpos, cpos);
		return;
	}
	bool SelectTokken(int rpos,int cpos) {
		for (int i = 0; i < TokenArray.size(); i++)
		{
			if (TokenArray[i]->MouseClick(rpos, cpos))
			{
				tokenSelected = TokenArray[i];
				return true;
			}
		}
		return false;
	}
	int SelectDiceNo()
	{
		int Di;
		cout << "Select Dice No" <<endl;
		bool found = false;
		int rpos, cpos;
		TakeInput(rpos, cpos);
		for (int i = 0; i < ForDiceSelectionSize; i++) {
			if (ForDiceSelection[i].MouseClick(rpos, cpos)) {
				return ForDiceSelection[i].diceNo;
			}
		}	
		if (SelectTokken(rpos, cpos)) {
			return -1;
		}
		return -2;
	}
	void RemoveDiceSelection(Dice* d) {
		for (int i = 0; i < ForDiceSelectionSize; i++) {
			ForDiceSelection[i].UnDrawCell();
			d->DisplayDice(ForDiceSelection[i].GetCoordinates(),-1);
		}
		ForDiceSelectionSize = 0;
	}
	void DisplayDiceSelection(Dice * d) {
		for (int i = 0; i < tokenSelected->TPDMsize; i++) {
			Cell a;
			a.SetCoordinates(600 + (i * 40), i);
			Coordinates C(600 + (i * 40), i);
			a.DrawCell();
			ForDiceSelection[i] = a;
			ForDiceSelection[i].diceNo = tokenSelected->TokenPossibleDiceMoves[i];
			d->DisplayDice(C, tokenSelected->TokenPossibleDiceMoves[i]);
		}
		ForDiceSelectionSize = tokenSelected->TPDMsize;
	}
	void ChoosingTokken()
	{
		cout << "Select Token " << endl;
		bool select;
		int rpos=0, cpos=0;
		do
		{
			TakeInput(rpos, cpos);
			select = SelectTokken(rpos, cpos);
		} while (!select);
	}
	virtual void DrawPlayerTokensAtHome() = 0;
	~Player() {
		
	}
};

