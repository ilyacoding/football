//---------------------------------------------------------------------------

#pragma hdrstop

#include "ClassTPid.h"
TPid::TPid()
{
	filename = "db/pid.bin";
}

void TPid::out()
{
	ofstream ss(filename.c_str(), std::ofstream::out | std::ofstream::trunc);
	ss << value;
	ss.close();
}

void TPid::in()
{
	ifstream ss(filename.c_str());
	ss >> value;
	ss.close();
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
