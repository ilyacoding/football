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
#include "Profile.h"
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
	TPanel *PanelPlayer1;
	TPanel *PanelPlayer2;
	TPanel *PanelPlayer3;
	TTimer *TimerCheckUserLogin;
	void __fastcall ToolBarPlayersResize(TObject *Sender);
	void __fastcall ButtonProfileClick(TObject *Sender);
	void __fastcall ButtonStartGameClick(TObject *Sender);
	void __fastcall TimerCheckUserLoginTimer(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:	// User declarations
public:		// User declarations
	__fastcall TFormMenu(TComponent* Owner);
	TProfiles Profiles;
	int PID;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMenu *FormMenu;
//---------------------------------------------------------------------------
#endif
