//---------------------------------------------------------------------------

#define TeamSize 3
#define PlayerSize 64

#ifndef ClassTTeamH
#define ClassTTeamH
#include "UnitMain.h"
#include "ClassTFiPlayer.h"
class TTeam
{
	public:
		TFiPlayer Player[TeamSize];
		int CurrPlayer;
		int GetAmount();
		bool AddPlayer(float PosX, float PosY, char ImgColor);
		bool DeletePlayer(int N);
};
//---------------------------------------------------------------------------
#endif
