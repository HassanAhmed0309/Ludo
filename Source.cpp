#include<conio.h>
#include"Ludo_4Player.h"
//void Draw4PlayerBoard(int x[], int y[]) {
//	int initalX = 0, initalY = 280;
//	int SquareDim = 40;
//	x[0] = initalX;
//	y[0] = initalY;
//	x[1] = initalX;
//	y[1] = initalY - SquareDim;
//	for (int i = 2; i <= 6; i++) {
//		x[i] = x[i - 1] + SquareDim;
//		y[i] = initalY - SquareDim;
//	}
//	for (int i = 7; i <= 12; i++) {
//		x[i] = x[6] + SquareDim;
//		y[i] = y[i - 1] - SquareDim;
//	}
//	x[13] = x[12] + SquareDim;
//	y[13] = y[12];
//	x[14] = x[13] + SquareDim;
//	y[14] = y[13];
//	for (int i = 15; i <= 19; i++) {
//		x[i] = x[12] + SquareDim + SquareDim;
//		y[i] = y[i - 1] + SquareDim;
//	}
//	for (int i = 20; i <= 25; i++) {
//		x[i] = x[i - 1] + SquareDim;
//		y[i] = initalY - SquareDim;
//	}
//	x[26] = x[25];
//	y[26] = y[25] + SquareDim;
//	x[27] = x[26];
//	y[27] = y[26] + SquareDim;
//	for (int i = 28; i <= 32; i++) {
//		x[i] = x[i - 1] - SquareDim;
//		y[i] = initalY + SquareDim;
//	}
//	for (int i = 33; i <= 38; i++) {
//		x[i] = x[32] - SquareDim;
//		y[i] = y[i - 1] + SquareDim;
//	}
//	x[39] = x[38] - SquareDim;
//	y[39] = y[38];
//	x[40] = x[39] - SquareDim;
//	y[40] = y[39];
//	for (int i = 41; i <= 45; i++) {
//		x[i] = x[40];
//		y[i] = y[i - 1] - SquareDim;
//	}
//	for (int i = 46; i <= 52; i++) {
//		x[i] = x[i - 1] - SquareDim;
//		y[i] = y[45] - SquareDim;
//	}
//	Cell C;
//	for (int i = 0; i < 52; i++) {
//		C.SetCoordinates(x[i], y[i]);
//		C.DrawCell();
//	}
//}
//void DrawBoard6Player(int x[],int y[]) {
//	int initalX = 0, initalY = 130;
//	int SquareDim = 35, grad = 20, dis = 10;
//	x[0] = initalX;
//	y[0] = initalY;
//	x[1] = x[0];
//	y[1] = y[0] - SquareDim;
//	for (int i = 2; i <= 6; i++) {
//		x[i] = x[i - 1] + SquareDim;
//		y[i] = y[i - 1] + grad;
//	}
//	y[7] = y[6] + grad - SquareDim;
//	x[7] = x[6] + SquareDim;
//	for (int i = 8; i <= 12; i++) {
//		x[i] = x[6] + SquareDim;
//		y[i] = y[i - 1] - SquareDim;
//	}
//	x[13] = x[12] + SquareDim;
//	y[13] = y[12];
//	x[14] = x[13] + SquareDim;
//	y[14] = y[13];
//	for (int i = 15; i <= 19; i++) {
//		x[i] = x[12] + SquareDim + SquareDim;
//		y[i] = y[i - 1] + SquareDim;
//	}
//	x[20] = x[19] + SquareDim;
//	y[20] = y[19] + SquareDim;
//	for (int i = 21; i <= 25; i++) {
//		x[i] = x[i - 1] + SquareDim;
//		y[i] = y[i - 1] - grad;
//	}
//	x[26] = x[25];
//	y[26] = y[25] + SquareDim;
//	x[27] = x[26];
//	y[27] = y[26] + SquareDim;
//	for (int i = 28; i <= 32; i++) {
//		x[i] = x[i - 1] - SquareDim;
//		y[i] = y[i - 1] + grad;
//	}
//	x[33] = x[32];
//	y[33] = y[32] + SquareDim;
//	for (int i = 34; i <= 38; i++) {
//		x[i] = x[i - 1] + SquareDim;
//		y[i] = y[i - 1] + grad;
//	}
//	x[39] = x[38];
//	y[39] = y[38] + SquareDim;
//	x[40] = x[39];
//	y[40] = y[39] + SquareDim;
//	for (int i = 41; i <= 45; i++) {
//		x[i] = x[i - 1] - SquareDim;
//		y[i] = y[i - 1] - grad;
//	}
//	for (int i = 46; i <= 51; i++) {
//		x[i] = x[45] - SquareDim;
//		y[i] = y[i - 1] + SquareDim;
//	}
//	x[52] = x[51] - SquareDim;
//	y[52] = y[51];
//	x[53] = x[52] - SquareDim;
//	y[53] = y[52];
//	for (int i = 54; i <= 58; i++) {
//		x[i] = x[53];
//		y[i] = y[i - 1] - SquareDim;
//	}
//	x[59] = x[58] - SquareDim;
//	y[59] = y[58] - (grad - 5);
//	for (int i = 60; i <= 64; i++) {
//		x[i] = x[i - 1] - SquareDim;
//		y[i] = y[i - 1] + grad;
//	}
//	x[65] = x[64];
//	y[65] = y[64] - SquareDim;
//	x[66] = x[65];
//	y[66] = y[65] - SquareDim;
//	for (int i = 67; i <= 71; i++) {
//		x[i] = x[i - 1] + SquareDim;
//		y[i] = y[i - 1] - grad;
//	}
//	x[72] = x[71];
//	y[72] = y[71] - (SquareDim + SquareDim + 5);
//	for (int i = 73; i <= 77; i++) {
//		x[i] = x[i - 1] - SquareDim;
//		y[i] = y[i - 1] - grad;
//	}
//	Cell C;
//	for (int i = 0; i <= 6; i++) {
//		C.SetCoordinates(x[i], y[i]);
//		C.SetGrad(grad);
//		C.DrawDiamond();
//	}
//	for (int i = 7; i <= 19; i++) {
//		C.SetCoordinates(x[i], y[i]);
//		C.SetGrad(0);
//		C.DrawDiamond();
//	}
//	for (int i = 20; i <= 27; i++) {
//		C.SetCoordinates(x[i], y[i]);
//		C.SetGrad(-grad);
//		C.DrawDiamond();
//	}
//	for (int i = 28; i <= 32; i++) {
//		C.SetCoordinates(x[i], y[i]);
//		C.SetGrad(-grad);
//		C.DrawDiamond();
//	}
//	for (int i = 33; i <= 40; i++) {
//		C.SetCoordinates(x[i], y[i]);
//		C.SetGrad(grad);
//		C.DrawDiamond();
//	}
//	for (int i = 41; i <= 45; i++) {
//		C.SetCoordinates(x[i], y[i]);
//		C.SetGrad(grad);
//		C.DrawDiamond();
//	}
//	for (int i = 46; i <= 58; i++) {
//		C.SetCoordinates(x[i], y[i]);
//		C.SetGrad(0);
//		C.DrawDiamond();
//	}
//	for (int i = 59; i <= 71; i++) {
//		C.SetCoordinates(x[i], y[i]);
//		C.SetGrad(-grad);
//		C.DrawDiamond();
//	}
//	for (int i = 72; i <= 77; i++) {
//		C.SetCoordinates(x[i], y[i]);
//		C.SetGrad(grad);
//		C.DrawDiamond();
//	}
//}
//void Draw6PlayerStops(int x[], int y[]) {
//	int x1[5], y1[5], grad = 20, SquareDim = 35;
//	x1[0] = x[0] + SquareDim;
//	y1[0] = y[0] + grad;
//	for (int i = 1; i < 5; i++) {
//		x1[i] = x1[i - 1] + SquareDim;
//		y1[i] = y1[i - 1] + grad;
//	}
//	Cell C;
//	for (int i = 0; i < 5; i++) {
//		C.SetCoordinates(x1[i], y1[i]);
//		C.SetGrad(grad);
//		C.DrawDiamond();
//	}
//
//	//2 Player Stop
//	int x2[5], y2[5];
//	x2[0] = x[13];
//	y2[0] = y[13] + SquareDim;
//	for (int i = 1; i < 5; i++) {
//		x2[i] = x2[i - 1];
//		y2[i] = y2[i - 1] + SquareDim;
//	}
//	for (int i = 0; i < 5; i++) {
//		C.SetCoordinates(x2[i], y2[i]);
//		C.SetGrad(0);
//		C.DrawDiamond();
//	}
//
//
//	//3 Player Stop
//	int x3[5], y3[5];
//	x3[0] = x[26] - SquareDim;
//	y3[0] = y[26] + grad;
//	for (int i = 1; i < 5; i++) {
//		x3[i] = x3[i - 1] - SquareDim;
//		y3[i] = y3[i - 1] + grad;
//	}
//	for (int i = 0; i < 5; i++) {
//		C.SetCoordinates(x3[i], y3[i]);
//		C.SetGrad(-grad);
//		C.DrawDiamond();
//	}
//
//
//	//4 Player Stop
//	int x4[5], y4[5];
//	x4[0] = x[39] - SquareDim;
//	y4[0] = y[39] - grad;
//	for (int i = 1; i < 5; i++) {
//		x4[i] = x4[i - 1] - SquareDim;
//		y4[i] = y4[i - 1] - grad;
//	}
//	for (int i = 0; i < 5; i++) {
//		C.SetCoordinates(x4[i], y4[i]);
//		C.SetGrad(grad);
//		C.DrawDiamond();
//	}
//
//	//5 Player Stop
//	int x5[5], y5[5];
//	x5[0] = x[52];
//	y5[0] = y[52] - SquareDim;
//	for (int i = 1; i < 5; i++) {
//		x5[i] = x5[i - 1];
//		y5[i] = y5[i - 1] - SquareDim;
//	}
//	for (int i = 0; i < 5; i++) {
//		C.SetCoordinates(x5[i], y5[i]);
//		C.SetGrad(0);
//		C.DrawDiamond();
//	}
//	//6 Player Stop
//	int x6[5], y6[5];
//	x6[0] = x[65] + SquareDim;
//	y6[0] = y[65] - grad;
//	for (int i = 1; i < 5; i++) {
//		x6[i] = x6[i - 1] + SquareDim;
//		y6[i] = y6[i - 1] - grad;
//	}
//	for (int i = 0; i < 5; i++) {
//		C.SetCoordinates(x6[i], y6[i]);
//		C.SetGrad(-grad);
//		C.DrawDiamond();
//	}
//}
//void DrawSafeZone(int x,int y,int SquareH,int SquareV, Cell *C) {
//	//1 player
//	int x1[5], y1[5];
//	x1[0] = x + SquareH;
//	y1[0] = y + SquareV;
//	for (int i = 1; i < 5; i++) {
//		x1[i] = x1[i - 1] + SquareH;
//		y1[i] = y1[i-1] + SquareV;
//	}
//	for (int i = 0; i < 5; i++) {
//		C[i].SetCoordinates(x1[i], y1[i]);
//		C[i].DrawCell();
//	}
//}
//void Draw4PlayerStops(int x[],int y[]) {
//	//1 player
//	int x1[5], y1[5], SquareDim = 40;
//	x1[0] = x[0] + SquareDim;
//	y1[0] = y[0];
//	for (int i = 1; i < 5; i++) {
//		x1[i] = x1[i - 1] + SquareDim;
//		y1[i] = y1[0];
//	}
//	Cell C;
//	for (int i = 0; i < 5; i++) {
//		C.SetCoordinates(x1[i], y1[i]);
//		C.DrawCell();
//	}
//
//	//2 player
//	x1[0] = x[13];
//	y1[0] = y[13] + SquareDim;
//	for (int i = 1; i < 5; i++) {
//		x1[i] = x1[i - 1];
//		y1[i] = y1[i - 1] + SquareDim;
//	}
//	for (int i = 0; i < 5; i++) {
//		C.SetCoordinates(x1[i], y1[i]);
//		C.DrawCell();
//	}
//
//
//	//3 player
//	x1[0] = x[26] - SquareDim;
//	y1[0] = y[26];
//	for (int i = 1; i < 5; i++) {
//		x1[i] = x1[i - 1] - SquareDim;
//		y1[i] = y1[i - 1];
//	}
//	for (int i = 0; i < 5; i++) {
//		C.SetCoordinates(x1[i], y1[i]);
//		C.DrawCell();
//	}
//
//	//4 player
//	x1[0] = x[39];
//	y1[0] = y[39] - SquareDim;
//	for (int i = 1; i < 5; i++) {
//		x1[i] = x1[i - 1];
//		y1[i] = y1[i - 1] - SquareDim;
//	}
//	for (int i = 0; i < 5; i++) {
//		C.SetCoordinates(x1[i], y1[i]);
//		C.DrawCell();
//	}
//}
int main() {
	//6 Player
	initwindow(1200, 1000, "Ws");
	Ludo_4Player Ludo(4);
	Ludo.StartGame();

	return _getch();
}