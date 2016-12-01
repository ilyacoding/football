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
//---------------------------------------------------------------------------
class TFormMenu : public TForm
{
__published:	// IDE-managed Components
	TButton *ButtonStartGame;
	TLabel *LabelInfo;
	TLabel *LabelUser;
	TButton *ButtonProfile;
	TButton *ButtonTeam;
	TButton *ButtonGlobStat;
	TButton *ButtonInfo;
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
	void __fastcall ToolBarPlayersResize(TObject *Sender);
	void __fastcall ButtonProfileClick(TObject *Sender);
	void __fastcall ButtonStartGameClick(TObject *Sender);
	void __fastcall TimerCheckUserLoginTimer(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall ButtonGlobStatClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormMenu(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMenu *FormMenu;
//---------------------------------------------------------------------------
#endif
