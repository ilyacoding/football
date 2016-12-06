//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitStat.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFormStat *FormStat;
TUdb Udb;

int k = 1;
//---------------------------------------------------------------------------
__fastcall TFormStat::TFormStat(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormStat::FormShow(TObject *Sender)
{
	Udb.in();
	Udb.pid.in();

    ListBox1->Items->Clear();

	string CurrentUser = Udb.GetUser(Udb.pid.value).name;
	Udb.SortForStat();
	ListBox1->Columns = 6;

	ListBox1->Items->Add("Место");
	ListBox1->Items->Add("Игрок");
	ListBox1->Items->Add("Уровень");
	ListBox1->Items->Add("Деньги");
	ListBox1->Items->Add("Уровень команды");
	ListBox1->Items->Add("Победы");

	for (int i = 0; i < Udb.length(); i++)
	{

		ListBox1->Items->Add(("#" + ToStr(k++)).c_str());
		if (Udb.GetUser(i).name == CurrentUser) {
			ListBox1->Items->Add(("> " + Udb.GetUser(i).name).c_str());
		} else {
			ListBox1->Items->Add(Udb.GetUser(i).name.c_str());
		}
		ListBox1->Items->Add(ToStr(Udb.GetUser(i).level).c_str());
		ListBox1->Items->Add(("$" + ToStr(Udb.GetUser(i).cash)).c_str());
		ListBox1->Items->Add(ToStr(Udb.GetUser(i).Team[0].level + Udb.GetUser(i).Team[1].level + Udb.GetUser(i).Team[2].level).c_str());
		ListBox1->Items->Add(ToStr(Udb.GetUser(i).wins).c_str());
	}
}
//---------------------------------------------------------------------------

