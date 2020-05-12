#pragma once
#include"Player.h"
class Player4 :public Player
{
public:
	Player4() {};
	virtual void SetTokens(Coordinates C);
	virtual void DrawPlayerTokensAtHome() {};
};

