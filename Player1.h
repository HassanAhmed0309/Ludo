#pragma once
#include"Player.h"
class Player1 :public Player
{
public:
	Player1() {};
	virtual void SetTokens(Coordinates C);
	virtual void DrawPlayerTokensAtHome() {};
};

