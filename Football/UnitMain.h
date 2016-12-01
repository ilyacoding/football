//---------------------------------------------------------------------------

#ifndef UnitMainH
#define UnitMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include <math.h>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Ani.hpp>
#include <FMX.ImgList.hpp>
#include <System.ImageList.hpp>
#include <FMX.MaterialSources.hpp>
#include <FMX.Effects.hpp>
#include <FMX.Viewport3D.hpp>
#include <FMX.Controls3D.hpp>
#include <FMX.Objects3D.hpp>
#include <System.Math.Vectors.hpp>
#include <FMX.Edit.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdCustomTCPServer.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <IdTCPServer.hpp>
#include <IdUDPBase.hpp>
#include <IdUDPClient.hpp>
#include <IdUDPServer.hpp>
#include <FMX.Menus.hpp>
#include <FMX.ComboEdit.hpp>
#include <IdContext.hpp>


//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
	TTimer *TimerMoveUser;
	TImage *ImageBackground;
	TCircle *Ball;
	TTimer *TimerMoveBall;
	TPanel *PanelPlayArea;
	TTimer *TimerCheckBall;
	TLabel *LabelFPS;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TToolBar *ToolBarMenu;
	TLabel *LabelCount;
	void __fastcall TimerMoveUserTimer(TObject *Sender);
	void __fastcall TimerMoveBallTimer(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
		  TShiftState Shift);
	void __fastcall PanelPlayAreaMouseMove(TObject *Sender, TShiftState Shift, float X, float Y);
	void __fastcall TimerCheckBallTimer(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall InitField();
	void __fastcall DestroyField();
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:	// User declarations
public:		// User declarations
	TImage *tmpImage;
	TLabel *tmpLabel;
	__fastcall TFormMain(TComponent* Owner);
};


//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
int UniqNum = 0;
//---------------------------------------------------------------------------
#endif


