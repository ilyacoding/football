#include "inc.h"

class TPlayer {
public:
	Player();
	string name;
	string surname;
	int level;
	int speed;
};

TPlayer::Player()
{
	name = "";
	surname = "";
	level = 0;
	speed = 0;
}

class TProfile {
public:
	string name;
	int level;
	int cash;
	int wins;
	TPlayer Team[3];
	void write(ofstream& ss);
	void read(ifstream& ss);
};

void TProfile::write(ofstream& ss)
{
	ss << name << " " << level << " " << cash << " " << wins << " ";
	for (int i = 0; i < 3; i++) {
		ss << Team[i].name << " " << Team[i].surname << " " << Team[i].level << " " << Team[i].speed;
		if (i < 2) ss << " ";
	}
}

void TProfile::read(ifstream& ss)
{
	string str;
	string tmp;
	ss >> name >> level >> cash >> wins;
	for (int i = 0; i < 3; i++)
		ss >> Team[i].name >> Team[i].surname >> Team[i].level >> Team[i].speed;
}

class TProfiles {
private:
	vector<TProfile> user;
public:
	TProfiles();
	string filename;
	void out();
	void in();
	bool IsExist(string name);
	bool reg(TProfile prfl);
	TProfile GetUser(int PID);
	int log(string name);
	int length();
};

TProfiles::TProfiles()
{
	filename = "db/db.bin";
}

void TProfiles::out()
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

void TProfiles::in()
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

bool TProfiles::IsExist(string name)
{
	for (int i = 0; i < user.size(); i++)
		if (user[i].name == name)
			return true;
	return false;
}

bool TProfiles::reg(TProfile prfl)
{
	if (!IsExist(prfl.name))
	{
		user.push_back(prfl);
		return true;
	} else {
		return false;
	}
}

int TProfiles::log(string name)
{
	for (int i = 0; i < user.size(); i++)
		if (user[i].name == name)
			return i;
	return -1;
}

int TProfiles::length()
{
	return user.size();
}

TProfile TProfiles::GetUser(int PID)
{
	return user[PID];
}

class TPID {
public:
	int value;
	//vector<TProfile> user;
	TPID();
	string filename;
	void out();
	void in();
	//bool IsExist(string name);
	//bool reg(TProfile prfl);
	//TProfile GetUser(int PID);
	//int log(string name);
	//int length();
};

TPID::TPID()
{
	filename = "db/pid.bin";
}

void TPID::out()
{
	ofstream ss(filename.c_str(), std::ofstream::out | std::ofstream::trunc);
	ss << value;
	ss.close();
}

void TPID::in()
{
	ifstream ss(filename.c_str());
	ss >> value;
	ss.close();
}
