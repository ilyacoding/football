//---------------------------------------------------------------------------


#include "ClassTProfile.h"
#include "ClassTPid.h"

#ifndef ClassTUdbH
#define ClassTUdbH

class TUdb {
private:
	vector<TProfile> user;
public:
	TUdb();
	TPid pid;
	string filename;
	void out();
	void in();
	void SortForStat();
	bool IsExist(string name);
	bool reg(TProfile prfl);
	int log(string name);
	TProfile GetUser(int PID);
	void AddWin(int PID, int Funds);
	bool BuyLvl(int PID, int PlayerID);
	bool BuyAccountLvl(int PID);
	int length();
};

//---------------------------------------------------------------------------
#endif
