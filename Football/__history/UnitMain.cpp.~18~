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
TUdb Udb;
TGame Game;
const int MainID = 1;
const int SecondID = 1 - MainID;

int DefSpeed[3];
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

//---------------------------------------------------------------------------
void __fastcall TFormMain::InitTimer(int Count)
{
	Game.TimerCount = Count;
	Game.CanMove = false;
	TimerCountDown->Enabled = true;
}

//---------------------------------------------------------------------------
void __fastcall TFormMain::PrintCount()
{
	LabelCount->Text = (ToStr(Game.Count[0]) + ":" + ToStr(Game.Count[1])).c_str();
}

//---------------------------------------------------------------------------
void __fastcall TFormMain::InitField()
{
	InitTimer(5);
	PrintCount();

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
	// Curr
	Field.Team[0].CurrPlayer = 1;
	Field.Team[1].CurrPlayer = 1;
	// Players end

	// Timers Start
	TimerMoveBall->Enabled = true;
	TimerMoveUser->Enabled = true;
	TimerMoveAI->Enabled = true;
	TimerCheckBall->Enabled = true;
	TimerAI->Enabled = true;
	// Timers end
}

//---------------------------------------------------------------------------
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
	TimerMoveAI->Enabled = false;
	TimerCheckBall->Enabled = false;
	TimerAI->Enabled = false;
	// Timers end
}

//---------------------------------------------------------------------------
void __fastcall TFormMain::TimerMoveUserTimer(TObject *Sender)
{
	if (Game.CanMove) {
		int TID = 1;
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
void __fastcall TFormMain::TimerMoveAITimer(TObject *Sender)
{
	if (Game.CanMove) {
		int TID = 0;
		for (int i = 0; i < 3; i++) {
			if (Field.CalcDistance(Field.Team[TID].Player[i].Img->Position->X + Field.Team[TID].Player[i].Img->Width/2, Field.Team[TID].Player[i].Img->Position->Y + Field.Team[TID].Player[i].Img->Height/2, Field.Team[TID].Player[i].mouseX, Field.Team[TID].Player[i].mouseY) > 3)
			{
				float Degree = Field.CalcDegree(Field.Team[TID].Player[i].Img->Position->X + Field.Team[TID].Player[i].Img->Width/2, Field.Team[TID].Player[i].Img->Position->Y + Field.Team[TID].Player[i].Img->Height/2, Field.Team[TID].Player[i].mouseX, Field.Team[TID].Player[i].mouseY);
				for (int j = 0; j <= Field.Team[TID].Player[i].Speed; j++)
				{
					Field.Team[TID].Player[i].Img->Position->X += (cos(Degree * pi / 180) * 1);
					Field.Team[TID].Player[i].Img->Position->Y -= (sin(Degree * pi / 180) * 1);
					Field.Team[TID].Player[i].Txt->Position->X += (cos(Degree * pi / 180) * 1);
					Field.Team[TID].Player[i].Txt->Position->Y -= (sin(Degree * pi / 180) * 1);
					ImageBackground->Repaint();
				}
			}
		}
	}
}

//---------------------------------------------------------------------------
void __fastcall TFormMain::TimerMoveBallTimer(TObject *Sender)
{
	if (Game.CanMove)
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
}

//---------------------------------------------------------------------------
void __fastcall TFormMain::TimerAITimer(TObject *Sender)
{
	if (Game.CanMove)
	{
		double BallX = Ball->Position->X + Ball->Width/2;
		double BallY = Ball->Position->Y + Ball->Height/2;

		// Player1 Нападающий
		double PlayX = Field.Team[SecondID].Player[1].Img->Position->X + Field.Team[SecondID].Player[1].Img->Width/2;
		double PlayY = Field.Team[SecondID].Player[1].Img->Position->Y + Field.Team[SecondID].Player[1].Img->Height/2;
		if ((Field.CalcDistance(Ball->Width/2 + Ball->Position->X, Ball->Height/2 + Ball->Position->Y, Field.Team[SecondID].Player[1].Img->Position->X + Field.Team[SecondID].Player[1].Img->Width/2, Field.Team[SecondID].Player[1].Img->Position->Y + Field.Team[SecondID].Player[1].Img->Height/2) <= 12)) {
			Field.Ball.Speed += 3;
			Field.Ball.Degree = Field.CalcDegree(BallX, BallY, ((1062 - 54)*PanelPlayArea->Width/1062), ((274 + rand() % 50 + 1)*PanelPlayArea->Height/545));
		}
		if (Field.CalcDistance(BallX, BallY, PlayX, PlayY) > 5)
		{
			Field.Team[SecondID].Player[1].Speed = 4;
			Field.Team[SecondID].Player[1].mouseX = BallX;
			Field.Team[SecondID].Player[1].mouseY = BallY;
		} else {
			Field.Team[SecondID].Player[1].Speed = -1;
		}

		// Player2 Воротарь
		PlayX = Field.Team[SecondID].Player[0].Img->Position->X + Field.Team[SecondID].Player[0].Img->Width/2;
		PlayY = Field.Team[SecondID].Player[0].Img->Position->Y + Field.Team[SecondID].Player[0].Img->Height/2;
		if ((Field.CalcDistance(Ball->Width/2 + Ball->Position->X, Ball->Height/2 + Ball->Position->Y, Field.Team[SecondID].Player[0].Img->Position->X + Field.Team[SecondID].Player[0].Img->Width/2, Field.Team[SecondID].Player[0].Img->Position->Y + Field.Team[SecondID].Player[0].Img->Height/2) <= 15)) {
			Field.Ball.Speed += 3;
			Field.Ball.Degree = Field.CalcDegree(BallX, BallY, ((1062 - 54)*PanelPlayArea->Width/1062), ((274 + rand() % 50 + 1)*PanelPlayArea->Height/545));
		}
		if (Field.CalcDistance(BallX, BallY, PlayX, PlayY) > 5 && (BallY > ((180)*PanelPlayArea->Height/545)) && (BallY < ((367)*PanelPlayArea->Height/545)))
		{
			Field.Team[SecondID].Player[0].Speed = 4;
			Field.Team[SecondID].Player[0].mouseX = PlayX;
			Field.Team[SecondID].Player[0].mouseY = BallY;
		} else {
			Field.Team[SecondID].Player[0].Speed = -1;
		}

		// Player3 Защитник
		PlayX = Field.Team[SecondID].Player[2].Img->Position->X + Field.Team[SecondID].Player[2].Img->Width/2;
		PlayY = Field.Team[SecondID].Player[2].Img->Position->Y + Field.Team[SecondID].Player[2].Img->Height/2;
		if ((Field.CalcDistance(Ball->Width/2 + Ball->Position->X, Ball->Height/2 + Ball->Position->Y, Field.Team[SecondID].Player[2].Img->Position->X + Field.Team[SecondID].Player[2].Img->Width/2, Field.Team[SecondID].Player[2].Img->Position->Y + Field.Team[SecondID].Player[2].Img->Height/2) <= 35)) {
			Field.Ball.Speed += 3;
			Field.Ball.Degree = Field.CalcDegree(BallX, BallY, ((1062 - 54)*PanelPlayArea->Width/1062), ((274 + rand() % 50 + 1)*PanelPlayArea->Height/545));
		}
		if (Field.CalcDistance(BallX, BallY, PlayX, PlayY) > 5)
		{
			Field.Team[SecondID].Player[2].Speed = 4;
			Field.Team[SecondID].Player[2].mouseX = PlayX;
			Field.Team[SecondID].Player[2].mouseY = BallY;
		} else {
			Field.Team[SecondID].Player[2].Speed = -1;
		}
	}
}

//---------------------------------------------------------------------------
void __fastcall TFormMain::FormKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
		  TShiftState Shift)
{
	if (!Game.CanMove) {return;}
	// Обработка ударов
	if (isalpha(KeyChar))
	{
		double dWidth = Field.Team[SecondID].Player[Field.Team[SecondID].CurrPlayer].Img->Width/2;
		double dHeight = Field.Team[SecondID].Player[Field.Team[SecondID].CurrPlayer].Img->Height/2;
		double dX = Field.Team[SecondID].Player[Field.Team[SecondID].CurrPlayer].Img->Position->X;
		double dY = Field.Team[SecondID].Player[Field.Team[SecondID].CurrPlayer].Img->Position->Y;
		int dSpeed = 5;

		switch (KeyChar) {
			case 'w': case 'W':
				Field.Team[SecondID].Player[Field.Team[SecondID].CurrPlayer].mouseX = dX + dWidth + 0.001;
				if ((Field.CalcDistance(Ball->Width/2 + Ball->Position->X, Ball->Height/2 + Ball->Position->Y, Field.Team[MainID].Player[Field.Team[MainID].CurrPlayer].Img->Position->X + Field.Team[MainID].Player[Field.Team[MainID].CurrPlayer].Img->Width/2, Field.Team[MainID].Player[Field.Team[MainID].CurrPlayer].Img->Position->Y + Field.Team[MainID].Player[Field.Team[MainID].CurrPlayer].Img->Height/2) <= Field.Team[MainID].Player[Field.Team[MainID].CurrPlayer].Img->Height)) {
					Field.Ball.Speed += 3;
					Field.Ball.Degree = Field.CalcDegree(Field.Team[MainID].Player[Field.Team[MainID].CurrPlayer].Img->Width/2 + Field.Team[MainID].Player[Field.Team[MainID].CurrPlayer].Img->Position->X, Field.Team[MainID].Player[Field.Team[MainID].CurrPlayer].Img->Height/2 + Field.Team[MainID].Player[Field.Team[MainID].CurrPlayer].Img->Position->Y, Ball->Width/2 + Ball->Position->X, Ball->Height/2 + Ball->Position->Y);
					Ball->Position->X += 5;
				}
			break;

			case 'e': case 'E':
				Field.Team[SecondID].Player[Field.Team[SecondID].CurrPlayer].mouseX = dX + dWidth + 0.001;
				if ((Field.CalcDistance(Ball->Width/2 + Ball->Position->X, Ball->Height/2 + Ball->Position->Y, Field.Team[MainID].Player[Field.Team[MainID].CurrPlayer].Img->Position->X + Field.Team[MainID].Player[Field.Team[MainID].CurrPlayer].Img->Width/2, Field.Team[MainID].Player[Field.Team[MainID].CurrPlayer].Img->Position->Y + Field.Team[MainID].Player[Field.Team[MainID].CurrPlayer].Img->Height/2) <= Field.Team[MainID].Player[Field.Team[MainID].CurrPlayer].Img->Height)) {
					Field.Ball.Speed += 3;
					Field.Ball.Degree = Field.CalcDegree(Field.Team[MainID].Player[Field.Team[MainID].CurrPlayer].Img->Width/2 + Field.Team[MainID].Player[Field.Team[MainID].CurrPlayer].Img->Position->X, Field.Team[MainID].Player[Field.Team[MainID].CurrPlayer].Img->Height/2 + Field.Team[MainID].Player[Field.Team[MainID].CurrPlayer].Img->Position->Y, ((54)*PanelPlayArea->Width/1062), ((274)*PanelPlayArea->Height/545));
					Ball->Position->X += 5;
				}
			break;
		}
	// Обработка переключений между игроками
	} else if (isdigit(KeyChar)) {
		KeyChar -= '0';
		switch(KeyChar) {
			case 1: case 2: case 3:
				Field.Team[MainID].Player[Field.Team[MainID].CurrPlayer].Speed = DefSpeed[Field.Team[MainID].CurrPlayer]/2;
				Field.Team[MainID].CurrPlayer = KeyChar - 1;
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
	Field.Team[MainID].Player[Field.Team[MainID].CurrPlayer].Speed = DefSpeed[Field.Team[MainID].CurrPlayer];
}

//---------------------------------------------------------------------------
void __fastcall TFormMain::TimerCheckBallTimer(TObject *Sender)
{
	// Проверка на ГОЛ
	double BallX = Field.Ball.CBall->Width/2 + Field.Ball.CBall->Position->X;
	double BallY = Field.Ball.CBall->Height/2 + Field.Ball.CBall->Position->Y;
	int GT = 0;
	if ((BallX < (54*PanelPlayArea->Width/1062)) && (BallY > (236*PanelPlayArea->Height/545)) && (BallY < (311*PanelPlayArea->Height/545)))
	{
		GT = 1;
	} else if ((BallX > ((1062 - 54)*PanelPlayArea->Width/1062)) && (BallY > (236*PanelPlayArea->Height/545)) && (BallY < (311*PanelPlayArea->Height/545)))
	{
		GT = 2;
	}
	if (GT > 0)
	{
		Game.GoalTo(GT);
		PrintCount();
		DestroyField();
		if (Game.Winner > -1) {
			ofstream ss("db/win.bin", std::ofstream::out | std::ofstream::trunc);
			if (Game.Winner == 0)
			{
				string msg = "Вы проиграли";
				ShowMessage(msg.c_str());
				ss << 0;
			} else {
				string msg = "Вы ПОБЕДИЛИ! На ваш счет будет зачислено $3000.";
				ShowMessage(msg.c_str());
				ss << 3000;
            }
			ss.close();
			FormMain->Close();
		} else {
            InitField();
        }
		Field.Ball.Speed = 0;
		Field.Ball.Degree = 0;
		return;
    }


	// Проверка на выход из поля
	if ((Field.Ball.CBall->Width/2 + Field.Ball.CBall->Position->X) < (54*PanelPlayArea->Width/1062))
	{
		InitTimer(0);
		Field.Ball.CBall->Position->X = BallDelta[0]*PanelPlayArea->Width - Field.Ball.CBall->Width/2;
		Field.Ball.CBall->Position->Y = PanelPlayArea->Height/2 - Field.Ball.CBall->Height/2;
		Field.Ball.Speed = 0;
		Field.Ball.Degree = 0;
		TimerMoveUser->Enabled = false;
		Field.Team[0].DeletePlayer(0);
		Field.Team[0].AddPlayer((GoalKeeperDelta[0]*PanelPlayArea->Width) - PlayerSize/2, (PanelPlayArea->Height - PlayerSize)/2, 'b');
		TimerMoveUser->Enabled = true;
		return;
	} else if ((Field.Ball.CBall->Width/2 + Field.Ball.CBall->Position->X) > ((1062-54)*PanelPlayArea->Width/1062))
	{
		InitTimer(0);
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
	for (int i = 1; i < 2; i++)
	{
		TImage* TestPlayer;
		for (int j = 0; j < 3; j++) {
			TestPlayer = Field.Team[i].Player[j].Img;
			if (sqrt(((Ball->Height/2 + Ball->Position->Y) - (TestPlayer->Height/2 + TestPlayer->Position->Y))*((Ball->Height/2 + Ball->Position->Y) - (TestPlayer->Height/2 + TestPlayer->Position->Y)) + ((Ball->Width/2 + Ball->Position->X) - (TestPlayer->Width/2 + TestPlayer->Position->X))*((Ball->Width/2 + Ball->Position->X) - (TestPlayer->Width/2 + TestPlayer->Position->X))) <= TestPlayer->Width/4/(2-i)) {
				Field.Ball.Speed = 0;
				return;
			}
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::FormShow(TObject *Sender)
{
	Udb.in();
	Udb.pid.in();
	for (int i = 0; i < 3; i++)
		DefSpeed[i] = Udb.GetUser(Udb.pid.value).Team[i].speed;
	LabelGameTo->Text = ("Игра до " + ToStr(Game.WinCount) + " побед.").c_str();
	Udb.pid.out();
	Udb.out();
	InitField();
	Game.InitGame();
}
//---------------------------------------------------------------------------


void __fastcall TFormMain::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	if (Game.Winner == -1) {
		ofstream ss("db/win.bin", std::ofstream::out | std::ofstream::trunc);
		ss << 0;
        ss.close();
	}
	DestroyField();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::TimerCountDownTimer(TObject *Sender)
{
	if (!Game.TimerCount) {
		LabelCountDown->Text = "";
		TimerCountDown->Enabled = false;
		PrintCount();
		Game.CanMove = true;
	} else {
		LabelCountDown->Text = ("Таймер: " + ToStr(Game.TimerCount--) + " секунд").c_str();
	}
}
//---------------------------------------------------------------------------

