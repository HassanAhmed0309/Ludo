#include "Controls.h"

bool Controls::MouseClick(int cpos,int rpos) {
	if (cpos > C.getx() && cpos < C.getx() + dim) {
		if (rpos > C.gety() && rpos < C.gety() + dim) {
			return true;
		}
	}
	return false;
}