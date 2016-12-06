//---------------------------------------------------------------------------

#include "IncludeLibs.h"
#ifndef ClassTGameH
#define ClassTGameH
class TGame {
public:
	void InitGame();
	TGame();
	bool CanMove;
	int WinCount; // Количество игр, которые необходимо выиграть
	int Count[2]; // Счет каждой команды
	int TimerCount;
	int Winner;   // Кто выиграл матч
	void GoalTo(int Team);  // Кто забил мяч = 1/2
};
//---------------------------------------------------------------------------
#endif
