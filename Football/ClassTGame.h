//---------------------------------------------------------------------------

#include "IncludeLibs.h"
#ifndef ClassTGameH
#define ClassTGameH
class TGame {
public:
	void InitGame();
	TGame();
	bool CanMove;
	int WinCount; // ���������� ���, ������� ���������� ��������
	int Count[2]; // ���� ������ �������
	int TimerCount;
	int Winner;   // ��� ������� ����
	void GoalTo(int Team);  // ��� ����� ��� = 1/2
};
//---------------------------------------------------------------------------
#endif
