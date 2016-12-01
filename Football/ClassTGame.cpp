//---------------------------------------------------------------------------

#pragma hdrstop

#include "ClassTGame.h"
TGame::TGame()
{
	Ended = false;
	Winner = -1;
	WinCount = 3;
	Count[0] = Count[1] = 0;
}

void TGame::Goal(int Team)
{
	if (Team == 1 || Team == 2)
		Count[Team - 1]++;
	if (WinCount == Count[0] || WinCount == Count[1])
		Ended = true;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
