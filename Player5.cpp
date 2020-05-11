#include "Player5.h"
#include"Token5.h"
void Player5::SetTokens(Coordinates C) {
	for (int i = 0; i < 4; i++) {
		TokenArray.push_back(new Token5);
		TokenArray[i]->SetFinalLocation(FinalLocation);
		Coordinates HomeLoc(C.X + (i * 40), C.Y);
		TokenArray[i]->SetHomeLocation(HomeLoc);
		TokenArray[i]->TokenLocationOnBoard = InitalLocation;
		TokenKilled(TokenArray[i]);
		TokenArray[i]->BelongsToPlayer = 5;
	}
}