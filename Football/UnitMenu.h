//---------------------------------------------------------------------------

#ifndef UnitMenuH
#define UnitMenuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Colors.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Objects.hpp>
//---------------------------------------------------------------------------
#include "ClassTUdb.h"
#include <FMX.ImgList.hpp>
#include <System.ImageList.hpp>
#include <FMX.Ani.hpp>
//---------------------------------------------------------------------------
class TFormMenu : public TForm
{
__published:	// IDE-managed Components
	TButton *ButtonStartGame;
	TLabel *LabelUser;
	TToolBar *ToolBarPlayers;
	TPanel *PanelPlayer0;
	TPanel *PanelPlayer1;
	TPanel *PanelPlayer2;
	TTimer *TimerCheckUserLogin;
	TLabel *LabelName0;
	TLabel *LabelLevel0;
	TLabel *LabelSpeed0;
	TImage *ImageUser0;
	TLabel *LabelSpeed1;
	TLabel *LabelLevel1;
	TLabel *LabelName1;
	TImage *ImageUser1;
	TLabel *LabelSpeed2;
	TLabel *LabelLevel2;
	TLabel *LabelName2;
	TImage *ImageUser2;
	TImage *ImageBackground;
	TToolBar *ToolBarTop;
	TLabel *LabelCash;
	TLabel *LabelLvl;
	TLabel *LabelWin;
	TButton *ButtonAdd0;
	TButton *ButtonAdd1;
	TButton *ButtonAdd2;
	TButton *ButtonAddLvl;
	TButton *ButtonExit;
	TSpeedButton *SpeedButtonProfile;
	TFloatAnimation *FloatAnimationPanelHeight;
	TImage *ImageProfile;
	TSpeedButton *SpeedButtonAbout;
	TImage *ImageAbout;
	TSpeedButton *SpeedButtonStats;
	TImage *ImageStatistics;
	TFloatAnimation *FloatAnimationMouseProfile;
	TFloatAnimation *FloatAnimationMouseStat;
	TFloatAnimation *FloatAnimationMouseInfo;
	void __fastcall ButtonProfileClick(TObject *Sender);
	void __fastcall ButtonStartGameClick(TObject *Sender);
	void __fastcall TimerCheckUserLoginTimer(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall ButtonAdd0Click(TObject *Sender);
	void __fastcall ButtonAdd1Click(TObject *Sender);
	void __fastcall ButtonAdd2Click(TObject *Sender);
	void __fastcall ButtonAddLvlClick(TObject *Sender);
	void __fastcall ButtonExitClick(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall SpeedButtonProfileClick(TObject *Sender);
	void __fastcall SpeedButtonAboutClick(TObject *Sender);
	void __fastcall SpeedButtonStatsClick(TObject *Sender);
	void __fastcall SpeedButtonProfileMouseEnter(TObject *Sender);
	void __fastcall SpeedButtonStatsMouseEnter(TObject *Sender);
	void __fastcall SpeedButtonAboutMouseEnter(TObject *Sender);
private:	// User declarations
public:		// User declarations
    void __fastcall SetUserVisible(bool state);
	__fastcall TFormMenu(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMenu *FormMenu;
//---------------------------------------------------------------------------
#endif
