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
//---------------------------------------------------------------------------
TFormMenu *FormMenu;
TUdb Udb;
//---------------------------------------------------------------------------
__fastcall TFormMenu::TFormMenu(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TFormMenu::ButtonProfileClick(TObject *Sender)
{
	FormAuth->ShowModal();
	Udb.in();
	Udb.pid.in();
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ButtonStartGameClick(TObject *Sender)
{
	if (Udb.pid.value == -1)
	{
		string msg = "����� ������� ���� ����� ������������������.";
		ShowMessage(msg.c_str());
		return;
	}
	Udb.pid.out();
	Udb.out();
	FormMain->ShowModal();
	Udb.in();
	Udb.pid.in();
	int MoneyToAdd;
	ifstream ss("db/win.bin");
	ss >> MoneyToAdd;
	Udb.AddWin(Udb.pid.value, MoneyToAdd);
	ss.close();
}
//---------------------------------------------------------------------------
void __fastcall TFormMenu::SetUserVisible(bool state)
{
	ImageUser0->Visible = state;
	ImageUser1->Visible = state;
	ImageUser2->Visible = state;
	LabelName0->Visible = state;
	LabelSpeed0->Visible = state;
	LabelLevel0->Visible = state;
	LabelName1->Visible = state;
	LabelSpeed1->Visible = state;
	LabelLevel1->Visible = state;
	LabelName2->Visible = state;
	LabelSpeed2->Visible = state;
	LabelLevel2->Visible = state;
	ButtonAddLvl->Visible = state;
	ButtonAdd0->Visible = state;
	ButtonAdd1->Visible = state;
	ButtonAdd2->Visible = state;
}

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
		SetUserVisible(true);
	} else {
		LabelUser->Text = "������� ��� �����������������";
		LabelCash->Text = "";
		LabelLvl->Text = "";
		LabelWin->Text = "";
		SetUserVisible(false);
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
	if (Udb.pid.value == -1)
	{
		string msg = "��� ��������� ���������� ����� ������������������.";
		ShowMessage(msg.c_str());
		return;
	}
	Udb.pid.out();
	Udb.out();
	Udb.in();
	Udb.pid.in();
	FormStat->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ButtonInfoClick(TObject *Sender)
{
	FormInfo->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ButtonAdd0Click(TObject *Sender)
{
	if (!Udb.BuyLvl(Udb.pid.value, 0))
	{
		string msg = "������������ ������� �� �����.";
		ShowMessage(msg.c_str());
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ButtonAdd1Click(TObject *Sender)
{
	if (!Udb.BuyLvl(Udb.pid.value, 1))
	{
		string msg = "������������ ������� �� �����.";
		ShowMessage(msg.c_str());
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ButtonAdd2Click(TObject *Sender)
{
	if (!Udb.BuyLvl(Udb.pid.value, 2))
	{
		string msg = "������������ ������� �� �����.";
		ShowMessage(msg.c_str());
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ButtonAddLvlClick(TObject *Sender)
{
	if (!Udb.BuyAccountLvl(Udb.pid.value))
	{
		string msg = "������������ ������� �� �����.";
		ShowMessage(msg.c_str());
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ButtonExitClick(TObject *Sender)
{
	Udb.pid.value = -1;
	Udb.pid.out();
	Udb.pid.in();
}
//---------------------------------------------------------------------------

