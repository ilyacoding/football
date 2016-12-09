//---------------------------------------------------------------------------

#pragma hdrstop

#include "ClassTUdb.h"
TUdb::TUdb()
{
	filename = "db/db.bin";
}

void TUdb::out()
{
	ofstream ss(filename.c_str(), std::ofstream::out | std::ofstream::trunc);
	for (int i = 0; i < user.size(); i++)
	{
		user[i].write(ss);
		if (i != user.size() - 1) ss << endl;
	}
	user.clear();
	ss.close();
}

void TUdb::in()
{
	ifstream ss(filename.c_str());
	TProfile tmp;
	user.clear();
	while (!ss.eof())
	{
		tmp.read(ss);
		user.push_back(tmp);
	}
	ss.close();
}

void TUdb::SortForStat()
{
	TProfile tmp;

	for (int i = 0; i < user.size(); i++)
	{
		for (int j = i + 1; j < user.size(); j++)
		{
			if (user[j].level > user[i].level) {
				tmp = user[i];
				user[i] = user[j];
				user[j] = tmp;
			}
		}
	}

	for (int i = 0; i < user.size(); i++)
	{
		for (int j = i + 1; j < user.size(); j++)
		{
			if (user[j].wins > user[i].wins) {
				tmp = user[i];
				user[i] = user[j];
				user[j] = tmp;
			}
		}
	}
}

bool TUdb::IsExist(string name)
{
	for (int i = 0; i < user.size(); i++)
		if (user[i].name == name)
			return true;
	return false;
}

bool TUdb::reg(TProfile prfl)
{
	if (!IsExist(prfl.name))
	{
		user.push_back(prfl);
		return true;
	} else {
		return false;
	}
}

int TUdb::log(string name)
{
	for (int i = 0; i < user.size(); i++)
		if (user[i].name == name)
			return i;
	return -1;
}

int TUdb::length()
{
	return user.size();
}

TProfile TUdb::GetUser(int PID)
{
	return user[PID];
}

void TUdb::AddWin(int PID, int Funds)
{
	if (Funds > 0) {
		user[PID].cash += Funds;
		user[PID].wins++;
	}
}

bool TUdb::BuyLvl(int PID, int PlayerID)
{
	if (user[PID].cash >= 20000) {
		user[PID].cash -= 20000;
		user[PID].Team[PlayerID].speed++;
		user[PID].Team[PlayerID].level = user[PID].Team[PlayerID].speed/3;
		return true;
	}
	return false;
}

bool TUdb::BuyAccountLvl(int PID)
{
	if (user[PID].cash >= 15000) {
		user[PID].cash -= 15000;
		user[PID].level++;
		return true;
	}
	return false;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
