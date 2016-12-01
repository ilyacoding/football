//---------------------------------------------------------------------------

#ifndef IncludeLibsH
#define IncludeLibsH
#include <sstream>
#include <fstream.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <iomanip>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "boost/algorithm/string.hpp"

template <typename T>
string ToStr(T Data)
{
	 ostringstream ss;
	 ss << Data;
	 return ss.str();
}
//---------------------------------------------------------------------------
#endif
