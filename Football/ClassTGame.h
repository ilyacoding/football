//---------------------------------------------------------------------------

#include "IncludeLibs.h"
#ifndef ClassTGameH
#define ClassTGameH
class TGame {
private:
	int WinCount; // ���������� ���, ������� ���������� ��������
public:
	void InitGame();
	TGame();
	bool CanMove;
	int Count[2]; // ���� ������ �������
	int TimerCount;
	int Winner;   // ��� ������� ����
	void GoalTo(int Team);  // ��� ����� ��� = 1/2
};
//---------------------------------------------------------------------------
#endif
