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

#include "ClassTUdb.h"
#include <FMX.Media.hpp>
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
	TToolBar *ToolBarMenu;
	TLabel *LabelCount;
	TTimer *TimerCountDown;
	TTimer *TimerAI;
	TTimer *TimerMoveAI;
	TLabel *LabelCountDown;
	TLabel *LabelGameTo;
	TMediaPlayer *MediaPlayer1;
	void __fastcall TimerMoveUserTimer(TObject *Sender);
	void __fastcall TimerMoveBallTimer(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
		  TShiftState Shift);
	void __fastcall PanelPlayAreaMouseMove(TObject *Sender, TShiftState Shift, float X, float Y);
	void __fastcall TimerCheckBallTimer(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall TimerCountDownTimer(TObject *Sender);
	void __fastcall TimerAITimer(TObject *Sender);
	void __fastcall TimerMoveAITimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
	void __fastcall AITick();
	void __fastcall InitField();
	void __fastcall DestroyField();
	void __fastcall PrintCount();
	void __fastcall InitTimer(int Count);
    void __fastcall PlayMusic(UnicodeString s);
	TImage *tmpImage;
	TLabel *tmpLabel;
	__fastcall TFormMain(TComponent* Owner);
};


//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
int UniqNum = 0;
//---------------------------------------------------------------------------
#endif


