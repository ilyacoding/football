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
//---------------------------------------------------------------------------
class TFormMenu : public TForm
{
__published:	// IDE-managed Components
	TButton *ButtonStartGame;
	TLabel *Label1;
	TLabel *Label2;
	TButton *ButtonProfile;
	TButton *ButtonTeam;
	TButton *ButtonGlobStat;
	TButton *ButtonInfo;
	TToolBar *ToolBarPlayers;
	TPanel *PanelPlayer1;
	TPanel *PanelPlayer2;
	TPanel *PanelPlayer3;
	void __fastcall ToolBarPlayersResize(TObject *Sender);
	void __fastcall ButtonProfileClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormMenu(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMenu *FormMenu;
//---------------------------------------------------------------------------
#endif
