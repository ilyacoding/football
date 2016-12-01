//---------------------------------------------------------------------------

#ifndef UnitStatH
#define UnitStatH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.ListView.Adapters.Base.hpp>
#include <FMX.ListView.Appearances.hpp>
#include <FMX.ListView.hpp>
#include <FMX.ListView.Types.hpp>
//---------------------------------------------------------------------------
#include "ClassTUdb.h"
//---------------------------------------------------------------------------
class TFormStat : public TForm
{
__published:	// IDE-managed Components
	TListBox *ListBox1;
	TLabel *LabelStat;
	TToolBar *ToolBar1;
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormStat(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormStat *FormStat;
//---------------------------------------------------------------------------
#endif
