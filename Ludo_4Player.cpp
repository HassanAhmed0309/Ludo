#include "Ludo_4Player.h"
Ludo_4Player::Ludo_4Player(int PNo):NoOfPlayers(PNo),CellSquareDim(40) {
	SetLudo();
}
void Ludo_4Player::SetLudo() {
	PlayZone = new Cell[55];
	int x[55], y[55];
	SetPlayZoneCoordinates(x, y);
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





void Ludo_4Player::StartGame() {
	PlayZone[0].DrawUnit();

	PlayZone[2].DrawUnit();
	PlayZone[6].DrawUnit();

	PlayZone[8].DrawUnit();

}