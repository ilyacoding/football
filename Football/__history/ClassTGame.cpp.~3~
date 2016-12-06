//---------------------------------------------------------------------------

#pragma hdrstop

#include "ClassTGame.h"
TGame::TGame()
{
	CanMove = false;
	Started = false;
	Ended = false;
	Winner = -1;
	WinCount = 1;
	TimerCount = 0;
	Count[0] = Count[1] = 0;
}

void TGame::InitGame()
{
	CanMove = false;
	Started = false;
	Ended = false;
	Winner = -1;
	WinCount = 1;
	TimerCount = 0;
	Count[0] = Count[1] = 0;
}

void TGame::GoalTo(int Team)
{
	if (Team == 1 || Team == 2)
		Count[2 - Team]++;
	if (WinCount == Count[0] || WinCount == Count[1])
	{
		Ended = true;
		(WinCount == Count[0]) ? (Winner = 0) : (Winner = 1);
	}
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
