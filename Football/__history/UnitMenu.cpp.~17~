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
TDateTime ExpireDate("01.12.2016 15:09:00");
TUdb Udb;
int AmountOfImages = 4;
int NumOfImage = 0;
int x = 5;
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
	SpeedButtonAddLvl->Visible = state;
	SpeedButtonAdd0->Visible = state;
	SpeedButtonAdd1->Visible = state;
	SpeedButtonExit->Visible = state;
	SpeedButtonAdd2->Visible = state;
	CalloutPanelToReg->Visible = !state;
	if (state) {
		FloatAnimationPanelHeight->StopValue = 89;
		FloatAnimationPanelTopHeight->StopValue = 49;
		FloatAnimationStartGameHeight->StopValue = 49;
		FloatAnimationUserNameHeight->StopValue = 25;
	} else {
		FloatAnimationPanelHeight->StopValue = 0;
		FloatAnimationPanelTopHeight->StopValue = 0;
		FloatAnimationStartGameHeight->StopValue = 0;
		FloatAnimationUserNameHeight->StopValue = 0;
	}
	FloatAnimationPanelHeight->Start();
	FloatAnimationPanelTopHeight->Start();
	FloatAnimationStartGameHeight->Start();
	FloatAnimationUserNameHeight->Start();
}

void __fastcall TFormMenu::TimerCheckUserLoginTimer(TObject *Sender)
{
	if (Udb.pid.value > -1)
	{
		LabelUser->Text = ("Добро пожаловать, " + Udb.GetUser(Udb.pid.value).name).c_str();
		LabelCash->Text = ("Деньги: $" + ToStr(Udb.GetUser(Udb.pid.value).cash)).c_str();
		LabelLvl->Text = ("Уровень: " + ToStr(Udb.GetUser(Udb.pid.value).level)).c_str();
		LabelWin->Text = ("Побед: " + ToStr(Udb.GetUser(Udb.pid.value).wins)).c_str();

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
			LabelSpeed->Text = ("Скорость: " + ToStr(Udb.GetUser(Udb.pid.value).Team[i].speed)).c_str();
			LabelLevel->Text = ("Уровень: " + ToStr(Udb.GetUser(Udb.pid.value).Team[i].level)).c_str();
		}
		SetUserVisible(true);
	} else {
		LabelUser->Text = "Войдите или зарегистрируйтесь";
		LabelCash->Text = "";
		LabelLvl->Text = "";
		LabelWin->Text = "";
		SetUserVisible(false);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::FormCreate(TObject *Sender)
{
	MediaPlayerMenu->Play();
	ImageBackground->Bitmap->LoadFromFile(("img/menu/" + ToStr(NumOfImage++) + ".jpg").c_str());
	PanelPlayer0->Width = ToolBarPlayers->Width/3;
	PanelPlayer1->Width = ToolBarPlayers->Width/3;
	PanelPlayer2->Width = ToolBarPlayers->Width/3;

	Udb.in();
	Udb.pid.in();
	Udb.pid.value = -1;
	Udb.pid.out();
	ToolBarPlayers->Height = 0;
	ToolBarTop->Height = 0;

}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	Udb.out();
	CanClose = true;
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::FormResize(TObject *Sender)
{
	PanelPlayer0->Width = ToolBarPlayers->Width/3;
	PanelPlayer1->Width = ToolBarPlayers->Width/3;
	PanelPlayer2->Width = ToolBarPlayers->Width/3;

}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::SpeedButtonProfileClick(TObject *Sender)
{
	FormAuth->ShowModal();
	Udb.in();
	Udb.pid.in();
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::SpeedButtonAboutClick(TObject *Sender)
{
	FormMenu->Hide();
	FormInfo->ShowModal();
	FormMenu->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::SpeedButtonStatsClick(TObject *Sender)
{
	if (Udb.pid.value == -1)
	{
		string msg = "Для просмотра статистики нужно зарегистрироваться.";
		ShowMessage(msg.c_str());
		return;
	}
	Udb.pid.out();
	Udb.out();
	Udb.in();
	Udb.pid.in();
	FormMenu->Hide();
	FormStat->ShowModal();
	FormMenu->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::SpeedButtonProfileMouseEnter(TObject *Sender)
{
	if (!FloatAnimationMouseProfile->Running)
		FloatAnimationMouseProfile->Start();
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::SpeedButtonStatsMouseEnter(TObject *Sender)
{
	if (!FloatAnimationMouseStat->Running)
		FloatAnimationMouseStat->Start();
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::SpeedButtonAboutMouseEnter(TObject *Sender)
{
	if (!FloatAnimationMouseInfo->Running)
		FloatAnimationMouseInfo->Start();
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::SpeedButtonStartGameClick(TObject *Sender)
{
	if (Udb.pid.value == -1)
	{
		string msg = "Перед началом игры нужно зарегистрироваться.";
		ShowMessage(msg.c_str());
		return;
	}
	Udb.pid.out();
	Udb.out();
	FormMenu->Hide();
	FormMain->ShowModal();
	FormMenu->Show();
	Udb.in();
	Udb.pid.in();
	int MoneyToAdd;
	ifstream ss("db/win.bin");
	ss >> MoneyToAdd;
	Udb.AddWin(Udb.pid.value, MoneyToAdd);
	ss.close();
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::SpeedButtonAdd0Click(TObject *Sender)
{
	if (!Udb.BuyLvl(Udb.pid.value, 0))
	{
		string msg = "Недостаточно средств на счету.";
		ShowMessage(msg.c_str());
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::SpeedButtonAdd1Click(TObject *Sender)
{
	if (!Udb.BuyLvl(Udb.pid.value, 1))
	{
		string msg = "Недостаточно средств на счету.";
		ShowMessage(msg.c_str());
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::SpeedButtonAdd2Click(TObject *Sender)
{
 	if (!Udb.BuyLvl(Udb.pid.value, 2))
	{
		string msg = "Недостаточно средств на счету.";
		ShowMessage(msg.c_str());
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::SpeedButtonExitClick(TObject *Sender)
{
	Udb.pid.value = -1;
	Udb.pid.out();
	Udb.pid.in();
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::SpeedButtonAddLvlClick(TObject *Sender)
{
	if (!Udb.BuyAccountLvl(Udb.pid.value))
	{
		string msg = "Недостаточно средств на счету.";
		ShowMessage(msg.c_str());
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::TimerChangePhotoTimer(TObject *Sender)
{
	ImageBackground->Bitmap->LoadFromFile(("img/menu/" + ToStr(NumOfImage) + ".jpg").c_str());
	NumOfImage = (NumOfImage + 1) % AmountOfImages;
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::SpeedButtonAddLvlMouseEnter(TObject *Sender)
{
	if (!FloatAnimationAddLvl->Running)
		FloatAnimationAddLvl->Start();
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::TimerCheckLicenseTimer(TObject *Sender)
{
	IdSNTP1->SyncTime();
	if (IdSNTP1->DateTime > ExpireDate)
	{
		//TimerCheckLicense->Enabled = false;
		throw Exception("License expried.");
		//Application->Terminate();
	}
}
//---------------------------------------------------------------------------

