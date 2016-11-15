//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitMenu.h"
#include "UnitAuth.h"
#include "Profile.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
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

	FormAuth->Show();
}
//---------------------------------------------------------------------------

