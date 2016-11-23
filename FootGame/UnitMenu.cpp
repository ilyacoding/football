//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitMain.h"
#include "UnitMenu.h"
#include "UnitAuth.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.Windows.fmx", _PLAT_MSWINDOWS)
#pragma resource ("*.Surface.fmx", _PLAT_MSWINDOWS)

TFormMenu *FormMenu;

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
	FormAuth->Show();;
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ButtonStartGameClick(TObject *Sender)
{
	BallGame->Show();;
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::TimerCheckUserLoginTimer(TObject *Sender)
{
	if (PID > -1)
	{
		LabelUser->Text = ("����� ����������, " + Profiles.GetUser(PID).name).c_str();
		LabelInfo->Text = ("�������: " + ToStr(Profiles.GetUser(PID).level) + " | ������: $" + ToStr(Profiles.GetUser(PID).cash) + " | ������: " + ToStr(Profiles.GetUser(PID).wins)).c_str();
	} else {
		LabelUser->Text = "������� ��� �����������������";
		LabelInfo->Text = "";
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::FormCreate(TObject *Sender)
{
	PID = -1;
	FormMenu->Profiles.in();
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	FormMenu->Profiles.out();
	CanClose = true;
}
//---------------------------------------------------------------------------
