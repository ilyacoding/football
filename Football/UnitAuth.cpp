//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitAuth.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
//---------------------------------------------------------------------------
TFormAuth *FormAuth;
TUdb Udb;
//---------------------------------------------------------------------------
__fastcall TFormAuth::TFormAuth(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------
string UnicodeToString(UnicodeString us) {
	string result = AnsiString(us.t_str()).c_str();
	return result;
}

//---------------------------------------------------------------------------
void __fastcall TFormAuth::ButtonLoginClick(TObject *Sender)
{
	string username = UnicodeToString(EditUsername->Text);
	Udb.pid.value = Udb.log(username);
	if (Udb.pid.value > - 1) {
		string msg = "�� ���� ������� �������������� ��� ����� " + username + ".";
		ShowMessage(msg.c_str());
		Udb.pid.out();
	} else {
		string msg = "������������ � ����� " + username + " �� ����������. ������ ����� ������������������.";
		ShowMessage(msg.c_str());
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormAuth::FormShow(TObject *Sender)
{
	Udb.pid.in();
	Udb.in();
	Label1->Text = ("����� �������������: " + ToStr(Udb.length())).c_str();
}
//---------------------------------------------------------------------------

void __fastcall TFormAuth::ButtonRegisterClick(TObject *Sender)
{
	TProfile profile;
	profile.name = UnicodeToString(EditUsername->Text);
	profile.level = 0;
	profile.cash = 3000;
	profile.wins = 0;
	profile.Team[0].name = "����";
	profile.Team[0].surname = "��������";
	profile.Team[0].level = 0;
	profile.Team[0].speed = 2;

	profile.Team[1].name = "����";
	profile.Team[1].surname = "������";
	profile.Team[1].level = 0;
	profile.Team[1].speed = 2;

	profile.Team[2].name = "�������";
	profile.Team[2].surname = "������������";
	profile.Team[2].level = 0;
	profile.Team[2].speed = 2;

	if (Udb.reg(profile)) {
		string msg = "�� ���� ������� ���������������� ��� ����� " + profile.name + ".";
		ShowMessage(msg.c_str());
	} else {
		string msg = "������������ � ����� " + profile.name + " ��� ����������. ������ �����.";
		ShowMessage(msg.c_str());
	}
	Udb.out();
	Udb.in();
	Label1->Text = ("����� �������������: " + ToStr(Udb.length()) + ".").c_str();
}
//---------------------------------------------------------------------------


void __fastcall TFormAuth::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	Udb.pid.out();
	Udb.out();
	CanClose = true;
}
//---------------------------------------------------------------------------

void __fastcall TFormAuth::EditUsernameKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift)
{
	if (KeyChar == 8) {
		ShowMessage("Good");
	}
}
//---------------------------------------------------------------------------

