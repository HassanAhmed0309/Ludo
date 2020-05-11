#pragma once
#include"Player.h"
class Player3 :public Player
{
public:
	Player3() {};
	virtual void SetTokens(Coordinates C);
	virtual void DrawPlayerTokensAtHome() {};
};

