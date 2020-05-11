#include "Ludo_4Player.h"

Ludo_4Player::Ludo_4Player(int PNo):NoOfPlayers(PNo),CellSquareDim(40) {
	SetLudo();
	Players[0] = new Player1;
	Players[1] = new Player2;
	Players[2] = new Player3;
	Players[3] = new Player4;
}
void Ludo_4Player::SetLudo() {
	PlayZone = new Cell[55];
	int x[55], y[55];
	SetPlayZoneCoordinates(x, y);
	PlayZone[2].stop = true;
	PlayZone[15].stop = true;
	PlayZone[28].stop = true;
	PlayZone[41].stop = true;
	for (int i = 0; i < 52; i++) {
		PlayZone[i].SetCoordinates(x[i], y[i]);
		PlayZone[i].DrawCell();
	}
	SafeZone = new Cell * [NoOfPlayers];
	for (int i = 0; i < NoOfPlayers; i++) {
		SafeZone[i] = new Cell[5];
	}
	DrawSafeZone(x[0], y[0], CellSquareDim, 0, SafeZone[0]);
	DrawSafeZone(x[13], y[13], 0, CellSquareDim, SafeZone[1]);
	if (NoOfPlayers == 4) {
		DrawSafeZone(x[26], y[26], -CellSquareDim, 0, SafeZone[2]);
		DrawSafeZone(x[39], y[39], 0, -CellSquareDim, SafeZone[3]);
	}
}
void Ludo_4Player::DrawSafeZone(int x, int y, int SquareH, int SquareV, Cell* SZ) {
	//1 player
	int x1[5], y1[5];
	x1[0] = x + SquareH;
	y1[0] = y + SquareV;
	for (int i = 1; i < 5; i++) {
		x1[i] = x1[i - 1] + SquareH;
		y1[i] = y1[i - 1] + SquareV;
	}
	for (int j = 0; j < 5; j++) {
		SZ[j].SetCoordinates(x1[j], y1[j]);
		SZ[j].stop = true;
		SZ[j].DrawCell();
	}
}
void Ludo_4Player::SetPlayZoneCoordinates(int x[],int y[]) {
	int initalX = 0, initalY = 280;
	int SquareDim = 40;
	x[0] = initalX;
	y[0] = initalY;
	x[1] = initalX;
	y[1] = initalY - SquareDim;
	for (int i = 2; i <= 6; i++) {
		x[i] = x[i - 1] + SquareDim;
		y[i] = initalY - SquareDim;
	}
	for (int i = 7; i <= 12; i++) {
		x[i] = x[6] + SquareDim;
		y[i] = y[i - 1] - SquareDim;
	}
	x[13] = x[12] + SquareDim;
	y[13] = y[12];
	x[14] = x[13] + SquareDim;
	y[14] = y[13];
	for (int i = 15; i <= 19; i++) {
		x[i] = x[12] + SquareDim + SquareDim;
		y[i] = y[i - 1] + SquareDim;
	}
	for (int i = 20; i <= 25; i++) {
		x[i] = x[i - 1] + SquareDim;
		y[i] = initalY - SquareDim;
	}
	x[26] = x[25];
	y[26] = y[25] + SquareDim;
	x[27] = x[26];
	y[27] = y[26] + SquareDim;
	for (int i = 28; i <= 32; i++) {
		x[i] = x[i - 1] - SquareDim;
		y[i] = initalY + SquareDim;
	}
	for (int i = 33; i <= 38; i++) {
		x[i] = x[32] - SquareDim;
		y[i] = y[i - 1] + SquareDim;
	}
	x[39] = x[38] - SquareDim;
	y[39] = y[38];
	x[40] = x[39] - SquareDim;
	y[40] = y[39];
	for (int i = 41; i <= 45; i++) {
		x[i] = x[40];
		y[i] = y[i - 1] - SquareDim;
	}
	for (int i = 46; i <= 52; i++) {
		x[i] = x[i - 1] - SquareDim;
		y[i] = y[45] - SquareDim;
	}

}
Ludo_4Player::~Ludo_4Player() {
	for (int i = 0; i < NoOfPlayers; i++) {
		delete[] SafeZone[i];
	}
	delete[] SafeZone;
	delete[] PlayZone;
}

void Ludo_4Player::InitPlayersTokens() {
	int fl = 0;
	Coordinates C1(10, 10);
	Coordinates C2(400, 10);
	Coordinates C3(400, 400);
	Coordinates C4(10, 400);
	Coordinates Player_4[4] = { C1,C2,C3,C4};
	for (int i = 0; i < NoOfPlayers; i++) {
		Players[i]->SetFinalLocation(fl);
		Players[i]->SetTokens(Player_4[i]);	
		fl += 13;
	}
}
void Ludo_4Player::PlayerWin(int turn) {
	moveto(10, 700 + (turn*20));
	if (turn + 1 == 1) outtext("Player 1 is first");
	else if (turn + 1 == 2) outtext("Player 2 is second");
	else if (turn + 1 == 3) outtext("Player 3 is third");
	else if (turn + 1 == 4) outtext("Player 4 is fourth");
	else if (turn + 1 == 5) outtext("Player 5 is fifth");
	for (int i = 0; i < NoOfPlayers; i++) {
		if (Players[i] == Players[turn]) {
			Players[i]->RemoveDiceSelection(&dice);
			delete Players[i];
			Players[i] = nullptr;
		}
	}
	int i;
	for (i = 0; i < NoOfPlayers; i++) {
		if (!Players[i]);
	}
	if (i == 1) exit(0);
}
void Ludo_4Player::MoveInSafe(int DiceNo) {
	SafeZone[Turn][Players[Turn]->tokenSelected->TokenLocationNearWin].DrawCell();
	Players[Turn]->tokenSelected->TokenLocationNearWin += DiceNo;
	if (Players[Turn]->tokenSelected->TokenLocationNearWin >= 5) {
		for (int i = 0; i < Players[Turn]->TokenArray.size(); i++) {
			if (Players[Turn]->TokenArray[i] == Players[Turn]->tokenSelected) {
				if (Players[Turn]->TokenArray[i]) {
					RemoveFromSavedTokens(Players[Turn]->TokenArray[i]);
					delete Players[Turn]->TokenArray[i];
					Players[Turn]->TokenArray.erase(Players[Turn]->TokenArray.begin() + i);
				}
				if (Players[Turn]->TokenArray.size() == 0) {
					PlayerWin(Turn);
				}
				return;
			}
		}

	}
	SafeZone[Turn][Players[Turn]->tokenSelected->TokenLocationNearWin].DrawCell();
	SafeZone[Turn][Players[Turn]->tokenSelected->TokenLocationNearWin].DrawUnit(Players[Turn]->tokenSelected);
}
int Ludo_4Player::AddDiceInTokenLocation(int initLoc, int DiceNo) {
	int fLocat = initLoc;
	for (int i = 1; i <= DiceNo; i++) {
		fLocat += 1;
		if (fLocat > 51) {
			fLocat = 0;
		}
	}
	return fLocat;
}
void Ludo_4Player::JustMove(int Diceno) {
	int org = Players[Turn]->tokenSelected->TokenLocationOnBoard;
	PlayZone[org].DrawCell();
	for (int i = 0; i < Players[Turn]->TokenArray.size(); i++) {
		if (Players[Turn]->TokenArray[i] != Players[Turn]->tokenSelected && Players[Turn]->TokenArray[i]->Status == 'P' && Players[Turn]->TokenArray[i]->TokenLocationOnBoard == org) {
			PlayZone[org].DrawUnit(Players[Turn]->TokenArray[i]);
		}
	}
	for (int i = 0; i < Diceno+1; i++) {
		int num = AddDiceInTokenLocation(Players[Turn]->tokenSelected->TokenLocationOnBoard,i);
		if (num == Players[Turn]->tokenSelected->FinalLocation) {
			if (i != Diceno) {
				Players[Turn]->tokenSelected->TokenLocationOnBoard = -1;
				Players[Turn]->tokenSelected->Status = 'C';
				MoveInSafe(Diceno - i-1);
				return;
			}
		};
	}
	int finalLoc = AddDiceInTokenLocation(Players[Turn]->tokenSelected->TokenLocationOnBoard, Diceno);
	MoveToKill(finalLoc);
	Players[Turn]->tokenSelected->TokenLocationOnBoard = finalLoc;
	if (PlayZone[Players[Turn]->tokenSelected->TokenLocationOnBoard].stop) {
		AddSavedTokens(Players[Turn]->tokenSelected);
	}
	PlayZone[Players[Turn]->tokenSelected->TokenLocationOnBoard].DrawCell();
	PlayZone[Players[Turn]->tokenSelected->TokenLocationOnBoard].DrawUnit(Players[Turn]->tokenSelected);
}
void Ludo_4Player::AddSavedTokens(Token* add) {
	for (int i = 0; i < SavedTokens.size(); i++) {
		if (SavedTokens[i] == add) {
			return;
		}
	}
	SavedTokens.push_back(add);
}
void Ludo_4Player::MoveToKill(int finalLoc) {
	bool stopCheck = false;
	if (!PlayZone[finalLoc].stop) {
		for (int i = 0; i < NoOfPlayers; i++) {
			if (i != Turn && Players[i]) {
				for (int j = 0; j < Players[i]->TokenArray.size(); j++) {
					if (Players[i]->TokenArray[j]->TokenLocationOnBoard == finalLoc) {
						Players[i]->TokenArray[j]->Status = 'H';
						Players[i]->TokenKilled(Players[i]->TokenArray[j]);
						bool stopCheck = true;
					}
				}
				if (stopCheck == true) return;
			}
		}
	}
}
void Ludo_4Player::RemoveFromSavedTokens(Token* rem) {
	for (int i = 0; i < SavedTokens.size(); i++) {
		if (SavedTokens[i] == rem) {
			SavedTokens.erase(SavedTokens.begin()+ i);
		}
	}
}
void Ludo_4Player::MoveSelectedPlayerPiece(int Diceno) {
	RemoveFromSavedTokens(Players[Turn]->tokenSelected);
	if (Players[Turn]->tokenSelected->Status == 'H') {
		JustMove(0);
		Players[Turn]->tokenSelected->Status = 'P';
		Cell C;
		C.SetCoordinates(Players[Turn]->tokenSelected->HomeLoc.X, Players[Turn]->tokenSelected->HomeLoc.Y);
		C.DrawCell();
		return;
	}
	if (Players[Turn]->tokenSelected->Status == 'C') {
		Players[Turn]->tokenSelected->Status = 'C';
		MoveInSafe(Diceno);
		return;
	}
	JustMove(Diceno);

}

void Ludo_4Player::PlayAllMoves() {
	int DiceNo = 0;
	bool reselectToken = false;
	Cell DiceNos[5];
	do{
		Token* TSelected;
		Players[Turn]->ChoosingTokken();
		TSelected = Players[Turn]->tokenSelected;
		for (int j = 0; j < dice.DiceNo.size(); j++) {
			TSelected->Can_DiceNoPlayed(dice.DiceNo[j]);
		}
		Players[Turn]->DisplayDiceSelection(&dice);
		do {
			DiceNo = Players[Turn]->SelectDiceNo();
			if (DiceNo == -1) {
				std::cout << "New Token Selected: " << endl;
				TSelected->TPDMsize = 0;
				TSelected = Players[Turn]->tokenSelected;
				Players[Turn]->RemoveDiceSelection(&dice);
				for (int j = 0; j < dice.DiceNo.size(); j++) {
					TSelected->Can_DiceNoPlayed(dice.DiceNo[j]);
				}
				Players[Turn]->DisplayDiceSelection(&dice);
			}
		} while (DiceNo == -1 || DiceNo == -2);
		MoveSelectedPlayerPiece(DiceNo);
		if (Players[Turn] == nullptr) break;
		dice.RemoveDiceNo(DiceNo);
		TSelected->TPDMsize = 0;
		Players[Turn]->RemoveDiceSelection(&dice);
	} while (dice.DiceNo.size() != 0);
}
void Ludo_4Player::RedrawSavedTokens(int turn) {
	turn++;
	for (int i = 0; i < SavedTokens.size(); i++) {
		if (SavedTokens[i]->BelongsToPlayer == turn) {
			PlayZone[SavedTokens[i]->TokenLocationOnBoard].DrawCell();
			PlayZone[SavedTokens[i]->TokenLocationOnBoard].DrawUnit(SavedTokens[i]);
		}
	}
}
void Ludo_4Player::TurnChange() {
	Turn++;
	if (Turn >= NoOfPlayers) Turn = 0;
	if (!Players[Turn]) TurnChange();
	RedrawSavedTokens(Turn);
}
void Ludo_4Player::StartGame() {
	InitPlayersTokens();
	Turn = 0;
	do {
		cout << "Player Turn's: " << Turn + 1 << endl;
		//while (dice.RollaDice());
		dice.DiceNo.push_back(6);
		if (dice.IsSixGained()) {
			PlayAllMoves();
		}
		else {
			for (int i = 0; i < Players[Turn]->TokenArray.size(); i++) {
				if (Players[Turn]->TokenArray[i]->Status != 'H') PlayAllMoves();
			}
		}
		dice.Reset();
		TurnChange();
	} while (true);
}