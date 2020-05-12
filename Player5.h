#pragma once
#include"Player.h"
class Player5 :public Player
{
public:
	Player5() {};
	virtual void SetTokens(Coordinates C);
	virtual void DrawPlayerTokensAtHome() {};
};

