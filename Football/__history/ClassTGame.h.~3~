//---------------------------------------------------------------------------

#include "IncludeLibs.h"
#ifndef ClassTGameH
#define ClassTGameH
class TGame {
private:
	int WinCount; // Количество игр, которые необходимо выиграть
public:
	TGame();
    void InitGame();
	bool CanMove;
	bool Started;
	bool Ended;  // Игра закончена или нет
	int Count[2]; // Счет каждой команды
	int TimerCount;
	int Winner;   // Кто выиграл матч
	void GoalTo(int Team);  // Кто забил мяч = 1/2
};
//---------------------------------------------------------------------------
#endif
