//---------------------------------------------------------------------------

#ifndef IncludeLibsH
#define IncludeLibsH
#include <sstream>
#include <fstream.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

template <typename T>
string ToStr(T Data)
{
	 ostringstream ss;
	 ss << Data;
	 return ss.str();
}
//---------------------------------------------------------------------------
#endif
