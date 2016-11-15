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

#define SSTR(x) static_cast< std::ostringstream & >((std::ostringstream() << std::dec << x)).str()

union ToInt32
{
		unsigned __int64 int64_val;
		unsigned __int32 int32_val[2];
} toInt32;

union ToShort
{
		unsigned __int32 int32_val;
		unsigned __int16 int16_val[2];
} toShort;

union ToByte
{
		unsigned __int16 int16_val;
		unsigned __int8 int8_val[2];
} toByte;

template <typename T>
string ToStr(T Data)
{
	 ostringstream ss;
	 ss << Data;
	 return ss.str();
}

template< typename T >
string ToHex( T i )
{
	stringstream stream;
	stream << std::setfill ('0') << std::setw(sizeof(T)*2) << std::hex << i;
	return stream.str();
}

template< typename T >
unsigned __int16 ToDec( T i )
{
	unsigned __int16 x;
	stringstream stream;
	stream << std::hex << i;
	stream >> std::hex >> x;
	return x;
}





