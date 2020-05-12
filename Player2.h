#pragma once
#include"Player.h"
class Player2 :public Player
{
public:
	Player2() {};
	virtual void SetTokens(Coordinates C);
	virtual void DrawPlayerTokensAtHome() {};
};

