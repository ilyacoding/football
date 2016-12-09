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
#include <FMX.ImgList.hpp>
#include <System.ImageList.hpp>
#include <FMX.Ani.hpp>
//---------------------------------------------------------------------------
#include "ClassTUdb.h"
#include <FMX.Media.hpp>
//---------------------------------------------------------------------------
class TFormMenu : public TForm
{
__published:	// IDE-managed Components
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
	TSpeedButton *SpeedButtonStartGame;
	TImage *ImageStartGame;
	TSpeedButton *SpeedButtonAdd0;
	TImage *ImageAdd0;
	TSpeedButton *SpeedButtonAdd1;
	TImage *ImageAdd1;
	TSpeedButton *SpeedButtonAdd2;
	TImage *ImageAdd2;
	TSpeedButton *SpeedButtonExit;
	TImage *ImageExit;
	TSpeedButton *SpeedButtonAddLvl;
	TImage *ImageAddLvl;
	TCalloutPanel *CalloutPanelToReg;
	TLabel *LabelNeedRegister;
	TFloatAnimation *FloatAnimationPanelTopHeight;
	TFloatAnimation *FloatAnimationStartGameHeight;
	TFloatAnimation *FloatAnimationUserNameHeight;
	TTimer *TimerChangePhoto;
	TProgressBar *ProgressBarPhoto;
	TFloatAnimation *FloatAnimationChangePhoto;
	TFloatAnimation *FloatAnimationAddLvl;
	TMediaPlayer *MediaPlayerMenu;
	void __fastcall ButtonProfileClick(TObject *Sender);
	void __fastcall TimerCheckUserLoginTimer(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall SpeedButtonProfileClick(TObject *Sender);
	void __fastcall SpeedButtonAboutClick(TObject *Sender);
	void __fastcall SpeedButtonStatsClick(TObject *Sender);
	void __fastcall SpeedButtonProfileMouseEnter(TObject *Sender);
	void __fastcall SpeedButtonStatsMouseEnter(TObject *Sender);
	void __fastcall SpeedButtonAboutMouseEnter(TObject *Sender);
	void __fastcall SpeedButtonStartGameClick(TObject *Sender);
	void __fastcall SpeedButtonAdd0Click(TObject *Sender);
	void __fastcall SpeedButtonAdd1Click(TObject *Sender);
	void __fastcall SpeedButtonAdd2Click(TObject *Sender);
	void __fastcall SpeedButtonExitClick(TObject *Sender);
	void __fastcall SpeedButtonAddLvlClick(TObject *Sender);
	void __fastcall TimerChangePhotoTimer(TObject *Sender);
	void __fastcall SpeedButtonAddLvlMouseEnter(TObject *Sender);
private:	// User declarations
public:		// User declarations
    void __fastcall SetUserVisible(bool state);
	__fastcall TFormMenu(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMenu *FormMenu;
//---------------------------------------------------------------------------
#endif
