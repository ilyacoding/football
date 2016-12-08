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
		string msg = "Вы были успешно авторизированы под ником " + username + ".";
		ShowMessage(msg.c_str());
		Udb.pid.out();
	} else {
		string msg = "Пользователя с ником " + username + " не существует. Сперва нужно зарегистрироваться.";
		ShowMessage(msg.c_str());
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormAuth::FormShow(TObject *Sender)
{
	Udb.pid.in();
	Udb.in();
	Label1->Text = ("Всего пользователей: " + ToStr(Udb.length())).c_str();
}
//---------------------------------------------------------------------------

void __fastcall TFormAuth::ButtonRegisterClick(TObject *Sender)
{
	TProfile profile;
	profile.name = UnicodeToString(EditUsername->Text);
	profile.level = 0;
	profile.cash = 3000;
	profile.wins = 0;
	profile.Team[0].name = "Иван";
	profile.Team[0].surname = "Петрович";
	profile.Team[0].level = 0;
	profile.Team[0].speed = 2;

	profile.Team[1].name = "Артём";
	profile.Team[1].surname = "Черных";
	profile.Team[1].level = 0;
	profile.Team[1].speed = 2;

	profile.Team[2].name = "Николай";
	profile.Team[2].surname = "Победоносный";
	profile.Team[2].level = 0;
	profile.Team[2].speed = 2;

	if (Udb.reg(profile)) {
		string msg = "Вы были успешно зарегистрированы под ником " + profile.name + ".";
		ShowMessage(msg.c_str());
	} else {
		string msg = "Пользователя с ником " + profile.name + " уже существует. Можете войти.";
		ShowMessage(msg.c_str());
	}
	Udb.out();
	Udb.in();
	Label1->Text = ("Всего пользователей: " + ToStr(Udb.length()) + ".").c_str();
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

