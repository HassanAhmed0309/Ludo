#pragma once
#include"Player.h"
class Player6 :public Player
{
public:
	Player6() {};
	virtual void SetTokens(Coordinates C);
	virtual void DrawPlayerTokensAtHome() {};
};

