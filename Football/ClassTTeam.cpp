//---------------------------------------------------------------------------

#pragma hdrstop

#include "ClassTTeam.h"
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

		// Создаем картинку игрока
		Player[i].Img = new TImage(FormMain);
		Player[i].Img->Parent = FormMain->ImageBackground;
		Player[i].Img->Name = "Image" + AnsiString(i) + "Team" + ++UniqNum;
		Player[i].Img->Width = PlayerSize;
		Player[i].Img->Height = PlayerSize;
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

		// Номер игрока, поверх картинки
		Player[i].Txt = new TText(FormMain);
		Player[i].Txt->Parent = FormMain->ImageBackground;
		Player[i].Txt->Height = PlayerSize;
		Player[i].Txt->Width = PlayerSize;
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
//---------------------------------------------------------------------------
#pragma package(smart_init)
