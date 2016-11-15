//---------------------------------------------------------------------------

#ifndef UnitAuthH
#define UnitAuthH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.ComboEdit.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TFormAuth : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TLabel *Label1;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormAuth(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAuth *FormAuth;
//---------------------------------------------------------------------------
#endif
