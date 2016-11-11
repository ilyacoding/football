//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitMain.h"
#include "math.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.Surface.fmx", _PLAT_MSWINDOWS)

// ���������, ������ ����������
TBallGame *BallGame;
UnicodeString Host;
const double pi = 3.14159265358979323;
const int TeamSize = 3;
int UniqNum = 0;
// ���������, ������ ����������

//---------------------------------------------------------------------------
__fastcall TBallGame::TBallGame(TComponent* Owner)
	: TForm(Owner)
{
}

class TPlayer
{
	public:
		int Speed;
		float mouseX, mouseY;
		bool InGame;
		TImage* Img;
		TText* Txt;
};

class TTeam
{
	public:
		TPlayer Player[TeamSize];
		int CurrPlayer;
		int Score;
		int GetAmount();
		bool AddPlayer(float PosX, float PosY, char ImgColor);
		bool DeletePlayer(int N);
};

class TBall
{
	public:
		float Speed, Accelerate, Degree;
};

class TField
{
	public:
		TTeam Team[2];
		TBall Ball;
		TImage* Background;
		float CalcDegree(float FromX, float FromY, float ToX, float ToY);
		float CalcDistance(float FromX, float FromY, float ToX, float ToY);
} Field;

int TTeam::GetAmount()
{
	int Amount = 0;
	for (int i = 0; i < TeamSize; i++)
		if (Player[i].InGame)
			Amount++;
	return Amount;
}

bool TTeam::AddPlayer(float PosX, float PosY, char ImgColor)
{
	if (GetAmount() < TeamSize)
	{
		int i = 0;
		while (Player[i].InGame) i++;
		Player[i].Speed = 0;
		Player[i].mouseX = 0;
		Player[i].mouseY = 0;
		Player[i].InGame = true;

		// ������� �������� ������
		Player[i].Img = new TImage(BallGame);
		Player[i].Img->Parent = Field.Background;
		Player[i].Img->Name = "Image" + AnsiString(i) + "Team" + ++UniqNum;
		Player[i].Img->Width = 64;
		Player[i].Img->Height = 64;
		Player[i].Img->Position->X = PosX;
		Player[i].Img->Position->Y = PosY;
		switch(ImgColor)
		{
			case 'r':
				Player[i].Img->Bitmap->LoadFromFile("img/player.png");
				break;
			case 'b':
				Player[i].Img->Bitmap->LoadFromFile("img/player.png");
				break;
			default:
				Player[i].Img->Bitmap->LoadFromFile("img/player.png");
				break;
		}

		// ����� ������, ������ ��������
		Player[i].Txt = new TText(BallGame);
		Player[i].Txt->Parent = BallGame->ImageBackground;
		Player[i].Txt->Height = 64;
		Player[i].Txt->Width = 64;
		Player[i].Txt->Name = "Text" + AnsiString(i) + "Team" + ++UniqNum;
		Player[i].Txt->Text = AnsiString(i + 1);
		Player[i].Txt->Font->Size = 36;
		Player[i].Txt->TextSettings->FontColor = TAlphaColor(claBlack);
		Player[i].Txt->Position->X = PosX;
		Player[i].Txt->Position->Y = PosY;
		return true;
	} else {
		return false;
	}
}

bool TTeam::DeletePlayer(int N)
{
	if (Player[N].InGame)
	{
		Player[N].Speed = 0;
		Player[N].mouseX = 0;
		Player[N].mouseY = 0;
		Player[N].InGame = false;
		delete Player[N].Img;
		delete Player[N].Txt;
		return true;
	} else {
		return false;
    }
}

float TField::CalcDegree(float FromX, float FromY, float ToX, float ToY)
{
	if ((ToX - (FromX) > 0) && (ToY - (FromY) > 0)) {// X+ Y+
		return ceil(atan(fabs(ToX - (FromX))/fabs(ToY - (FromY))) * 180 / pi) + 270;
	} else if ((ToX - (FromX) < 0) && (ToY - (FromY) > 0)) {// X- Y+
		return ceil(atan(fabs(ToY - (FromY))/fabs(ToX - (FromX))) * 180 / pi) + 180;
	} else if ((ToX - (FromX) > 0) && (ToY - (FromY) < 0)) {// X+ Y-
		return ceil(atan(fabs(ToY - (FromY))/fabs(ToX - (FromX))) * 180 / pi);
	} else if ((ToX - (FromX) < 0) && (ToY - (FromY) < 0)) {// X- Y-
		return 180 - ceil(atan(fabs(ToY - (FromY))/fabs(ToX - (FromX))) * 180 / pi);
	} else {
		return 0;
	}
}

float TField::CalcDistance(float FromX, float FromY, float ToX, float ToY)
{
	return sqrt(((FromY) - (ToY))*((FromY) - (ToY)) + ((FromX) - (ToX))*((FromX) - (ToX)));
}

//---------------------------------------------------------------------------
void __fastcall TBallGame::TimerMoveUserTimer(TObject *Sender)
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

	/*
	for (int i = 0; i < 2; i++)
	{
		float Degree = Field.CalcDegree();
		//moveDeg = CalcDeg(ImgPlayer->Position->X + ImgPlayer->Width/2, ImgPlayer->Position->Y + ImgPlayer->Height/2, mouseX, mouseY);
		//Label1->Text = IntToStr(moveDeg);
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < TeamSize; k++)
			{
				if (Field.Team[j].Player[k].Speed > 0)
				{
					Field.Team[j].Player[k].Img->Position->X += (cos(Field.Team[j].Player[k].Degree * pi / 180) * 1);
					Field.Team[j].Player[k].Img->Position->Y -= (sin(Field.Team[j].Player[k].Degree * pi / 180) * 1);

					Field.Team[j].Player[k].Txt->Position->X += (cos(Field.Team[j].Player[k].Degree * pi / 180) * 1);
					Field.Team[j].Player[k].Txt->Position->Y -= (sin(Field.Team[j].Player[k].Degree * pi / 180) * 1);
				}
			}
			if (Field.Team[j].Player[Field.Team[j].CurrPlayer].Speed > 0) {
				for (int k = 0; k < Field.Team[j].Player[Field.Team[j].CurrPlayer].Speed; k++) {
					Field.Team[j].Player[Field.Team[j].CurrPlayer].Img->Position->X += (cos(Field.Team[j].Player[Field.Team[j].CurrPlayer].Degree * pi / 180) * 1);
					Field.Team[j].Player[Field.Team[j].CurrPlayer].Img->Position->Y -= (sin(Field.Team[j].Player[Field.Team[j].CurrPlayer].Degree * pi / 180) * 1);

					Field.Team[j].Player[Field.Team[j].CurrPlayer].Txt->Position->X += (cos(Field.Team[j].Player[Field.Team[j].CurrPlayer].Degree * pi / 180) * 1);
					Field.Team[j].Player[Field.Team[j].CurrPlayer].Txt->Position->Y -= (sin(Field.Team[j].Player[Field.Team[j].CurrPlayer].Degree * pi / 180) * 1);
				}
			}
		}

		//if (((cos(int(moveDeg) * pi / 180) * 1) + ImgPlayer->Position->X < 2 +ImageUser->Width) && ((cos(int(moveDeg) * pi / 180) * 1) + ImgPlayer->Position->X > (1-ImgPlayer->Width/2)))
		//{
		//	ImgPlayer->Position->X += (cos(int(moveDeg) * pi / 180) * 1);
		//}
		//if ((ImgPlayer->Position->Y - (sin(int(moveDeg) * pi / 180) * 1) < 2 + ImageUser->Height) && (ImgPlayer->Position->Y - (sin(int(moveDeg) * pi / 180) * 1) > (1-ImgPlayer->Width/2)))
		//{
		//	ImgPlayer->Position->Y -= (sin(int(moveDeg) * pi / 180) * 1);
		//}
		Field.Background->Repaint();
	}*/
}
//---------------------------------------------------------------------------

void __fastcall TBallGame::FormCreate(TObject *Sender)
{
	// Background
	Field.Background = ImageBackground;
	Field.Background->Bitmap->LoadFromFile("img/bg.png");

	// Players
	for (int i = 1; Field.Team[0].AddPlayer(i*70, i*70, 'r'); i++);
	Field.Team[0].CurrPlayer = 0;

	for (int i = 1; Field.Team[1].AddPlayer(400, i*10 + 20, 'r'); i++);
	Field.Team[1].CurrPlayer = 0;
	// Ball
	Field.Ball.Degree = 0;
	Field.Ball.Accelerate = 0.002;
	Field.Ball.Speed = 1;
}

//---------------------------------------------------------------------------

void __fastcall TBallGame::TimerMoveBallTimer(TObject *Sender)
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

void __fastcall TBallGame::FormKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
		  TShiftState Shift)
{
	Label1->Text = KeyChar;
	if ((KeyChar == 'w') && (Field.CalcDistance(Ball->Width/2 + Ball->Position->X, Ball->Height/2 + Ball->Position->Y, Field.Team[0].Player[Field.Team[0].CurrPlayer].Img->Position->X + Field.Team[0].Player[Field.Team[0].CurrPlayer].Img->Width/2, Field.Team[0].Player[Field.Team[0].CurrPlayer].Img->Position->Y + Field.Team[0].Player[Field.Team[0].CurrPlayer].Img->Height/2) <= Field.Team[0].Player[Field.Team[0].CurrPlayer].Img->Height)) {
		Field.Ball.Speed += 3;
		Field.Ball.Degree = Field.CalcDegree(Field.Team[0].Player[Field.Team[0].CurrPlayer].Img->Width/2 + Field.Team[0].Player[Field.Team[0].CurrPlayer].Img->Position->X, Field.Team[0].Player[Field.Team[0].CurrPlayer].Img->Height/2 + Field.Team[0].Player[Field.Team[0].CurrPlayer].Img->Position->Y, Ball->Width/2 + Ball->Position->X, Ball->Height/2 + Ball->Position->Y);
	} else if (isdigit(KeyChar) && (KeyChar - '0' <= TeamSize)) {
		Field.Team[0].Player[Field.Team[0].CurrPlayer].Speed = 2;
		Field.Team[0].CurrPlayer = KeyChar - '0' - 1;
	}
}
//---------------------------------------------------------------------------

void __fastcall TBallGame::PanelPlayAreaMouseMove(TObject *Sender, TShiftState Shift, float X,
		  float Y)
{
	Field.Team[0].Player[Field.Team[0].CurrPlayer].mouseX = X;
	Field.Team[0].Player[Field.Team[0].CurrPlayer].mouseY = Y;
	Field.Team[0].Player[Field.Team[0].CurrPlayer].Speed = 5;
}
//---------------------------------------------------------------------------

void __fastcall TBallGame::TimerStopBallTimer(TObject *Sender)
{
	TImage* TestPlayer;
	for (int i = 0; i < TeamSize; i++) {
		TestPlayer = Field.Team[0].Player[i].Img;
		if (sqrt(((Ball->Height/2 + Ball->Position->Y) - (TestPlayer->Height/2 + TestPlayer->Position->Y))*((Ball->Height/2 + Ball->Position->Y) - (TestPlayer->Height/2 + TestPlayer->Position->Y)) + ((Ball->Width/2 + Ball->Position->X) - (TestPlayer->Width/2 + TestPlayer->Position->X))*((Ball->Width/2 + Ball->Position->X) - (TestPlayer->Width/2 + TestPlayer->Position->X))) <= TestPlayer->Width/4) {
			Field.Ball.Speed = 0;
		}
	}
}
//---------------------------------------------------------------------------

