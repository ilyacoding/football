//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitInfo.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFormInfo *FormInfo;
//---------------------------------------------------------------------------
__fastcall TFormInfo::TFormInfo(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
