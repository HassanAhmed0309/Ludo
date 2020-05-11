#include "Ludo_6Player.h"


Ludo_6Player::Ludo_6Player(int PNo) :NoOfPlayers(PNo), CellSquareDim(35) {
	SetLudo();
	Players[0] = new Player1;
	Players[1] = new Player2;
	Players[2] = new Player3;
	Players[3] = new Player4;
	Players[4] = new Player5;
	Players[5] = new Player6;
}
void Ludo_6Player::DrawSafeZones(int x[], int y[]) {
	int x1[5], y1[5], grad = 20, SquareDim = 35;
	x1[0] = x[0] + SquareDim;
	y1[0] = y[0] + grad;
	for (int i = 1; i < 5; i++) {
		x1[i] = x1[i - 1] + SquareDim;
		y1[i] = y1[i - 1] + grad;
	}
	for (int i = 0; i < 5; i++) {
		SafeZone[0][i].SetCoordinates(x1[i], y1[i]);
		SafeZone[0][i].SetGrad(grad);
		SafeZone[0][i].stop = true;
		SafeZone[0][i].SetDim(SquareDim);
		SafeZone[0][i].DrawDiamond();
	}

	//2 Player Stop
	int x2[5], y2[5];
	x2[0] = x[13];
	y2[0] = y[13] + SquareDim;
	for (int i = 1; i < 5; i++) {
		x2[i] = x2[i - 1];
		y2[i] = y2[i - 1] + SquareDim;
	}
	for (int i = 0; i < 5; i++) {
		SafeZone[1][i].SetCoordinates(x2[i], y2[i]);
		SafeZone[1][i].SetGrad(0);
		SafeZone[1][i].stop = true;
		SafeZone[1][i].SetDim(SquareDim);
		SafeZone[1][i].DrawDiamond();
	}


	//3 Player Stop
	int x3[5], y3[5];
	x3[0] = x[26] - SquareDim;
	y3[0] = y[26] + grad;	
	for (int i = 1; i < 5; i++) {
		x3[i] = x3[i - 1] - SquareDim;
		y3[i] = y3[i - 1] + grad;
	}
	for (int i = 0; i < 5; i++) {
		SafeZone[2][i].SetCoordinates(x3[i], y3[i]);
		SafeZone[2][i].SetDim(SquareDim);
		SafeZone[2][i].SetGrad(-grad);
		SafeZone[2][i].stop = true;
		SafeZone[2][i].DrawDiamond();
	}
	//4 Player Stop
	int x4[5], y4[5];
	x4[0] = x[39] - SquareDim;
	y4[0] = y[39] - grad;
	for (int i = 1; i < 5; i++) {
		x4[i] = x4[i - 1] - SquareDim;
		y4[i] = y4[i - 1] - grad;
	}
	for (int i = 0; i < 5; i++) {
		SafeZone[3][i].SetCoordinates(x4[i], y4[i]);
		SafeZone[3][i].SetGrad(grad);
		SafeZone[3][i].stop = true;
		SafeZone[3][i].SetDim(SquareDim);
		SafeZone[3][i].DrawDiamond();
	}

	//5 Player Stop
	int x5[5], y5[5];
	x5[0] = x[52];
	y5[0] = y[52] - SquareDim;
	for (int i = 1; i < 5; i++) {
		x5[i] = x5[i - 1];
		y5[i] = y5[i - 1] - SquareDim;
	}
	for (int i = 0; i < 5; i++) {
		SafeZone[4][i].SetCoordinates(x5[i], y5[i]);
		SafeZone[4][i].SetGrad(0);
		SafeZone[4][i].stop = true;
		SafeZone[4][i].SetDim(SquareDim);
		SafeZone[4][i].DrawDiamond();
	}
	//6 Player Stop
	int x6[5], y6[5];
	x6[0] = x[65] + SquareDim;
	y6[0] = y[65] - grad;
	for (int i = 1; i < 5; i++) {
		x6[i] = x6[i - 1] + SquareDim;
		y6[i] = y6[i - 1] - grad;
	}
	for (int i = 0; i < 5; i++) {
		SafeZone[5][i].SetCoordinates(x6[i], y6[i]);
		SafeZone[5][i].SetGrad(-grad);
		SafeZone[5][i].SetDim(SquareDim);
		SafeZone[5][i].stop = true;
		SafeZone[5][i].DrawDiamond();

	}

}
void Ludo_6Player::DrawPlayZone(int x[], int y[]) {
	int i = 0, grad = 20, SquareDim = CellSquareDim;
	PlayZone[2].stop = true;
	PlayZone[15].stop = true;
	PlayZone[28].stop = true;
	PlayZone[41].stop = true;
	PlayZone[54].stop = true;
	PlayZone[67].stop = true;
	for (i = 0; i <= 6; i++) {
		PlayZone[i].SetCoordinates(x[i], y[i]);
		PlayZone[i].SetGrad(grad);
		PlayZone[i].SetDim(SquareDim);
		
		PlayZone[i].DrawDiamond();
	}

	for (i = 7; i <= 19; i++) {
		PlayZone[i].SetCoordinates(x[i], y[i]);
		PlayZone[i].SetGrad(0);
		PlayZone[i].SetDim(SquareDim);
		PlayZone[i].DrawDiamond();
	}
	for (i = 20; i <= 27; i++) {
		PlayZone[i].SetCoordinates(x[i], y[i]);
		PlayZone[i].SetGrad(-grad);
		PlayZone[i].SetDim(SquareDim);
		PlayZone[i].DrawDiamond();
	}
	for (i = 28; i <= 32; i++) {
		PlayZone[i].SetCoordinates(x[i], y[i]);
		PlayZone[i].SetGrad(-grad);
		PlayZone[i].SetDim(SquareDim);
		PlayZone[i].DrawDiamond();

	}
	for (i = 33; i <= 40; i++) {
		PlayZone[i].SetCoordinates(x[i], y[i]);
		PlayZone[i].SetGrad(grad);
		PlayZone[i].SetDim(SquareDim);
		PlayZone[i].DrawDiamond();
	}
	for (i = 41; i <= 45; i++) {
		PlayZone[i].SetCoordinates(x[i], y[i]);
		PlayZone[i].SetGrad(grad);
		PlayZone[i].SetDim(SquareDim);
		PlayZone[i].DrawDiamond();
	}
	for (i = 46; i <= 58; i++) {
		PlayZone[i].SetCoordinates(x[i], y[i]);
		PlayZone[i].SetGrad(0);
		PlayZone[i].SetDim(SquareDim);
		PlayZone[i].DrawDiamond();
	}
	for (i = 59; i <= 71; i++) {
		PlayZone[i].SetCoordinates(x[i], y[i]);
		PlayZone[i].SetGrad(-grad);
		PlayZone[i].SetDim(SquareDim);
		PlayZone[i].DrawDiamond();
	}
	for (i = 72; i <= 77; i++) {
		PlayZone[i].SetCoordinates(x[i], y[i]);
		PlayZone[i].SetDim(SquareDim);
		PlayZone[i].SetGrad(grad);
		PlayZone[i].DrawDiamond();
	}
}
void Ludo_6Player::SetLudo() {
	PlayZone = new Cell[90];
	int x[90], y[90];
	SetPlayZoneCoordinates(x, y);
	DrawPlayZone(x,y);
	SafeZone = new Cell * [NoOfPlayers];
	for (int i = 0; i < NoOfPlayers; i++) {
		SafeZone[i] = new Cell[5];
	}
	DrawSafeZones(x, y);
}
void Ludo_6Player::SetPlayZoneCoordinates(int x[], int y[]) {
	int initalX = 0, initalY = 130;
	int SquareDim = 35, grad = 20, dis = 10;
	x[0] = initalX;
	y[0] = initalY;
	x[1] = x[0];
	y[1] = y[0] - SquareDim;
	for (int i = 2; i <= 6; i++) {
		x[i] = x[i - 1] + SquareDim;
		y[i] = y[i - 1] + grad;
	}
	y[7] = y[6] + grad - SquareDim;
	x[7] = x[6] + SquareDim;
	for (int i = 8; i <= 12; i++) {
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
	x[20] = x[19] + SquareDim;
	y[20] = y[19] + SquareDim;
	for (int i = 21; i <= 25; i++) {
		x[i] = x[i - 1] + SquareDim;
		y[i] = y[i - 1] - grad;
	}
	x[26] = x[25];
	y[26] = y[25] + SquareDim;
	x[27] = x[26];
	y[27] = y[26] + SquareDim;
	for (int i = 28; i <= 32; i++) {
		x[i] = x[i - 1] - SquareDim;
		y[i] = y[i - 1] + grad;
	}
	x[33] = x[32];
	y[33] = y[32] + SquareDim;
	for (int i = 34; i <= 38; i++) {
		x[i] = x[i - 1] + SquareDim;
		y[i] = y[i - 1] + grad;
	}
	x[39] = x[38];
	y[39] = y[38] + SquareDim;
	x[40] = x[39];
	y[40] = y[39] + SquareDim;
	for (int i = 41; i <= 45; i++) {
		x[i] = x[i - 1] - SquareDim;
		y[i] = y[i - 1] - grad;
	}
	for (int i = 46; i <= 51; i++) {
		x[i] = x[45] - SquareDim;
		y[i] = y[i - 1] + SquareDim;
	}
	x[52] = x[51] - SquareDim;
	y[52] = y[51];
	x[53] = x[52] - SquareDim;
	y[53] = y[52];
	for (int i = 54; i <= 58; i++) {
		x[i] = x[53];
		y[i] = y[i - 1] - SquareDim;
	}
	x[59] = x[58] - SquareDim;
	y[59] = y[58] - (grad - 5);
	for (int i = 60; i <= 64; i++) {
		x[i] = x[i - 1] - SquareDim;
		y[i] = y[i - 1] + grad;
	}
	x[65] = x[64];
	y[65] = y[64] - SquareDim;
	x[66] = x[65];
	y[66] = y[65] - SquareDim;
	for (int i = 67; i <= 71; i++) {
		x[i] = x[i - 1] + SquareDim;
		y[i] = y[i - 1] - grad;
	}
	x[72] = x[71];
	y[72] = y[71] - (SquareDim + SquareDim + 5);
	for (int i = 73; i <= 77; i++) {
		x[i] = x[i - 1] - SquareDim;
		y[i] = y[i - 1] - grad;
	}

}
Ludo_6Player::~Ludo_6Player() {
	for (int i = 0; i < NoOfPlayers; i++) {
		delete[] SafeZone[i];
	}
	delete[] SafeZone;
	delete[] PlayZone;
}

void Ludo_6Player::InitPlayersTokens() {
	int fl = 0;
	Coordinates C1(5, 10);
	Coordinates C2(370, 10);
	Coordinates C3(370, 300);
	Coordinates C4(370, 560);
	Coordinates C5(5, 560);
	Coordinates C6(5, 300);
	Coordinates Player_6[6] = { C1,C2,C3,C4,C5,C6 };
	for (int i = 0; i < NoOfPlayers; i++) {
		Players[i]->SetFinalLocation(fl);
		Players[i]->SetTokens(Player_6[i]);
		fl += 13;
	}
}
void Ludo_6Player::PlayerWin(int turn) {
	moveto(10, 700 + (turn * 20));
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
void Ludo_6Player::MoveInSafe(int DiceNo) {
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
				return;
			}
		}

	}
	SafeZone[Turn][Players[Turn]->tokenSelected->TokenLocationNearWin].DrawCell();
	SafeZone[Turn][Players[Turn]->tokenSelected->TokenLocationNearWin].DrawUnit(Players[Turn]->tokenSelected);
}
int Ludo_6Player::AddDiceInTokenLocation(int initLoc, int DiceNo) {
	int fLocat = initLoc;
	for (int i = 1; i <= DiceNo; i++) {
		fLocat += 1;
		if (fLocat > 77) {
			fLocat = 0;
		}
	}
	return fLocat;
}
void Ludo_6Player::JustMove(int Diceno) {
	int org = Players[Turn]->tokenSelected->TokenLocationOnBoard;
	PlayZone[org].DrawCell();
	for (int i = 0; i < Players[Turn]->TokenArray.size(); i++) {
		if (Players[Turn]->TokenArray[i] != Players[Turn]->tokenSelected && Players[Turn]->TokenArray[i]->Status == 'P' && Players[Turn]->TokenArray[i]->TokenLocationOnBoard == org) {
			PlayZone[org].DrawUnit(Players[Turn]->TokenArray[i]);
		}
	}
	for (int i = 0; i < Diceno + 1; i++) {
		int num = AddDiceInTokenLocation(Players[Turn]->tokenSelected->TokenLocationOnBoard, i);
		if (num == Players[Turn]->tokenSelected->FinalLocation) {
			if (i != Diceno) {
				Players[Turn]->tokenSelected->TokenLocationOnBoard = -1;
				Players[Turn]->tokenSelected->Status = 'C';
				MoveInSafe(Diceno - i - 1);
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
void Ludo_6Player::AddSavedTokens(Token* add) {
	for (int i = 0; i < SavedTokens.size(); i++) {
		if (SavedTokens[i] == add) {
			return;
		}
	}
	SavedTokens.push_back(add);
}
void Ludo_6Player::MoveToKill(int finalLoc) {
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
void Ludo_6Player::RemoveFromSavedTokens(Token* rem) {
	for (int i = 0; i < SavedTokens.size(); i++) {
		if (SavedTokens[i] == rem) {
			SavedTokens.erase(SavedTokens.begin() + i);
		}
	}
}
void Ludo_6Player::MoveSelectedPlayerPiece(int Diceno) {
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

void Ludo_6Player::PlayAllMoves() {
	int DiceNo = 0;
	bool reselectToken = false;
	Cell DiceNos[5];
	do {
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
void Ludo_6Player::RedrawSavedTokens(int turn) {
	turn++;
	for (int i = 0; i < SavedTokens.size(); i++) {
		if (SavedTokens[i]->BelongsToPlayer == turn) {
			PlayZone[SavedTokens[i]->TokenLocationOnBoard].DrawCell();
			PlayZone[SavedTokens[i]->TokenLocationOnBoard].DrawUnit(SavedTokens[i]);
		}
	}
}
void Ludo_6Player::TurnChange() {
	Turn++;
	if (Turn >= NoOfPlayers) Turn = 0;
	if (!Players[Turn]) TurnChange();
	RedrawSavedTokens(Turn);
}
void Ludo_6Player::StartGame() {
	InitPlayersTokens();
	Turn = 0;
	do {
		cout << "Player Turn's: " << Turn + 1 << endl;
		while (dice.RollaDice());
		//dice.DiceNo.push_back(6);
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