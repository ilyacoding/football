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

// ���������, ������ ����������
TFormMain *FormMain;
TField Field;
TGame Game;
UnicodeString Host;

double GoalKeeperDelta[2] = { (double)88/1062, (double)(1062 - 88)/1062};
double AttackerDelta[2] = { (double)472/1062, (double)(1062 - 472)/1062};
double DefenderDelta[2] = { (double)340/1062, (double)(1062 - 340)/1062};
// ���������, ������ ����������

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
	Field.Team[0].AddPlayer((GoalKeeperDelta[0]*PanelPlayArea->Width) - PlayerSize/2, (PanelPlayArea->Height - PlayerSize)/2, 'r');
	Field.Team[0].AddPlayer((AttackerDelta[0]*PanelPlayArea->Width) - PlayerSize/2, (PanelPlayArea->Height - PlayerSize)/2, 'r');
	Field.Team[0].AddPlayer((DefenderDelta[0]*PanelPlayArea->Width) - PlayerSize/2, (PanelPlayArea->Height - PlayerSize)/2, 'r');
	// - Team1 (Main)
	Field.Team[1].AddPlayer((GoalKeeperDelta[1]*PanelPlayArea->Width) - PlayerSize/2, (PanelPlayArea->Height - PlayerSize)/2, 'r');
	Field.Team[1].AddPlayer((AttackerDelta[1]*PanelPlayArea->Width) - PlayerSize/2, (PanelPlayArea->Height - PlayerSize)/2, 'r');
	Field.Team[1].AddPlayer((DefenderDelta[1]*PanelPlayArea->Width) - PlayerSize/2, (PanelPlayArea->Height - PlayerSize)/2, 'r');
	// Players end

	// Timers Start
	TimerMoveBall->Enabled = true;
	//TimerMoveUser->Enabled = true;
	TimerStopBall->Enabled = true;
	// Timers end
}

//---------------------------------------------------------------------------
void __fastcall TFormMain::TimerMoveUserTimer(TObject *Sender)
{
	if (Field.CalcDistance(Field.Team[0].Player[Field.Team[0].CurrPlayer].Img->Position->X + Field.Team[0].Player[Field.Team[0].CurrPlayer].Img->Width/2, Field.Team[0].Player[Field.Team[0].CurrPlayer].Img->Position->Y + Field.Team[0].Player[Field.Team[0].CurrPlayer].Img->Height/2, Field.Team[0].Player[Field.Team[0].CurrPlayer].mouseX, Field.Team[0].Player[Field.Team[0].CurrPlayer].mouseY) > 3)
	{
		float Degree = Field.CalcDegree(Field.Team[0].Player[Field.Team[0].CurrPlayer].Img->Position->X + Field.Team[0].Player[Field.Team[0].CurrPlayer].Img->Width/2, Field.Team[0].Player[Field.Team[0].CurrPlayer].Img->Position->Y + Field.Team[0].Player[Field.Team[0].CurrPlayer].Img->Height/2, Field.Team[0].Player[Field.Team[0].CurrPlayer].mouseX, Field.Team[0].Player[Field.Team[0].CurrPlayer].mouseY);
		for (int j = 0; j <= Field.Team[0].Player[Field.Team[0].CurrPlayer].Speed; j++)
		{
			Field.Team[0].Player[Field.Team[0].CurrPlayer].Img->Position->X += (cos(Degree * pi / 180) * 1);
			Field.Team[0].Player[Field.Team[0].CurrPlayer].Img->Position->Y -= (sin(Degree * pi / 180) * 1);

			Field.Team[0].Player[Field.Team[0].CurrPlayer].Txt->Position->X += (cos(Degree * pi / 180) * 1);
			Field.Team[0].Player[Field.Team[0].CurrPlayer].Txt->Position->Y -= (sin(Degree * pi / 180) * 1);
            Field.Background->Repaint();
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
				// ��������� �� 180
				Field.Ball.Degree = 180 - Field.Ball.Degree;
				Field.Ball.Speed *= 0.8;
			}
			Ball->Position->X += (cos(Field.Ball.Degree * pi / 180) * 1);
			if (!(Ball->Position->Y + Ball->Height/2 - (sin(int(Field.Ball.Degree) * pi / 180) * 1) < ImageBackground->Height) || !(Ball->Position->Y + Ball->Height/2 - (sin(int(Field.Ball.Degree) * pi / 180) * 1) > 0))
			{
				// ��������� �� 180
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
	if ((KeyChar == 'w') && (Field.CalcDistance(Ball->Width/2 + Ball->Position->X, Ball->Height/2 + Ball->Position->Y, Field.Team[0].Player[Field.Team[0].CurrPlayer].Img->Position->X + Field.Team[0].Player[Field.Team[0].CurrPlayer].Img->Width/2, Field.Team[0].Player[Field.Team[0].CurrPlayer].Img->Position->Y + Field.Team[0].Player[Field.Team[0].CurrPlayer].Img->Height/2) <= Field.Team[0].Player[Field.Team[0].CurrPlayer].Img->Height)) {
		Field.Ball.Speed += 3;
		Field.Ball.Degree = Field.CalcDegree(Field.Team[0].Player[Field.Team[0].CurrPlayer].Img->Width/2 + Field.Team[0].Player[Field.Team[0].CurrPlayer].Img->Position->X, Field.Team[0].Player[Field.Team[0].CurrPlayer].Img->Height/2 + Field.Team[0].Player[Field.Team[0].CurrPlayer].Img->Position->Y, Ball->Width/2 + Ball->Position->X, Ball->Height/2 + Ball->Position->Y);
	} else if (isdigit(KeyChar) && (KeyChar - '0' <= 3)) {
		Field.Team[0].Player[Field.Team[0].CurrPlayer].Speed = 2;
		Field.Team[0].CurrPlayer = KeyChar - '0' - 1;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::PanelPlayAreaMouseMove(TObject *Sender, TShiftState Shift, float X,
		  float Y)
{
	Field.Team[0].Player[Field.Team[0].CurrPlayer].mouseX = X;
	Field.Team[0].Player[Field.Team[0].CurrPlayer].mouseY = Y;
	Field.Team[0].Player[Field.Team[0].CurrPlayer].Speed = 5;
	Label2->Text = ToStr(X).c_str();
	Label3->Text = ToStr(Y).c_str();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::TimerStopBallTimer(TObject *Sender)
{
	TImage* TestPlayer;
	for (int i = 0; i < 3; i++) {
		TestPlayer = Field.Team[0].Player[i].Img;
		if (sqrt(((Ball->Height/2 + Ball->Position->Y) - (TestPlayer->Height/2 + TestPlayer->Position->Y))*((Ball->Height/2 + Ball->Position->Y) - (TestPlayer->Height/2 + TestPlayer->Position->Y)) + ((Ball->Width/2 + Ball->Position->X) - (TestPlayer->Width/2 + TestPlayer->Position->X))*((Ball->Width/2 + Ball->Position->X) - (TestPlayer->Width/2 + TestPlayer->Position->X))) <= TestPlayer->Width/4) {
			Field.Ball.Speed = 0;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::FormShow(TObject *Sender)
{
	InitField();


}
//---------------------------------------------------------------------------

