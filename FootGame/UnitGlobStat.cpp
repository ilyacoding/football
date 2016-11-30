//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitGlobStat.h"
#include "Profile.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFormGlobStat *FormGlobStat;
TProfiles Profiles;
TPID PID;
//---------------------------------------------------------------------------
__fastcall TFormGlobStat::TFormGlobStat(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormGlobStat::FormCreate(TObject *Sender)
{
	Profiles.in();
	ListBox1->Columns = 5;

	ListBox1->Items->Add("Игрок");
	ListBox1->Items->Add("Уровень");
	ListBox1->Items->Add("Деньги");
	ListBox1->Items->Add("Уровень команды");
	ListBox1->Items->Add("Победы");

	for (int i = 0; i < Profiles.length(); i++)
	{
		ListBox1->Items->Add(Profiles.GetUser(i).name.c_str());
		ListBox1->Items->Add(ToStr(Profiles.GetUser(i).level).c_str());
		ListBox1->Items->Add(("$" + ToStr(Profiles.GetUser(i).cash)).c_str());
		ListBox1->Items->Add(ToStr(Profiles.GetUser(i).Team[0].level + Profiles.GetUser(i).Team[1].level + Profiles.GetUser(i).Team[2].level).c_str());
		ListBox1->Items->Add(ToStr(Profiles.GetUser(i).wins).c_str());
	}

}
//---------------------------------------------------------------------------

