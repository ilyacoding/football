//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitMenu.h"
#include "UnitAuth.h"
#include "UnitMain.h"
#include "UnitStat.h"
#include "UnitInfo.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.Windows.fmx", _PLAT_MSWINDOWS)
#pragma resource ("*.Surface.fmx", _PLAT_MSWINDOWS)

TFormMenu *FormMenu;
TUdb Udb;

//---------------------------------------------------------------------------
__fastcall TFormMenu::TFormMenu(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormMenu::ToolBarPlayersResize(TObject *Sender)
{
	PanelPlayer0->Width = ToolBarPlayers->Width/3;
	PanelPlayer1->Width = ToolBarPlayers->Width/3;
	PanelPlayer2->Width = ToolBarPlayers->Width/3;
}
//---------------------------------------------------------------------------


void __fastcall TFormMenu::ButtonProfileClick(TObject *Sender)
{
	//Application->CreateForm(TFormAuth, FormAuth);
	FormAuth->ShowModal();
	Udb.in();
	Udb.pid.in();
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ButtonStartGameClick(TObject *Sender)
{
	FormMain->ShowModal();
	int MoneyToAdd;
	ifstream ss("db/win.bin");
	ss >> MoneyToAdd;
	Udb.AddWin(Udb.pid.value, MoneyToAdd);
	ss.close();
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::TimerCheckUserLoginTimer(TObject *Sender)
{
	if (Udb.pid.value > -1)
	{
		LabelUser->Text = ("����� ����������, " + Udb.GetUser(Udb.pid.value).name).c_str();
		LabelCash->Text = ("������: $" + ToStr(Udb.GetUser(Udb.pid.value).cash)).c_str();
		LabelLvl->Text = ("�������: " + ToStr(Udb.GetUser(Udb.pid.value).level)).c_str();
		LabelWin->Text = ("�����: " + ToStr(Udb.GetUser(Udb.pid.value).wins)).c_str();

		for (int i = 0; i < 3; i++)
		{
			TImage* Img;
			TLabel* LabelName;
			TLabel* LabelSpeed;
			TLabel* LabelLevel;
			switch(i)
			{
				case 0:
					Img = ImageUser0;
					LabelName = LabelName0;
					LabelSpeed = LabelSpeed0;
					LabelLevel = LabelLevel0;
				break;
				case 1:
					Img = ImageUser1;
					LabelName = LabelName1;
					LabelSpeed = LabelSpeed1;
					LabelLevel = LabelLevel1;
				break;
				case 2:
					Img = ImageUser2;
					LabelName = LabelName2;
					LabelSpeed = LabelSpeed2;
					LabelLevel = LabelLevel2;
				break;
			}
			Img->Bitmap->LoadFromFile("img/user.png");
			LabelName->Text = (Udb.GetUser(Udb.pid.value).Team[i].name + " " + Udb.GetUser(Udb.pid.value).Team[i].surname).c_str();
			LabelSpeed->Text = ("��������: " + ToStr(Udb.GetUser(Udb.pid.value).Team[i].speed)).c_str();
			LabelLevel->Text = ("�������: " + ToStr(Udb.GetUser(Udb.pid.value).Team[i].level)).c_str();

        }

	} else {
		LabelUser->Text = "������� ��� �����������������";
		LabelCash->Text = "";
		LabelLvl->Text = "";
		LabelWin->Text = "";
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::FormCreate(TObject *Sender)
{
	ImageBackground->Bitmap->LoadFromFile("img/menu-bg.jpg");
	PanelPlayer0->Width = ToolBarPlayers->Width/3;
	PanelPlayer1->Width = ToolBarPlayers->Width/3;
	PanelPlayer2->Width = ToolBarPlayers->Width/3;

	Udb.in();
	Udb.pid.in();
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	Udb.out();
	CanClose = true;
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ButtonGlobStatClick(TObject *Sender)
{
	FormStat->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ButtonInfoClick(TObject *Sender)
{
	FormInfo->ShowModal();
}
//---------------------------------------------------------------------------

