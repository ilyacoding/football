//---------------------------------------------------------------------------

#include "IncludeLibs.h"
#ifndef ClassTGameH
#define ClassTGameH
class TGame {
public:
	TGame();
	bool Ended;  // ���� ��������� ��� ���
	int Winner;   // ��� ������� ����
	int WinCount; // ���������� ���, ������� ���������� ��������
	int Count[2]; // ���� ������ �������
	void Goal(int Team);  // ��� ����� ��� = 1/2
};
//---------------------------------------------------------------------------
#endif
