#include "Player4.h"
#include"Token4.h"
void Player4::SetTokens(Coordinates C) {
	for (int i = 0; i < 4; i++) {
		TokenArray.push_back(new Token4);
		TokenArray[i]->SetFinalLocation(FinalLocation);
		Coordinates HomeLoc(C.X + (i * 40), C.Y);
		TokenArray[i]->SetHomeLocation(HomeLoc);
		TokenArray[i]->TokenLocationOnBoard = InitalLocation;
		TokenKilled(TokenArray[i]);
		TokenArray[i]->BelongsToPlayer = 4;
	}
}