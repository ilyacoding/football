//---------------------------------------------------------------------------

#ifndef UnitInfoH
#define UnitInfoH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TFormInfo : public TForm
{
__published:	// IDE-managed Components
	TToolBar *ToolBar1;
	TLabel *LabelInfo;
	TMemo *Memo1;
private:	// User declarations
public:		// User declarations
	__fastcall TFormInfo(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormInfo *FormInfo;
//---------------------------------------------------------------------------
#endif
