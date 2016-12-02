//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitMain.h"
#include "ClassTField.h"
#include "ClassTGame.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.Surface.fmx", _PLAT_MSWINDOWS)

// Константы, важные объявления
TFormMain *FormMain;
TField Field;
TGame Game;
UnicodeString Host;
const int MainID = 1;
const int SecondID = 1 - MainID;

double GoalKeeperDelta[2] = { (double)88/1062, (double)(1062 - 88)/1062};
double AttackerDelta[2] = { (double)472/1062, (double)(1062 - 472)/1062};
double DefenderDelta[2] = { (double)340/1062, (double)(1062 - 340)/1062};
double BallDelta[2] = { (double)182/1062, (double)(1062 - 182)/1062};
// Константы, важные объявления

//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TFormMain::InitField()
{
	// Background Start
	Field.Background = ImageBackground;
	Field.Background->Bitmap->LoadFromFile("img/field.jpg");
	// Background end

	// Ball Start
	Field.Ball.CBall = Ball;
	Field.Ball.Speed = 0;
	Field.Ball.Degree = 0;
	Field.Ball.CBall->Position->X = (PanelPlayArea->Width - Field.Ball.CBall->Width)/2;
	Field.Ball.CBall->Position->Y = (PanelPlayArea->Height - Field.Ball.CBall->Height)/2;
	// Ball end

	// Players Start
	// - Team0 (Robotics)
	Field.Team[0].AddPlayer((GoalKeeperDelta[0]*PanelPlayArea->Width) - PlayerSize/2, (PanelPlayArea->Height - PlayerSize)/2, 'b');
	Field.Team[0].AddPlayer((AttackerDelta[0]*PanelPlayArea->Width) - PlayerSize/2, (PanelPlayArea->Height - PlayerSize)/2, 'b');
	Field.Team[0].AddPlayer((DefenderDelta[0]*PanelPlayArea->Width) - PlayerSize/2, (PanelPlayArea->Height - PlayerSize)/2, 'b');
	// - Team1 (Main)
	Field.Team[1].AddPlayer((GoalKeeperDelta[1]*PanelPlayArea->Width) - PlayerSize/2, (PanelPlayArea->Height - PlayerSize)/2, 'o');
	Field.Team[1].AddPlayer((AttackerDelta[1]*PanelPlayArea->Width) - PlayerSize/2, (PanelPlayArea->Height - PlayerSize)/2, 'o');
	Field.Team[1].AddPlayer((DefenderDelta[1]*PanelPlayArea->Width) - PlayerSize/2, (PanelPlayArea->Height - PlayerSize)/2, 'o');
	// Players end

	// Timers Start
	TimerMoveBall->Enabled = true;
	TimerMoveUser->Enabled = true;
	TimerCheckBall->Enabled = true;
	// Timers end
}

void __fastcall TFormMain::DestroyField()
{
	// Players Start
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Field.Team[i].DeletePlayer(j);
        }
    }
	// Players end

	// Timers Start
	TimerMoveBall->Enabled = false;
	TimerMoveUser->Enabled = false;
	TimerCheckBall->Enabled = false;
	// Timers end
}

//---------------------------------------------------------------------------
void __fastcall TFormMain::TimerMoveUserTimer(TObject *Sender)
{
	for (int TID = 0; TID < 1; TID++)
	{
		if (Field.CalcDistance(Field.Team[TID].Player[Field.Team[TID].CurrPlayer].Img->Position->X + Field.Team[TID].Player[Field.Team[TID].CurrPlayer].Img->Width/2, Field.Team[TID].Player[Field.Team[TID].CurrPlayer].Img->Position->Y + Field.Team[TID].Player[Field.Team[TID].CurrPlayer].Img->Height/2, Field.Team[TID].Player[Field.Team[TID].CurrPlayer].mouseX, Field.Team[TID].Player[Field.Team[TID].CurrPlayer].mouseY) > 3)
		{
			float Degree = Field.CalcDegree(Field.Team[TID].Player[Field.Team[TID].CurrPlayer].Img->Position->X + Field.Team[TID].Player[Field.Team[TID].CurrPlayer].Img->Width/2, Field.Team[TID].Player[Field.Team[TID].CurrPlayer].Img->Position->Y + Field.Team[TID].Player[Field.Team[TID].CurrPlayer].Img->Height/2, Field.Team[TID].Player[Field.Team[TID].CurrPlayer].mouseX, Field.Team[TID].Player[Field.Team[TID].CurrPlayer].mouseY);
			for (int j = 0; j <= Field.Team[TID].Player[Field.Team[TID].CurrPlayer].Speed; j++)
			{
				Field.Team[TID].Player[Field.Team[TID].CurrPlayer].Img->Position->X += (cos(Degree * pi / 180) * 1);
				Field.Team[TID].Player[Field.Team[TID].CurrPlayer].Img->Position->Y -= (sin(Degree * pi / 180) * 1);

				Field.Team[TID].Player[Field.Team[TID].CurrPlayer].Txt->Position->X += (cos(Degree * pi / 180) * 1);
				Field.Team[TID].Player[Field.Team[TID].CurrPlayer].Txt->Position->Y -= (sin(Degree * pi / 180) * 1);
				ImageBackground->Repaint();
			}
		}
	}
}

//---------------------------------------------------------------------------

void __fastcall TFormMain::TimerMoveBallTimer(TObject *Sender)
{
	if (Field.Ball.Speed > 0)
	{
		for (int i = 0; i < (Field.Ball.Speed - Field.Ball.Accelerate); i++)
		{
			if (!((cos(int(Field.Ball.Degree) * pi / 180) * 1) + Ball->Position->X + Ball->Width/2 < ImageBackground->Width) || !((cos(int(Field.Ball.Degree) * pi / 180) * 1) + Ball->Position->X + Ball->Width/2 > 0))
			{
				// Отражение на 180
				Field.Ball.Degree = 180 - Field.Ball.Degree;
				Field.Ball.Speed *= 0.8;
			}
			Ball->Position->X += (cos(Field.Ball.Degree * pi / 180) * 1);
			if (!(Ball->Position->Y + Ball->Height/2 - (sin(int(Field.Ball.Degree) * pi / 180) * 1) < ImageBackground->Height) || !(Ball->Position->Y + Ball->Height/2 - (sin(int(Field.Ball.Degree) * pi / 180) * 1) > 0))
			{
				// Отражение на 180
				Field.Ball.Degree = (180 - Field.Ball.Degree) * 2 + Field.Ball.Degree;
				Field.Ball.Speed *= 0.8;
			}
			Ball->Position->Y -= (sin(Field.Ball.Degree * pi / 180) * 1);
			Ball->RotationAngle += 2 * ((cos(Field.Ball.Degree * pi / 180) * 1) - (sin(Field.Ball.Degree * pi / 180) * 1));
			Field.Ball.Speed -= Field.Ball.Accelerate;
			Field.Background->Repaint();
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::FormKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
		  TShiftState Shift)
{
	Label1->Text = KeyChar;

	// Обработка удара Team0
	if (isalpha(KeyChar))
	{
		double dWidth = Field.Team[SecondID].Player[Field.Team[SecondID].CurrPlayer].Img->Width/2;
		double dHeight = Field.Team[SecondID].Player[Field.Team[SecondID].CurrPlayer].Img->Height/2;
		double dX = Field.Team[SecondID].Player[Field.Team[SecondID].CurrPlayer].Img->Position->X;
		double dY = Field.Team[SecondID].Player[Field.Team[SecondID].CurrPlayer].Img->Position->Y;
		int dSpeed;

		(Shift.Contains(System_Classes__1::ssShift)) ? (dSpeed = 5) : (dSpeed = 2);

		switch (KeyChar) {
			case 'w': case 'W':
				Field.Team[SecondID].Player[Field.Team[SecondID].CurrPlayer].mouseX = dX + dWidth + 0.001;
				Field.Team[SecondID].Player[Field.Team[SecondID].CurrPlayer].mouseY = 2;
				Field.Team[SecondID].Player[Field.Team[SecondID].CurrPlayer].Speed = dSpeed;
			break;

			case 's': case 'S':
				Field.Team[SecondID].Player[Field.Team[SecondID].CurrPlayer].mouseX = dX + dWidth + 0.001;
				Field.Team[SecondID].Player[Field.Team[SecondID].CurrPlayer].mouseY = ImageBackground->Height;
				Field.Team[SecondID].Player[Field.Team[SecondID].CurrPlayer].Speed = dSpeed;
			break;

			case 'a': case 'A':
				Field.Team[SecondID].Player[Field.Team[SecondID].CurrPlayer].mouseX = 2;
				Field.Team[SecondID].Player[Field.Team[SecondID].CurrPlayer].mouseY = dY + dHeight + 0.001;
				Field.Team[SecondID].Player[Field.Team[SecondID].CurrPlayer].Speed = dSpeed;
			break;

			case 'd': case 'D':
				Field.Team[SecondID].Player[Field.Team[SecondID].CurrPlayer].mouseX = ImageBackground->Width;
				Field.Team[SecondID].Player[Field.Team[SecondID].CurrPlayer].mouseY = dY + dHeight + 0.001;
				Field.Team[SecondID].Player[Field.Team[SecondID].CurrPlayer].Speed = dSpeed;
			break;

			case 'q': case 'Q':
            	Field.Team[SecondID].Player[Field.Team[SecondID].CurrPlayer].Speed = 0;
			break;
		}

	} else if (isdigit(KeyChar)) {
		KeyChar -= '0';
		switch(KeyChar) {
			case 1: case 2: case 3:
				if (KeyChar - 1 == Field.Team[MainID].CurrPlayer) {
					if ((Field.CalcDistance(Ball->Width/2 + Ball->Position->X, Ball->Height/2 + Ball->Position->Y, Field.Team[MainID].Player[Field.Team[MainID].CurrPlayer].Img->Position->X + Field.Team[MainID].Player[Field.Team[MainID].CurrPlayer].Img->Width/2, Field.Team[MainID].Player[Field.Team[MainID].CurrPlayer].Img->Position->Y + Field.Team[MainID].Player[Field.Team[MainID].CurrPlayer].Img->Height/2) <= Field.Team[MainID].Player[Field.Team[MainID].CurrPlayer].Img->Height)) {
						Field.Ball.Speed += 3;
						Field.Ball.Degree = Field.CalcDegree(Field.Team[MainID].Player[Field.Team[MainID].CurrPlayer].Img->Width/2 + Field.Team[MainID].Player[Field.Team[MainID].CurrPlayer].Img->Position->X, Field.Team[MainID].Player[Field.Team[MainID].CurrPlayer].Img->Height/2 + Field.Team[MainID].Player[Field.Team[MainID].CurrPlayer].Img->Position->Y, Ball->Width/2 + Ball->Position->X, Ball->Height/2 + Ball->Position->Y);
					}
				}
				Field.Team[MainID].Player[Field.Team[MainID].CurrPlayer].Speed = 2;
				Field.Team[MainID].CurrPlayer = KeyChar - 1;
			break;

			case 7: case 8: case 9:
				if (KeyChar - 7 == Field.Team[SecondID].CurrPlayer) {
					if ((Field.CalcDistance(Ball->Width/2 + Ball->Position->X, Ball->Height/2 + Ball->Position->Y, Field.Team[SecondID].Player[Field.Team[SecondID].CurrPlayer].Img->Position->X + Field.Team[SecondID].Player[Field.Team[SecondID].CurrPlayer].Img->Width/2, Field.Team[SecondID].Player[Field.Team[SecondID].CurrPlayer].Img->Position->Y + Field.Team[SecondID].Player[Field.Team[SecondID].CurrPlayer].Img->Height/2) <= Field.Team[SecondID].Player[Field.Team[SecondID].CurrPlayer].Img->Height)) {
						Field.Ball.Speed += 3;
						Field.Ball.Degree = Field.CalcDegree(Field.Team[SecondID].Player[Field.Team[SecondID].CurrPlayer].Img->Width/2 + Field.Team[SecondID].Player[Field.Team[SecondID].CurrPlayer].Img->Position->X, Field.Team[SecondID].Player[Field.Team[SecondID].CurrPlayer].Img->Height/2 + Field.Team[SecondID].Player[Field.Team[SecondID].CurrPlayer].Img->Position->Y, Ball->Width/2 + Ball->Position->X, Ball->Height/2 + Ball->Position->Y);
					}
				}
				Field.Team[SecondID].Player[Field.Team[SecondID].CurrPlayer].Speed = 2;
				Field.Team[SecondID].CurrPlayer = KeyChar - 7;
			break;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::PanelPlayAreaMouseMove(TObject *Sender, TShiftState Shift, float X,
		  float Y)
{
	Field.Team[MainID].Player[Field.Team[MainID].CurrPlayer].mouseX = X;
	Field.Team[MainID].Player[Field.Team[MainID].CurrPlayer].mouseY = Y;
	Field.Team[MainID].Player[Field.Team[MainID].CurrPlayer].Speed = 5;

}
//---------------------------------------------------------------------------

void __fastcall TFormMain::TimerCheckBallTimer(TObject *Sender)
{
	// Проверка на ГОЛ

	// Проверка на выход из поля

	if ((Field.Ball.CBall->Width/2 + Field.Ball.CBall->Position->X) < (56*PanelPlayArea->Width/1062))
	{
		Field.Ball.CBall->Position->X = BallDelta[0]*PanelPlayArea->Width - Field.Ball.CBall->Width/2;
		Field.Ball.CBall->Position->Y = PanelPlayArea->Height/2 - Field.Ball.CBall->Height/2;
		Field.Ball.Speed = 0;
		Field.Ball.Degree = 0;
		TimerMoveUser->Enabled = false;
		Field.Team[0].DeletePlayer(0);
		Field.Team[0].AddPlayer((GoalKeeperDelta[0]*PanelPlayArea->Width) - PlayerSize/2, (PanelPlayArea->Height - PlayerSize)/2, 'b');
		TimerMoveUser->Enabled = true;
		return;
	} else if ((Field.Ball.CBall->Width/2 + Field.Ball.CBall->Position->X) > ((1062-56)*PanelPlayArea->Width/1062))
	{
		Field.Ball.CBall->Position->X = BallDelta[1]*PanelPlayArea->Width - Field.Ball.CBall->Width/2;
		Field.Ball.CBall->Position->Y = PanelPlayArea->Height/2 - Field.Ball.CBall->Height/2;
		Field.Ball.Speed = 0;
		Field.Ball.Degree = 0;
		TimerMoveUser->Enabled = false;
		Field.Team[1].DeletePlayer(0);
		Field.Team[1].AddPlayer((GoalKeeperDelta[1]*PanelPlayArea->Width) - PlayerSize/2, (PanelPlayArea->Height - PlayerSize)/2, 'o');
		TimerMoveUser->Enabled = true;
		return;
    }

	// Проверка на столкновение с игроком
	for (int i = 0; i < 2; i++)
	{
		TImage* TestPlayer;
		for (int j = 0; j < 3; j++) {
			TestPlayer = Field.Team[i].Player[j].Img;
			if (sqrt(((Ball->Height/2 + Ball->Position->Y) - (TestPlayer->Height/2 + TestPlayer->Position->Y))*((Ball->Height/2 + Ball->Position->Y) - (TestPlayer->Height/2 + TestPlayer->Position->Y)) + ((Ball->Width/2 + Ball->Position->X) - (TestPlayer->Width/2 + TestPlayer->Position->X))*((Ball->Width/2 + Ball->Position->X) - (TestPlayer->Width/2 + TestPlayer->Position->X))) <= TestPlayer->Width/4) {
				Field.Ball.Speed = 0;
				return;
			}
		}        // 182 274
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::FormShow(TObject *Sender)
{
	InitField();
}
//---------------------------------------------------------------------------


void __fastcall TFormMain::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	DestroyField();
}

//---------------------------------------------------------------------------

