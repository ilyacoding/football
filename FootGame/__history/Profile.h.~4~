#include "inc.h"

class Player {
public:
	Player();
	string name;
	string surname;
	int level;
	int speed;
};

Player::Player()
{
	name = "";
	surname = "";
	level = 0;
	speed = 0;
}

class Profile {
public:
	string name;
	int level;
	int cash;
	int wins;
	Player Team[3];
	void write(ofstream& ss);
	void read(ifstream& ss);
};

void TProfile::write(ofstream& ss)
{
	ss << name << " " << level << " " << cash << " " << wins << " ";
	for (int i = 0; i < 3; i++)
		ss << Team[i].name << " " << Team[i].surname << " " << Team[i].level << Team[i].speed << " ";
	ss << endl;
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
	bool reg();
	int log();
};

TProfiles::TProfiles()
{
	filenam = "db.bin";
}

void TProfiles::out()
{
	ofstream ss(filename.c_str());
	for (int i = 0; i < user.size(); i++)
	{
		user[i].write(ss);
	}
}

void TProfiles::in()
{
	ifstream ss(filename.c_str());
	Profile tmp;
	while (!ss.eof())
	{
		tmp.read(ss);
		user.push_back(tmp);
	}
}

bool IsExist(string name)
{
	for (int i = 0; i < user.size(); i++)
		if (user[i].name == name)
			return true;
	return false;
}

void TProfiles::reg(TProfile prfl)
{
	if (!IsExist(profile))
	user.push_back(prfl);
}

TProfiles Profiles;
