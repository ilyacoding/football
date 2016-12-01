//---------------------------------------------------------------------------

#pragma hdrstop

#include "ClassTProfile.h"
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
//---------------------------------------------------------------------------
#pragma package(smart_init)
