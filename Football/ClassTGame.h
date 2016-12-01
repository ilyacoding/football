//---------------------------------------------------------------------------

#include "IncludeLibs.h"
#ifndef ClassTGameH
#define ClassTGameH
class TGame {
public:
	TGame();
	bool Ended;  // Игра закончена или нет
	int Winner;   // Кто выиграл матч
	int WinCount; // Количество игр, которые необходимо выиграть
	int Count[2]; // Счет каждой команды
	void Goal(int Team);  // Кто забил мяч = 1/2
};
//---------------------------------------------------------------------------
#endif
