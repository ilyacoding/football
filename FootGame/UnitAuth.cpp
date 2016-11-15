//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitAuth.h"
#include "Profile.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFormAuth *FormAuth;
//---------------------------------------------------------------------------
__fastcall TFormAuth::TFormAuth(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormAuth::Button1Click(TObject *Sender)
{
	ofstream db("db.bin", ios_base::binary);
	Profile play;

	play.name = "Ilya";
	play.cash = 5000;
	play.level = 5;
	play.wins = 2;
	play.Team[0].name = "����";
	play.Team[0].surname = "������";
	play.Team[0].level = 8;
	play.Team[0].speed = 5;

	play.Team[1].name = "����";
	play.Team[1].surname = "������";
	play.Team[1].level = 8;
	play.Team[1].speed = 10;

	play.Team[2].name = "����";
	play.Team[2].surname = "������";
	play.Team[2].level = 8;
	play.Team[2].speed = 5;

	play.write(db);
	db.close();

	Profile play2;
	ifstream db2("db.bin", ios_base::binary);
	play2.read(db2);
	Label1->Text = ToStr(play.Team[1].speed).c_str();
}
//---------------------------------------------------------------------------
