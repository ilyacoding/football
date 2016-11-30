//---------------------------------------------------------------------------

#ifndef UnitGlobStatH
#define UnitGlobStatH
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
class TFormGlobStat : public TForm
{
__published:	// IDE-managed Components
	TListBox *ListBox1;
	TLabel *LabelStat;
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormGlobStat(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormGlobStat *FormGlobStat;
//---------------------------------------------------------------------------
#endif
