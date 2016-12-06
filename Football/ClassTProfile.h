//---------------------------------------------------------------------------

#include "ClassTPlayer.h"

#ifndef ClassTProfileH
#define ClassTProfileH

class TProfile {
public:
	TPlayer Team[3];
	string name;
	int level;
	int cash;
	int wins;
	void write(ofstream& ss);
	void read(ifstream& ss);
};

//---------------------------------------------------------------------------
#endif
