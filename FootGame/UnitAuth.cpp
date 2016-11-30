//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitAuth.h"
#include "Profile.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFormAuth *FormAuth;
TProfiles Profiles;
TPID PID;
//---------------------------------------------------------------------------
__fastcall TFormAuth::TFormAuth(TComponent* Owner)
	: TForm(Owner)
{
}



string UnicodeToString(UnicodeString us) {
	string result = AnsiString(us.t_str()).c_str();
	return result;
}
//---------------------------------------------------------------------------

void __fastcall TFormAuth::ButtonLoginClick(TObject *Sender)
{
	string username = UnicodeToString(EditUsername->Text);
	PID.value = Profiles.log(username);
	if (PID.value > - 1) {
		string msg = "Вы были успешно авторизированы под ником " + username;
		//FormMenu->LabelUser->Text = username.c_str();
		ShowMessage(msg.c_str());
		PID.out();
	} else {
		string msg = "Пользователя с ником " + username + " не существует. Сперва нужно зарегистрироваться.";
		ShowMessage(msg.c_str());
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormAuth::FormShow(TObject *Sender)
{
	PID.in();
	Profiles.in();
	Label1->Text = ("Всего пользователей: " + ToStr(Profiles.length())).c_str();
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
	profile.Team[0].level = 1;
	profile.Team[0].speed = 5;

	profile.Team[1].name = "Артем";
	profile.Team[1].surname = "Черных";
	profile.Team[1].level = 1;
	profile.Team[1].speed = 5;

	profile.Team[2].name = "Николай";
	profile.Team[2].surname = "Победоносный";
	profile.Team[2].level = 1;
	profile.Team[2].speed = 5;

	if (Profiles.reg(profile)) {
		string msg = "Вы были успешно зарегистрированы под ником " + profile.name;
		ShowMessage(msg.c_str());
	} else {
		string msg = "Пользователя с ником " + profile.name + " уже существует. Можете войти.";
		ShowMessage(msg.c_str());
	}
	Profiles.out();
	Profiles.in();
	Label1->Text = ("Всего пользователей: " + ToStr(Profiles.length())).c_str();
}
//---------------------------------------------------------------------------


void __fastcall TFormAuth::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	PID.out();
	Profiles.out();
	CanClose = true;
}
//---------------------------------------------------------------------------

