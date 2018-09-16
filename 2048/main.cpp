#include "2048.h"
#include <Windows.h>

void Run() {
	Board *BoardPt = new Board();

	while (true) {
		if (GetAsyncKeyState(VK_UP))
			BoardPt->MoveUpMatrix();
		else if (GetAsyncKeyState(VK_DOWN))
			BoardPt->MoveDownMatrix();
		else if (GetAsyncKeyState(VK_LEFT))
			BoardPt->MoveLeftMatrix();
		else if (GetAsyncKeyState(VK_RIGHT))
			BoardPt->MoveRightMatrix();
		else if (GetAsyncKeyState('R'))
			BoardPt->RestartGame();
		else if (GetAsyncKeyState(VK_ESCAPE))
			break;
		Sleep(200);
	}
	delete BoardPt;
}


int main() {
	Run();
	return 0;
}