//---------------------------------------------------------------------------

#pragma hdrstop

#include "ClassTField.h"
float TField::CalcDegree(float FromX, float FromY, float ToX, float ToY)
{
	if ((ToX - (FromX) > 0) && (ToY - (FromY) > 0)) {// X+ Y+
		return ceil(atan(fabs(ToX - (FromX))/fabs(ToY - (FromY))) * 180 / pi) + 270;
	} else if ((ToX - (FromX) < 0) && (ToY - (FromY) > 0)) {// X- Y+
		return ceil(atan(fabs(ToY - (FromY))/fabs(ToX - (FromX))) * 180 / pi) + 180;
	} else if ((ToX - (FromX) > 0) && (ToY - (FromY) < 0)) {// X+ Y-
		return ceil(atan(fabs(ToY - (FromY))/fabs(ToX - (FromX))) * 180 / pi);
	} else if ((ToX - (FromX) < 0) && (ToY - (FromY) < 0)) {// X- Y-
		return 180 - ceil(atan(fabs(ToY - (FromY))/fabs(ToX - (FromX))) * 180 / pi);
	} else {
		return 0;
	}
}

float TField::CalcDistance(float FromX, float FromY, float ToX, float ToY)
{
	return sqrt(((FromY) - (ToY))*((FromY) - (ToY)) + ((FromX) - (ToX))*((FromX) - (ToX)));
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
