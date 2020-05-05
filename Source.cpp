#include<iostream>
#include<conio.h>
using namespace std;
#include"Cell.h"
int main()
{
	initwindow(900, 900, "Shehrazlul");
	Cell C;
	C.SetCoordinates(60,60);
	C.DrawCell();
	C.DrawUnit();
	return _getch();
}