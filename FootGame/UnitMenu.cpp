//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitAuth.h"
#include "UnitMain.h"
#include "UnitGlobStat.h"
#include "UnitMenu.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.Windows.fmx", _PLAT_MSWINDOWS)
#pragma resource ("*.Surface.fmx", _PLAT_MSWINDOWS)

TFormMenu *FormMenu;
TProfiles Profiles;
TPID PID;

//---------------------------------------------------------------------------
__fastcall TFormMenu::TFormMenu(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormMenu::ToolBarPlayersResize(TObject *Sender)
{
	PanelPlayer1->Width = ToolBarPlayers->Width/3;
	PanelPlayer2->Width = ToolBarPlayers->Width/3;
	PanelPlayer3->Width = ToolBarPlayers->Width/3;
}
//---------------------------------------------------------------------------


void __fastcall TFormMenu::ButtonProfileClick(TObject *Sender)
{
	//Application->CreateForm(TFormAuth, FormAuth);
	FormAuth->ShowModal();
	Profiles.in();
	PID.in();
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ButtonStartGameClick(TObject *Sender)
{
	BallGame->Show();;
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::TimerCheckUserLoginTimer(TObject *Sender)
{
	if (PID.value > -1)
	{
		LabelUser->Text = ("Добро пожаловать, " + Profiles.GetUser(PID.value).name).c_str();
		LabelInfo->Text = ("Уровень: " + ToStr(Profiles.GetUser(PID.value).level) + " | Деньги: $" + ToStr(Profiles.GetUser(PID.value).cash) + " | Победы: " + ToStr(Profiles.GetUser(PID.value).wins)).c_str();
	} else {
		LabelUser->Text = "Войдите или зарегистрируйтесь";
		LabelInfo->Text = "";
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::FormCreate(TObject *Sender)
{
	Profiles.in();
	PID.in();
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	Profiles.out();
	CanClose = true;
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ButtonGlobStatClick(TObject *Sender)
{
	FormGlobStat->ShowModal();
}
//---------------------------------------------------------------------------

