#include "Player3.h"
#include"Token3.h"
void Player3::SetTokens(Coordinates C) {
	for (int i = 0; i < 4; i++) {
		TokenArray.push_back(new Token3);
		TokenArray[i]->SetFinalLocation(FinalLocation);
		Coordinates HomeLoc(C.X + (i * 40), C.Y);
		TokenArray[i]->SetHomeLocation(HomeLoc);
		TokenArray[i]->TokenLocationOnBoard = InitalLocation;
		TokenKilled(TokenArray[i]);
		TokenArray[i]->BelongsToPlayer = 3;
	}

}