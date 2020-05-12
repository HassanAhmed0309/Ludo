#include "Player1.h"
#include"Token1.h"
#include"Cell.h"
void Player1::SetTokens(Coordinates C) {
	for (int i = 0; i < 4; i++) {
		TokenArray.push_back(new Token1);
		TokenArray[i]->SetFinalLocation(FinalLocation);
		Coordinates HomeLoc(C.X + (i * 40), C.Y);
		TokenArray[i]->SetHomeLocation(HomeLoc);
		TokenArray[i]->TokenLocationOnBoard = InitalLocation;
		TokenKilled(TokenArray[i]);
		TokenArray[i]->BelongsToPlayer = 1;
	}
}